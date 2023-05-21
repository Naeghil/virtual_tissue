#include "neuronModels.h"

class rateInput : public NeuronModels::Base {
public:
    DECLARE_MODEL(rateInput, 0, 2);
    SET_SIM_CODE("$(r) += ($(input) - $(r)) / 10.;\n"); // Exponential moving average
    SET_VARS({{"r", "scalar"}, {"input", "scalar"}});
};
IMPLEMENT_MODEL(rateInput);

class rateNeuronE : public NeuronModels::Base {
public:
    DECLARE_MODEL(rateNeuronE, 0, 5);

    SET_ADDITIONAL_INPUT_VARS({ {"excFF","scalar","0"}, {"excFB", "scalar","0"}, {"inh", "scalar","0"}});
    SET_SIM_CODE(
        "$(m) += ( $(a) * ( $(excFF) + $(FB)*$(excFB) - $(inh) - $(theta) ) - $(m) ) / 10.;\n"
        "$(r) = min(3., max(.0, $(m)));\n"  // saturation step for Exc neurons; not in spec
    );

    SET_VARS({ {"m", "scalar"}, {"r", "scalar"}, {"theta", "scalar"}, {"a", "scalar"}, {"FB", "scalar"}});
};
IMPLEMENT_MODEL(rateNeuronE);


// Inhibitory neurons are not bound
class rateNeuronI : public NeuronModels::Base {
public:
    DECLARE_MODEL(rateNeuronI, 0, 5);

    SET_ADDITIONAL_INPUT_VARS({ {"excFF","scalar","0"}, {"excFB", "scalar","0"}, {"inh", "scalar","0"} });
    SET_SIM_CODE(
        "$(m) += ( $(a) * ( $(excFF) + $(FB)*$(excFB) - $(inh) - $(theta) ) - $(m) ) / 10.;\n"
        "$(r) = max(.0, $(m));\n"
 );
    SET_VARS({ {"m", "scalar"}, {"r", "scalar"}, {"theta", "scalar"}, {"a", "scalar"}, {"FB", "scalar"} });
};
IMPLEMENT_MODEL(rateNeuronI);