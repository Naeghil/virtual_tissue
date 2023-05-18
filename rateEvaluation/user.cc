// Model simulation code
#include <iostream>
#include <vector>
#include <chrono>

#include "rateModel_CODE/definitions.h"
#include "parameters.h"
#include "scene.cc"
#include "../userproject/sharedLibraryModel.h"    // From ${GENN}/userproject/include/

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

#define NO_PATCHES 200000
#define SP_INTERVAL 100 * 5 // The base interval is 100 patches (10s) but the implementation uses 5*10 = 50s
#define SP false
#define RES_PATH "../RESULTS/training/"

void initialiseConnectivity(SharedLibraryModel<scalar> &m) {
    for (int i = 0; i < noSynapses; i++) {
        // Definitions
        const int *syn = Synapses[i];
        string sName = PName[syn[0]];
        string tName = PName[syn[1]];
        // Matrices
        fstream mat("./architecture/matrices/"+sName+"-"+tName, ios_base::in);
        if (!mat.is_open()) throw runtime_error("  Matrix file could not be opened.");
        m.pullVarFromDevice(sName+"_"+tName, "active");
        auto conn = m.getArray<bool>("active"+sName+"_"+tName);
        int noS = pow(side[syn[0]],2)*depth[syn[0]];
        int noT = pow(side[syn[1]],2)*depth[syn[1]];
        scalar c;
        for (int s = 0; s < noS; s++) for (int t = 0; t < noT; t++) {
            mat >> c;
            conn[s*noT + t] = c > .5;
        }
        m.pushVarToDevice(sName+"_"+tName, "active");
    } 
}

void presentPatch(SharedLibraryModel<scalar> &m, iMat patch) {
    m.pullVarFromDevice("LGN", "r");
    scalar *iRates = m.getArray<scalar>("rLGN");
    for (int y = 0; y < side[LGN]; y++) for (int x = 0; x < side[LGN]; x ++) for (int z = 0; z < 2; z ++) iRates[y*2*side[LGN] + 2*x + z] = patch[y][x][z];
    m.pushVarToDevice("LGN","r");
}

// Global variables because yes
unordered_map<string, vector<scalar>> rAvg;
unordered_map<string, vector<vector<float>>> rBins;
unordered_map<string, vector<vector<int>>> rDists;
unordered_map<string, vector<scalar>> wAvg;
unordered_map<string, vector<vector<float>>> wBins;
unordered_map<string, vector<vector<int>>> wDists;




// The save function is NOT for the purpose of restarting a simulation from a certain point
// Rather to observe the results of the simulation
vector<scalar> makeHist(scalar *arr, int dim, vector<int> &counts, bool *mask = nullptr, bool nonzero = false) {
    scalar delta = .0;
    for (int i = 0; i<dim; i++) if (arr[i] > delta) delta = arr[i];
    delta /= 100.;
    vector<scalar> bins(101, .0);
    for (int i = 0; i<101; i++) bins[i] = delta*i;
    for (int i=0; i<dim; i++) {
        if (nonzero && !mask[i]) continue;
        int idx = (delta == .0) ? 0 : int(arr[i] / delta);
        counts[idx]++;
    }
    return bins;
}

void saveNetwork(SharedLibraryModel<scalar> &m) {
    // Neurons
    string n;
    int dim;
    scalar *arr;
    for (int p = 0; p < PMax; p++) {
        scalar avg = 0;
        vector<int> counts(100, 0); 
        n = PName[p]; dim = side[p]*side[p]*depth[p]; 
        m.pullVarFromDevice(n, "r"); arr = m.getArray<scalar>("r"+n);
        // Histograms
        rBins[n].push_back(makeHist(arr, dim, counts));
        rDists[n].push_back(counts);
        // Average
        for (int i = 0; i < dim; i++) avg += arr[i];
        rAvg[n].push_back(avg/dim);
    }
    // Synapses
    for (int syn = 0; syn < noSynapses; syn++) {
        scalar avg = 0;
        int count = 0;
        vector<int> counts(100, 0);
        int s = Synapses[syn][0]; int t = Synapses[syn][1];
        string sN = string(PName[s])+"-"+string(PName[t]);
        dim = side[s] * side[s] * depth[s] * side[t] * side[t] * depth[t];
        m.pullVarFromDevice(string(PName[s]) + "_" + string(PName[t]), "w");
        arr = m.getArray<scalar>("w"+string(PName[s]) + "_" + string(PName[t]));
        bool *mask = m.getArray<bool>("active"+string(PName[s]) + "_" + string(PName[t]));
        // Histograms
        wBins[sN].push_back(makeHist(arr, dim, counts, mask, true));
        wDists[sN].push_back(counts);
        for (int i = 0; i < dim; i ++) if (mask[i]) {
                avg += arr[i];
                count++;
        }
        wAvg[sN].push_back(avg/count);
    }
}

