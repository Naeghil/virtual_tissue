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
        cout << "  Setting "+sName+"-"+tName+" connectivity\n";
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
    auto iRates = m.getArray<scalar>("rLGN");
    for (int y = 0; y < side[LGN]; y++) for (int x = 0; x < side[LGN]; x ++) for (int z = 0; z < 2; z ++) iRates[y*2*side[LGN] + 2*x + z] = patch[y][x][z];
}

// The save function is NOT for the purpose of restarting a simulation from a certain point
// Rather to observe the results of the simulation
void saveNetwork(SharedLibraryModel<scalar> &m, int p) {
    ofstream f(RES_PATH+to_string(p), ios::out | ios::binary | ios::app);
    if (!f.is_open()) throw runtime_error("  Could not save state.");
    // Neurons
    string n;
    for (int p = 0; p < PMax; p++) {
        n = PName[p];
        scalar *arr;
        // Save states in a specific order
        m.pullVarFromDevice(n, "r");
        arr = m.getArray<scalar>("r"+n);
        f.write(reinterpret_cast<char*>(arr), sizeof(scalar)* side[p] * side[p] * depth[p]);
        m.pullVarFromDevice(n, "avgR");
        arr = m.getArray<scalar>("avgR"+n);
        f.write(reinterpret_cast<char*>(arr), sizeof(scalar)* side[p] * side[p] * depth[p]);
        if (p == LGN) continue;
        m.pullVarFromDevice(n, "m");
        arr = m.getArray<scalar>("m"+n);
        f.write(reinterpret_cast<char*>(arr), sizeof(scalar)* side[p] * side[p] * depth[p]);
    }
    // Synapses
    for (int syn = 0; syn < noSynapses; syn++) {
        int s = Synapses[syn][0]; int t = Synapses[syn][1];
        string sName = string(PName[s]) + "_" + string(PName[t]);
        m.pullVarFromDevice(sName, "w");
        scalar *arr = m.getArray<scalar>("w"+sName);
        f.write(reinterpret_cast<char*>(arr), sizeof(scalar) * side[s] * side[s] * depth[s] * side[t] * side[t] * depth[t]);
    }
    // TODO: save connectivity (if connectivity changes)
    f.close();
}


int main() {
    srand(42); // Set seed

    SharedLibraryModel<float> model("./", "rateModel");
    cout << "Initialise model\n";
    model.allocateMem();
    model.initialize();
    cout << "Initialise connectivity\n";
//    initialiseConnectivity(model);

    Scene image("IMAGES_NORM2015");  // Training scene
    auto start = chrono::high_resolution_clock::now();
    auto lastPatchgroup = start;

    // Training protocol
    for (int p = 0; p < NO_PATCHES; p++) {
        // Record midway
        if (p%500 == 0) {
            cout << "Patch no " << p << "/" << NO_PATCHES <<endl;
            auto newTime = chrono::high_resolution_clock::now();
            double diff = chrono::duration_cast<chrono::microseconds>(newTime - lastPatchgroup).count()/1000.;
            cout << "  " << diff/500. << "ms per patch at " << diff/50000 << " acceleration" << endl;
            lastPatchgroup = newTime;
            saveNetwork(model, p);
            newTime = chrono::high_resolution_clock::now();
            cout << "  Network saved. IO time: " << chrono::duration_cast<chrono::microseconds>(newTime - lastPatchgroup).count()/1000. << "ms" << endl;
            sleep(10); // Don't want your computer to overheat
            lastPatchgroup = chrono::high_resolution_clock::now();
        }
        // if (p > 0 && p%SP_INTERVAL == 0 && SP); // TODO: structural plasticity

        presentPatch(model, image.saccade());  // Adjust LGN rates for input
        for (int _ = 0; _ < 100; _++) model.stepTime();  // Simulate
    }
    saveNetwork(model, NO_PATCHES);


    return 0;
}