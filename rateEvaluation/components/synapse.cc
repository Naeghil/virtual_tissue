#include "weightUpdateModels.h"
#include "postsynapticModels.h"

// #define TAU_ALPHA "50000" // Time constant alpha regulation
// #define TAU_H "100" // Time constant helper function
// #define GAMMA_R ".6" // Threshold on the firing rate
// #define EPSILON_ALPHA ".015" // Constant decay
// #define KAPPA ".005" // Constant decay
// #define DELTA "10" // Scaling factor intrinsic plasticity


// Excitatory learning
// Tau_learnj*(dw_ij/dt) = (r_i - Theta)*Ca_j - alpha_j*(Ca_j)^2*w_ij
// w_ij = w_ij+
// Tau_Ca*(dCa_j/dt) = r_j - Ca_j  <- suggests different taus for different connections, might be an issue
// Tau_j = 5000+30000*e^(-15*Ca_j) 

// TauLearn only depends on Ca, so it's computed as a property of the neuron

// NOTE: DT has been removed from the euqations as the simulation is meant to be run at DT=1ms
// NOTE: the learning rule in this model uses the squared Calcium levels as per specs; teichmann's implementation uses the squared rate; compare and constrast (?)


// For feedforward and lateral excitation
class ExcitatoryFF : public WeightUpdateModels::Base {
public:
    DECLARE_WEIGHT_UPDATE_MODEL(ExcitatoryFF, 0, 3, 0, 3);
    SET_VARS({{"w", "scalar"}, {"active", "bool"}, {"delay", "uint8_t"}});
    SET_SYNAPSE_DYNAMICS_CODE(
        "if ($(active)) {\n"
        "   $(addToInSynDelay, $(w)*$(r_pre), $(delay) );\n"
        // THETA: avgR is used; alternatives: population average of pre (complex), constant (.6)
        "   if ($(tauLearn_post) != .0) $(w) += ( ($(r_pre) - $(avgR_pre)) * $(Ca_post) - $(alphaFF) * $(Ca_post) * $(Ca_post)* $(w) ) / $(tauLearn_post);\n"  // Where the fuck do I get THETA
        "   $(w) = max(0., $(w));\n"
        "};\n"
    );

    // Gamma Current can change for FF synapses as per implementation
    SET_POST_VARS({{"alphaFF", "scalar"}, {"HFF", "scalar"}, {"gammaC", "scalar"}});
    SET_POST_DYNAMICS_CODE(""
        // "$(HFF) += ( .5 * max( 0.,  $(r_post) - "GAMMA_R" ) * excFF + .1 * max(0., excFF - $(gammaC) ) - "KAPPA" - $(HFF) ) * DT / "TAU_H";\n"
        "$(HFF) += ( .5 * max( 0.,  $(r_post) - .6 ) * excFF + .1 * max(0., excFF - $(gammaC) ) - .005 - $(HFF) ) / 100.;\n"
        "$(HFF) = max( 0., min( 3., $(HFF) ) );\n"
        // +.01 unclear; used in original implementation: it could be to avoid multiplying by 0, but this can be done in the max step
        // The helper function contribution is implemented differently but mathematically equivalent
        // "$(alphaFF) += ($(alphaFF) + .01) * ( $(HFF) - "EPSILON_ALPHA" * ( 1 - "DELTA" * $(theta_post) ) ) * DT / "TAU_ALPHA";\n"
        "$(alphaFF) += ( $(alphaFF) + .01) * ( $(HFF) - .015 + .15 * $(theta_post) ) / 50000.;\n"
        "$(alphaFF) = max(0., $(alphaFF));\n"
    );
};
IMPLEMENT_MODEL(ExcitatoryFF);

