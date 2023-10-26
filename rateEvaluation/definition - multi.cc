// Model definintion file

#include "modelSpec.h"
#include "components/neuron.cc"
#include "components/synapse.cc"
#include "parameters.h"    

#define FEEDBACK 1  // Define as any other number to turn off feedback pathways

void addSyn(ModelSpec &m, Populations s, Populations t, int d, STypes type, int it) {
    SynapseGroup *syn;
    synapse::VarValues s_ini(.0, .0, d);
    std::string src = std::string(PName[s])+std::to_string(it);
    std::string trg = std::string(PName[t])+std::to_string(it);
    std::string sName = src+"_"+trg;
    if (s%2==0) {   // Excitatory
        if(type!=FB) syn = m.addSynapsePopulation<synapse, ffPS>(sName, SynapseMatrixType::DENSE_INDIVIDUALG, 0, src, trg, {}, s_ini, {}, {});
        else syn = m.addSynapsePopulation<synapse, fbPS>(sName, SynapseMatrixType::DENSE_INDIVIDUALG, 0, src, trg, {}, s_ini, {}, {});
    } else syn = m.addSynapsePopulation<synapse, inhPS>(sName, SynapseMatrixType::DENSE_INDIVIDUALG, 0, src, trg, {}, s_ini, {}, {});
    syn->setMaxDendriticDelayTimesteps(d);
};

void modelDefinition(ModelSpec &model)
{
    model.setDT(1);
    model.setName("rateEvaluation");
    for (int it = 0; it < 5; it++) {
        // NEURONS
        model.addNeuronPopulation<rateInput>("LGN"+std::to_string(it), side[LGN]*side[LGN]*depth[LGN], {}, rateInput::VarValues(.0, .0));
        rateNeuronE::VarValues iniE(/*m*/.0, /*r*/.0, /*theta*/.0, /*a*/1.);
        rateNeuronI::VarValues iniI(/*m*/.0, /*r*/.0, /*theta*/.0, /*a*/1.);
        for (int p = 0; p < PMax-1; p++) {  // tauCa changes by layer
            int noNeurons = side[p]*side[p]*depth[p];
            if (p%2 == 1) model.addNeuronPopulation<rateNeuronI>(std::string(PName[p])+std::to_string(it), noNeurons, {}, iniI);
            else model.addNeuronPopulation<rateNeuronE>(std::string(PName[p])+std::to_string(it), noNeurons, {}, iniE);
        }
        // SYNAPSES
        // --Feedforward pathway--
        addSyn(model, LGN, V1L4E, 2, FF, it);
        addSyn(model, LGN, V1L4I, 1, FF, it);
        addSyn(model, V1L4E, V1L23E, 2, FF, it);
        addSyn(model, V1L4E, V1L23I, 1, FF, it);
        addSyn(model, V1L23E, V2L4E, 3, FF, it);
        addSyn(model, V1L23E, V2L4I, 2, FF, it);
        addSyn(model, V2L4E, V2L23E, 2, FF, it);
        addSyn(model,V2L4E, V2L23I, 1, FF, it);
        // --Lateral pathway--
        addSyn(model, V1L4E, V1L4I, 1, Lat, it);
        addSyn(model, V1L4I, V1L4E, 1, Lat, it);
        addSyn(model, V1L4I, V1L4I, 1, Lat, it);
        addSyn(model, V1L23E, V1L23I, 1, Lat, it);
        addSyn(model, V1L23I, V1L23E, 1, Lat, it);
        addSyn(model, V1L23I, V1L23I, 1, Lat, it);
        addSyn(model, V2L4E, V2L4I, 1, Lat, it);
        addSyn(model, V2L4I, V2L4E, 1, Lat, it);
        addSyn(model, V2L4I, V2L4I, 1, Lat, it);
        addSyn(model, V2L23E, V2L23I, 1, Lat, it);
        addSyn(model, V2L23I, V2L23E, 1, Lat, it);
        addSyn(model, V2L23I, V2L23I, 1, Lat, it);
        // --Feedback pathway--
    #if FEEDBACK == 1
        addSyn(model, V2L23E, V1L23E, 3, FB, it);
        addSyn(model, V2L23E, V1L23I, 2, FB, it);
        addSyn(model, V1L23E, V1L4I, 1, FB, it);
        addSyn(model, V2L23E, V2L4I, 1, FB, it);
    #endif
        // --Feedforward inhibition--
        addSyn(model, V1L4I, V1L23E, 1, FF, it);
        addSyn(model, V1L4I, V1L23I, 1, FF, it);
        addSyn(model, V2L4I, V2L23E, 1, FF, it);
        addSyn(model, V2L4I, V2L23I, 1, FF, it);

    }

}
