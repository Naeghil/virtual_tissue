// Model simulation code
#include <iostream>
#include <vector>
#include <chrono>

#include "rateEvaluation_CODE/definitions.h"
#include "parameters.h"
#include "scene.cc"
#include "../userproject/sharedLibraryModel.h"    // From ${GENN}/userproject/include/

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

#define RES_PATH "../RESULTS/"

void initialiseConnectivity(SharedLibraryModel<scalar> &m) {
    for (int i = 0; i < noSynapses; i++) {
        // Definitions
        const int *syn = Synapses[i];
        string sName = PName[syn[0]];
        string tName = PName[syn[1]];
        // Matrices
        fstream mat("./architecture/matrices/"+sName+"-"+tName, ios_base::in);
        if (!mat.is_open()) throw runtime_error("  Matrix file could not be opened.");
        fstream weights("../RESULTS/training/"+sName+"-"+tName+"weights.vec", ios_base::in)
        if (!mat.is_open()) throw runtime_error("  Weights file could not be opened.");
        m.pullVarFromDevice(sName+"_"+tName, "active");
        m.pullVarFromDevice(sName+"_"+tName, "w");
        auto conn = m.getArray<bool>("active"+sName+"_"+tName);
        auto w = m.getArray<scalar>("w"+sName+"_"+tName);
        int noS = pow(side[syn[0]],2)*depth[syn[0]];
        int noT = pow(side[syn[1]],2)*depth[syn[1]];
        scalar c; scalar k;
        for (int s = 0; s < noS; s++) for (int t = 0; t < noT; t++) {
            mat >> c; conn[s*noT + t] = c > .5;
            weights >> k; w[s*noT + t] = k;
        }
        m.pushVarToDevice(sName+"_"+tName, "active");
        m.pushVarToDevice(sName+"_"+tName, "w");
    } 
}

void initialiseNeurons(SharedLibraryModel<scalar> &m) {
    for (int p = 0; p < PMax; p++) {
        fstream theta("../RESULTS/training/theta"+PName[p]);
        if (!theta.is_open()) throw runtime_error("Theta file could not be opened.");
        fstream a("../RESULTS/training/a"+PName[p]);
        if (!a.is_open()) throw runtime_error("A file could not be opened.");
        m.pullVarFromDevice(PName[p], "theta");
        m.pullVarFromDevice(PName[p], "a");
        auto thp = m.getArray<scalar>("theta"+PName[p]);
        auto ap = m.getArray<scalar>("a"+PName[p]);
        int dim = pow(side[p],2)*depth[p];
        scalar t; scalar k;
        for(int i=0; i < dim; i++) {
            theta >> t; thp[i] = t;
            a >> k; ap[i] = k;
        }
        m.pushVarToDevice(PName[p],"theta");
        m.pushVarToDevice(PName[p],"a");
    }
}

void presentPatch(SharedLibraryModel<scalar> &m, iMat patch) {
    resetActivities(m);
    m.pullVarFromDevice("LGN", "input");
    scalar *iRates = m.getArray<scalar>("inputLGN");
    for (int y = 0; y < side[LGN]; y++) for (int x = 0; x < side[LGN]; x ++) for (int z = 0; z < 2; z ++) iRates[y*2*side[LGN] + 2*x + z] = patch[y][x][z];
    m.pushVarToDevice("LGN","input");
}

void resetActivities(SharedLibraryModel<scalar> &m, scalar FB = 1.) {
    for (int p = 0; p < PMax; p++) {
        int dim = pow(side[p],2)*depth[p];
        m.pullVarFromDevice(PName[p], "r");
        auto arr = m.getArray<scalar>("r"+string(PName[p]));
        for (int i=0; i < dim; i++) arr[i] = 0.;
        m.pushVarToDevice(PName[p],"r");
        if (p==LGN) {
            m.pullVarFromDevice(PName[p], "input");
            auto arr = m.getArray<scalar>("input"+string(PName[p]));
            for (int i=0; i < dim; i++) arr[i] = 0.;
            m.pushVarToDevice(PName[p],"input");
        } else {
            m.pullVarFromDevice(PName[p], "m");
            auto arr = m.getArray<scalar>("m"+string(PName[p]));
            for (int i=0; i < dim; i++) arr[i] = 0.;
            m.pushVarToDevice(PName[p],"m");
            m.pullVarFromDevice(PName[p], "FB");
            auto arr = m.getArray<scalar>("FB"+string(PName[p]));
            for (int i=0; i < dim; i++) arr[i] = FB;
            m.pushVarToDevice(PName[p],"FB");
        }
    }
    m.stepTime(); // This should reset iSyn
}

// Global variables because yes 
unordered_map<string, vector<vector<scalar>>> rates30FBon;
unordered_map<string, vector<vector<scalar>>> rates30FBoff;
unordered_map<string, vector<vector<scalar>>> rates42FBon;
unordered_map<string, vector<vector<scalar>>> rates42FBoff;
unordered_map<string, vector<vector<scalar>>> rates100FBon;
unordered_map<string, vector<vector<scalar>>> rates100FBoff;