// For feedback
class ExcitatoryFB : public WeightUpdateModels::Base {
public:
    DECLARE_WEIGHT_UPDATE_MODEL(ExcitatoryFB, 0, 3, 0, 2);
    SET_VARS({{"w", "scalar"}, {"active", "bool"}, {"delay", "uint8_t"}});
    SET_SYNAPSE_DYNAMICS_CODE(
        "if ($(active)) {\n"
        "   $(addToInSynDelay, $(w)*$(r_pre), $(delay));\n"
        // THETA: avgR is used; alternatives: population average of pre (complex), constant (.6)
        "   if ($(tauLearn_post) != .0) $(w) += ( ( $(r_pre) - $(avgR_pre) ) * $(Ca_post) - $(alphaFB) * $(Ca_post) * $(Ca_post)* $(w) ) / $(tauLearn_post);\n"  // Where the fuck do I get THETA
        "   $(w) = max(0., $(w));\n"
        "};\n"
    );
    SET_POST_VARS({{"alphaFB", "scalar"}, {"HFB", "scalar"}});
    SET_POST_DYNAMICS_CODE(""
        // "$(HFF) += ( .5 * max( 0.,  $(r_post) - "GAMMA_R" ) * excFB + .1 * max(0., excFB ) - "KAPPA" - $(HFF) ) * DT / "TAU_H";\n"
        "$(HFB) += ( .5 * max( 0.,  $(r_post) - .6 ) * excFB + .1 * excFB - .005 - $(HFB) ) / 100.;\n"
        "$(HFB) = max( 0., min( 3., $(HFB) ) );\n"
        // +.01 unclear; used in original implementation
        // The helper function contribution is implemented differently but mathematically equivalent
        // "$(alphaFB) += ($(alphaFB) + .01) * ( $(HFB) - "EPSILON_ALPHA" * ( 1 - "DELTA" * $(theta_post) ) ) * DT / "TAU_ALPHA";\n"
        "$(alphaFB) += ($(alphaFB) + .01) * ( $(HFB) - .015 + .15 * $(theta_post) ) / 50000.;\n"
        "$(alphaFB) = max(0., $(alphaFB));\n"
    );
};
IMPLEMENT_MODEL(ExcitatoryFB);


// Inhibitory learning
// Tau_c*(dc/dt) = r_k*r_j - r_k(<r_j> - Theta_j)+ * (1+c_kj)
// c_kj = c_kj+

class Inhibitory : public WeightUpdateModels::Base {
public:
    DECLARE_WEIGHT_UPDATE_MODEL(Inhibitory, 0, 3, 0, 0);
    SET_VARS({{"w", "scalar"}, {"active", "bool"}, {"delay", "uint8_t"}});
    SET_SYNAPSE_DYNAMICS_CODE(
        "if ($(active)) {\n"
        "   $(addToInSynDelay, $(w)*$(r_pre), $(delay));\n"
        "   if ($(tauLearn_post) != .0) $(w) += ( $(r_pre) * $(r_post) - $(r_pre) * max(0., $(avgR_post) - $(theta_post) ) * ( 1 + $(w) ) ) / 5000;\n"  // Antihebbian just has a fixed tau huh. But still
        "   $(w) = max(0., $(w));\n"
        "};\n"
    );

};
IMPLEMENT_MODEL(Inhibitory);


// Postsynaptic models define input target
class ffPS : public PostsynapticModels::Base {
    DECLARE_MODEL(ffPS, 0, 0);
    SET_APPLY_INPUT_CODE("$(excFF) += $(inSyn); $(inSyn) = 0;");
};
IMPLEMENT_MODEL(ffPS);

class fbPS : public PostsynapticModels::Base {
    DECLARE_MODEL(fbPS, 0, 0);
    SET_APPLY_INPUT_CODE("$(excFB) += $(inSyn); $(inSyn) = 0;");
};
IMPLEMENT_MODEL(fbPS);

class inhPS : public PostsynapticModels::Base {
    DECLARE_MODEL(inhPS, 0, 0);
    SET_APPLY_INPUT_CODE("$(inh) += $(inSyn); $(inSyn) = 0;");
};
IMPLEMENT_MODEL(inhPS);


// "Fake" synapses to accumulate averages
class dirAvg : public WeightUpdateModels::Base {
public:
    DECLARE_WEIGHT_UPDATE_MODEL(dirAvg, 0, 0, 0, 0);
    SET_SYNAPSE_DYNAMICS_CODE("$(addToInSyn, $(r_pre));\n");
    
};
IMPLEMENT_MODEL(dirAvg);
class diravgPS : public PostsynapticModels::Base {
    DECLARE_MODEL(diravgPS, 0, 0);
    SET_APPLY_INPUT_CODE("$(popAvg) += $(inSyn); $(inSyn) = 0;");
};
IMPLEMENT_MODEL(diravgPS);

class sqrAvg : public WeightUpdateModels::Base {
public:
    DECLARE_WEIGHT_UPDATE_MODEL(sqrAvg, 0, 0, 0, 0);
    SET_SYNAPSE_DYNAMICS_CODE("$(addToInSyn, $(r_pre)*$(r_pre));\n");
    
};
IMPLEMENT_MODEL(sqrAvg);
class sqravgPS : public PostsynapticModels::Base {
    DECLARE_MODEL(sqravgPS, 0, 0);
    SET_APPLY_INPUT_CODE("$(sqPopAvg) += $(inSyn); $(inSyn) = 0;");
};
IMPLEMENT_MODEL(sqravgPS);