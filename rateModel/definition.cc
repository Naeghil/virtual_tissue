// Model definintion file

#include "modelSpec.h"
#include "components/neuron.cc"
#include "components/synapse.cc"
#include "parameters.h"    

void addSyn(ModelSpec &m, Populations s, Populations t, int d, STypes type, double ewSeed, double alphadisc = .0, double gammac = 1.3) {
    auto tLayer = Layers(t/2);
    SynapseGroup *syn;
    double Ew = ewSeed / (RF[type][tLayer]*RF[type][tLayer]*depth[s]*expR[s]);
    if (s%2==0) {   // Excitatory
        double alphainit = 1.;
        // Unclear what alphadisc is; initialised as such in the original implementation
        if (alphadisc != .0)  alphainit = alphadisc / (sqrt(RF[type][tLayer]*RF[type][tLayer]*depth[s]) * Ew);
        if(type!=FB) {  // Feedforward and Lat
            ExcitatoryFF::VarValues s_ini(initVar<InitVarSnippet::Uniform>({0.,2*Ew}), .0, d);
            ExcitatoryFF::PostVarValues p_ini({alphainit, .0, gammac});
            syn = m.addSynapsePopulation<ExcitatoryFF, ffPS>(
                std::string(PName[s])+"_"+std::string(PName[t]), 
                SynapseMatrixType::DENSE_INDIVIDUALG, 0, PName[s], PName[t], {}, s_ini, {}, p_ini, {}, {});
        } else {        // Feedback
            ExcitatoryFB::VarValues s_ini(initVar<InitVarSnippet::Uniform>({0,2*Ew}), .0, d);
            ExcitatoryFB::PostVarValues p_ini({alphainit, .0});
            syn = m.addSynapsePopulation<ExcitatoryFB, fbPS>(
                std::string(PName[s])+"_"+std::string(PName[t]), 
                SynapseMatrixType::DENSE_INDIVIDUALG, 0, PName[s], PName[t], {}, s_ini, {}, p_ini, {}, {});
        }
    } else {        // Inhibitory
        Inhibitory::VarValues s_ini(initVar<InitVarSnippet::Uniform>({0,2*Ew}), .0, d);  
        syn = m.addSynapsePopulation<Inhibitory, inhPS>(
            std::string(PName[s])+"_"+std::string(PName[t]), 
            SynapseMatrixType::DENSE_INDIVIDUALG, 0, PName[s], PName[t], {}, s_ini, {}, {});
    } 
    syn->setMaxDendriticDelayTimesteps(d);
};

void modelDefinition(ModelSpec &model)
{
    model.setDT(1);
    model.setName("rateModel");
    // NEURONS
    // Watch out for initial averages
    model.addNeuronPopulation<rateInput>("LGN", side[LGN]*side[LGN]*depth[LGN], {}, rateInput::VarValues(.0, .09, .0));
    rateNeuronE::VarValues iniE(/*m*/.0, /*r*/.0, /*theta*/.0, /*a*/1., /*Ca*/.06, /*avgR*/.06);
    rateNeuronI::VarValues iniI(/*m*/.0, /*r*/.0, /*theta*/.0, /*a*/1., /*Ca*/.06, /*avgR*/.06);
    for (int p = 0; p < PMax-1; p++) {  // tauCa changes by layer
        int noNeurons = side[p]*side[p]*depth[p];
        double tauCa = 10.;
        if (p == V1L23E || p == V2L23E) tauCa = 500.;
        if (p%2 == 1) model.addNeuronPopulation<rateNeuronI>(PName[p], noNeurons, rateNeuronI::ParamValues(tauCa, noNeurons), iniI);
        else model.addNeuronPopulation<rateNeuronE>(PName[p], noNeurons, rateNeuronE::ParamValues(tauCa, noNeurons), iniE);
        // Fake synapses for population averages    
        model.addSynapsePopulation<dirAvg, diravgPS>(std::string(PName[p])+"avg", SynapseMatrixType::DENSE_INDIVIDUALG, 0, PName[p], PName[p], {}, {}, {}, {});
        model.addSynapsePopulation<sqrAvg, sqravgPS>(std::string(PName[p])+"sqavg", SynapseMatrixType::DENSE_INDIVIDUALG, 0, PName[p], PName[p], {}, {}, {}, {});
    }
    // SYNAPSES
    // --Feedforward pathway--
    addSyn(model, LGN, V1L4E, 2, FF, 1., 1.);
    addSyn(model, LGN, V1L4I, 1, FF, .334, 1.);
    addSyn(model, V1L4E, V1L23E, 2, FF, .5, 1.,.8);
    addSyn(model, V1L4E, V1L23I, 1, FF, .334, 1., .8);
    addSyn(model, V1L23E, V2L4E, 3, FF, 1., 1.);
    addSyn(model, V1L23E, V2L4I, 2, FF, .334, 1.);
    addSyn(model, V2L4E, V2L23E, 2, FF, 1., 1.);
    addSyn(model,V2L4E, V2L23I, 1, FF, .5, 1.);
    // --Lateral pathway--
    addSyn(model, V1L4E, V1L4I, 1, Lat, .334, 1.);
    addSyn(model, V1L4I, V1L4E, 1, Lat, 1.);
    addSyn(model, V1L4I, V1L4I, 1, Lat, 1.);
    addSyn(model, V1L23E, V1L23I, 1, Lat, .334, 1.);
    addSyn(model, V1L23I, V1L23E, 1, Lat, .5);
    addSyn(model, V1L23I, V1L23I, 1, Lat, .5);
    addSyn(model, V2L4E, V2L4I, 1, Lat, .334, 1.);
    addSyn(model, V2L4I, V2L4E, 1, Lat, 1.);
    addSyn(model, V2L4I, V2L4I, 1, Lat, 1.);
    addSyn(model, V2L23E, V2L23I, 1, Lat, .5, 1.);
    addSyn(model, V2L23I, V2L23E, 1, Lat, .5);
    addSyn(model, V2L23I, V2L23I, 1, Lat, .5);
    // --Feedback pathway--: comment this out to shut off inhibition
    addSyn(model, V2L23E, V1L23E, 3, FB, .5, .6);
    addSyn(model, V2L23E, V1L23I, 2, FB, .5, .6);
    addSyn(model, V1L23E, V1L4I, 1, FB, .334, .6);
    addSyn(model, V2L23E, V2L4I, 1, FB, .334, .6);
    // --Feedforward inhibition--
    addSyn(model, V1L4I, V1L23E, 1, FF, .5);
    addSyn(model, V1L4I, V1L23I, 1, FF, .5);
    addSyn(model, V2L4I, V2L23E, 1, FF, .5);
    addSyn(model, V2L4I, V2L23I, 1, FF, .5);
}
