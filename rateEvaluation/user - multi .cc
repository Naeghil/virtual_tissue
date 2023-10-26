#include <iostream>
#include <vector>

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

// This is the name of the condition used in the model
#define CNO 3
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

#define FEEDBACK 1  // Define as any other number to turn off feedback pathways


void initialiseModel(SharedLibraryModel<scalar> &m, string condition = CONDITION) {
    for (int it = 0; it < 5; it++) {
        ifstream pars("../RESULTS/" + condition + "/It"+to_string(it), ios::in | ios::binary);
        if (!pars.is_open()) throw runtime_error("Parameters file could not be opened.");
        for (int p = 0; p < PMax-1; p++) {
            int dim = pow(side[p],2)*depth[p];
            string name = string(PName[p])+to_string(it);
            m.pullStateFromDevice(name);
            pars.read(reinterpret_cast<char*>(m.getArray<scalar>("theta"+name)), sizeof(scalar)*dim);
            pars.read(reinterpret_cast<char*>(m.getArray<scalar>("a"+name)), sizeof(scalar)*dim);
            m.pushStateToDevice(name);
        }
        for (int i = 0; i < noSynapses; i++) {
            int src = Synapses[i][0]; int trg = Synapses[i][1];
            int dimS = pow(side[src],2)*depth[src]; int dimT = pow(side[trg],2)*depth[trg];
            int dim = dimS * dimT;
            string sName = string(PName[src])+to_string(it);
            string tName = string(PName[trg])+to_string(it);
            
            if ((FEEDBACK != 1) && (Synapses[i][2] == FB)) { // For off-feedback
                float *buf = new float[dim];
                pars.read(reinterpret_cast<char*>(buf), sizeof(scalar)*dim);
                continue;         
            }

            m.pullVarFromDevice(sName+"_"+tName, "active");
            m.pullVarFromDevice(sName+"_"+tName, "w");

            fstream mat("../rateModel/architecture/matrices/"+string(PName[src])+"-"+string(PName[trg]), ios_base::in);
            if (!mat.is_open()) throw runtime_error("  Matrix file could not be opened.");
            bool *conn = m.getArray<bool>("active"+sName+"_"+tName);
            scalar c;
            for (int s = 0; s < dimS; s++) for (int t = 0; t < dimT; t++) { 
                mat >> c; conn[s*dimT + t] = c > .5; 
            }
            pars.read(reinterpret_cast<char*>(m.getArray<scalar>("w"+sName+"_"+tName)), sizeof(scalar)*dim);

            m.pushVarToDevice(sName+"_"+tName, "active");
            m.pushVarToDevice(sName+"_"+tName, "w");
        }
    }
}

void presentPatch(SharedLibraryModel<scalar> &m, iMat patch) {
    for (int it = 0; it < 5; it++) {
        // Resecting activity 
        for (int p = 0; p < PMax; p++) {
            string name = string(PName[p])+to_string(it);
            int dim = pow(side[p],2)*depth[p];
            //m.pullVarFromDevice(name, "r");
            auto arr = m.getArray<scalar>("r"+name);
            for (int i=0; i < dim; i++) arr[i] = 0.;
            m.pushVarToDevice(name,"r");
            if (p==LGN) {
                //m.pullVarFromDevice(name, "input");
                arr = m.getArray<scalar>("input"+name);
                for (int i=0; i < dim; i++) arr[i] = 0.;
                m.pushVarToDevice(name,"input");
            } else {
                //m.pullVarFromDevice(name, "m");
                arr = m.getArray<scalar>("m"+name);
                for (int i=0; i < dim; i++) arr[i] = 0.;
                m.pushVarToDevice(name,"m");
            }
        }
        m.stepTime(); // This should reset iSyn
        // Presenting patch
        //m.pullVarFromDevice("LGN"+to_string(it), "input");
        scalar *iRates = m.getArray<scalar>("inputLGN"+to_string(it));
        for (int y = 0; y < side[LGN]; y++) for (int x = 0; x < side[LGN]; x ++) for (int z = 0; z < 2; z ++) iRates[y*2*side[LGN] + 2*x + z] = patch[y][x][z];
        m.pushVarToDevice("LGN"+to_string(it),"input");
    }
}

// Global variables because yes 
unordered_map<string, vector<vector<ofstream>>> recording;

