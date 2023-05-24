// Tau_m*(dm/dt) = a_j*([weighted_input] - Theta_j) - m_j
// r_j = m_j+
// Tau_theta*(dTheta/dt) = (r_j - Theta_target)*delta(Theta_j)   <- delta is a drift function here delta(x) = episilon*sign(x)
// Tau_a*(da/dt) = (a_target - r^2) - delta(a-1)


// For excitatory learning: 
// Tau_alpha*(dalpha_j/dt) = alpha_j *(H_j - epsilon_alpha(1- delta*Theta_j))  is the previous theta from somewhere?
// Tau_H*(dH_j/dt) = 1/2 (r_j - gamma_r)+ * incoming_activity + 1/10 (incoming_activity - gammma_c)+ - K - H_j
// alpha_j = alpha_j+
// H_j = H_j+

#include "neuronModels.h"


class rateInput : public NeuronModels::Base {
public:
    DECLARE_MODEL(rateInput, 0, 3);
    SET_SIM_CODE(
        "$(r) += ($(input) - $(r)) / 10.;\n"
        "$(avgR) += ( $(r) - $(avgR) ) * DT / 50000.;\n"
    
    ); // Exponential moving average
    SET_VARS({{"r", "scalar"}, {"avgR", "scalar"}, {"input", "scalar"}});
};
IMPLEMENT_MODEL(rateInput);

// Parameters from Table 9 Teichmann et al., 2021
// #define TAU "10." // Time constant membrane potential
// #define TAU_AVG "50000." // Time constant alpha regulation
// #define TAU_IP "10000." // Time constant intrinsic plasticity
// #define EPSILON ".01" // Drift strength


// NOTE: DT has been removed from the euqations as the simulation is meant to be run at DT=1ms

class rateNeuronE : public NeuronModels::Base {
public:
    DECLARE_MODEL(rateNeuronE, 2, 6);

    SET_ADDITIONAL_INPUT_VARS({ {"excFF","scalar","0"}, {"excFB", "scalar","0"}, {"inh", "scalar","0"}, 
                                {"popAvg", "scalar", "0"}, {"sqPopAvg", "scalar", "0"}});  // These are always 1 step behind
    SET_SIM_CODE(
        "$(m) += ( $(a) * ( $(excFF) + $(excFB) - $(inh) - $(theta) ) - $(m) ) / 10.;\n"
        "$(r) = min(3., max(.0, $(m)));\n"  // saturation step for Exc neurons; not in spec

        "$(Ca) += ( $(r) - $(Ca) ) / $(tauCa);\n"

        //"scalar drift = ($(theta) > 0) ? .01 : -.01;\n"
        // "$(theta) +=  ( ( $(r) - $(thetaTarget ) - "EPSILON" * sign) * dt / "TAU_IP" ;\n"
        //"$(theta) +=  ( $(r) - ($(popAvg)/$(noNeurons)) - (($(theta) > 0) ? .01 : -.01) ) / 10000.;\n"  // TODO: change    
        "$(theta) +=  ( $(r) - $(avgR) - (($(theta) > 0) ? .01 : -.01) ) / 10000.;\n"  // Better result    

        //"drift = ($(a) > 1) ? .01 : -.01;\n"
        // "$(a) += ( ( $(aTarget) - $(r) * $(r) ) - "EPSILON" * sign) * dt / "TAU_IP";\n"
        //"$(a) += ( ($(sqPopAvg)/$(noNeurons)) - $(r)*$(r) - (($(a) > 1) ? .01 : -.01) ) / 10000.;\n"  // TODO: change
        "$(a) += ( $(avgR)*$(avgR) - $(r)*$(r) - (($(a) > 1) ? .01 : -.01) ) / 10000.;\n"  // Better result

        // "$(avgR) += ($(r) - $(avgR))*dt/"TAU_AVG";\n" // Exponential moving average
        "$(avgR) += ( $(r) - $(avgR) ) / 50000.;\n"
    );

    SET_PARAM_NAMES({"tauCa", "noNeurons"});
    SET_VARS({
        {"m", "scalar"}, {"r", "scalar"}, {"theta", "scalar"}, {"a", "scalar"},
        {"Ca", "scalar"} /*For E synapses*/, {"avgR", "scalar"} /* Used as THETA */
    });
};
IMPLEMENT_MODEL(rateNeuronE);


// Inhibitory neurons are not bound
class rateNeuronI : public NeuronModels::Base {
public:
    DECLARE_MODEL(rateNeuronI, 2, 6);

    SET_ADDITIONAL_INPUT_VARS({ {"excFF","scalar","0"}, {"excFB", "scalar","0"}, {"inh", "scalar","0"}, 
                                {"popAvg", "scalar", "0"}, {"sqPopAvg", "scalar", "0"}});  // These are always 1 step behind
    SET_SIM_CODE(
        "$(m) += ( $(a) * ( $(excFF) + $(excFB) - $(inh) - $(theta) ) - $(m) ) / 10.;\n"
        "$(r) = max(.0, $(m));\n"

        "$(Ca) += ( $(r) - $(Ca) ) / $(tauCa);\n"
    
        //"scalar drift = ($(theta) > 0) ? .01 : -.01;\n"
        // "$(theta) +=  ( ( $(r) - $(thetaTarget ) - "EPSILON" * sign) * dt / "TAU_IP" ;\n"
        //"$(theta) +=  ( $(r) - ($(popAvg)/$(noNeurons)) - (($(theta) > 0) ? .01 : -.01) ) / 10000.;\n"  // TODO: change    
        "$(theta) +=  ( $(r) - $(avgR) - (($(theta) > 0) ? .01 : -.01) ) / 10000.;\n"  // Better result    

        //"drift = ($(a) > 1) ? .01 : -.01;\n"
        // "$(a) += ( ( $(aTarget) - $(r) * $(r) ) - "EPSILON" * sign) * dt / "TAU_IP";\n"
        //"$(a) += ( ($(sqPopAvg)/$(noNeurons)) - $(r)*$(r) - (($(a) > 1) ? .01 : -.01) ) / 10000.;\n"  // TODO: change
        "$(a) += ( $(avgR)*$(avgR) - $(r)*$(r) - (($(a) > 1) ? .01 : -.01) ) / 10000.;\n"  // Better result

        // "$(avgR) += ($(r) - $(avgR))*dt/"TAU_AVG";\n" // Exponential moving average
        "$(avgR) += ( $(r) - $(avgR) ) / 50000.;\n"
    );

    SET_PARAM_NAMES({"tauCa", "noNeurons"});
    SET_VARS({
        {"m", "scalar"}, {"r", "scalar"}, {"theta", "scalar"}, {"a", "scalar"},
        {"Ca", "scalar"} /*For E synapses*/, {"avgR", "scalar"} /* Used as THETA */
    });
};
IMPLEMENT_MODEL(rateNeuronI);