void writeResults(SharedLibraryModel<scalar> &m) {
    // Rates
    ofstream f(RES_PATH + string("avgRates.tsv"), ios::out);
    if (!f.is_open()) throw runtime_error("Cannot save simulation results.");
    for (int p = 0; p < PMax; p++) f << PName[p] << "\t"; 
    f << "\n";
    for (int i = 0; i < int(rAvg["LGN"].size()); i++) { 
        for (int p = 0; p < PMax; p++) f << rAvg[PName[p]][i] << "\t"; 
        f << "\n"; 
    } f.close();
    
    // Weights
    f = ofstream(RES_PATH + string("avgWeights.tsv"), ios::out);
    if (!f.is_open()) throw runtime_error("Cannot save simulation results.");
    for (int s = 0; s < noSynapses; s++) f << string(PName[Synapses[s][0]])+"-"+string(PName[Synapses[s][1]]) << "\t"; 
    f << "\n";
    for (int i = 0; i < int(wAvg["LGN-V1L4E"].size()); i++) { 
        for (int s = 0; s < noSynapses; s++) f << wAvg[string(PName[Synapses[s][0]])+"-"+string(PName[Synapses[s][1]])][i] << "\t"; 
        f << "\n"; 
    } f.close();

    // TODO: add mean and sd
    // Distributions: they are just two vectors each 
    for (int p = 0; p < PMax; p++) {
        string pN = PName[p];
        f = ofstream(RES_PATH + pN + string("dist.vec"), ios::out);
        if (!f.is_open()) throw runtime_error("Cannot save simulation results.");
        for (int i = 0; i < int(rDists[pN].size()); i++) {
            for (int k = 0; k < 100; k++) f << rDists[pN][i][k] << " ";
            f << "\n";
            for (int k = 0; k < 101; k++) f << rBins[pN][i][k] << " ";
            f << "\n";
        }
        f.close();
    }
    for (int s = 0; s < noSynapses; s++) {
        string sN = string(PName[Synapses[s][0]])+"-"+string(PName[Synapses[s][1]]);
        f = ofstream(RES_PATH + sN + string("dist.vec"), ios::out);
        if (!f.is_open()) throw runtime_error("Cannot save simulation results.");
        for (int i = 0; i < int(wDists[sN].size()); i++) {
            for (int k = 0; k < 100; k++) f << wDists[sN][i][k] << " ";
            f << "\n";
            for (int k = 0; k < 101; k++) f << wBins[sN][i][k] << " ";
            f << "\n";
        } f.close();
    }

    // Save matrix weights: this is both for analysis and for evaluation initialisation purposes
    for (int s = 0; s < noSynapses; s++) {
        int src = Synapses[s][0]; int trg = Synapses[s][1];
        string sName = PName[src]; string tName = PName[trg];
        int sDim = side[src] * side[src] * depth[src];
        int tDim = side[trg] * side[trg] * depth[trg];

        scalar *weights = m.getArray<scalar>("w"+sName+"_"+tName);
        ofstream f(RES_PATH+sName+"-"+tName+"weights.vec");
        if (!f.is_open()) throw runtime_error("Cannot save simulation results.");
        for (int i = 0; i < sDim; i++) {
            for (int k = 0; k < tDim; k++) f << weights[i*tDim + k] << " "; 
            f << "\n";
        } f.close();
    }
}

int main() {
    srand(42); // Set seed

    // Model setup
    SharedLibraryModel<float> model("./", "rateModel");
    cout << "Initialise model\n";
    model.allocateMem();
    model.initialize();
    cout << "Initialise connectivity\n";
    initialiseConnectivity(model);
    
    // Recorders setup 
    for (int p = 0; p < PMax; p++) {
        rAvg[PName[p]] = vector<scalar>(0);
        rDists[PName[p]] = vector<vector<int>>(0);
        rBins[PName[p]] = vector<vector<scalar>>(0);
    }
    for (int s = 0; s < noSynapses; s++) {
        string n = string(PName[Synapses[s][0]]) + "-" + string(PName[Synapses[s][1]]);
        wAvg[n] = vector<scalar>(0);
        wDists[n] =  vector<vector<int>>(0);
        wBins[n] =  vector<vector<scalar>>(0);
    }

    // Training setup
    Scene image("IMAGES_NORM2015");  // Training scene
    auto start = chrono::high_resolution_clock::now();
    auto lastPatchgroup = start;

    // Training protocol
    for (int p = 0; p < NO_PATCHES; p++) {
        // Record midway
        if (p%1000 == 0) {
            cout << "Patch no " << p << "/" << NO_PATCHES <<endl;
            auto newTime = chrono::high_resolution_clock::now();
            double diff = chrono::duration_cast<chrono::microseconds>(newTime - lastPatchgroup).count()/1000.;
            cout << "  " << diff/1000. << "ms per patch at " << diff/100000 << " acceleration" << endl;
            lastPatchgroup = newTime;
            saveNetwork(model);
            newTime = chrono::high_resolution_clock::now();
            cout << "  Network saved. IO time: " << chrono::duration_cast<chrono::microseconds>(newTime - lastPatchgroup).count()/1000. << "ms" << endl;
            sleep(10); // Don't want your computer to overheat
            lastPatchgroup = chrono::high_resolution_clock::now();
        }
        presentPatch(model, image.saccade());  // Adjust LGN rates for input
        for (int _ = 0; _ < 100; _++) model.stepTime();  // Simulate
    }
    saveNetwork(model);
    // All weights should be already pulled
    writeResults(model);


    return 0;
}