void record(SharedLibraryModel<scalar> &m, int t) {
    for (int it=0; it < 5; it++) {
        for (int p=0; p < PMax-1; p++) {
            int dim = pow(side[p],2)*depth[p];  
            m.pullVarFromDevice(string(PName[p])+to_string(it),"r");
            recording[PName[p]][it][t].write(reinterpret_cast<char*>(m.getArray<scalar>("r"+string(PName[p])+to_string(it))), sizeof(scalar)*dim);
        }
    }
}

/* Unused
void recordDelays(SharedLibraryModel<scalar> &m, unordered_map<string, vector<vector<scalar>>> &r) {
    // Delays are known
    for (int _ = 0; _ < 2; _++) m.stepTime(); // +2
    // V1L4E
    int dim = pow(side[V1L4E],2)*depth[V1L4E];
    vector<scalar> rate(dim);
    m.pullVarFromDevice(PName[V1L4E],"r");
    scalar *arr = m.getArray<scalar>("r"+string(PName[V1L4E]));
    for (int i=0; i<dim; i++) rate[i] = arr[i];
    r[PName[V1L4E]].push_back(rate);
    // V1L4I
    dim = pow(side[V1L4I],2)*depth[V1L4I];
    rate = vector<scalar>(dim);
    m.pullVarFromDevice(PName[V1L4I],"r");
    arr = m.getArray<scalar>("r"+string(PName[V1L4I]));
    for (int i=0; i<dim; i++) rate[i] = arr[i];
    r[PName[V1L4I]].push_back(rate);

    for (int _ = 0; _ < 2; _++) m.stepTime(); // +2
    // V1L23E
    dim = pow(side[V1L23E],2)*depth[V1L23E];
    rate = vector<scalar>(dim);
    m.pullVarFromDevice(PName[V1L23E],"r");
    arr = m.getArray<scalar>("r"+string(PName[V1L23E]));
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
} //*/

string makeRecPath(string set, int it, string pName, int time, string condition = CONDITION, int imgNo = -1) {
    string path = "../RESULTS/" + condition + "/evaluation/" + set + "/";
    if (FEEDBACK==1) path+= "On";
    else path+= "Off";
    path += "It"+to_string(it)+"_"+pName;
    if (imgNo > -1) path+= "/"+ to_string(imgNo)+"_";
    path+="t"+to_string(int(10+10*time));
    return path;
}

void runTiled(string condition, string set, int noImgs) {
    for (int p = 0; p < PMax-1; p++) {
        recording[PName[p]] = vector<vector<ofstream>>(5);
        for (int it = 0; it < 5; it++) recording[PName[p]][it] = vector<ofstream>(10);
    }

    // Model setup
    SharedLibraryModel<float> model("./", "rateEvaluation");
    cout << "Initialise model\n";
    model.allocateMem();
    model.initialize();
    cout << "Initialise network parameters\n";
    initialiseModel(model, condition);
    cout << "Evaluating dataset " << set << " on " << condition << " with Feedback " << FEEDBACK << endl;
    Scene scene(set, noImgs, true);
    int img = 0;
    while ((img = scene.next()) != -1) {
        if (img%100 == 0) cout << "  image " << img << "/" << noImgs << endl;
        for (int p = 0; p < PMax-1; p++) for (int it = 0; it < 5; it++) for (int t = 0; t < 10; t++) recording[PName[p]][it][t].open(makeRecPath(set, it, PName[p], t, condition, img), ios::out | ios::binary); 
        while(scene.nextTile()) {
            presentPatch(model, scene.patch());
            for (int t = 0; t < 10; t++) {
                for (int _ = 0; _ < 10; _++) model.stepTime();
                record(model, t);
            }
        }
        for (int p = 0; p < PMax-1; p++) for (int it = 0; it < 5; it++) for (int t = 0; t < 10; t++) recording[PName[p]][it][t].close(); 
    }
}