void record(SharedLibraryModel<scalar> &m, unordered_map<string, vector<vector<scalar>>> &r) {
    for (int p=0; p < PMax-1; p++) {
        int dim = pow(side[p],2)*depth[p];
        vector<scalar> rate(dim);
        m.pullVarFromDevice(PName[p],"r");
        auto arr = m.getArray<scalar>("r"+string(PName[p]));
        for (int i=0; i<dim; i++) rate[i] = arr[i];
        r[PName[p]].push_back(rate);
    }
}

void recordDelays(SharedLibraryModel<scalar> &m, unordered_map<string, vector<vector<scalar>>> &r) {
    // Delays are known
    for (int _ = 0; _ < 2; _++) m.stepTime(); // +2
    // V1L4E
    int dim = pow(side[V1L4E],2)*depth[V1L4E];
    vector<scalar> rate(dim);
    m.pullVarFromDevice(PName[V1L4E],"r");
    auto arr = m.getArray<scalar>("r"+string(PName[V1L4E]));
    for (int i=0; i<dim; i++) rate[i] = arr[i];
    r[PName[V1L4E]].push_back(rate);
    // V1L4I
    dim = pow(side[V1L4I],2)*depth[V1L4I];
    rate = vector<scalar>(dim);
    m.pullVarFromDevice(PName[V1L4I],"r");
    auto arr = m.getArray<scalar>("r"+string(PName[V1L4I]));
    for (int i=0; i<dim; i++) rate[i] = arr[i];
    r[PName[V1L4I]].push_back(rate);

    for (int _ = 0; _ < 2; _++) m.stepTime(); // +2
    // V1L23E
    dim = pow(side[V1L23E],2)*depth[V1L23E];
    rate = vector<scalar>(dim);
    m.pullVarFromDevice(PName[V1L23E],"r");
    auto arr = m.getArray<scalar>("r"+string(PName[V1L23E]));
    for (int i=0; i<dim; i++) rate[i] = arr[i];
    r[PName[V1L23E]].push_back(rate);
    // V1L23I
    dim = pow(side[V1L23I],2)*depth[V1L23I];
    rate = vector<scalar>(dim);
    m.pullVarFromDevice(PName[V1L23I],"r");
    arr = m.getArray<scalar>("r"+string(PName[V1L23I]));
    for (int i=0; i<dim; i++) rate[i] = arr[i];
    r[PName[V1L23I]].push_back(rate);

    for (int _ = 0; _ < 3; _++) m.stepTime(); // +3
    // V2L4E
    dim = pow(side[V2L4E],2)*depth[V2L4E];
    rate = vector<scalar>(dim);
    m.pullVarFromDevice(PName[V2L4E],"r");
    arr = m.getArray<scalar>("r"+string(PName[V2L4E]));
    for (int i=0; i<dim; i++) rate[i] = arr[i];
    r[PName[V2L4E]].push_back(rate);
    // V2L4I
    dim = pow(side[V2L4I],2)*depth[V2L4I];
    rate = vector<scalar>(dim);
    m.pullVarFromDevice(PName[V2L4I],"r");
    arr = m.getArray<scalar>("r"+string(PName[V2L4I]));
    for (int i=0; i<dim; i++) rate[i] = arr[i];
    r[PName[V2L4I]].push_back(rate);

    for (int _ = 0; _ < 2; _++) m.stepTime(); // +2
    // V2L23E
    dim = pow(side[V2L23E],2)*depth[V2L23E];
    rate = vector<scalar>(dim);
    m.pullVarFromDevice(PName[V2L23E],"r");
    arr = m.getArray<scalar>("r"+string(PName[V2L23E]));
    for (int i=0; i<dim; i++) rate[i] = arr[i];
    r[PName[V2L23E]].push_back(rate);
    // V2L23I
    dim = pow(side[V2L23I],2)*depth[V2L23I];
    rate = vector<scalar>(dim);
    m.pullVarFromDevice(PName[V2L23I],"r");
    arr = m.getArray<scalar>("r"+string(PName[V2L23I]));
    for (int i=0; i<dim; i++) rate[i] = arr[i];
    r[PName[V2L23I]].push_back(rate);
}

void writeResults(string path) {
    for (int p=0; p<PMax-1; p++) {
        int dim = pow(side[p],2)*depth[p];
        // t30on
        ofstream f(RES_PATH+path+string("30on")+string(PName[p]));
        for (int t = 0; t < rates30FBon[PName[p]].size(); t++) {
            for (int k=0; k<dim; k++) f << rates30FBon[PName[p]][t][k] << " ";
            f << "\n";
        } f.close();
        // t30off
        ofstream f(RES_PATH+path+string("30off")+string(PName[p]));
        for (int t = 0; t < rates30FBoff[PName[p]].size(); t++) {
            for (int k=0; k<dim; k++) f << rates30FBoff[PName[p]][t][k] << " ";
            f << "\n";
        } f.close();
        // t42on
        ofstream f(RES_PATH+path+string("42on")+string(PName[p]));
        for (int t = 0; t < rates42FBon[PName[p]].size(); t++) {
            for (int k=0; k<dim; k++) f << rates42FBon[PName[p]][t][k] << " ";
            f << "\n";
        } f.close();
        // t42off
        ofstream f(RES_PATH+path+string("42off")+string(PName[p]));
        for (int t = 0; t < rates42FBoff[PName[p]].size(); t++) {
            for (int k=0; k<dim; k++) f << rates42FBof[PName[p]][t][k] << " ";
            f << "\n";
        } f.close();
        // t100on
        ofstream f(RES_PATH+path+string("100on")+string(PName[p]));
        for (int t = 0; t < rates100FBon[PName[p]].size(); t++) {
            for (int k=0; k<dim; k++) f << rates100FBon[PName[p]][t][k] << " ";
            f << "\n";
        } f.close();
        // t100off
        ofstream f(RES_PATH+path+string("100off")+string(PName[p]));
        for (int t = 0; t < rates100FBoff[PName[p]].size(); t++) {
            for (int k=0; k<dim; k++) f << rates100FBof[PName[p]][t][k] << " ";
            f << "\n";
        } f.close();
    }
}

