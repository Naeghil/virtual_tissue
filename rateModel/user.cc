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

#define NO_ITERS 5
#define NO_PATCHES 200000
#define PRES_TIME 100
#define SP_INTERVAL 100 * 5 // The base interval is 100 patches (10s) but the implementation uses 5*10 = 50s
#define SP false

// This is the name of the condition used in the model
#define CNO 5
#if CNO == 1
    #define CONDITION "popAvg"
#elif CNO == 2
    #define CONDITION "ogTrace"
#elif CNO == 3
    #define CONDITION "slowTrace"
#elif CNO == 4
    #define CONDITION "midTrace"
#elif CNO == 5
    #define CONDITION "fastTrace"
#elif CNO == 6
    #define CONDITION "constant"
#endif

string synName(int s, string div = "-") {
    return string(PName[Synapses[s][0]]) + div + string(PName[Synapses[s][1]]);
}

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
// Global variables because yes
unordered_map<string, ofstream> rates;
unordered_map<string, ofstream> weights;

void recordProgress(SharedLibraryModel<scalar> &m) {
    // Neurons
    for (int p = 0; p < PMax; p++) {
        int dim = side[p]*side[p]*depth[p]; 
        m.pullVarFromDevice(PName[p], "r");
        rates[PName[p]].write(reinterpret_cast<char*>(m.getArray<scalar>("r"+string(PName[p]))), sizeof(scalar)*dim);
    }
    // Synapses
    for (int s = 0; s < noSynapses; s++) {
        int src = Synapses[s][0]; int trg = Synapses[s][1];
        int dim = side[src] * side[src] * depth[src] * side[trg] * side[trg] * depth[trg];
        m.pullVarFromDevice(synName(s, "_"), "w");
        weights[synName(s)].write(reinterpret_cast<char*>(m.getArray<scalar>("w"+synName(s, "_"))), sizeof(scalar)*dim);
    }
}

void writeResults(SharedLibraryModel<scalar> &m, int it) {
    ofstream f(string("../RESULTS/" CONDITION "/It")+to_string(it), ios::out | ios::binary);

    // Neuron populations
    for (int p = 0; p < PMax-1; p++) {
        int dim = side[p]*side[p]*depth[p];
        m.pullStateFromDevice(PName[p]);
        f.write(reinterpret_cast<char*>(m.getArray<scalar>("theta"+string(PName[p]))), sizeof(scalar)*dim);
        f.write(reinterpret_cast<char*>(m.getArray<scalar>("a"+string(PName[p]))), sizeof(scalar)*dim);
    }
    // Synapses
    for (int s = 0; s < noSynapses; s++) {
        int src = Synapses[s][0]; int trg = Synapses[s][1];
        int dim = side[src] * side[src] * depth[src] * side[trg] * side[trg] * depth[trg];
        m.pullStateFromDevice(synName(s, "_"));
        f.write(reinterpret_cast<char*>(m.getArray<scalar>("w"+synName(s,"_"))), sizeof(scalar)*dim);
    }
    f.close();
}

int main() {
    srand(42); // Set seed

    for(int it = 0; it < NO_ITERS; it++) {
        cout << "Training iteration " << it+1 << "/" << NO_ITERS << endl;
        // Model setup
        SharedLibraryModel<float> model("./", "rateModel");
        cout << "Initialising model" << endl;
        model.allocateMem();
        model.initialize();
        cout << "Initialising connectivity" << endl;
        initialiseConnectivity(model);

        // Recorders setup 
        for (int p = 0; p < PMax; p++) rates[PName[p]].open(string("../RESULTS/" CONDITION "/It")+to_string(it)+string("_")+string(PName[p]), ios::out|ios::binary);
        for (int s = 0; s < noSynapses; s++) weights[synName(s)].open(string("../RESULTS/" CONDITION "/It")+to_string(it)+string("_")+synName(s), ios::out|ios::binary);

        // Training setup
        scalar *inRates = model.getArray<scalar>("inputLGN");
        Scene image("IMAGES_NORM2015");  // Training scene
        auto lastPatchgroup = chrono::high_resolution_clock::now();
        double compTime = 0;
        double ioTime = 0;

        // Training protocol
        for (int p = 0; p < NO_PATCHES; p++) {
            // Recording 
            if (p%1000 == 0) {
                cout << "Patch no " << p << "/" << NO_PATCHES <<endl;
                auto newTime = chrono::high_resolution_clock::now();
                compTime += chrono::duration_cast<chrono::microseconds>(newTime - lastPatchgroup).count()/1000.;
                lastPatchgroup = newTime;
                recordProgress(model);
                newTime = chrono::high_resolution_clock::now();
                ioTime += chrono::duration_cast<chrono::microseconds>(newTime - lastPatchgroup).count()/1000.;
                cout << "  Network saved." << endl;
                sleep(5); // Don't want your computer to overheat
                lastPatchgroup = chrono::high_resolution_clock::now();
            }
            // Present Patch
            iMat patch = image.saccade();
            for (int y = 0; y < side[LGN]; y++) for (int x = 0; x < side[LGN]; x ++) for (int z = 0; z < 2; z ++) inRates[y*2*side[LGN] + 2*x + z] = patch[y][x][z];
            model.pushVarToDevice("LGN","input");
            // Simulate
            for (int _ = 0; _ < 100; _++) model.stepTime();   
        }

        // Output and Summary
        recordProgress(model);
        writeResults(model, it);
        cout << "Computation Time: " << compTime << "ms" << endl;
        cout << "Speed Factor: " << compTime / (NO_PATCHES*100.) << endl;
        cout << "IO Time: " << ioTime << "ms" << endl;

        // Recording reset
        for (int p = 0; p < PMax; p++) rates[PName[p]].close();
        for (int s = 0; s < noSynapses; s++) weights[synName(s)].close();
    }




    




    return 0;
}