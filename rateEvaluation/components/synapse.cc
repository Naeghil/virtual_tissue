#include "weightUpdateModels.h"
#include "postsynapticModels.h"

class synapse : public WeightUpdateModels::Base {
public:
    DECLARE_WEIGHT_UPDATE_MODEL(synapse, 0, 3, 0, 0);
    SET_VARS({{"w", "scalar"}, {"active", "bool"}, {"delay", "uint8_t"}});
    SET_SYNAPSE_DYNAMICS_CODE("if ($(active)) $(addToInSynDelay, $(w)*$(r_pre), $(delay) );\n");
};
IMPLEMENT_MODEL(synapse);

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