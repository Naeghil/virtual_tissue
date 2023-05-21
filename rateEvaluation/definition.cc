// Model definintion file

#include "modelSpec.h"
#include "components/neuron.cc"
#include "components/synapse.cc"
#include "parameters.h"    

void addSyn(ModelSpec &m, Populations s, Populations t, int d, STypes type) {
    auto tLayer = Layers(t/2);
    SynapseGroup *syn;
    synapse::VarValues s_ini(.0, .0, d);
    std::string sName = std::string(PName[s])+"_"+std::string(PName[t]);
    if (s%2==0) {   // Excitatory
        if(type!=FB) syn = m.addSynapsePopulation<synapse, ffPS>(sName, SynapseMatrixType::DENSE_INDIVIDUALG, 0, PName[s], PName[t], {}, s_ini, {}, {});
        else syn = m.addSynapsePopulation<synapse, fbPS>(sName, SynapseMatrixType::DENSE_INDIVIDUALG, 0, PName[s], PName[t], {}, s_ini, {}, {});
    } else syn = m.addSynapsePopulation<synapse, inhPS>(sName, SynapseMatrixType::DENSE_INDIVIDUALG, 0, PName[s], PName[t], {}, s_ini, {}, {});
    syn->setMaxDendriticDelayTimesteps(d);
};

void modelDefinition(ModelSpec &model)
{
    model.setDT(1);
    model.setName("rateEvaluation");
    // NEURONS
    model.addNeuronPopulation<rateInput>("LGN", side[LGN]*side[LGN]*depth[LGN], {}, rateInput::VarValues(.0, .0));
    rateNeuronE::VarValues iniE(/*m*/.0, /*r*/.0, /*theta*/.0, /*a*/1., 1.);
    rateNeuronI::VarValues iniI(/*m*/.0, /*r*/.0, /*theta*/.0, /*a*/1., 1.);
    for (int p = 0; p < PMax-1; p++) {  // tauCa changes by layer
        int noNeurons = side[p]*side[p]*depth[p];
        if (p%2 == 1) model.addNeuronPopulation<rateNeuronI>(PName[p], noNeurons, {}, iniI);
        else model.addNeuronPopulation<rateNeuronE>(PName[p], noNeurons, {}, iniE);
    }
    // SYNAPSES
    // --Feedforward pathway--
    addSyn(model, LGN, V1L4E, 2, FF);
    addSyn(model, LGN, V1L4I, 1, FF);
    addSyn(model, V1L4E, V1L23E, 2, FF);
    addSyn(model, V1L4E, V1L23I, 1, FF);
    addSyn(model, V1L23E, V2L4E, 3, FF);
    addSyn(model, V1L23E, V2L4I, 2, FF);
    addSyn(model, V2L4E, V2L23E, 2, FF);
    addSyn(model,V2L4E, V2L23I, 1, FF);
    // --Lateral pathway--
    addSyn(model, V1L4E, V1L4I, 1, Lat);
    addSyn(model, V1L4I, V1L4E, 1, Lat);
    addSyn(model, V1L4I, V1L4I, 1, Lat);
    addSyn(model, V1L23E, V1L23I, 1, Lat);
    addSyn(model, V1L23I, V1L23E, 1, Lat);
    addSyn(model, V1L23I, V1L23I, 1, Lat);
    addSyn(model, V2L4E, V2L4I, 1, Lat);
    addSyn(model, V2L4I, V2L4E, 1, Lat);
    addSyn(model, V2L4I, V2L4I, 1, Lat);
    addSyn(model, V2L23E, V2L23I, 1, Lat);
    addSyn(model, V2L23I, V2L23E, 1, Lat);
    addSyn(model, V2L23I, V2L23I, 1, Lat);
    // --Feedback pathway--
    addSyn(model, V2L23E, V1L23E, 3, FB);
    addSyn(model, V2L23E, V1L23I, 2, FB);
    addSyn(model, V1L23E, V1L4I, 1, FB);
    addSyn(model, V2L23E, V2L4I, 1, FB);  
    // --Feedforward inhibition--
    addSyn(model, V1L4I, V1L23E, 1, FF);
    addSyn(model, V1L4I, V1L23I, 1, FF);
    addSyn(model, V2L4I, V2L23E, 1, FF);
    addSyn(model, V2L4I, V2L23I, 1, FF);
}