int noSets = 10;
string *sets = {"MNIST_train","MNIST_test","CIFAR-10_test_gray","CIFAR-10_train_gray","SVHN_test","SVHN_train","EMNIST_test","EMNIST_train","ETH80_gray_vector","CalTec101_subset"};
int *noImages = {60000,10000,10000,50000,26032,73257,18800,112800,3280,1233};
int tileCut = 8; // sets after this are tiled; sets before this are cut

int main() {
    srand(42); // Set seed

    // Model setup
    SharedLibraryModel<float> model("./", "rateEvaluation");
    cout << "Initialise model\n";
    model.allocateMem();
    model.initialize();
    cout << "Initialise network\n";
    initialiseConnectivity(model);
    initialiseNeurons(model);
    
    for(int d=0; d < tileCut; d++) {
        cout << "Evaluating dataset " << sets[d] << endl;
        // Setup
        for (int p = 0; p < PMax-1; p++) {
            rates30FBon[PName[p]] = vector<vector<scalar>>(); 
            rates30FBoff[PName[p]] = vector<vector<scalar>>();
            rates42FBon[PName[p]] = vector<vector<scalar>>();
            rates42FBoff[PName[p]] = vector<vector<scalar>>();
            rates100FBon[PName[p]] = vector<vector<scalar>>();
            rates100FBoff[PName[p]] = vector<vector<scalar>>();
        }
        Scene scene(sets[d], noImages[d], false); // TODO: adapt
        int img = 0;
        while ((img = scene.next()) > 0) { // All images
            if (img%100 == 0) cout << "  image " << img << "/" << noImages[d] << endl; 
            auto in = scene.patch();
            // FB on
            presentPatch(model, in, 1.);
            for (int _ = 0; _ < 30; _++) m.stepTime();
            record(m, rates30FBon);
            for (int _ = 0; _ < 12; _++) m.stepTime();
            recordDelays(m, rates42FBon);
            for (int _ = 0; _ < 49; _++) m.stepTime();
            record(m, rates100FBon);
            // FB off
            presentPatch(model, in, 0.);
            for (int _ = 0; _ < 30; _++) m.stepTime();
            record(m, rates30FBoff);
            for (int _ = 0; _ < 12; _++) m.stepTime();
            recordDelays(m, rates42FBoff);
            for (int _ = 0; _ < 49; _++) m.stepTime();
            record(m, rates100FBoff);
        }
        writeResults("eval/"+sets[d])
    }
    for(int d=tileCut; d<noSets; d++) {
        Scene scene(sets[d], noImages[d], true); // TODO: adapt
        int img = 0;
        while ((img = scene.next()) > 0) {
            if (img%100 == 0) cout << "  image " << img << "/" << noImages[d] << endl;
            for (int p = 0; p < PMax-1; p++) {
                rates30FBon[PName[p]] = vector<vector<scalar>>(); 
                rates30FBoff[PName[p]] = vector<vector<scalar>>();
                rates42FBon[PName[p]] = vector<vector<scalar>>();
                rates42FBoff[PName[p]] = vector<vector<scalar>>();
                rates100FBon[PName[p]] = vector<vector<scalar>>();
                rates100FBoff[PName[p]] = vector<vector<scalar>>();
            }
            while(scene.nextTile()) {
                auto in = scene.patch();
                // FB on
                presentPatch(model, in, 1.);
                for (int _ = 0; _ < 30; _++) m.stepTime();
                record(m, rates30FBon);
                for (int _ = 0; _ < 12; _++) m.stepTime();
                recordDelays(m, rates42FBon);
                for (int _ = 0; _ < 49; _++) m.stepTime();
                record(m, rates100FBon);
                // FB off
                presentPatch(model, in, 0.);
                for (int _ = 0; _ < 30; _++) m.stepTime();
                record(m, rates30FBoff);
                for (int _ = 0; _ < 12; _++) m.stepTime();
                recordDelays(m, rates42FBoff);
                for (int _ = 0; _ < 49; _++) m.stepTime();
                record(m, rates100FBoff);
            }
            writeResults("eval/"+sets[d]+"/"+to_string(img));
        }
    }
    return 0;
}