void runUntiled(string condition, string set, int noImgs) {
    for (int p = 0; p < PMax-1; p++) {
        recording[PName[p]] = vector<vector<ofstream>>(5);
        for (int it = 0; it < 5; it++) recording[PName[p]][it] = vector<ofstream>(10);
    }
    
    // Model setup
    SharedLibraryModel<float> model("./", "rateEvaluation");
    cout << "Initialise model\n";
    model.allocateMem();
    model.initialize();
    cout << "Initialise network parameters\n";
    initialiseModel(model, condition);
    cout << "Evaluating dataset " << set << " on " << condition << " with Feedback " << FEEDBACK << endl;

    for (int p = 0; p < PMax-1; p++) for (int it = 0; it < 5; it++) for (int t = 0; t < 10; t++) recording[PName[p]][it][t].open(makeRecPath(set, it, PName[p], t, condition), ios::out | ios::binary); 
    Scene scene(set, noImgs, false);
    int img = 0;
    while ((img = scene.next()) != -1) { // All images
        if (img%1000 == 0) cout << "  image " << img << "/" << noImgs << endl; 
        presentPatch(model, scene.patch());
        for (int t = 0; t < 10; t++) {
            for (int _ = 0; _ < 10; _++) model.stepTime();
            record(model, t);
        }
    }
    for (int p = 0; p < PMax-1; p++) for (int it = 0; it < 5; it++) for (int t = 0; t < 10; t++) recording[PName[p]][it][t].close(); 
}

const int noSets = 10;
string sets[noSets] = {"MNIST_train","MNIST_test","CIFAR-10_test_gray","CIFAR-10_train_gray","SVHN_test","SVHN_train","EMNIST_test","EMNIST_train","ETH80_gray_vector","CalTec101_subset"};
int counts[noSets] = {60000,10000,10000,50000,26032,73257,18800,112800,3280,1233};
int tileCut = 8; // sets after this are tiled; sets before this are cut
#define SETNO 8

int main() {
    int sNo = 7;
    //runUntiled("popAvg", sets[sNo], counts[sNo]);
    runUntiled("ogTrace", sets[sNo], counts[sNo]);
    //runUntiled("slowTrace", sets[sNo], counts[sNo]);
    //runUntiled("midTrace", sets[sNo], counts[sNo]);
    //runUntiled("fastTrace", sets[sNo], counts[sNo]);
    sNo = 6;
    //runUntiled("popAvg", sets[sNo], counts[sNo]);
    runUntiled("ogTrace", sets[sNo], counts[sNo]);
    //runUntiled("slowTrace", sets[sNo], counts[sNo]);
    //runUntiled("midTrace", sets[sNo], counts[sNo]);
    //runUntiled("fastTrace", sets[sNo], counts[sNo]);

/*    string set = sets[SETNO];
    int noImgs = counts[SETNO];
    string condition = CONDITION;

    for (int p = 0; p < PMax-1; p++) recording[PName[p]] = vector<ofstream>(10);
    for (int it = 0; it < 5; it++) {
        // Model setup
        SharedLibraryModel<float> model("./", "rateEvaluation");
        cout << "Initialise model\n";
        model.allocateMem();
        model.initialize();
        cout << "Initialise network parameters\n";
        initialiseModel(model, it);
        cout << "Evaluating dataset " << set << " on " << condition << " iteration " << it+1 << " with Feedback " << FEEDBACK << endl;

        #if SETNO < 8
        for (int p = 0; p < PMax-1; p++) for (int t = 0; t < 10; t++) recording[PName[p]][t].open(makeRecPath(set, it, PName[p], t), ios::out | ios::binary); 
        Scene scene(set, noImgs, false);
        int img = 0;
        while ((img = scene.next()) != -1) { // All images
            if (img%1000 == 0) cout << "  image " << img << "/" << noImgs << endl; 
            presentPatch(model, scene.patch());
            for (int t = 0; t < 10; t++) {
                for (int _ = 0; _ < 10; _++) model.stepTime();
                record(model, t);
            }
        }
        for (int p = 0; p < PMax-1; p++) for (int t = 0; t < 10; t++) recording[PName[p]][t].close(); 
        #else
        Scene scene(set, noImgs, true);
        int img = 0;
        while ((img = scene.next()) != -1) {
            if (img%100 == 0) cout << "  image " << img << "/" << noImgs << endl;
            for (int p = 0; p < PMax-1; p++) for (int t = 0; t < 10; t++) recording[PName[p]][t].open(makeRecPath(set, it, PName[p], t, condition, img), ios::out | ios::binary); 
            while(scene.nextTile()) {
                presentPatch(model, scene.patch());
                for (int t = 0; t < 10; t++) {
                    for (int _ = 0; _ < 10; _++) model.stepTime();
                    record(model, t);
                }
            }
            for (int p = 0; p < PMax-1; p++) for (int t = 0; t < 10; t++) recording[PName[p]][t].close(); 
        }
        #endif

    } */
    return 0;
}