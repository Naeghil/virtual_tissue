#include "definitionsInternal.h"

extern "C" {
// ------------------------------------------------------------------------
// global variables
// ------------------------------------------------------------------------
unsigned long long iT;
float t;

// ------------------------------------------------------------------------
// timers
// ------------------------------------------------------------------------
double initTime = 0.0;
double initSparseTime = 0.0;
double neuronUpdateTime = 0.0;
double presynapticUpdateTime = 0.0;
double postsynapticUpdateTime = 0.0;
double synapseDynamicsTime = 0.0;
// ------------------------------------------------------------------------
// merged group arrays
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// local neuron groups
// ------------------------------------------------------------------------
unsigned int* glbSpkCntLGN;
unsigned int* d_glbSpkCntLGN;
unsigned int* glbSpkLGN;
unsigned int* d_glbSpkLGN;
scalar* rLGN;
scalar* d_rLGN;
scalar* inputLGN;
scalar* d_inputLGN;
unsigned int* glbSpkCntV1L23E;
unsigned int* d_glbSpkCntV1L23E;
unsigned int* glbSpkV1L23E;
unsigned int* d_glbSpkV1L23E;
scalar* mV1L23E;
scalar* d_mV1L23E;
scalar* rV1L23E;
scalar* d_rV1L23E;
scalar* thetaV1L23E;
scalar* d_thetaV1L23E;
scalar* aV1L23E;
scalar* d_aV1L23E;
unsigned int* glbSpkCntV1L23I;
unsigned int* d_glbSpkCntV1L23I;
unsigned int* glbSpkV1L23I;
unsigned int* d_glbSpkV1L23I;
scalar* mV1L23I;
scalar* d_mV1L23I;
scalar* rV1L23I;
scalar* d_rV1L23I;
scalar* thetaV1L23I;
scalar* d_thetaV1L23I;
scalar* aV1L23I;
scalar* d_aV1L23I;
unsigned int* glbSpkCntV1L4E;
unsigned int* d_glbSpkCntV1L4E;
unsigned int* glbSpkV1L4E;
unsigned int* d_glbSpkV1L4E;
scalar* mV1L4E;
scalar* d_mV1L4E;
scalar* rV1L4E;
scalar* d_rV1L4E;
scalar* thetaV1L4E;
scalar* d_thetaV1L4E;
scalar* aV1L4E;
scalar* d_aV1L4E;
unsigned int* glbSpkCntV1L4I;
unsigned int* d_glbSpkCntV1L4I;
unsigned int* glbSpkV1L4I;
unsigned int* d_glbSpkV1L4I;
scalar* mV1L4I;
scalar* d_mV1L4I;
scalar* rV1L4I;
scalar* d_rV1L4I;
scalar* thetaV1L4I;
scalar* d_thetaV1L4I;
scalar* aV1L4I;
scalar* d_aV1L4I;
unsigned int* glbSpkCntV2L23E;
unsigned int* d_glbSpkCntV2L23E;
unsigned int* glbSpkV2L23E;
unsigned int* d_glbSpkV2L23E;
scalar* mV2L23E;
scalar* d_mV2L23E;
scalar* rV2L23E;
scalar* d_rV2L23E;
scalar* thetaV2L23E;
scalar* d_thetaV2L23E;
scalar* aV2L23E;
scalar* d_aV2L23E;
unsigned int* glbSpkCntV2L23I;
unsigned int* d_glbSpkCntV2L23I;
unsigned int* glbSpkV2L23I;
unsigned int* d_glbSpkV2L23I;
scalar* mV2L23I;
scalar* d_mV2L23I;
scalar* rV2L23I;
scalar* d_rV2L23I;
scalar* thetaV2L23I;
scalar* d_thetaV2L23I;
scalar* aV2L23I;
scalar* d_aV2L23I;
unsigned int* glbSpkCntV2L4E;
unsigned int* d_glbSpkCntV2L4E;
unsigned int* glbSpkV2L4E;
unsigned int* d_glbSpkV2L4E;
scalar* mV2L4E;
scalar* d_mV2L4E;
scalar* rV2L4E;
scalar* d_rV2L4E;
scalar* thetaV2L4E;
scalar* d_thetaV2L4E;
scalar* aV2L4E;
scalar* d_aV2L4E;
unsigned int* glbSpkCntV2L4I;
unsigned int* d_glbSpkCntV2L4I;
unsigned int* glbSpkV2L4I;
unsigned int* d_glbSpkV2L4I;
scalar* mV2L4I;
scalar* d_mV2L4I;
scalar* rV2L4I;
scalar* d_rV2L4I;
scalar* thetaV2L4I;
scalar* d_thetaV2L4I;
scalar* aV2L4I;
scalar* d_aV2L4I;

// ------------------------------------------------------------------------
// custom update variables
// ------------------------------------------------------------------------

// ------------------------------------------------------------------------
// pre and postsynaptic variables
// ------------------------------------------------------------------------
float* inSynV1L4I_V1L23E;
float* d_inSynV1L4I_V1L23E;
float* denDelayV1L4I_V1L23E;
float* d_denDelayV1L4I_V1L23E;
unsigned int denDelayPtrV1L4I_V1L23E = 0;
unsigned int* d_denDelayPtrV1L4I_V1L23E;
float* inSynV2L23E_V1L23E;
float* d_inSynV2L23E_V1L23E;
float* denDelayV2L23E_V1L23E;
float* d_denDelayV2L23E_V1L23E;
unsigned int denDelayPtrV2L23E_V1L23E = 0;
unsigned int* d_denDelayPtrV2L23E_V1L23E;
float* inSynV1L23I_V1L23E;
float* d_inSynV1L23I_V1L23E;
float* denDelayV1L23I_V1L23E;
float* d_denDelayV1L23I_V1L23E;
unsigned int denDelayPtrV1L23I_V1L23E = 0;
unsigned int* d_denDelayPtrV1L23I_V1L23E;
float* inSynV1L4E_V1L23E;
float* d_inSynV1L4E_V1L23E;
float* denDelayV1L4E_V1L23E;
float* d_denDelayV1L4E_V1L23E;
unsigned int denDelayPtrV1L4E_V1L23E = 0;
unsigned int* d_denDelayPtrV1L4E_V1L23E;
float* inSynV1L4I_V1L23I;
float* d_inSynV1L4I_V1L23I;
float* denDelayV1L4I_V1L23I;
float* d_denDelayV1L4I_V1L23I;
unsigned int denDelayPtrV1L4I_V1L23I = 0;
unsigned int* d_denDelayPtrV1L4I_V1L23I;
float* inSynV2L23E_V1L23I;
float* d_inSynV2L23E_V1L23I;
float* denDelayV2L23E_V1L23I;
float* d_denDelayV2L23E_V1L23I;
unsigned int denDelayPtrV2L23E_V1L23I = 0;
unsigned int* d_denDelayPtrV2L23E_V1L23I;
float* inSynV1L23I_V1L23I;
float* d_inSynV1L23I_V1L23I;
float* denDelayV1L23I_V1L23I;
float* d_denDelayV1L23I_V1L23I;
unsigned int denDelayPtrV1L23I_V1L23I = 0;
unsigned int* d_denDelayPtrV1L23I_V1L23I;
float* inSynV1L23E_V1L23I;
float* d_inSynV1L23E_V1L23I;
float* denDelayV1L23E_V1L23I;
float* d_denDelayV1L23E_V1L23I;
unsigned int denDelayPtrV1L23E_V1L23I = 0;
unsigned int* d_denDelayPtrV1L23E_V1L23I;
float* inSynV1L4E_V1L23I;
float* d_inSynV1L4E_V1L23I;
float* denDelayV1L4E_V1L23I;
float* d_denDelayV1L4E_V1L23I;
unsigned int denDelayPtrV1L4E_V1L23I = 0;
unsigned int* d_denDelayPtrV1L4E_V1L23I;
float* inSynV1L4I_V1L4E;
float* d_inSynV1L4I_V1L4E;
float* denDelayV1L4I_V1L4E;
float* d_denDelayV1L4I_V1L4E;
unsigned int denDelayPtrV1L4I_V1L4E = 0;
unsigned int* d_denDelayPtrV1L4I_V1L4E;
float* inSynLGN_V1L4E;
float* d_inSynLGN_V1L4E;
float* denDelayLGN_V1L4E;
float* d_denDelayLGN_V1L4E;
unsigned int denDelayPtrLGN_V1L4E = 0;
unsigned int* d_denDelayPtrLGN_V1L4E;
float* inSynV1L23E_V1L4I;
float* d_inSynV1L23E_V1L4I;
float* denDelayV1L23E_V1L4I;
float* d_denDelayV1L23E_V1L4I;
unsigned int denDelayPtrV1L23E_V1L4I = 0;
unsigned int* d_denDelayPtrV1L23E_V1L4I;
float* inSynV1L4I_V1L4I;
float* d_inSynV1L4I_V1L4I;
float* denDelayV1L4I_V1L4I;
float* d_denDelayV1L4I_V1L4I;
unsigned int denDelayPtrV1L4I_V1L4I = 0;
unsigned int* d_denDelayPtrV1L4I_V1L4I;
float* inSynV1L4E_V1L4I;
float* d_inSynV1L4E_V1L4I;
float* denDelayV1L4E_V1L4I;
float* d_denDelayV1L4E_V1L4I;
unsigned int denDelayPtrV1L4E_V1L4I = 0;
unsigned int* d_denDelayPtrV1L4E_V1L4I;
float* inSynLGN_V1L4I;
float* d_inSynLGN_V1L4I;
float* denDelayLGN_V1L4I;
float* d_denDelayLGN_V1L4I;
unsigned int denDelayPtrLGN_V1L4I = 0;
unsigned int* d_denDelayPtrLGN_V1L4I;
float* inSynV2L4I_V2L23E;
float* d_inSynV2L4I_V2L23E;
float* denDelayV2L4I_V2L23E;
float* d_denDelayV2L4I_V2L23E;
unsigned int denDelayPtrV2L4I_V2L23E = 0;
unsigned int* d_denDelayPtrV2L4I_V2L23E;
float* inSynV2L23I_V2L23E;
float* d_inSynV2L23I_V2L23E;
float* denDelayV2L23I_V2L23E;
float* d_denDelayV2L23I_V2L23E;
unsigned int denDelayPtrV2L23I_V2L23E = 0;
unsigned int* d_denDelayPtrV2L23I_V2L23E;
float* inSynV2L4E_V2L23E;
float* d_inSynV2L4E_V2L23E;
float* denDelayV2L4E_V2L23E;
float* d_denDelayV2L4E_V2L23E;
unsigned int denDelayPtrV2L4E_V2L23E = 0;
unsigned int* d_denDelayPtrV2L4E_V2L23E;
float* inSynV2L4I_V2L23I;
float* d_inSynV2L4I_V2L23I;
float* denDelayV2L4I_V2L23I;
float* d_denDelayV2L4I_V2L23I;
unsigned int denDelayPtrV2L4I_V2L23I = 0;
unsigned int* d_denDelayPtrV2L4I_V2L23I;
float* inSynV2L23I_V2L23I;
float* d_inSynV2L23I_V2L23I;
float* denDelayV2L23I_V2L23I;
float* d_denDelayV2L23I_V2L23I;
unsigned int denDelayPtrV2L23I_V2L23I = 0;
unsigned int* d_denDelayPtrV2L23I_V2L23I;
float* inSynV2L23E_V2L23I;
float* d_inSynV2L23E_V2L23I;
float* denDelayV2L23E_V2L23I;
float* d_denDelayV2L23E_V2L23I;
unsigned int denDelayPtrV2L23E_V2L23I = 0;
unsigned int* d_denDelayPtrV2L23E_V2L23I;
float* inSynV2L4E_V2L23I;
float* d_inSynV2L4E_V2L23I;
float* denDelayV2L4E_V2L23I;
float* d_denDelayV2L4E_V2L23I;
unsigned int denDelayPtrV2L4E_V2L23I = 0;
unsigned int* d_denDelayPtrV2L4E_V2L23I;
float* inSynV2L4I_V2L4E;
float* d_inSynV2L4I_V2L4E;
float* denDelayV2L4I_V2L4E;
float* d_denDelayV2L4I_V2L4E;
unsigned int denDelayPtrV2L4I_V2L4E = 0;
unsigned int* d_denDelayPtrV2L4I_V2L4E;
float* inSynV1L23E_V2L4E;
float* d_inSynV1L23E_V2L4E;
float* denDelayV1L23E_V2L4E;
float* d_denDelayV1L23E_V2L4E;
unsigned int denDelayPtrV1L23E_V2L4E = 0;
unsigned int* d_denDelayPtrV1L23E_V2L4E;
float* inSynV2L23E_V2L4I;
float* d_inSynV2L23E_V2L4I;
float* denDelayV2L23E_V2L4I;
float* d_denDelayV2L23E_V2L4I;
unsigned int denDelayPtrV2L23E_V2L4I = 0;
unsigned int* d_denDelayPtrV2L23E_V2L4I;
float* inSynV2L4I_V2L4I;
float* d_inSynV2L4I_V2L4I;
float* denDelayV2L4I_V2L4I;
float* d_denDelayV2L4I_V2L4I;
unsigned int denDelayPtrV2L4I_V2L4I = 0;
unsigned int* d_denDelayPtrV2L4I_V2L4I;
float* inSynV2L4E_V2L4I;
float* d_inSynV2L4E_V2L4I;
float* denDelayV2L4E_V2L4I;
float* d_denDelayV2L4E_V2L4I;
unsigned int denDelayPtrV2L4E_V2L4I = 0;
unsigned int* d_denDelayPtrV2L4E_V2L4I;
float* inSynV1L23E_V2L4I;
float* d_inSynV1L23E_V2L4I;
float* denDelayV1L23E_V2L4I;
float* d_denDelayV1L23E_V2L4I;
unsigned int denDelayPtrV1L23E_V2L4I = 0;
unsigned int* d_denDelayPtrV1L23E_V2L4I;

// ------------------------------------------------------------------------
// synapse connectivity
// ------------------------------------------------------------------------

// ------------------------------------------------------------------------
// synapse variables
// ------------------------------------------------------------------------
scalar* wLGN_V1L4E;
scalar* d_wLGN_V1L4E;
bool* activeLGN_V1L4E;
bool* d_activeLGN_V1L4E;
uint8_t* delayLGN_V1L4E;
uint8_t* d_delayLGN_V1L4E;
scalar* wLGN_V1L4I;
scalar* d_wLGN_V1L4I;
bool* activeLGN_V1L4I;
bool* d_activeLGN_V1L4I;
uint8_t* delayLGN_V1L4I;
uint8_t* d_delayLGN_V1L4I;
scalar* wV1L23E_V1L23I;
scalar* d_wV1L23E_V1L23I;
bool* activeV1L23E_V1L23I;
bool* d_activeV1L23E_V1L23I;
uint8_t* delayV1L23E_V1L23I;
uint8_t* d_delayV1L23E_V1L23I;
scalar* wV1L23E_V1L4I;
scalar* d_wV1L23E_V1L4I;
bool* activeV1L23E_V1L4I;
bool* d_activeV1L23E_V1L4I;
uint8_t* delayV1L23E_V1L4I;
uint8_t* d_delayV1L23E_V1L4I;
scalar* wV1L23E_V2L4E;
scalar* d_wV1L23E_V2L4E;
bool* activeV1L23E_V2L4E;
bool* d_activeV1L23E_V2L4E;
uint8_t* delayV1L23E_V2L4E;
uint8_t* d_delayV1L23E_V2L4E;
scalar* wV1L23E_V2L4I;
scalar* d_wV1L23E_V2L4I;
bool* activeV1L23E_V2L4I;
bool* d_activeV1L23E_V2L4I;
uint8_t* delayV1L23E_V2L4I;
uint8_t* d_delayV1L23E_V2L4I;
scalar* wV1L23I_V1L23E;
scalar* d_wV1L23I_V1L23E;
bool* activeV1L23I_V1L23E;
bool* d_activeV1L23I_V1L23E;
uint8_t* delayV1L23I_V1L23E;
uint8_t* d_delayV1L23I_V1L23E;
scalar* wV1L23I_V1L23I;
scalar* d_wV1L23I_V1L23I;
bool* activeV1L23I_V1L23I;
bool* d_activeV1L23I_V1L23I;
uint8_t* delayV1L23I_V1L23I;
uint8_t* d_delayV1L23I_V1L23I;
scalar* wV1L4E_V1L23E;
scalar* d_wV1L4E_V1L23E;
bool* activeV1L4E_V1L23E;
bool* d_activeV1L4E_V1L23E;
uint8_t* delayV1L4E_V1L23E;
uint8_t* d_delayV1L4E_V1L23E;
scalar* wV1L4E_V1L23I;
scalar* d_wV1L4E_V1L23I;
bool* activeV1L4E_V1L23I;
bool* d_activeV1L4E_V1L23I;
uint8_t* delayV1L4E_V1L23I;
uint8_t* d_delayV1L4E_V1L23I;
scalar* wV1L4E_V1L4I;
scalar* d_wV1L4E_V1L4I;
bool* activeV1L4E_V1L4I;
bool* d_activeV1L4E_V1L4I;
uint8_t* delayV1L4E_V1L4I;
uint8_t* d_delayV1L4E_V1L4I;
scalar* wV1L4I_V1L23E;
scalar* d_wV1L4I_V1L23E;
bool* activeV1L4I_V1L23E;
bool* d_activeV1L4I_V1L23E;
uint8_t* delayV1L4I_V1L23E;
uint8_t* d_delayV1L4I_V1L23E;
scalar* wV1L4I_V1L23I;
scalar* d_wV1L4I_V1L23I;
bool* activeV1L4I_V1L23I;
bool* d_activeV1L4I_V1L23I;
uint8_t* delayV1L4I_V1L23I;
uint8_t* d_delayV1L4I_V1L23I;
scalar* wV1L4I_V1L4E;
scalar* d_wV1L4I_V1L4E;
bool* activeV1L4I_V1L4E;
bool* d_activeV1L4I_V1L4E;
uint8_t* delayV1L4I_V1L4E;
uint8_t* d_delayV1L4I_V1L4E;
scalar* wV1L4I_V1L4I;
scalar* d_wV1L4I_V1L4I;
bool* activeV1L4I_V1L4I;
bool* d_activeV1L4I_V1L4I;
uint8_t* delayV1L4I_V1L4I;
uint8_t* d_delayV1L4I_V1L4I;
scalar* wV2L23E_V1L23E;
scalar* d_wV2L23E_V1L23E;
bool* activeV2L23E_V1L23E;
bool* d_activeV2L23E_V1L23E;
uint8_t* delayV2L23E_V1L23E;
uint8_t* d_delayV2L23E_V1L23E;
scalar* wV2L23E_V1L23I;
scalar* d_wV2L23E_V1L23I;
bool* activeV2L23E_V1L23I;
bool* d_activeV2L23E_V1L23I;
uint8_t* delayV2L23E_V1L23I;
uint8_t* d_delayV2L23E_V1L23I;
scalar* wV2L23E_V2L23I;
scalar* d_wV2L23E_V2L23I;
bool* activeV2L23E_V2L23I;
bool* d_activeV2L23E_V2L23I;
uint8_t* delayV2L23E_V2L23I;
uint8_t* d_delayV2L23E_V2L23I;
scalar* wV2L23E_V2L4I;
scalar* d_wV2L23E_V2L4I;
bool* activeV2L23E_V2L4I;
bool* d_activeV2L23E_V2L4I;
uint8_t* delayV2L23E_V2L4I;
uint8_t* d_delayV2L23E_V2L4I;
scalar* wV2L23I_V2L23E;
scalar* d_wV2L23I_V2L23E;
bool* activeV2L23I_V2L23E;
bool* d_activeV2L23I_V2L23E;
uint8_t* delayV2L23I_V2L23E;
uint8_t* d_delayV2L23I_V2L23E;
scalar* wV2L23I_V2L23I;
scalar* d_wV2L23I_V2L23I;
bool* activeV2L23I_V2L23I;
bool* d_activeV2L23I_V2L23I;
uint8_t* delayV2L23I_V2L23I;
uint8_t* d_delayV2L23I_V2L23I;
scalar* wV2L4E_V2L23E;
scalar* d_wV2L4E_V2L23E;
bool* activeV2L4E_V2L23E;
bool* d_activeV2L4E_V2L23E;
uint8_t* delayV2L4E_V2L23E;
uint8_t* d_delayV2L4E_V2L23E;
scalar* wV2L4E_V2L23I;
scalar* d_wV2L4E_V2L23I;
bool* activeV2L4E_V2L23I;
bool* d_activeV2L4E_V2L23I;
uint8_t* delayV2L4E_V2L23I;
uint8_t* d_delayV2L4E_V2L23I;
scalar* wV2L4E_V2L4I;
scalar* d_wV2L4E_V2L4I;
bool* activeV2L4E_V2L4I;
bool* d_activeV2L4E_V2L4I;
uint8_t* delayV2L4E_V2L4I;
uint8_t* d_delayV2L4E_V2L4I;
scalar* wV2L4I_V2L23E;
scalar* d_wV2L4I_V2L23E;
bool* activeV2L4I_V2L23E;
bool* d_activeV2L4I_V2L23E;
uint8_t* delayV2L4I_V2L23E;
uint8_t* d_delayV2L4I_V2L23E;
scalar* wV2L4I_V2L23I;
scalar* d_wV2L4I_V2L23I;
bool* activeV2L4I_V2L23I;
bool* d_activeV2L4I_V2L23I;
uint8_t* delayV2L4I_V2L23I;
uint8_t* d_delayV2L4I_V2L23I;
scalar* wV2L4I_V2L4E;
scalar* d_wV2L4I_V2L4E;
bool* activeV2L4I_V2L4E;
bool* d_activeV2L4I_V2L4E;
uint8_t* delayV2L4I_V2L4E;
uint8_t* d_delayV2L4I_V2L4E;
scalar* wV2L4I_V2L4I;
scalar* d_wV2L4I_V2L4I;
bool* activeV2L4I_V2L4I;
bool* d_activeV2L4I_V2L4I;
uint8_t* delayV2L4I_V2L4I;
uint8_t* d_delayV2L4I_V2L4I;

}  // extern "C"
// ------------------------------------------------------------------------
// extra global params
// ------------------------------------------------------------------------

// ------------------------------------------------------------------------
// copying things to device
// ------------------------------------------------------------------------
void pushLGNSpikesToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntLGN, glbSpkCntLGN, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkLGN, glbSpkLGN, 2048 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
}

void pushLGNCurrentSpikesToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntLGN, glbSpkCntLGN, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkLGN, glbSpkLGN, glbSpkCntLGN[0] * sizeof(unsigned int), cudaMemcpyHostToDevice));
}

void pushrLGNToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_rLGN, rLGN, 2048 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentrLGNToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_rLGN, rLGN, 2048 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushinputLGNToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inputLGN, inputLGN, 2048 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentinputLGNToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_inputLGN, inputLGN, 2048 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushLGNStateToDevice(bool uninitialisedOnly) {
    pushrLGNToDevice(uninitialisedOnly);
    pushinputLGNToDevice(uninitialisedOnly);
}

void pushV1L23ESpikesToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV1L23E, glbSpkCntV1L23E, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV1L23E, glbSpkV1L23E, 2023 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
}

void pushV1L23ECurrentSpikesToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV1L23E, glbSpkCntV1L23E, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV1L23E, glbSpkV1L23E, glbSpkCntV1L23E[0] * sizeof(unsigned int), cudaMemcpyHostToDevice));
}

void pushmV1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_mV1L23E, mV1L23E, 2023 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentmV1L23EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_mV1L23E, mV1L23E, 2023 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushrV1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_rV1L23E, rV1L23E, 2023 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentrV1L23EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_rV1L23E, rV1L23E, 2023 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushthetaV1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV1L23E, thetaV1L23E, 2023 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentthetaV1L23EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV1L23E, thetaV1L23E, 2023 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushaV1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_aV1L23E, aV1L23E, 2023 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentaV1L23EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_aV1L23E, aV1L23E, 2023 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushV1L23EStateToDevice(bool uninitialisedOnly) {
    pushmV1L23EToDevice(uninitialisedOnly);
    pushrV1L23EToDevice(uninitialisedOnly);
    pushthetaV1L23EToDevice(uninitialisedOnly);
    pushaV1L23EToDevice(uninitialisedOnly);
}

void pushV1L23ISpikesToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV1L23I, glbSpkCntV1L23I, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV1L23I, glbSpkV1L23I, 578 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
}

void pushV1L23ICurrentSpikesToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV1L23I, glbSpkCntV1L23I, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV1L23I, glbSpkV1L23I, glbSpkCntV1L23I[0] * sizeof(unsigned int), cudaMemcpyHostToDevice));
}

void pushmV1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_mV1L23I, mV1L23I, 578 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentmV1L23IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_mV1L23I, mV1L23I, 578 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushrV1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_rV1L23I, rV1L23I, 578 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentrV1L23IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_rV1L23I, rV1L23I, 578 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushthetaV1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV1L23I, thetaV1L23I, 578 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentthetaV1L23IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV1L23I, thetaV1L23I, 578 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushaV1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_aV1L23I, aV1L23I, 578 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentaV1L23IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_aV1L23I, aV1L23I, 578 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushV1L23IStateToDevice(bool uninitialisedOnly) {
    pushmV1L23IToDevice(uninitialisedOnly);
    pushrV1L23IToDevice(uninitialisedOnly);
    pushthetaV1L23IToDevice(uninitialisedOnly);
    pushaV1L23IToDevice(uninitialisedOnly);
}

void pushV1L4ESpikesToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV1L4E, glbSpkCntV1L4E, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV1L4E, glbSpkV1L4E, 2116 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
}

void pushV1L4ECurrentSpikesToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV1L4E, glbSpkCntV1L4E, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV1L4E, glbSpkV1L4E, glbSpkCntV1L4E[0] * sizeof(unsigned int), cudaMemcpyHostToDevice));
}

void pushmV1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_mV1L4E, mV1L4E, 2116 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentmV1L4EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_mV1L4E, mV1L4E, 2116 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushrV1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_rV1L4E, rV1L4E, 2116 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentrV1L4EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_rV1L4E, rV1L4E, 2116 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushthetaV1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV1L4E, thetaV1L4E, 2116 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentthetaV1L4EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV1L4E, thetaV1L4E, 2116 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushaV1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_aV1L4E, aV1L4E, 2116 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentaV1L4EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_aV1L4E, aV1L4E, 2116 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushV1L4EStateToDevice(bool uninitialisedOnly) {
    pushmV1L4EToDevice(uninitialisedOnly);
    pushrV1L4EToDevice(uninitialisedOnly);
    pushthetaV1L4EToDevice(uninitialisedOnly);
    pushaV1L4EToDevice(uninitialisedOnly);
}

void pushV1L4ISpikesToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV1L4I, glbSpkCntV1L4I, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV1L4I, glbSpkV1L4I, 529 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
}

void pushV1L4ICurrentSpikesToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV1L4I, glbSpkCntV1L4I, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV1L4I, glbSpkV1L4I, glbSpkCntV1L4I[0] * sizeof(unsigned int), cudaMemcpyHostToDevice));
}

void pushmV1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_mV1L4I, mV1L4I, 529 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentmV1L4IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_mV1L4I, mV1L4I, 529 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushrV1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_rV1L4I, rV1L4I, 529 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentrV1L4IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_rV1L4I, rV1L4I, 529 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushthetaV1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV1L4I, thetaV1L4I, 529 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentthetaV1L4IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV1L4I, thetaV1L4I, 529 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushaV1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_aV1L4I, aV1L4I, 529 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentaV1L4IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_aV1L4I, aV1L4I, 529 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushV1L4IStateToDevice(bool uninitialisedOnly) {
    pushmV1L4IToDevice(uninitialisedOnly);
    pushrV1L4IToDevice(uninitialisedOnly);
    pushthetaV1L4IToDevice(uninitialisedOnly);
    pushaV1L4IToDevice(uninitialisedOnly);
}

void pushV2L23ESpikesToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV2L23E, glbSpkCntV2L23E, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV2L23E, glbSpkV2L23E, 1600 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
}

void pushV2L23ECurrentSpikesToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV2L23E, glbSpkCntV2L23E, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV2L23E, glbSpkV2L23E, glbSpkCntV2L23E[0] * sizeof(unsigned int), cudaMemcpyHostToDevice));
}

void pushmV2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_mV2L23E, mV2L23E, 1600 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentmV2L23EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_mV2L23E, mV2L23E, 1600 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushrV2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_rV2L23E, rV2L23E, 1600 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentrV2L23EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_rV2L23E, rV2L23E, 1600 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushthetaV2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV2L23E, thetaV2L23E, 1600 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentthetaV2L23EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV2L23E, thetaV2L23E, 1600 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushaV2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_aV2L23E, aV2L23E, 1600 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentaV2L23EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_aV2L23E, aV2L23E, 1600 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushV2L23EStateToDevice(bool uninitialisedOnly) {
    pushmV2L23EToDevice(uninitialisedOnly);
    pushrV2L23EToDevice(uninitialisedOnly);
    pushthetaV2L23EToDevice(uninitialisedOnly);
    pushaV2L23EToDevice(uninitialisedOnly);
}

void pushV2L23ISpikesToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV2L23I, glbSpkCntV2L23I, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV2L23I, glbSpkV2L23I, 500 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
}

void pushV2L23ICurrentSpikesToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV2L23I, glbSpkCntV2L23I, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV2L23I, glbSpkV2L23I, glbSpkCntV2L23I[0] * sizeof(unsigned int), cudaMemcpyHostToDevice));
}

void pushmV2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_mV2L23I, mV2L23I, 500 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentmV2L23IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_mV2L23I, mV2L23I, 500 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushrV2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_rV2L23I, rV2L23I, 500 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentrV2L23IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_rV2L23I, rV2L23I, 500 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushthetaV2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV2L23I, thetaV2L23I, 500 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentthetaV2L23IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV2L23I, thetaV2L23I, 500 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushaV2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_aV2L23I, aV2L23I, 500 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentaV2L23IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_aV2L23I, aV2L23I, 500 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushV2L23IStateToDevice(bool uninitialisedOnly) {
    pushmV2L23IToDevice(uninitialisedOnly);
    pushrV2L23IToDevice(uninitialisedOnly);
    pushthetaV2L23IToDevice(uninitialisedOnly);
    pushaV2L23IToDevice(uninitialisedOnly);
}

void pushV2L4ESpikesToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV2L4E, glbSpkCntV2L4E, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV2L4E, glbSpkV2L4E, 1690 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
}

void pushV2L4ECurrentSpikesToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV2L4E, glbSpkCntV2L4E, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV2L4E, glbSpkV2L4E, glbSpkCntV2L4E[0] * sizeof(unsigned int), cudaMemcpyHostToDevice));
}

void pushmV2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_mV2L4E, mV2L4E, 1690 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentmV2L4EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_mV2L4E, mV2L4E, 1690 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushrV2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_rV2L4E, rV2L4E, 1690 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentrV2L4EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_rV2L4E, rV2L4E, 1690 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushthetaV2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV2L4E, thetaV2L4E, 1690 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentthetaV2L4EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV2L4E, thetaV2L4E, 1690 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushaV2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_aV2L4E, aV2L4E, 1690 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentaV2L4EToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_aV2L4E, aV2L4E, 1690 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushV2L4EStateToDevice(bool uninitialisedOnly) {
    pushmV2L4EToDevice(uninitialisedOnly);
    pushrV2L4EToDevice(uninitialisedOnly);
    pushthetaV2L4EToDevice(uninitialisedOnly);
    pushaV2L4EToDevice(uninitialisedOnly);
}

void pushV2L4ISpikesToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV2L4I, glbSpkCntV2L4I, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV2L4I, glbSpkV2L4I, 507 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    }
}

void pushV2L4ICurrentSpikesToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkCntV2L4I, glbSpkCntV2L4I, 1 * sizeof(unsigned int), cudaMemcpyHostToDevice));
    CHECK_CUDA_ERRORS(cudaMemcpy(d_glbSpkV2L4I, glbSpkV2L4I, glbSpkCntV2L4I[0] * sizeof(unsigned int), cudaMemcpyHostToDevice));
}

void pushmV2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_mV2L4I, mV2L4I, 507 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentmV2L4IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_mV2L4I, mV2L4I, 507 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushrV2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_rV2L4I, rV2L4I, 507 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentrV2L4IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_rV2L4I, rV2L4I, 507 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushthetaV2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV2L4I, thetaV2L4I, 507 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentthetaV2L4IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_thetaV2L4I, thetaV2L4I, 507 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushaV2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_aV2L4I, aV2L4I, 507 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushCurrentaV2L4IToDevice(bool uninitialisedOnly) {
    CHECK_CUDA_ERRORS(cudaMemcpy(d_aV2L4I, aV2L4I, 507 * sizeof(scalar), cudaMemcpyHostToDevice));
}

void pushV2L4IStateToDevice(bool uninitialisedOnly) {
    pushmV2L4IToDevice(uninitialisedOnly);
    pushrV2L4IToDevice(uninitialisedOnly);
    pushthetaV2L4IToDevice(uninitialisedOnly);
    pushaV2L4IToDevice(uninitialisedOnly);
}

void pushwLGN_V1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wLGN_V1L4E, wLGN_V1L4E, 4333568 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveLGN_V1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeLGN_V1L4E, activeLGN_V1L4E, 4333568 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayLGN_V1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayLGN_V1L4E, delayLGN_V1L4E, 4333568 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynLGN_V1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynLGN_V1L4E, inSynLGN_V1L4E, 2116 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushLGN_V1L4EStateToDevice(bool uninitialisedOnly) {
    pushwLGN_V1L4EToDevice(uninitialisedOnly);
    pushactiveLGN_V1L4EToDevice(uninitialisedOnly);
    pushdelayLGN_V1L4EToDevice(uninitialisedOnly);
    pushinSynLGN_V1L4EToDevice(uninitialisedOnly);
}

void pushwLGN_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wLGN_V1L4I, wLGN_V1L4I, 1083392 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveLGN_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeLGN_V1L4I, activeLGN_V1L4I, 1083392 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayLGN_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayLGN_V1L4I, delayLGN_V1L4I, 1083392 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynLGN_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynLGN_V1L4I, inSynLGN_V1L4I, 529 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushLGN_V1L4IStateToDevice(bool uninitialisedOnly) {
    pushwLGN_V1L4IToDevice(uninitialisedOnly);
    pushactiveLGN_V1L4IToDevice(uninitialisedOnly);
    pushdelayLGN_V1L4IToDevice(uninitialisedOnly);
    pushinSynLGN_V1L4IToDevice(uninitialisedOnly);
}

void pushwV1L23E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L23E_V1L23I, wV1L23E_V1L23I, 1169294 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L23E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L23E_V1L23I, activeV1L23E_V1L23I, 1169294 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L23E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L23E_V1L23I, delayV1L23E_V1L23I, 1169294 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L23E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L23E_V1L23I, inSynV1L23E_V1L23I, 578 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L23E_V1L23IStateToDevice(bool uninitialisedOnly) {
    pushwV1L23E_V1L23IToDevice(uninitialisedOnly);
    pushactiveV1L23E_V1L23IToDevice(uninitialisedOnly);
    pushdelayV1L23E_V1L23IToDevice(uninitialisedOnly);
    pushinSynV1L23E_V1L23IToDevice(uninitialisedOnly);
}

void pushwV1L23E_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L23E_V1L4I, wV1L23E_V1L4I, 1070167 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L23E_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L23E_V1L4I, activeV1L23E_V1L4I, 1070167 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L23E_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L23E_V1L4I, delayV1L23E_V1L4I, 1070167 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L23E_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L23E_V1L4I, inSynV1L23E_V1L4I, 529 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L23E_V1L4IStateToDevice(bool uninitialisedOnly) {
    pushwV1L23E_V1L4IToDevice(uninitialisedOnly);
    pushactiveV1L23E_V1L4IToDevice(uninitialisedOnly);
    pushdelayV1L23E_V1L4IToDevice(uninitialisedOnly);
    pushinSynV1L23E_V1L4IToDevice(uninitialisedOnly);
}

void pushwV1L23E_V2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L23E_V2L4E, wV1L23E_V2L4E, 3418870 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L23E_V2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L23E_V2L4E, activeV1L23E_V2L4E, 3418870 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L23E_V2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L23E_V2L4E, delayV1L23E_V2L4E, 3418870 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L23E_V2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L23E_V2L4E, inSynV1L23E_V2L4E, 1690 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L23E_V2L4EStateToDevice(bool uninitialisedOnly) {
    pushwV1L23E_V2L4EToDevice(uninitialisedOnly);
    pushactiveV1L23E_V2L4EToDevice(uninitialisedOnly);
    pushdelayV1L23E_V2L4EToDevice(uninitialisedOnly);
    pushinSynV1L23E_V2L4EToDevice(uninitialisedOnly);
}

void pushwV1L23E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L23E_V2L4I, wV1L23E_V2L4I, 1025661 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L23E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L23E_V2L4I, activeV1L23E_V2L4I, 1025661 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L23E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L23E_V2L4I, delayV1L23E_V2L4I, 1025661 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L23E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L23E_V2L4I, inSynV1L23E_V2L4I, 507 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L23E_V2L4IStateToDevice(bool uninitialisedOnly) {
    pushwV1L23E_V2L4IToDevice(uninitialisedOnly);
    pushactiveV1L23E_V2L4IToDevice(uninitialisedOnly);
    pushdelayV1L23E_V2L4IToDevice(uninitialisedOnly);
    pushinSynV1L23E_V2L4IToDevice(uninitialisedOnly);
}

void pushwV1L23I_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L23I_V1L23E, wV1L23I_V1L23E, 1169294 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L23I_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L23I_V1L23E, activeV1L23I_V1L23E, 1169294 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L23I_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L23I_V1L23E, delayV1L23I_V1L23E, 1169294 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L23I_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L23I_V1L23E, inSynV1L23I_V1L23E, 2023 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L23I_V1L23EStateToDevice(bool uninitialisedOnly) {
    pushwV1L23I_V1L23EToDevice(uninitialisedOnly);
    pushactiveV1L23I_V1L23EToDevice(uninitialisedOnly);
    pushdelayV1L23I_V1L23EToDevice(uninitialisedOnly);
    pushinSynV1L23I_V1L23EToDevice(uninitialisedOnly);
}

void pushwV1L23I_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L23I_V1L23I, wV1L23I_V1L23I, 334084 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L23I_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L23I_V1L23I, activeV1L23I_V1L23I, 334084 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L23I_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L23I_V1L23I, delayV1L23I_V1L23I, 334084 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L23I_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L23I_V1L23I, inSynV1L23I_V1L23I, 578 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L23I_V1L23IStateToDevice(bool uninitialisedOnly) {
    pushwV1L23I_V1L23IToDevice(uninitialisedOnly);
    pushactiveV1L23I_V1L23IToDevice(uninitialisedOnly);
    pushdelayV1L23I_V1L23IToDevice(uninitialisedOnly);
    pushinSynV1L23I_V1L23IToDevice(uninitialisedOnly);
}

void pushwV1L4E_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L4E_V1L23E, wV1L4E_V1L23E, 4280668 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L4E_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L4E_V1L23E, activeV1L4E_V1L23E, 4280668 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L4E_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L4E_V1L23E, delayV1L4E_V1L23E, 4280668 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L4E_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L4E_V1L23E, inSynV1L4E_V1L23E, 2023 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L4E_V1L23EStateToDevice(bool uninitialisedOnly) {
    pushwV1L4E_V1L23EToDevice(uninitialisedOnly);
    pushactiveV1L4E_V1L23EToDevice(uninitialisedOnly);
    pushdelayV1L4E_V1L23EToDevice(uninitialisedOnly);
    pushinSynV1L4E_V1L23EToDevice(uninitialisedOnly);
}

void pushwV1L4E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L4E_V1L23I, wV1L4E_V1L23I, 1223048 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L4E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L4E_V1L23I, activeV1L4E_V1L23I, 1223048 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L4E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L4E_V1L23I, delayV1L4E_V1L23I, 1223048 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L4E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L4E_V1L23I, inSynV1L4E_V1L23I, 578 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L4E_V1L23IStateToDevice(bool uninitialisedOnly) {
    pushwV1L4E_V1L23IToDevice(uninitialisedOnly);
    pushactiveV1L4E_V1L23IToDevice(uninitialisedOnly);
    pushdelayV1L4E_V1L23IToDevice(uninitialisedOnly);
    pushinSynV1L4E_V1L23IToDevice(uninitialisedOnly);
}

void pushwV1L4E_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L4E_V1L4I, wV1L4E_V1L4I, 1119364 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L4E_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L4E_V1L4I, activeV1L4E_V1L4I, 1119364 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L4E_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L4E_V1L4I, delayV1L4E_V1L4I, 1119364 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L4E_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L4E_V1L4I, inSynV1L4E_V1L4I, 529 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L4E_V1L4IStateToDevice(bool uninitialisedOnly) {
    pushwV1L4E_V1L4IToDevice(uninitialisedOnly);
    pushactiveV1L4E_V1L4IToDevice(uninitialisedOnly);
    pushdelayV1L4E_V1L4IToDevice(uninitialisedOnly);
    pushinSynV1L4E_V1L4IToDevice(uninitialisedOnly);
}

void pushwV1L4I_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L4I_V1L23E, wV1L4I_V1L23E, 1070167 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L4I_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L4I_V1L23E, activeV1L4I_V1L23E, 1070167 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L4I_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L4I_V1L23E, delayV1L4I_V1L23E, 1070167 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L4I_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L4I_V1L23E, inSynV1L4I_V1L23E, 2023 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L4I_V1L23EStateToDevice(bool uninitialisedOnly) {
    pushwV1L4I_V1L23EToDevice(uninitialisedOnly);
    pushactiveV1L4I_V1L23EToDevice(uninitialisedOnly);
    pushdelayV1L4I_V1L23EToDevice(uninitialisedOnly);
    pushinSynV1L4I_V1L23EToDevice(uninitialisedOnly);
}

void pushwV1L4I_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L4I_V1L23I, wV1L4I_V1L23I, 305762 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L4I_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L4I_V1L23I, activeV1L4I_V1L23I, 305762 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L4I_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L4I_V1L23I, delayV1L4I_V1L23I, 305762 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L4I_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L4I_V1L23I, inSynV1L4I_V1L23I, 578 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L4I_V1L23IStateToDevice(bool uninitialisedOnly) {
    pushwV1L4I_V1L23IToDevice(uninitialisedOnly);
    pushactiveV1L4I_V1L23IToDevice(uninitialisedOnly);
    pushdelayV1L4I_V1L23IToDevice(uninitialisedOnly);
    pushinSynV1L4I_V1L23IToDevice(uninitialisedOnly);
}

void pushwV1L4I_V1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L4I_V1L4E, wV1L4I_V1L4E, 1119364 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L4I_V1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L4I_V1L4E, activeV1L4I_V1L4E, 1119364 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L4I_V1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L4I_V1L4E, delayV1L4I_V1L4E, 1119364 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L4I_V1L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L4I_V1L4E, inSynV1L4I_V1L4E, 2116 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L4I_V1L4EStateToDevice(bool uninitialisedOnly) {
    pushwV1L4I_V1L4EToDevice(uninitialisedOnly);
    pushactiveV1L4I_V1L4EToDevice(uninitialisedOnly);
    pushdelayV1L4I_V1L4EToDevice(uninitialisedOnly);
    pushinSynV1L4I_V1L4EToDevice(uninitialisedOnly);
}

void pushwV1L4I_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV1L4I_V1L4I, wV1L4I_V1L4I, 279841 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV1L4I_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV1L4I_V1L4I, activeV1L4I_V1L4I, 279841 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV1L4I_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV1L4I_V1L4I, delayV1L4I_V1L4I, 279841 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV1L4I_V1L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV1L4I_V1L4I, inSynV1L4I_V1L4I, 529 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV1L4I_V1L4IStateToDevice(bool uninitialisedOnly) {
    pushwV1L4I_V1L4IToDevice(uninitialisedOnly);
    pushactiveV1L4I_V1L4IToDevice(uninitialisedOnly);
    pushdelayV1L4I_V1L4IToDevice(uninitialisedOnly);
    pushinSynV1L4I_V1L4IToDevice(uninitialisedOnly);
}

void pushwV2L23E_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L23E_V1L23E, wV2L23E_V1L23E, 3236800 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L23E_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L23E_V1L23E, activeV2L23E_V1L23E, 3236800 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L23E_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L23E_V1L23E, delayV2L23E_V1L23E, 3236800 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L23E_V1L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L23E_V1L23E, inSynV2L23E_V1L23E, 2023 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L23E_V1L23EStateToDevice(bool uninitialisedOnly) {
    pushwV2L23E_V1L23EToDevice(uninitialisedOnly);
    pushactiveV2L23E_V1L23EToDevice(uninitialisedOnly);
    pushdelayV2L23E_V1L23EToDevice(uninitialisedOnly);
    pushinSynV2L23E_V1L23EToDevice(uninitialisedOnly);
}

void pushwV2L23E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L23E_V1L23I, wV2L23E_V1L23I, 924800 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L23E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L23E_V1L23I, activeV2L23E_V1L23I, 924800 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L23E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L23E_V1L23I, delayV2L23E_V1L23I, 924800 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L23E_V1L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L23E_V1L23I, inSynV2L23E_V1L23I, 578 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L23E_V1L23IStateToDevice(bool uninitialisedOnly) {
    pushwV2L23E_V1L23IToDevice(uninitialisedOnly);
    pushactiveV2L23E_V1L23IToDevice(uninitialisedOnly);
    pushdelayV2L23E_V1L23IToDevice(uninitialisedOnly);
    pushinSynV2L23E_V1L23IToDevice(uninitialisedOnly);
}

void pushwV2L23E_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L23E_V2L23I, wV2L23E_V2L23I, 800000 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L23E_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L23E_V2L23I, activeV2L23E_V2L23I, 800000 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L23E_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L23E_V2L23I, delayV2L23E_V2L23I, 800000 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L23E_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L23E_V2L23I, inSynV2L23E_V2L23I, 500 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L23E_V2L23IStateToDevice(bool uninitialisedOnly) {
    pushwV2L23E_V2L23IToDevice(uninitialisedOnly);
    pushactiveV2L23E_V2L23IToDevice(uninitialisedOnly);
    pushdelayV2L23E_V2L23IToDevice(uninitialisedOnly);
    pushinSynV2L23E_V2L23IToDevice(uninitialisedOnly);
}

void pushwV2L23E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L23E_V2L4I, wV2L23E_V2L4I, 811200 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L23E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L23E_V2L4I, activeV2L23E_V2L4I, 811200 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L23E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L23E_V2L4I, delayV2L23E_V2L4I, 811200 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L23E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L23E_V2L4I, inSynV2L23E_V2L4I, 507 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L23E_V2L4IStateToDevice(bool uninitialisedOnly) {
    pushwV2L23E_V2L4IToDevice(uninitialisedOnly);
    pushactiveV2L23E_V2L4IToDevice(uninitialisedOnly);
    pushdelayV2L23E_V2L4IToDevice(uninitialisedOnly);
    pushinSynV2L23E_V2L4IToDevice(uninitialisedOnly);
}

void pushwV2L23I_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L23I_V2L23E, wV2L23I_V2L23E, 800000 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L23I_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L23I_V2L23E, activeV2L23I_V2L23E, 800000 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L23I_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L23I_V2L23E, delayV2L23I_V2L23E, 800000 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L23I_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L23I_V2L23E, inSynV2L23I_V2L23E, 1600 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L23I_V2L23EStateToDevice(bool uninitialisedOnly) {
    pushwV2L23I_V2L23EToDevice(uninitialisedOnly);
    pushactiveV2L23I_V2L23EToDevice(uninitialisedOnly);
    pushdelayV2L23I_V2L23EToDevice(uninitialisedOnly);
    pushinSynV2L23I_V2L23EToDevice(uninitialisedOnly);
}

void pushwV2L23I_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L23I_V2L23I, wV2L23I_V2L23I, 250000 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L23I_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L23I_V2L23I, activeV2L23I_V2L23I, 250000 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L23I_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L23I_V2L23I, delayV2L23I_V2L23I, 250000 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L23I_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L23I_V2L23I, inSynV2L23I_V2L23I, 500 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L23I_V2L23IStateToDevice(bool uninitialisedOnly) {
    pushwV2L23I_V2L23IToDevice(uninitialisedOnly);
    pushactiveV2L23I_V2L23IToDevice(uninitialisedOnly);
    pushdelayV2L23I_V2L23IToDevice(uninitialisedOnly);
    pushinSynV2L23I_V2L23IToDevice(uninitialisedOnly);
}

void pushwV2L4E_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L4E_V2L23E, wV2L4E_V2L23E, 2704000 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L4E_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L4E_V2L23E, activeV2L4E_V2L23E, 2704000 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L4E_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L4E_V2L23E, delayV2L4E_V2L23E, 2704000 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L4E_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L4E_V2L23E, inSynV2L4E_V2L23E, 1600 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L4E_V2L23EStateToDevice(bool uninitialisedOnly) {
    pushwV2L4E_V2L23EToDevice(uninitialisedOnly);
    pushactiveV2L4E_V2L23EToDevice(uninitialisedOnly);
    pushdelayV2L4E_V2L23EToDevice(uninitialisedOnly);
    pushinSynV2L4E_V2L23EToDevice(uninitialisedOnly);
}

void pushwV2L4E_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L4E_V2L23I, wV2L4E_V2L23I, 845000 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L4E_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L4E_V2L23I, activeV2L4E_V2L23I, 845000 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L4E_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L4E_V2L23I, delayV2L4E_V2L23I, 845000 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L4E_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L4E_V2L23I, inSynV2L4E_V2L23I, 500 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L4E_V2L23IStateToDevice(bool uninitialisedOnly) {
    pushwV2L4E_V2L23IToDevice(uninitialisedOnly);
    pushactiveV2L4E_V2L23IToDevice(uninitialisedOnly);
    pushdelayV2L4E_V2L23IToDevice(uninitialisedOnly);
    pushinSynV2L4E_V2L23IToDevice(uninitialisedOnly);
}

void pushwV2L4E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L4E_V2L4I, wV2L4E_V2L4I, 856830 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L4E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L4E_V2L4I, activeV2L4E_V2L4I, 856830 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L4E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L4E_V2L4I, delayV2L4E_V2L4I, 856830 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L4E_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L4E_V2L4I, inSynV2L4E_V2L4I, 507 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L4E_V2L4IStateToDevice(bool uninitialisedOnly) {
    pushwV2L4E_V2L4IToDevice(uninitialisedOnly);
    pushactiveV2L4E_V2L4IToDevice(uninitialisedOnly);
    pushdelayV2L4E_V2L4IToDevice(uninitialisedOnly);
    pushinSynV2L4E_V2L4IToDevice(uninitialisedOnly);
}

void pushwV2L4I_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L4I_V2L23E, wV2L4I_V2L23E, 811200 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L4I_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L4I_V2L23E, activeV2L4I_V2L23E, 811200 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L4I_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L4I_V2L23E, delayV2L4I_V2L23E, 811200 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L4I_V2L23EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L4I_V2L23E, inSynV2L4I_V2L23E, 1600 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L4I_V2L23EStateToDevice(bool uninitialisedOnly) {
    pushwV2L4I_V2L23EToDevice(uninitialisedOnly);
    pushactiveV2L4I_V2L23EToDevice(uninitialisedOnly);
    pushdelayV2L4I_V2L23EToDevice(uninitialisedOnly);
    pushinSynV2L4I_V2L23EToDevice(uninitialisedOnly);
}

void pushwV2L4I_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L4I_V2L23I, wV2L4I_V2L23I, 253500 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L4I_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L4I_V2L23I, activeV2L4I_V2L23I, 253500 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L4I_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L4I_V2L23I, delayV2L4I_V2L23I, 253500 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L4I_V2L23IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L4I_V2L23I, inSynV2L4I_V2L23I, 500 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L4I_V2L23IStateToDevice(bool uninitialisedOnly) {
    pushwV2L4I_V2L23IToDevice(uninitialisedOnly);
    pushactiveV2L4I_V2L23IToDevice(uninitialisedOnly);
    pushdelayV2L4I_V2L23IToDevice(uninitialisedOnly);
    pushinSynV2L4I_V2L23IToDevice(uninitialisedOnly);
}

void pushwV2L4I_V2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L4I_V2L4E, wV2L4I_V2L4E, 856830 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L4I_V2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L4I_V2L4E, activeV2L4I_V2L4E, 856830 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L4I_V2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L4I_V2L4E, delayV2L4I_V2L4E, 856830 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L4I_V2L4EToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L4I_V2L4E, inSynV2L4I_V2L4E, 1690 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L4I_V2L4EStateToDevice(bool uninitialisedOnly) {
    pushwV2L4I_V2L4EToDevice(uninitialisedOnly);
    pushactiveV2L4I_V2L4EToDevice(uninitialisedOnly);
    pushdelayV2L4I_V2L4EToDevice(uninitialisedOnly);
    pushinSynV2L4I_V2L4EToDevice(uninitialisedOnly);
}

void pushwV2L4I_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_wV2L4I_V2L4I, wV2L4I_V2L4I, 257049 * sizeof(scalar), cudaMemcpyHostToDevice));
    }
}

void pushactiveV2L4I_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_activeV2L4I_V2L4I, activeV2L4I_V2L4I, 257049 * sizeof(bool), cudaMemcpyHostToDevice));
    }
}

void pushdelayV2L4I_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_delayV2L4I_V2L4I, delayV2L4I_V2L4I, 257049 * sizeof(uint8_t), cudaMemcpyHostToDevice));
    }
}

void pushinSynV2L4I_V2L4IToDevice(bool uninitialisedOnly) {
    if(!uninitialisedOnly) {
        CHECK_CUDA_ERRORS(cudaMemcpy(d_inSynV2L4I_V2L4I, inSynV2L4I_V2L4I, 507 * sizeof(float), cudaMemcpyHostToDevice));
    }
}

void pushV2L4I_V2L4IStateToDevice(bool uninitialisedOnly) {
    pushwV2L4I_V2L4IToDevice(uninitialisedOnly);
    pushactiveV2L4I_V2L4IToDevice(uninitialisedOnly);
    pushdelayV2L4I_V2L4IToDevice(uninitialisedOnly);
    pushinSynV2L4I_V2L4IToDevice(uninitialisedOnly);
}


// ------------------------------------------------------------------------
// copying things from device
// ------------------------------------------------------------------------
void pullLGNSpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntLGN, d_glbSpkCntLGN, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkLGN, d_glbSpkLGN, 2048 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullLGNCurrentSpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntLGN, d_glbSpkCntLGN, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkLGN, d_glbSpkLGN, glbSpkCntLGN[0] * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullrLGNFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rLGN, d_rLGN, 2048 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentrLGNFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rLGN, d_rLGN, 2048 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullinputLGNFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inputLGN, d_inputLGN, 2048 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentinputLGNFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inputLGN, d_inputLGN, 2048 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullLGNStateFromDevice() {
    pullrLGNFromDevice();
    pullinputLGNFromDevice();
}

void pullV1L23ESpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV1L23E, d_glbSpkCntV1L23E, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV1L23E, d_glbSpkV1L23E, 2023 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullV1L23ECurrentSpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV1L23E, d_glbSpkCntV1L23E, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV1L23E, d_glbSpkV1L23E, glbSpkCntV1L23E[0] * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullmV1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV1L23E, d_mV1L23E, 2023 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentmV1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV1L23E, d_mV1L23E, 2023 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullrV1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV1L23E, d_rV1L23E, 2023 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentrV1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV1L23E, d_rV1L23E, 2023 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullthetaV1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV1L23E, d_thetaV1L23E, 2023 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentthetaV1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV1L23E, d_thetaV1L23E, 2023 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullaV1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV1L23E, d_aV1L23E, 2023 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentaV1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV1L23E, d_aV1L23E, 2023 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullV1L23EStateFromDevice() {
    pullmV1L23EFromDevice();
    pullrV1L23EFromDevice();
    pullthetaV1L23EFromDevice();
    pullaV1L23EFromDevice();
}

void pullV1L23ISpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV1L23I, d_glbSpkCntV1L23I, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV1L23I, d_glbSpkV1L23I, 578 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullV1L23ICurrentSpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV1L23I, d_glbSpkCntV1L23I, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV1L23I, d_glbSpkV1L23I, glbSpkCntV1L23I[0] * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullmV1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV1L23I, d_mV1L23I, 578 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentmV1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV1L23I, d_mV1L23I, 578 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullrV1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV1L23I, d_rV1L23I, 578 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentrV1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV1L23I, d_rV1L23I, 578 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullthetaV1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV1L23I, d_thetaV1L23I, 578 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentthetaV1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV1L23I, d_thetaV1L23I, 578 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullaV1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV1L23I, d_aV1L23I, 578 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentaV1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV1L23I, d_aV1L23I, 578 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullV1L23IStateFromDevice() {
    pullmV1L23IFromDevice();
    pullrV1L23IFromDevice();
    pullthetaV1L23IFromDevice();
    pullaV1L23IFromDevice();
}

void pullV1L4ESpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV1L4E, d_glbSpkCntV1L4E, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV1L4E, d_glbSpkV1L4E, 2116 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullV1L4ECurrentSpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV1L4E, d_glbSpkCntV1L4E, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV1L4E, d_glbSpkV1L4E, glbSpkCntV1L4E[0] * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullmV1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV1L4E, d_mV1L4E, 2116 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentmV1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV1L4E, d_mV1L4E, 2116 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullrV1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV1L4E, d_rV1L4E, 2116 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentrV1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV1L4E, d_rV1L4E, 2116 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullthetaV1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV1L4E, d_thetaV1L4E, 2116 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentthetaV1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV1L4E, d_thetaV1L4E, 2116 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullaV1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV1L4E, d_aV1L4E, 2116 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentaV1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV1L4E, d_aV1L4E, 2116 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullV1L4EStateFromDevice() {
    pullmV1L4EFromDevice();
    pullrV1L4EFromDevice();
    pullthetaV1L4EFromDevice();
    pullaV1L4EFromDevice();
}

void pullV1L4ISpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV1L4I, d_glbSpkCntV1L4I, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV1L4I, d_glbSpkV1L4I, 529 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullV1L4ICurrentSpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV1L4I, d_glbSpkCntV1L4I, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV1L4I, d_glbSpkV1L4I, glbSpkCntV1L4I[0] * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullmV1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV1L4I, d_mV1L4I, 529 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentmV1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV1L4I, d_mV1L4I, 529 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullrV1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV1L4I, d_rV1L4I, 529 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentrV1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV1L4I, d_rV1L4I, 529 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullthetaV1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV1L4I, d_thetaV1L4I, 529 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentthetaV1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV1L4I, d_thetaV1L4I, 529 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullaV1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV1L4I, d_aV1L4I, 529 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentaV1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV1L4I, d_aV1L4I, 529 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullV1L4IStateFromDevice() {
    pullmV1L4IFromDevice();
    pullrV1L4IFromDevice();
    pullthetaV1L4IFromDevice();
    pullaV1L4IFromDevice();
}

void pullV2L23ESpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV2L23E, d_glbSpkCntV2L23E, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV2L23E, d_glbSpkV2L23E, 1600 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullV2L23ECurrentSpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV2L23E, d_glbSpkCntV2L23E, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV2L23E, d_glbSpkV2L23E, glbSpkCntV2L23E[0] * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullmV2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV2L23E, d_mV2L23E, 1600 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentmV2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV2L23E, d_mV2L23E, 1600 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullrV2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV2L23E, d_rV2L23E, 1600 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentrV2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV2L23E, d_rV2L23E, 1600 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullthetaV2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV2L23E, d_thetaV2L23E, 1600 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentthetaV2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV2L23E, d_thetaV2L23E, 1600 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullaV2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV2L23E, d_aV2L23E, 1600 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentaV2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV2L23E, d_aV2L23E, 1600 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullV2L23EStateFromDevice() {
    pullmV2L23EFromDevice();
    pullrV2L23EFromDevice();
    pullthetaV2L23EFromDevice();
    pullaV2L23EFromDevice();
}

void pullV2L23ISpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV2L23I, d_glbSpkCntV2L23I, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV2L23I, d_glbSpkV2L23I, 500 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullV2L23ICurrentSpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV2L23I, d_glbSpkCntV2L23I, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV2L23I, d_glbSpkV2L23I, glbSpkCntV2L23I[0] * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullmV2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV2L23I, d_mV2L23I, 500 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentmV2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV2L23I, d_mV2L23I, 500 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullrV2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV2L23I, d_rV2L23I, 500 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentrV2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV2L23I, d_rV2L23I, 500 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullthetaV2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV2L23I, d_thetaV2L23I, 500 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentthetaV2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV2L23I, d_thetaV2L23I, 500 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullaV2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV2L23I, d_aV2L23I, 500 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentaV2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV2L23I, d_aV2L23I, 500 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullV2L23IStateFromDevice() {
    pullmV2L23IFromDevice();
    pullrV2L23IFromDevice();
    pullthetaV2L23IFromDevice();
    pullaV2L23IFromDevice();
}

void pullV2L4ESpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV2L4E, d_glbSpkCntV2L4E, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV2L4E, d_glbSpkV2L4E, 1690 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullV2L4ECurrentSpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV2L4E, d_glbSpkCntV2L4E, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV2L4E, d_glbSpkV2L4E, glbSpkCntV2L4E[0] * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullmV2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV2L4E, d_mV2L4E, 1690 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentmV2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV2L4E, d_mV2L4E, 1690 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullrV2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV2L4E, d_rV2L4E, 1690 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentrV2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV2L4E, d_rV2L4E, 1690 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullthetaV2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV2L4E, d_thetaV2L4E, 1690 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentthetaV2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV2L4E, d_thetaV2L4E, 1690 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullaV2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV2L4E, d_aV2L4E, 1690 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentaV2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV2L4E, d_aV2L4E, 1690 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullV2L4EStateFromDevice() {
    pullmV2L4EFromDevice();
    pullrV2L4EFromDevice();
    pullthetaV2L4EFromDevice();
    pullaV2L4EFromDevice();
}

void pullV2L4ISpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV2L4I, d_glbSpkCntV2L4I, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV2L4I, d_glbSpkV2L4I, 507 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullV2L4ICurrentSpikesFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkCntV2L4I, d_glbSpkCntV2L4I, 1 * sizeof(unsigned int), cudaMemcpyDeviceToHost));
    CHECK_CUDA_ERRORS(cudaMemcpy(glbSpkV2L4I, d_glbSpkV2L4I, glbSpkCntV2L4I[0] * sizeof(unsigned int), cudaMemcpyDeviceToHost));
}

void pullmV2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV2L4I, d_mV2L4I, 507 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentmV2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(mV2L4I, d_mV2L4I, 507 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullrV2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV2L4I, d_rV2L4I, 507 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentrV2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(rV2L4I, d_rV2L4I, 507 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullthetaV2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV2L4I, d_thetaV2L4I, 507 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentthetaV2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(thetaV2L4I, d_thetaV2L4I, 507 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullaV2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV2L4I, d_aV2L4I, 507 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullCurrentaV2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(aV2L4I, d_aV2L4I, 507 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullV2L4IStateFromDevice() {
    pullmV2L4IFromDevice();
    pullrV2L4IFromDevice();
    pullthetaV2L4IFromDevice();
    pullaV2L4IFromDevice();
}

void pullwLGN_V1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wLGN_V1L4E, d_wLGN_V1L4E, 4333568 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveLGN_V1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeLGN_V1L4E, d_activeLGN_V1L4E, 4333568 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayLGN_V1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayLGN_V1L4E, d_delayLGN_V1L4E, 4333568 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynLGN_V1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynLGN_V1L4E, d_inSynLGN_V1L4E, 2116 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullLGN_V1L4EStateFromDevice() {
    pullwLGN_V1L4EFromDevice();
    pullactiveLGN_V1L4EFromDevice();
    pulldelayLGN_V1L4EFromDevice();
    pullinSynLGN_V1L4EFromDevice();
}

void pullwLGN_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wLGN_V1L4I, d_wLGN_V1L4I, 1083392 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveLGN_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeLGN_V1L4I, d_activeLGN_V1L4I, 1083392 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayLGN_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayLGN_V1L4I, d_delayLGN_V1L4I, 1083392 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynLGN_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynLGN_V1L4I, d_inSynLGN_V1L4I, 529 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullLGN_V1L4IStateFromDevice() {
    pullwLGN_V1L4IFromDevice();
    pullactiveLGN_V1L4IFromDevice();
    pulldelayLGN_V1L4IFromDevice();
    pullinSynLGN_V1L4IFromDevice();
}

void pullwV1L23E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L23E_V1L23I, d_wV1L23E_V1L23I, 1169294 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L23E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L23E_V1L23I, d_activeV1L23E_V1L23I, 1169294 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L23E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L23E_V1L23I, d_delayV1L23E_V1L23I, 1169294 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L23E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L23E_V1L23I, d_inSynV1L23E_V1L23I, 578 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L23E_V1L23IStateFromDevice() {
    pullwV1L23E_V1L23IFromDevice();
    pullactiveV1L23E_V1L23IFromDevice();
    pulldelayV1L23E_V1L23IFromDevice();
    pullinSynV1L23E_V1L23IFromDevice();
}

void pullwV1L23E_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L23E_V1L4I, d_wV1L23E_V1L4I, 1070167 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L23E_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L23E_V1L4I, d_activeV1L23E_V1L4I, 1070167 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L23E_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L23E_V1L4I, d_delayV1L23E_V1L4I, 1070167 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L23E_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L23E_V1L4I, d_inSynV1L23E_V1L4I, 529 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L23E_V1L4IStateFromDevice() {
    pullwV1L23E_V1L4IFromDevice();
    pullactiveV1L23E_V1L4IFromDevice();
    pulldelayV1L23E_V1L4IFromDevice();
    pullinSynV1L23E_V1L4IFromDevice();
}

void pullwV1L23E_V2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L23E_V2L4E, d_wV1L23E_V2L4E, 3418870 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L23E_V2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L23E_V2L4E, d_activeV1L23E_V2L4E, 3418870 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L23E_V2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L23E_V2L4E, d_delayV1L23E_V2L4E, 3418870 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L23E_V2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L23E_V2L4E, d_inSynV1L23E_V2L4E, 1690 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L23E_V2L4EStateFromDevice() {
    pullwV1L23E_V2L4EFromDevice();
    pullactiveV1L23E_V2L4EFromDevice();
    pulldelayV1L23E_V2L4EFromDevice();
    pullinSynV1L23E_V2L4EFromDevice();
}

void pullwV1L23E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L23E_V2L4I, d_wV1L23E_V2L4I, 1025661 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L23E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L23E_V2L4I, d_activeV1L23E_V2L4I, 1025661 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L23E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L23E_V2L4I, d_delayV1L23E_V2L4I, 1025661 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L23E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L23E_V2L4I, d_inSynV1L23E_V2L4I, 507 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L23E_V2L4IStateFromDevice() {
    pullwV1L23E_V2L4IFromDevice();
    pullactiveV1L23E_V2L4IFromDevice();
    pulldelayV1L23E_V2L4IFromDevice();
    pullinSynV1L23E_V2L4IFromDevice();
}

void pullwV1L23I_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L23I_V1L23E, d_wV1L23I_V1L23E, 1169294 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L23I_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L23I_V1L23E, d_activeV1L23I_V1L23E, 1169294 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L23I_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L23I_V1L23E, d_delayV1L23I_V1L23E, 1169294 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L23I_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L23I_V1L23E, d_inSynV1L23I_V1L23E, 2023 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L23I_V1L23EStateFromDevice() {
    pullwV1L23I_V1L23EFromDevice();
    pullactiveV1L23I_V1L23EFromDevice();
    pulldelayV1L23I_V1L23EFromDevice();
    pullinSynV1L23I_V1L23EFromDevice();
}

void pullwV1L23I_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L23I_V1L23I, d_wV1L23I_V1L23I, 334084 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L23I_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L23I_V1L23I, d_activeV1L23I_V1L23I, 334084 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L23I_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L23I_V1L23I, d_delayV1L23I_V1L23I, 334084 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L23I_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L23I_V1L23I, d_inSynV1L23I_V1L23I, 578 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L23I_V1L23IStateFromDevice() {
    pullwV1L23I_V1L23IFromDevice();
    pullactiveV1L23I_V1L23IFromDevice();
    pulldelayV1L23I_V1L23IFromDevice();
    pullinSynV1L23I_V1L23IFromDevice();
}

void pullwV1L4E_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L4E_V1L23E, d_wV1L4E_V1L23E, 4280668 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L4E_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L4E_V1L23E, d_activeV1L4E_V1L23E, 4280668 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L4E_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L4E_V1L23E, d_delayV1L4E_V1L23E, 4280668 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L4E_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L4E_V1L23E, d_inSynV1L4E_V1L23E, 2023 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L4E_V1L23EStateFromDevice() {
    pullwV1L4E_V1L23EFromDevice();
    pullactiveV1L4E_V1L23EFromDevice();
    pulldelayV1L4E_V1L23EFromDevice();
    pullinSynV1L4E_V1L23EFromDevice();
}

void pullwV1L4E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L4E_V1L23I, d_wV1L4E_V1L23I, 1223048 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L4E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L4E_V1L23I, d_activeV1L4E_V1L23I, 1223048 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L4E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L4E_V1L23I, d_delayV1L4E_V1L23I, 1223048 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L4E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L4E_V1L23I, d_inSynV1L4E_V1L23I, 578 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L4E_V1L23IStateFromDevice() {
    pullwV1L4E_V1L23IFromDevice();
    pullactiveV1L4E_V1L23IFromDevice();
    pulldelayV1L4E_V1L23IFromDevice();
    pullinSynV1L4E_V1L23IFromDevice();
}

void pullwV1L4E_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L4E_V1L4I, d_wV1L4E_V1L4I, 1119364 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L4E_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L4E_V1L4I, d_activeV1L4E_V1L4I, 1119364 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L4E_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L4E_V1L4I, d_delayV1L4E_V1L4I, 1119364 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L4E_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L4E_V1L4I, d_inSynV1L4E_V1L4I, 529 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L4E_V1L4IStateFromDevice() {
    pullwV1L4E_V1L4IFromDevice();
    pullactiveV1L4E_V1L4IFromDevice();
    pulldelayV1L4E_V1L4IFromDevice();
    pullinSynV1L4E_V1L4IFromDevice();
}

void pullwV1L4I_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L4I_V1L23E, d_wV1L4I_V1L23E, 1070167 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L4I_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L4I_V1L23E, d_activeV1L4I_V1L23E, 1070167 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L4I_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L4I_V1L23E, d_delayV1L4I_V1L23E, 1070167 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L4I_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L4I_V1L23E, d_inSynV1L4I_V1L23E, 2023 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L4I_V1L23EStateFromDevice() {
    pullwV1L4I_V1L23EFromDevice();
    pullactiveV1L4I_V1L23EFromDevice();
    pulldelayV1L4I_V1L23EFromDevice();
    pullinSynV1L4I_V1L23EFromDevice();
}

void pullwV1L4I_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L4I_V1L23I, d_wV1L4I_V1L23I, 305762 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L4I_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L4I_V1L23I, d_activeV1L4I_V1L23I, 305762 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L4I_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L4I_V1L23I, d_delayV1L4I_V1L23I, 305762 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L4I_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L4I_V1L23I, d_inSynV1L4I_V1L23I, 578 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L4I_V1L23IStateFromDevice() {
    pullwV1L4I_V1L23IFromDevice();
    pullactiveV1L4I_V1L23IFromDevice();
    pulldelayV1L4I_V1L23IFromDevice();
    pullinSynV1L4I_V1L23IFromDevice();
}

void pullwV1L4I_V1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L4I_V1L4E, d_wV1L4I_V1L4E, 1119364 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L4I_V1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L4I_V1L4E, d_activeV1L4I_V1L4E, 1119364 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L4I_V1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L4I_V1L4E, d_delayV1L4I_V1L4E, 1119364 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L4I_V1L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L4I_V1L4E, d_inSynV1L4I_V1L4E, 2116 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L4I_V1L4EStateFromDevice() {
    pullwV1L4I_V1L4EFromDevice();
    pullactiveV1L4I_V1L4EFromDevice();
    pulldelayV1L4I_V1L4EFromDevice();
    pullinSynV1L4I_V1L4EFromDevice();
}

void pullwV1L4I_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV1L4I_V1L4I, d_wV1L4I_V1L4I, 279841 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV1L4I_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV1L4I_V1L4I, d_activeV1L4I_V1L4I, 279841 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV1L4I_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV1L4I_V1L4I, d_delayV1L4I_V1L4I, 279841 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV1L4I_V1L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV1L4I_V1L4I, d_inSynV1L4I_V1L4I, 529 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV1L4I_V1L4IStateFromDevice() {
    pullwV1L4I_V1L4IFromDevice();
    pullactiveV1L4I_V1L4IFromDevice();
    pulldelayV1L4I_V1L4IFromDevice();
    pullinSynV1L4I_V1L4IFromDevice();
}

void pullwV2L23E_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L23E_V1L23E, d_wV2L23E_V1L23E, 3236800 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L23E_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L23E_V1L23E, d_activeV2L23E_V1L23E, 3236800 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L23E_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L23E_V1L23E, d_delayV2L23E_V1L23E, 3236800 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L23E_V1L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L23E_V1L23E, d_inSynV2L23E_V1L23E, 2023 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L23E_V1L23EStateFromDevice() {
    pullwV2L23E_V1L23EFromDevice();
    pullactiveV2L23E_V1L23EFromDevice();
    pulldelayV2L23E_V1L23EFromDevice();
    pullinSynV2L23E_V1L23EFromDevice();
}

void pullwV2L23E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L23E_V1L23I, d_wV2L23E_V1L23I, 924800 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L23E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L23E_V1L23I, d_activeV2L23E_V1L23I, 924800 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L23E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L23E_V1L23I, d_delayV2L23E_V1L23I, 924800 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L23E_V1L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L23E_V1L23I, d_inSynV2L23E_V1L23I, 578 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L23E_V1L23IStateFromDevice() {
    pullwV2L23E_V1L23IFromDevice();
    pullactiveV2L23E_V1L23IFromDevice();
    pulldelayV2L23E_V1L23IFromDevice();
    pullinSynV2L23E_V1L23IFromDevice();
}

void pullwV2L23E_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L23E_V2L23I, d_wV2L23E_V2L23I, 800000 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L23E_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L23E_V2L23I, d_activeV2L23E_V2L23I, 800000 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L23E_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L23E_V2L23I, d_delayV2L23E_V2L23I, 800000 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L23E_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L23E_V2L23I, d_inSynV2L23E_V2L23I, 500 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L23E_V2L23IStateFromDevice() {
    pullwV2L23E_V2L23IFromDevice();
    pullactiveV2L23E_V2L23IFromDevice();
    pulldelayV2L23E_V2L23IFromDevice();
    pullinSynV2L23E_V2L23IFromDevice();
}

void pullwV2L23E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L23E_V2L4I, d_wV2L23E_V2L4I, 811200 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L23E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L23E_V2L4I, d_activeV2L23E_V2L4I, 811200 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L23E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L23E_V2L4I, d_delayV2L23E_V2L4I, 811200 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L23E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L23E_V2L4I, d_inSynV2L23E_V2L4I, 507 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L23E_V2L4IStateFromDevice() {
    pullwV2L23E_V2L4IFromDevice();
    pullactiveV2L23E_V2L4IFromDevice();
    pulldelayV2L23E_V2L4IFromDevice();
    pullinSynV2L23E_V2L4IFromDevice();
}

void pullwV2L23I_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L23I_V2L23E, d_wV2L23I_V2L23E, 800000 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L23I_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L23I_V2L23E, d_activeV2L23I_V2L23E, 800000 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L23I_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L23I_V2L23E, d_delayV2L23I_V2L23E, 800000 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L23I_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L23I_V2L23E, d_inSynV2L23I_V2L23E, 1600 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L23I_V2L23EStateFromDevice() {
    pullwV2L23I_V2L23EFromDevice();
    pullactiveV2L23I_V2L23EFromDevice();
    pulldelayV2L23I_V2L23EFromDevice();
    pullinSynV2L23I_V2L23EFromDevice();
}

void pullwV2L23I_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L23I_V2L23I, d_wV2L23I_V2L23I, 250000 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L23I_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L23I_V2L23I, d_activeV2L23I_V2L23I, 250000 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L23I_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L23I_V2L23I, d_delayV2L23I_V2L23I, 250000 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L23I_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L23I_V2L23I, d_inSynV2L23I_V2L23I, 500 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L23I_V2L23IStateFromDevice() {
    pullwV2L23I_V2L23IFromDevice();
    pullactiveV2L23I_V2L23IFromDevice();
    pulldelayV2L23I_V2L23IFromDevice();
    pullinSynV2L23I_V2L23IFromDevice();
}

void pullwV2L4E_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L4E_V2L23E, d_wV2L4E_V2L23E, 2704000 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L4E_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L4E_V2L23E, d_activeV2L4E_V2L23E, 2704000 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L4E_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L4E_V2L23E, d_delayV2L4E_V2L23E, 2704000 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L4E_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L4E_V2L23E, d_inSynV2L4E_V2L23E, 1600 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L4E_V2L23EStateFromDevice() {
    pullwV2L4E_V2L23EFromDevice();
    pullactiveV2L4E_V2L23EFromDevice();
    pulldelayV2L4E_V2L23EFromDevice();
    pullinSynV2L4E_V2L23EFromDevice();
}

void pullwV2L4E_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L4E_V2L23I, d_wV2L4E_V2L23I, 845000 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L4E_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L4E_V2L23I, d_activeV2L4E_V2L23I, 845000 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L4E_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L4E_V2L23I, d_delayV2L4E_V2L23I, 845000 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L4E_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L4E_V2L23I, d_inSynV2L4E_V2L23I, 500 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L4E_V2L23IStateFromDevice() {
    pullwV2L4E_V2L23IFromDevice();
    pullactiveV2L4E_V2L23IFromDevice();
    pulldelayV2L4E_V2L23IFromDevice();
    pullinSynV2L4E_V2L23IFromDevice();
}

void pullwV2L4E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L4E_V2L4I, d_wV2L4E_V2L4I, 856830 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L4E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L4E_V2L4I, d_activeV2L4E_V2L4I, 856830 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L4E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L4E_V2L4I, d_delayV2L4E_V2L4I, 856830 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L4E_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L4E_V2L4I, d_inSynV2L4E_V2L4I, 507 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L4E_V2L4IStateFromDevice() {
    pullwV2L4E_V2L4IFromDevice();
    pullactiveV2L4E_V2L4IFromDevice();
    pulldelayV2L4E_V2L4IFromDevice();
    pullinSynV2L4E_V2L4IFromDevice();
}

void pullwV2L4I_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L4I_V2L23E, d_wV2L4I_V2L23E, 811200 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L4I_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L4I_V2L23E, d_activeV2L4I_V2L23E, 811200 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L4I_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L4I_V2L23E, d_delayV2L4I_V2L23E, 811200 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L4I_V2L23EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L4I_V2L23E, d_inSynV2L4I_V2L23E, 1600 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L4I_V2L23EStateFromDevice() {
    pullwV2L4I_V2L23EFromDevice();
    pullactiveV2L4I_V2L23EFromDevice();
    pulldelayV2L4I_V2L23EFromDevice();
    pullinSynV2L4I_V2L23EFromDevice();
}

void pullwV2L4I_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L4I_V2L23I, d_wV2L4I_V2L23I, 253500 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L4I_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L4I_V2L23I, d_activeV2L4I_V2L23I, 253500 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L4I_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L4I_V2L23I, d_delayV2L4I_V2L23I, 253500 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L4I_V2L23IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L4I_V2L23I, d_inSynV2L4I_V2L23I, 500 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L4I_V2L23IStateFromDevice() {
    pullwV2L4I_V2L23IFromDevice();
    pullactiveV2L4I_V2L23IFromDevice();
    pulldelayV2L4I_V2L23IFromDevice();
    pullinSynV2L4I_V2L23IFromDevice();
}

void pullwV2L4I_V2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L4I_V2L4E, d_wV2L4I_V2L4E, 856830 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L4I_V2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L4I_V2L4E, d_activeV2L4I_V2L4E, 856830 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L4I_V2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L4I_V2L4E, d_delayV2L4I_V2L4E, 856830 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L4I_V2L4EFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L4I_V2L4E, d_inSynV2L4I_V2L4E, 1690 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L4I_V2L4EStateFromDevice() {
    pullwV2L4I_V2L4EFromDevice();
    pullactiveV2L4I_V2L4EFromDevice();
    pulldelayV2L4I_V2L4EFromDevice();
    pullinSynV2L4I_V2L4EFromDevice();
}

void pullwV2L4I_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(wV2L4I_V2L4I, d_wV2L4I_V2L4I, 257049 * sizeof(scalar), cudaMemcpyDeviceToHost));
}

void pullactiveV2L4I_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(activeV2L4I_V2L4I, d_activeV2L4I_V2L4I, 257049 * sizeof(bool), cudaMemcpyDeviceToHost));
}

void pulldelayV2L4I_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(delayV2L4I_V2L4I, d_delayV2L4I_V2L4I, 257049 * sizeof(uint8_t), cudaMemcpyDeviceToHost));
}

void pullinSynV2L4I_V2L4IFromDevice() {
    CHECK_CUDA_ERRORS(cudaMemcpy(inSynV2L4I_V2L4I, d_inSynV2L4I_V2L4I, 507 * sizeof(float), cudaMemcpyDeviceToHost));
}

void pullV2L4I_V2L4IStateFromDevice() {
    pullwV2L4I_V2L4IFromDevice();
    pullactiveV2L4I_V2L4IFromDevice();
    pulldelayV2L4I_V2L4IFromDevice();
    pullinSynV2L4I_V2L4IFromDevice();
}


// ------------------------------------------------------------------------
// helper getter functions
// ------------------------------------------------------------------------
unsigned int* getLGNCurrentSpikes(unsigned int batch) {
    return (glbSpkLGN);
}

unsigned int& getLGNCurrentSpikeCount(unsigned int batch) {
    return glbSpkCntLGN[0];
}

scalar* getCurrentrLGN(unsigned int batch) {
    return rLGN;
}

scalar* getCurrentinputLGN(unsigned int batch) {
    return inputLGN;
}

unsigned int* getV1L23ECurrentSpikes(unsigned int batch) {
    return (glbSpkV1L23E);
}

unsigned int& getV1L23ECurrentSpikeCount(unsigned int batch) {
    return glbSpkCntV1L23E[0];
}

scalar* getCurrentmV1L23E(unsigned int batch) {
    return mV1L23E;
}

scalar* getCurrentrV1L23E(unsigned int batch) {
    return rV1L23E;
}

scalar* getCurrentthetaV1L23E(unsigned int batch) {
    return thetaV1L23E;
}

scalar* getCurrentaV1L23E(unsigned int batch) {
    return aV1L23E;
}

unsigned int* getV1L23ICurrentSpikes(unsigned int batch) {
    return (glbSpkV1L23I);
}

unsigned int& getV1L23ICurrentSpikeCount(unsigned int batch) {
    return glbSpkCntV1L23I[0];
}

scalar* getCurrentmV1L23I(unsigned int batch) {
    return mV1L23I;
}

scalar* getCurrentrV1L23I(unsigned int batch) {
    return rV1L23I;
}

scalar* getCurrentthetaV1L23I(unsigned int batch) {
    return thetaV1L23I;
}

scalar* getCurrentaV1L23I(unsigned int batch) {
    return aV1L23I;
}

unsigned int* getV1L4ECurrentSpikes(unsigned int batch) {
    return (glbSpkV1L4E);
}

unsigned int& getV1L4ECurrentSpikeCount(unsigned int batch) {
    return glbSpkCntV1L4E[0];
}

scalar* getCurrentmV1L4E(unsigned int batch) {
    return mV1L4E;
}

scalar* getCurrentrV1L4E(unsigned int batch) {
    return rV1L4E;
}

scalar* getCurrentthetaV1L4E(unsigned int batch) {
    return thetaV1L4E;
}

scalar* getCurrentaV1L4E(unsigned int batch) {
    return aV1L4E;
}

unsigned int* getV1L4ICurrentSpikes(unsigned int batch) {
    return (glbSpkV1L4I);
}

unsigned int& getV1L4ICurrentSpikeCount(unsigned int batch) {
    return glbSpkCntV1L4I[0];
}

scalar* getCurrentmV1L4I(unsigned int batch) {
    return mV1L4I;
}

scalar* getCurrentrV1L4I(unsigned int batch) {
    return rV1L4I;
}

scalar* getCurrentthetaV1L4I(unsigned int batch) {
    return thetaV1L4I;
}

scalar* getCurrentaV1L4I(unsigned int batch) {
    return aV1L4I;
}

unsigned int* getV2L23ECurrentSpikes(unsigned int batch) {
    return (glbSpkV2L23E);
}

unsigned int& getV2L23ECurrentSpikeCount(unsigned int batch) {
    return glbSpkCntV2L23E[0];
}

scalar* getCurrentmV2L23E(unsigned int batch) {
    return mV2L23E;
}

scalar* getCurrentrV2L23E(unsigned int batch) {
    return rV2L23E;
}

scalar* getCurrentthetaV2L23E(unsigned int batch) {
    return thetaV2L23E;
}

scalar* getCurrentaV2L23E(unsigned int batch) {
    return aV2L23E;
}

unsigned int* getV2L23ICurrentSpikes(unsigned int batch) {
    return (glbSpkV2L23I);
}

unsigned int& getV2L23ICurrentSpikeCount(unsigned int batch) {
    return glbSpkCntV2L23I[0];
}

scalar* getCurrentmV2L23I(unsigned int batch) {
    return mV2L23I;
}

scalar* getCurrentrV2L23I(unsigned int batch) {
    return rV2L23I;
}

scalar* getCurrentthetaV2L23I(unsigned int batch) {
    return thetaV2L23I;
}

scalar* getCurrentaV2L23I(unsigned int batch) {
    return aV2L23I;
}

unsigned int* getV2L4ECurrentSpikes(unsigned int batch) {
    return (glbSpkV2L4E);
}

unsigned int& getV2L4ECurrentSpikeCount(unsigned int batch) {
    return glbSpkCntV2L4E[0];
}

scalar* getCurrentmV2L4E(unsigned int batch) {
    return mV2L4E;
}

scalar* getCurrentrV2L4E(unsigned int batch) {
    return rV2L4E;
}

scalar* getCurrentthetaV2L4E(unsigned int batch) {
    return thetaV2L4E;
}

scalar* getCurrentaV2L4E(unsigned int batch) {
    return aV2L4E;
}

unsigned int* getV2L4ICurrentSpikes(unsigned int batch) {
    return (glbSpkV2L4I);
}

unsigned int& getV2L4ICurrentSpikeCount(unsigned int batch) {
    return glbSpkCntV2L4I[0];
}

scalar* getCurrentmV2L4I(unsigned int batch) {
    return mV2L4I;
}

scalar* getCurrentrV2L4I(unsigned int batch) {
    return rV2L4I;
}

scalar* getCurrentthetaV2L4I(unsigned int batch) {
    return thetaV2L4I;
}

scalar* getCurrentaV2L4I(unsigned int batch) {
    return aV2L4I;
}


void copyStateToDevice(bool uninitialisedOnly) {
    pushLGNStateToDevice(uninitialisedOnly);
    pushV1L23EStateToDevice(uninitialisedOnly);
    pushV1L23IStateToDevice(uninitialisedOnly);
    pushV1L4EStateToDevice(uninitialisedOnly);
    pushV1L4IStateToDevice(uninitialisedOnly);
    pushV2L23EStateToDevice(uninitialisedOnly);
    pushV2L23IStateToDevice(uninitialisedOnly);
    pushV2L4EStateToDevice(uninitialisedOnly);
    pushV2L4IStateToDevice(uninitialisedOnly);
    pushLGN_V1L4EStateToDevice(uninitialisedOnly);
    pushLGN_V1L4IStateToDevice(uninitialisedOnly);
    pushV1L23E_V1L23IStateToDevice(uninitialisedOnly);
    pushV1L23E_V1L4IStateToDevice(uninitialisedOnly);
    pushV1L23E_V2L4EStateToDevice(uninitialisedOnly);
    pushV1L23E_V2L4IStateToDevice(uninitialisedOnly);
    pushV1L23I_V1L23EStateToDevice(uninitialisedOnly);
    pushV1L23I_V1L23IStateToDevice(uninitialisedOnly);
    pushV1L4E_V1L23EStateToDevice(uninitialisedOnly);
    pushV1L4E_V1L23IStateToDevice(uninitialisedOnly);
    pushV1L4E_V1L4IStateToDevice(uninitialisedOnly);
    pushV1L4I_V1L23EStateToDevice(uninitialisedOnly);
    pushV1L4I_V1L23IStateToDevice(uninitialisedOnly);
    pushV1L4I_V1L4EStateToDevice(uninitialisedOnly);
    pushV1L4I_V1L4IStateToDevice(uninitialisedOnly);
    pushV2L23E_V1L23EStateToDevice(uninitialisedOnly);
    pushV2L23E_V1L23IStateToDevice(uninitialisedOnly);
    pushV2L23E_V2L23IStateToDevice(uninitialisedOnly);
    pushV2L23E_V2L4IStateToDevice(uninitialisedOnly);
    pushV2L23I_V2L23EStateToDevice(uninitialisedOnly);
    pushV2L23I_V2L23IStateToDevice(uninitialisedOnly);
    pushV2L4E_V2L23EStateToDevice(uninitialisedOnly);
    pushV2L4E_V2L23IStateToDevice(uninitialisedOnly);
    pushV2L4E_V2L4IStateToDevice(uninitialisedOnly);
    pushV2L4I_V2L23EStateToDevice(uninitialisedOnly);
    pushV2L4I_V2L23IStateToDevice(uninitialisedOnly);
    pushV2L4I_V2L4EStateToDevice(uninitialisedOnly);
    pushV2L4I_V2L4IStateToDevice(uninitialisedOnly);
}

void copyConnectivityToDevice(bool uninitialisedOnly) {
}

void copyStateFromDevice() {
    pullLGNStateFromDevice();
    pullV1L23EStateFromDevice();
    pullV1L23IStateFromDevice();
    pullV1L4EStateFromDevice();
    pullV1L4IStateFromDevice();
    pullV2L23EStateFromDevice();
    pullV2L23IStateFromDevice();
    pullV2L4EStateFromDevice();
    pullV2L4IStateFromDevice();
    pullLGN_V1L4EStateFromDevice();
    pullLGN_V1L4IStateFromDevice();
    pullV1L23E_V1L23IStateFromDevice();
    pullV1L23E_V1L4IStateFromDevice();
    pullV1L23E_V2L4EStateFromDevice();
    pullV1L23E_V2L4IStateFromDevice();
    pullV1L23I_V1L23EStateFromDevice();
    pullV1L23I_V1L23IStateFromDevice();
    pullV1L4E_V1L23EStateFromDevice();
    pullV1L4E_V1L23IStateFromDevice();
    pullV1L4E_V1L4IStateFromDevice();
    pullV1L4I_V1L23EStateFromDevice();
    pullV1L4I_V1L23IStateFromDevice();
    pullV1L4I_V1L4EStateFromDevice();
    pullV1L4I_V1L4IStateFromDevice();
    pullV2L23E_V1L23EStateFromDevice();
    pullV2L23E_V1L23IStateFromDevice();
    pullV2L23E_V2L23IStateFromDevice();
    pullV2L23E_V2L4IStateFromDevice();
    pullV2L23I_V2L23EStateFromDevice();
    pullV2L23I_V2L23IStateFromDevice();
    pullV2L4E_V2L23EStateFromDevice();
    pullV2L4E_V2L23IStateFromDevice();
    pullV2L4E_V2L4IStateFromDevice();
    pullV2L4I_V2L23EStateFromDevice();
    pullV2L4I_V2L23IStateFromDevice();
    pullV2L4I_V2L4EStateFromDevice();
    pullV2L4I_V2L4IStateFromDevice();
}

void copyCurrentSpikesFromDevice() {
    pullLGNCurrentSpikesFromDevice();
    pullV1L23ECurrentSpikesFromDevice();
    pullV1L23ICurrentSpikesFromDevice();
    pullV1L4ECurrentSpikesFromDevice();
    pullV1L4ICurrentSpikesFromDevice();
    pullV2L23ECurrentSpikesFromDevice();
    pullV2L23ICurrentSpikesFromDevice();
    pullV2L4ECurrentSpikesFromDevice();
    pullV2L4ICurrentSpikesFromDevice();
}

void copyCurrentSpikeEventsFromDevice() {
}

void allocateMem() {
    int deviceID;
    CHECK_CUDA_ERRORS(cudaDeviceGetByPCIBusId(&deviceID, "0000:01:00.0"));
    CHECK_CUDA_ERRORS(cudaSetDevice(deviceID));
    
    // ------------------------------------------------------------------------
    // global variables
    // ------------------------------------------------------------------------
    
    // ------------------------------------------------------------------------
    // timers
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    // local neuron groups
    // ------------------------------------------------------------------------
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkCntLGN, 1 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkCntLGN, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkLGN, 2048 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkLGN, 2048 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&rLGN, 2048 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_rLGN, 2048 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inputLGN, 2048 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inputLGN, 2048 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkCntV1L23E, 1 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkCntV1L23E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkV1L23E, 2023 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkV1L23E, 2023 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&mV1L23E, 2023 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_mV1L23E, 2023 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&rV1L23E, 2023 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_rV1L23E, 2023 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&thetaV1L23E, 2023 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_thetaV1L23E, 2023 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&aV1L23E, 2023 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_aV1L23E, 2023 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkCntV1L23I, 1 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkCntV1L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkV1L23I, 578 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkV1L23I, 578 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&mV1L23I, 578 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_mV1L23I, 578 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&rV1L23I, 578 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_rV1L23I, 578 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&thetaV1L23I, 578 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_thetaV1L23I, 578 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&aV1L23I, 578 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_aV1L23I, 578 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkCntV1L4E, 1 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkCntV1L4E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkV1L4E, 2116 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkV1L4E, 2116 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&mV1L4E, 2116 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_mV1L4E, 2116 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&rV1L4E, 2116 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_rV1L4E, 2116 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&thetaV1L4E, 2116 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_thetaV1L4E, 2116 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&aV1L4E, 2116 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_aV1L4E, 2116 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkCntV1L4I, 1 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkCntV1L4I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkV1L4I, 529 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkV1L4I, 529 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&mV1L4I, 529 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_mV1L4I, 529 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&rV1L4I, 529 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_rV1L4I, 529 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&thetaV1L4I, 529 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_thetaV1L4I, 529 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&aV1L4I, 529 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_aV1L4I, 529 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkCntV2L23E, 1 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkCntV2L23E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkV2L23E, 1600 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkV2L23E, 1600 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&mV2L23E, 1600 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_mV2L23E, 1600 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&rV2L23E, 1600 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_rV2L23E, 1600 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&thetaV2L23E, 1600 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_thetaV2L23E, 1600 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&aV2L23E, 1600 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_aV2L23E, 1600 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkCntV2L23I, 1 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkCntV2L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkV2L23I, 500 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkV2L23I, 500 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&mV2L23I, 500 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_mV2L23I, 500 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&rV2L23I, 500 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_rV2L23I, 500 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&thetaV2L23I, 500 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_thetaV2L23I, 500 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&aV2L23I, 500 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_aV2L23I, 500 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkCntV2L4E, 1 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkCntV2L4E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkV2L4E, 1690 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkV2L4E, 1690 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&mV2L4E, 1690 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_mV2L4E, 1690 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&rV2L4E, 1690 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_rV2L4E, 1690 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&thetaV2L4E, 1690 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_thetaV2L4E, 1690 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&aV2L4E, 1690 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_aV2L4E, 1690 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkCntV2L4I, 1 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkCntV2L4I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&glbSpkV2L4I, 507 * sizeof(unsigned int), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_glbSpkV2L4I, 507 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&mV2L4I, 507 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_mV2L4I, 507 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&rV2L4I, 507 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_rV2L4I, 507 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&thetaV2L4I, 507 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_thetaV2L4I, 507 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&aV2L4I, 507 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_aV2L4I, 507 * sizeof(scalar)));
    
    // ------------------------------------------------------------------------
    // custom update variables
    // ------------------------------------------------------------------------
    
    // ------------------------------------------------------------------------
    // pre and postsynaptic variables
    // ------------------------------------------------------------------------
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L4I_V1L23E, 2023 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L4I_V1L23E, 2023 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L4I_V1L23E, 2023 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L4I_V1L23E, 2023 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L4I_V1L23E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L23E_V1L23E, 2023 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L23E_V1L23E, 2023 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L23E_V1L23E, 6069 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L23E_V1L23E, 6069 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L23E_V1L23E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L23I_V1L23E, 2023 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L23I_V1L23E, 2023 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L23I_V1L23E, 2023 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L23I_V1L23E, 2023 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L23I_V1L23E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L4E_V1L23E, 2023 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L4E_V1L23E, 2023 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L4E_V1L23E, 4046 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L4E_V1L23E, 4046 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L4E_V1L23E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L4I_V1L23I, 578 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L4I_V1L23I, 578 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L4I_V1L23I, 578 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L4I_V1L23I, 578 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L4I_V1L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L23E_V1L23I, 578 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L23E_V1L23I, 578 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L23E_V1L23I, 1156 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L23E_V1L23I, 1156 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L23E_V1L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L23I_V1L23I, 578 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L23I_V1L23I, 578 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L23I_V1L23I, 578 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L23I_V1L23I, 578 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L23I_V1L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L23E_V1L23I, 578 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L23E_V1L23I, 578 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L23E_V1L23I, 578 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L23E_V1L23I, 578 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L23E_V1L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L4E_V1L23I, 578 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L4E_V1L23I, 578 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L4E_V1L23I, 578 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L4E_V1L23I, 578 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L4E_V1L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L4I_V1L4E, 2116 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L4I_V1L4E, 2116 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L4I_V1L4E, 2116 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L4I_V1L4E, 2116 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L4I_V1L4E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynLGN_V1L4E, 2116 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynLGN_V1L4E, 2116 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayLGN_V1L4E, 4232 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayLGN_V1L4E, 4232 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrLGN_V1L4E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L23E_V1L4I, 529 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L23E_V1L4I, 529 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L23E_V1L4I, 529 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L23E_V1L4I, 529 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L23E_V1L4I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L4I_V1L4I, 529 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L4I_V1L4I, 529 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L4I_V1L4I, 529 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L4I_V1L4I, 529 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L4I_V1L4I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L4E_V1L4I, 529 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L4E_V1L4I, 529 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L4E_V1L4I, 529 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L4E_V1L4I, 529 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L4E_V1L4I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynLGN_V1L4I, 529 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynLGN_V1L4I, 529 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayLGN_V1L4I, 529 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayLGN_V1L4I, 529 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrLGN_V1L4I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L4I_V2L23E, 1600 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L4I_V2L23E, 1600 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L4I_V2L23E, 1600 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L4I_V2L23E, 1600 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L4I_V2L23E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L23I_V2L23E, 1600 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L23I_V2L23E, 1600 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L23I_V2L23E, 1600 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L23I_V2L23E, 1600 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L23I_V2L23E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L4E_V2L23E, 1600 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L4E_V2L23E, 1600 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L4E_V2L23E, 3200 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L4E_V2L23E, 3200 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L4E_V2L23E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L4I_V2L23I, 500 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L4I_V2L23I, 500 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L4I_V2L23I, 500 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L4I_V2L23I, 500 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L4I_V2L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L23I_V2L23I, 500 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L23I_V2L23I, 500 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L23I_V2L23I, 500 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L23I_V2L23I, 500 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L23I_V2L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L23E_V2L23I, 500 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L23E_V2L23I, 500 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L23E_V2L23I, 500 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L23E_V2L23I, 500 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L23E_V2L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L4E_V2L23I, 500 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L4E_V2L23I, 500 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L4E_V2L23I, 500 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L4E_V2L23I, 500 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L4E_V2L23I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L4I_V2L4E, 1690 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L4I_V2L4E, 1690 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L4I_V2L4E, 1690 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L4I_V2L4E, 1690 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L4I_V2L4E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L23E_V2L4E, 1690 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L23E_V2L4E, 1690 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L23E_V2L4E, 5070 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L23E_V2L4E, 5070 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L23E_V2L4E, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L23E_V2L4I, 507 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L23E_V2L4I, 507 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L23E_V2L4I, 507 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L23E_V2L4I, 507 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L23E_V2L4I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L4I_V2L4I, 507 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L4I_V2L4I, 507 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L4I_V2L4I, 507 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L4I_V2L4I, 507 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L4I_V2L4I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV2L4E_V2L4I, 507 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV2L4E_V2L4I, 507 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV2L4E_V2L4I, 507 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV2L4E_V2L4I, 507 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV2L4E_V2L4I, 1 * sizeof(unsigned int)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&inSynV1L23E_V2L4I, 507 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_inSynV1L23E_V2L4I, 507 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&denDelayV1L23E_V2L4I, 1014 * sizeof(float), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayV1L23E_V2L4I, 1014 * sizeof(float)));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_denDelayPtrV1L23E_V2L4I, 1 * sizeof(unsigned int)));
    
    // ------------------------------------------------------------------------
    // synapse connectivity
    // ------------------------------------------------------------------------
    
    // ------------------------------------------------------------------------
    // synapse variables
    // ------------------------------------------------------------------------
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wLGN_V1L4E, 4333568 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wLGN_V1L4E, 4333568 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeLGN_V1L4E, 4333568 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeLGN_V1L4E, 4333568 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayLGN_V1L4E, 4333568 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayLGN_V1L4E, 4333568 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wLGN_V1L4I, 1083392 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wLGN_V1L4I, 1083392 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeLGN_V1L4I, 1083392 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeLGN_V1L4I, 1083392 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayLGN_V1L4I, 1083392 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayLGN_V1L4I, 1083392 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L23E_V1L23I, 1169294 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L23E_V1L23I, 1169294 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L23E_V1L23I, 1169294 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L23E_V1L23I, 1169294 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L23E_V1L23I, 1169294 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L23E_V1L23I, 1169294 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L23E_V1L4I, 1070167 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L23E_V1L4I, 1070167 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L23E_V1L4I, 1070167 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L23E_V1L4I, 1070167 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L23E_V1L4I, 1070167 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L23E_V1L4I, 1070167 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L23E_V2L4E, 3418870 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L23E_V2L4E, 3418870 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L23E_V2L4E, 3418870 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L23E_V2L4E, 3418870 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L23E_V2L4E, 3418870 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L23E_V2L4E, 3418870 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L23E_V2L4I, 1025661 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L23E_V2L4I, 1025661 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L23E_V2L4I, 1025661 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L23E_V2L4I, 1025661 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L23E_V2L4I, 1025661 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L23E_V2L4I, 1025661 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L23I_V1L23E, 1169294 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L23I_V1L23E, 1169294 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L23I_V1L23E, 1169294 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L23I_V1L23E, 1169294 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L23I_V1L23E, 1169294 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L23I_V1L23E, 1169294 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L23I_V1L23I, 334084 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L23I_V1L23I, 334084 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L23I_V1L23I, 334084 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L23I_V1L23I, 334084 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L23I_V1L23I, 334084 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L23I_V1L23I, 334084 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L4E_V1L23E, 4280668 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L4E_V1L23E, 4280668 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L4E_V1L23E, 4280668 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L4E_V1L23E, 4280668 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L4E_V1L23E, 4280668 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L4E_V1L23E, 4280668 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L4E_V1L23I, 1223048 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L4E_V1L23I, 1223048 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L4E_V1L23I, 1223048 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L4E_V1L23I, 1223048 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L4E_V1L23I, 1223048 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L4E_V1L23I, 1223048 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L4E_V1L4I, 1119364 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L4E_V1L4I, 1119364 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L4E_V1L4I, 1119364 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L4E_V1L4I, 1119364 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L4E_V1L4I, 1119364 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L4E_V1L4I, 1119364 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L4I_V1L23E, 1070167 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L4I_V1L23E, 1070167 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L4I_V1L23E, 1070167 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L4I_V1L23E, 1070167 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L4I_V1L23E, 1070167 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L4I_V1L23E, 1070167 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L4I_V1L23I, 305762 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L4I_V1L23I, 305762 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L4I_V1L23I, 305762 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L4I_V1L23I, 305762 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L4I_V1L23I, 305762 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L4I_V1L23I, 305762 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L4I_V1L4E, 1119364 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L4I_V1L4E, 1119364 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L4I_V1L4E, 1119364 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L4I_V1L4E, 1119364 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L4I_V1L4E, 1119364 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L4I_V1L4E, 1119364 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV1L4I_V1L4I, 279841 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV1L4I_V1L4I, 279841 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV1L4I_V1L4I, 279841 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV1L4I_V1L4I, 279841 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV1L4I_V1L4I, 279841 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV1L4I_V1L4I, 279841 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L23E_V1L23E, 3236800 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L23E_V1L23E, 3236800 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L23E_V1L23E, 3236800 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L23E_V1L23E, 3236800 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L23E_V1L23E, 3236800 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L23E_V1L23E, 3236800 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L23E_V1L23I, 924800 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L23E_V1L23I, 924800 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L23E_V1L23I, 924800 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L23E_V1L23I, 924800 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L23E_V1L23I, 924800 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L23E_V1L23I, 924800 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L23E_V2L23I, 800000 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L23E_V2L23I, 800000 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L23E_V2L23I, 800000 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L23E_V2L23I, 800000 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L23E_V2L23I, 800000 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L23E_V2L23I, 800000 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L23E_V2L4I, 811200 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L23E_V2L4I, 811200 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L23E_V2L4I, 811200 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L23E_V2L4I, 811200 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L23E_V2L4I, 811200 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L23E_V2L4I, 811200 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L23I_V2L23E, 800000 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L23I_V2L23E, 800000 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L23I_V2L23E, 800000 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L23I_V2L23E, 800000 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L23I_V2L23E, 800000 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L23I_V2L23E, 800000 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L23I_V2L23I, 250000 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L23I_V2L23I, 250000 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L23I_V2L23I, 250000 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L23I_V2L23I, 250000 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L23I_V2L23I, 250000 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L23I_V2L23I, 250000 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L4E_V2L23E, 2704000 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L4E_V2L23E, 2704000 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L4E_V2L23E, 2704000 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L4E_V2L23E, 2704000 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L4E_V2L23E, 2704000 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L4E_V2L23E, 2704000 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L4E_V2L23I, 845000 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L4E_V2L23I, 845000 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L4E_V2L23I, 845000 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L4E_V2L23I, 845000 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L4E_V2L23I, 845000 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L4E_V2L23I, 845000 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L4E_V2L4I, 856830 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L4E_V2L4I, 856830 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L4E_V2L4I, 856830 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L4E_V2L4I, 856830 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L4E_V2L4I, 856830 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L4E_V2L4I, 856830 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L4I_V2L23E, 811200 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L4I_V2L23E, 811200 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L4I_V2L23E, 811200 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L4I_V2L23E, 811200 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L4I_V2L23E, 811200 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L4I_V2L23E, 811200 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L4I_V2L23I, 253500 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L4I_V2L23I, 253500 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L4I_V2L23I, 253500 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L4I_V2L23I, 253500 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L4I_V2L23I, 253500 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L4I_V2L23I, 253500 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L4I_V2L4E, 856830 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L4I_V2L4E, 856830 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L4I_V2L4E, 856830 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L4I_V2L4E, 856830 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L4I_V2L4E, 856830 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L4I_V2L4E, 856830 * sizeof(uint8_t)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&wV2L4I_V2L4I, 257049 * sizeof(scalar), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_wV2L4I_V2L4I, 257049 * sizeof(scalar)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&activeV2L4I_V2L4I, 257049 * sizeof(bool), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_activeV2L4I_V2L4I, 257049 * sizeof(bool)));
    CHECK_CUDA_ERRORS(cudaHostAlloc(&delayV2L4I_V2L4I, 257049 * sizeof(uint8_t), cudaHostAllocPortable));
    CHECK_CUDA_ERRORS(cudaMalloc(&d_delayV2L4I_V2L4I, 257049 * sizeof(uint8_t)));
    
    pushMergedNeuronInitGroup0ToDevice(0, d_denDelayPtrV2L23E_V2L4I, d_denDelayPtrV1L23E_V2L4I, d_denDelayV1L23E_V2L4I, d_inSynV1L23E_V2L4I, d_denDelayPtrV2L4E_V2L4I, d_denDelayV2L4E_V2L4I, d_inSynV2L4E_V2L4I, d_denDelayPtrV2L4I_V2L4I, d_denDelayV2L4I_V2L4I, d_inSynV2L4I_V2L4I, d_denDelayV2L23E_V2L4I, d_inSynV2L23E_V2L4I, d_aV2L4I, d_thetaV2L4I, d_rV2L4I, d_mV2L4I, d_glbSpkV2L4I, d_glbSpkCntV2L4I, 507);
    pushMergedNeuronInitGroup1ToDevice(0, d_glbSpkCntV2L4E, d_glbSpkV2L4E, d_mV2L4E, d_rV2L4E, d_thetaV2L4E, d_aV2L4E, d_inSynV1L23E_V2L4E, d_denDelayV1L23E_V2L4E, d_denDelayPtrV1L23E_V2L4E, d_inSynV2L4I_V2L4E, d_denDelayV2L4I_V2L4E, d_denDelayPtrV2L4I_V2L4E, 1690);
    pushMergedNeuronInitGroup2ToDevice(0, d_glbSpkCntV2L23E, d_glbSpkV2L23E, d_mV2L23E, d_rV2L23E, d_thetaV2L23E, d_aV2L23E, d_inSynV2L4I_V2L23E, d_denDelayV2L4I_V2L23E, d_denDelayPtrV2L4I_V2L23E, d_inSynV2L23I_V2L23E, d_denDelayV2L23I_V2L23E, d_denDelayPtrV2L23I_V2L23E, d_inSynV2L4E_V2L23E, d_denDelayV2L4E_V2L23E, d_denDelayPtrV2L4E_V2L23E, 1600);
    pushMergedNeuronInitGroup3ToDevice(0, d_denDelayPtrV1L23E_V1L4I, d_denDelayPtrLGN_V1L4I, d_denDelayLGN_V1L4I, d_inSynLGN_V1L4I, d_denDelayPtrV1L4E_V1L4I, d_denDelayV1L4E_V1L4I, d_inSynV1L4E_V1L4I, d_denDelayPtrV1L4I_V1L4I, d_denDelayV1L4I_V1L4I, d_inSynV1L4I_V1L4I, d_denDelayV1L23E_V1L4I, d_inSynV1L23E_V1L4I, d_aV1L4I, d_thetaV1L4I, d_rV1L4I, d_mV1L4I, d_glbSpkV1L4I, d_glbSpkCntV1L4I, 529);
    pushMergedNeuronInitGroup3ToDevice(1, d_denDelayPtrV2L4I_V2L23I, d_denDelayPtrV2L4E_V2L23I, d_denDelayV2L4E_V2L23I, d_inSynV2L4E_V2L23I, d_denDelayPtrV2L23E_V2L23I, d_denDelayV2L23E_V2L23I, d_inSynV2L23E_V2L23I, d_denDelayPtrV2L23I_V2L23I, d_denDelayV2L23I_V2L23I, d_inSynV2L23I_V2L23I, d_denDelayV2L4I_V2L23I, d_inSynV2L4I_V2L23I, d_aV2L23I, d_thetaV2L23I, d_rV2L23I, d_mV2L23I, d_glbSpkV2L23I, d_glbSpkCntV2L23I, 500);
    pushMergedNeuronInitGroup4ToDevice(0, d_glbSpkCntV1L4E, d_glbSpkV1L4E, d_mV1L4E, d_rV1L4E, d_thetaV1L4E, d_aV1L4E, d_inSynV1L4I_V1L4E, d_denDelayV1L4I_V1L4E, d_denDelayPtrV1L4I_V1L4E, d_inSynLGN_V1L4E, d_denDelayLGN_V1L4E, d_denDelayPtrLGN_V1L4E, 2116);
    pushMergedNeuronInitGroup5ToDevice(0, d_denDelayV1L23I_V1L23I, d_denDelayPtrV2L23E_V1L23I, d_denDelayV2L23E_V1L23I, d_inSynV2L23E_V1L23I, d_denDelayPtrV1L4E_V1L23I, d_denDelayV1L4E_V1L23I, d_inSynV1L4E_V1L23I, d_denDelayPtrV1L23E_V1L23I, d_denDelayV1L23E_V1L23I, d_inSynV1L23E_V1L23I, d_denDelayPtrV1L23I_V1L23I, d_inSynV1L23I_V1L23I, d_denDelayPtrV1L4I_V1L23I, d_denDelayV1L4I_V1L23I, d_inSynV1L4I_V1L23I, d_aV1L23I, d_thetaV1L23I, d_rV1L23I, d_mV1L23I, d_glbSpkV1L23I, d_glbSpkCntV1L23I, 578);
    pushMergedNeuronInitGroup6ToDevice(0, d_denDelayPtrV2L23E_V1L23E, d_denDelayPtrV1L4E_V1L23E, d_denDelayV1L4E_V1L23E, d_inSynV1L4E_V1L23E, d_denDelayPtrV1L23I_V1L23E, d_denDelayV1L23I_V1L23E, d_inSynV1L23I_V1L23E, d_denDelayPtrV1L4I_V1L23E, d_denDelayV1L4I_V1L23E, d_inSynV1L4I_V1L23E, d_denDelayV2L23E_V1L23E, d_inSynV2L23E_V1L23E, d_aV1L23E, d_thetaV1L23E, d_rV1L23E, d_mV1L23E, d_glbSpkV1L23E, d_glbSpkCntV1L23E, 2023);
    pushMergedNeuronInitGroup7ToDevice(0, d_glbSpkCntLGN, d_glbSpkLGN, d_rLGN, d_inputLGN, 2048);
    pushMergedSynapseInitGroup0ToDevice(0, d_wLGN_V1L4E, d_activeLGN_V1L4E, d_delayLGN_V1L4E, 2116, 2048, 2116, 2.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(1, d_wLGN_V1L4I, d_activeLGN_V1L4I, d_delayLGN_V1L4I, 529, 2048, 529, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(2, d_wV1L23E_V1L23I, d_activeV1L23E_V1L23I, d_delayV1L23E_V1L23I, 578, 2023, 578, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(3, d_wV1L23E_V1L4I, d_activeV1L23E_V1L4I, d_delayV1L23E_V1L4I, 529, 2023, 529, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(4, d_wV1L23E_V2L4E, d_activeV1L23E_V2L4E, d_delayV1L23E_V2L4E, 1690, 2023, 1690, 3.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(5, d_wV1L23E_V2L4I, d_activeV1L23E_V2L4I, d_delayV1L23E_V2L4I, 507, 2023, 507, 2.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(6, d_wV1L23I_V1L23E, d_activeV1L23I_V1L23E, d_delayV1L23I_V1L23E, 2023, 578, 2023, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(7, d_wV1L23I_V1L23I, d_activeV1L23I_V1L23I, d_delayV1L23I_V1L23I, 578, 578, 578, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(8, d_wV1L4E_V1L23E, d_activeV1L4E_V1L23E, d_delayV1L4E_V1L23E, 2023, 2116, 2023, 2.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(9, d_wV1L4E_V1L23I, d_activeV1L4E_V1L23I, d_delayV1L4E_V1L23I, 578, 2116, 578, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(10, d_wV1L4E_V1L4I, d_activeV1L4E_V1L4I, d_delayV1L4E_V1L4I, 529, 2116, 529, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(11, d_wV1L4I_V1L23E, d_activeV1L4I_V1L23E, d_delayV1L4I_V1L23E, 2023, 529, 2023, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(12, d_wV1L4I_V1L23I, d_activeV1L4I_V1L23I, d_delayV1L4I_V1L23I, 578, 529, 578, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(13, d_wV1L4I_V1L4E, d_activeV1L4I_V1L4E, d_delayV1L4I_V1L4E, 2116, 529, 2116, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(14, d_wV1L4I_V1L4I, d_activeV1L4I_V1L4I, d_delayV1L4I_V1L4I, 529, 529, 529, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(15, d_wV2L23E_V1L23E, d_activeV2L23E_V1L23E, d_delayV2L23E_V1L23E, 2023, 1600, 2023, 3.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(16, d_wV2L23E_V1L23I, d_activeV2L23E_V1L23I, d_delayV2L23E_V1L23I, 578, 1600, 578, 2.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(17, d_wV2L23E_V2L23I, d_activeV2L23E_V2L23I, d_delayV2L23E_V2L23I, 500, 1600, 500, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(18, d_wV2L23E_V2L4I, d_activeV2L23E_V2L4I, d_delayV2L23E_V2L4I, 507, 1600, 507, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(19, d_wV2L23I_V2L23E, d_activeV2L23I_V2L23E, d_delayV2L23I_V2L23E, 1600, 500, 1600, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(20, d_wV2L23I_V2L23I, d_activeV2L23I_V2L23I, d_delayV2L23I_V2L23I, 500, 500, 500, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(21, d_wV2L4E_V2L23E, d_activeV2L4E_V2L23E, d_delayV2L4E_V2L23E, 1600, 1690, 1600, 2.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(22, d_wV2L4E_V2L23I, d_activeV2L4E_V2L23I, d_delayV2L4E_V2L23I, 500, 1690, 500, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(23, d_wV2L4E_V2L4I, d_activeV2L4E_V2L4I, d_delayV2L4E_V2L4I, 507, 1690, 507, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(24, d_wV2L4I_V2L23E, d_activeV2L4I_V2L23E, d_delayV2L4I_V2L23E, 1600, 507, 1600, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(25, d_wV2L4I_V2L23I, d_activeV2L4I_V2L23I, d_delayV2L4I_V2L23I, 500, 507, 500, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(26, d_wV2L4I_V2L4E, d_activeV2L4I_V2L4E, d_delayV2L4I_V2L4E, 1690, 507, 1690, 1.00000000000000000e+00f);
    pushMergedSynapseInitGroup0ToDevice(27, d_wV2L4I_V2L4I, d_activeV2L4I_V2L4I, d_delayV2L4I_V2L4I, 507, 507, 507, 1.00000000000000000e+00f);
    pushMergedNeuronUpdateGroup0ToDevice(0, d_glbSpkCntV2L4E, d_glbSpkV2L4E, d_mV2L4E, d_rV2L4E, d_thetaV2L4E, d_aV2L4E, d_inSynV1L23E_V2L4E, d_denDelayV1L23E_V2L4E, d_denDelayPtrV1L23E_V2L4E, d_inSynV2L4I_V2L4E, d_denDelayV2L4I_V2L4E, d_denDelayPtrV2L4I_V2L4E, 1690);
    pushMergedNeuronUpdateGroup1ToDevice(0, d_glbSpkCntV2L23E, d_glbSpkV2L23E, d_mV2L23E, d_rV2L23E, d_thetaV2L23E, d_aV2L23E, d_inSynV2L4E_V2L23E, d_denDelayV2L4E_V2L23E, d_denDelayPtrV2L4E_V2L23E, d_inSynV2L4I_V2L23E, d_denDelayV2L4I_V2L23E, d_denDelayPtrV2L4I_V2L23E, d_inSynV2L23I_V2L23E, d_denDelayV2L23I_V2L23E, d_denDelayPtrV2L23I_V2L23E, 1600);
    pushMergedNeuronUpdateGroup2ToDevice(0, d_denDelayPtrV1L4E_V1L4I, d_denDelayPtrV1L4I_V1L4I, d_denDelayV1L4I_V1L4I, d_inSynV1L4I_V1L4I, d_denDelayPtrV1L23E_V1L4I, d_denDelayV1L23E_V1L4I, d_inSynV1L23E_V1L4I, d_denDelayPtrLGN_V1L4I, d_denDelayLGN_V1L4I, d_inSynLGN_V1L4I, d_denDelayV1L4E_V1L4I, d_inSynV1L4E_V1L4I, d_aV1L4I, d_thetaV1L4I, d_rV1L4I, d_mV1L4I, d_glbSpkV1L4I, d_glbSpkCntV1L4I, 529);
    pushMergedNeuronUpdateGroup3ToDevice(0, d_denDelayV1L23E_V1L23I, d_denDelayPtrV1L23I_V1L23I, d_denDelayV1L23I_V1L23I, d_inSynV1L23I_V1L23I, d_denDelayPtrV1L4I_V1L23I, d_denDelayV1L4I_V1L23I, d_inSynV1L4I_V1L23I, d_denDelayPtrV1L4E_V1L23I, d_denDelayV1L4E_V1L23I, d_inSynV1L4E_V1L23I, d_denDelayPtrV1L23E_V1L23I, d_inSynV1L23E_V1L23I, d_denDelayPtrV2L23E_V1L23I, d_denDelayV2L23E_V1L23I, d_inSynV2L23E_V1L23I, d_aV1L23I, d_thetaV1L23I, d_rV1L23I, d_mV1L23I, d_glbSpkV1L23I, d_glbSpkCntV1L23I, 578);
    pushMergedNeuronUpdateGroup4ToDevice(0, d_denDelayPtrV1L4E_V1L23E, d_denDelayPtrV1L23I_V1L23E, d_denDelayV1L23I_V1L23E, d_inSynV1L23I_V1L23E, d_denDelayPtrV1L4I_V1L23E, d_denDelayV1L4I_V1L23E, d_inSynV1L4I_V1L23E, d_denDelayPtrV2L23E_V1L23E, d_denDelayV2L23E_V1L23E, d_inSynV2L23E_V1L23E, d_denDelayV1L4E_V1L23E, d_inSynV1L4E_V1L23E, d_aV1L23E, d_thetaV1L23E, d_rV1L23E, d_mV1L23E, d_glbSpkV1L23E, d_glbSpkCntV1L23E, 2023);
    pushMergedNeuronUpdateGroup5ToDevice(0, d_denDelayPtrV1L23E_V2L4I, d_denDelayPtrV2L4I_V2L4I, d_denDelayV2L4I_V2L4I, d_inSynV2L4I_V2L4I, d_denDelayPtrV2L23E_V2L4I, d_denDelayV2L23E_V2L4I, d_inSynV2L23E_V2L4I, d_denDelayPtrV2L4E_V2L4I, d_denDelayV2L4E_V2L4I, d_inSynV2L4E_V2L4I, d_denDelayV1L23E_V2L4I, d_inSynV1L23E_V2L4I, d_aV2L4I, d_thetaV2L4I, d_rV2L4I, d_mV2L4I, d_glbSpkV2L4I, d_glbSpkCntV2L4I, 507);
    pushMergedNeuronUpdateGroup6ToDevice(0, d_denDelayPtrV2L23E_V2L23I, d_denDelayPtrV2L23I_V2L23I, d_denDelayV2L23I_V2L23I, d_inSynV2L23I_V2L23I, d_denDelayPtrV2L4I_V2L23I, d_denDelayV2L4I_V2L23I, d_inSynV2L4I_V2L23I, d_denDelayPtrV2L4E_V2L23I, d_denDelayV2L4E_V2L23I, d_inSynV2L4E_V2L23I, d_denDelayV2L23E_V2L23I, d_inSynV2L23E_V2L23I, d_aV2L23I, d_thetaV2L23I, d_rV2L23I, d_mV2L23I, d_glbSpkV2L23I, d_glbSpkCntV2L23I, 500);
    pushMergedNeuronUpdateGroup7ToDevice(0, d_glbSpkCntV1L4E, d_glbSpkV1L4E, d_mV1L4E, d_rV1L4E, d_thetaV1L4E, d_aV1L4E, d_inSynLGN_V1L4E, d_denDelayLGN_V1L4E, d_denDelayPtrLGN_V1L4E, d_inSynV1L4I_V1L4E, d_denDelayV1L4I_V1L4E, d_denDelayPtrV1L4I_V1L4E, 2116);
    pushMergedNeuronUpdateGroup8ToDevice(0, d_glbSpkCntLGN, d_glbSpkLGN, d_rLGN, d_inputLGN, 2048);
    pushMergedSynapseDynamicsGroup0ToDevice(0, d_denDelayLGN_V1L4I, d_denDelayPtrLGN_V1L4I, d_rLGN, d_wLGN_V1L4I, d_activeLGN_V1L4I, d_delayLGN_V1L4I, 529, 2048, 529);
    pushMergedSynapseDynamicsGroup0ToDevice(1, d_denDelayV1L23E_V1L23I, d_denDelayPtrV1L23E_V1L23I, d_rV1L23E, d_wV1L23E_V1L23I, d_activeV1L23E_V1L23I, d_delayV1L23E_V1L23I, 578, 2023, 578);
    pushMergedSynapseDynamicsGroup0ToDevice(2, d_denDelayV1L23E_V1L4I, d_denDelayPtrV1L23E_V1L4I, d_rV1L23E, d_wV1L23E_V1L4I, d_activeV1L23E_V1L4I, d_delayV1L23E_V1L4I, 529, 2023, 529);
    pushMergedSynapseDynamicsGroup0ToDevice(3, d_denDelayV1L23I_V1L23E, d_denDelayPtrV1L23I_V1L23E, d_rV1L23I, d_wV1L23I_V1L23E, d_activeV1L23I_V1L23E, d_delayV1L23I_V1L23E, 2023, 578, 2023);
    pushMergedSynapseDynamicsGroup0ToDevice(4, d_denDelayV1L23I_V1L23I, d_denDelayPtrV1L23I_V1L23I, d_rV1L23I, d_wV1L23I_V1L23I, d_activeV1L23I_V1L23I, d_delayV1L23I_V1L23I, 578, 578, 578);
    pushMergedSynapseDynamicsGroup0ToDevice(5, d_denDelayV1L4E_V1L23I, d_denDelayPtrV1L4E_V1L23I, d_rV1L4E, d_wV1L4E_V1L23I, d_activeV1L4E_V1L23I, d_delayV1L4E_V1L23I, 578, 2116, 578);
    pushMergedSynapseDynamicsGroup0ToDevice(6, d_denDelayV1L4E_V1L4I, d_denDelayPtrV1L4E_V1L4I, d_rV1L4E, d_wV1L4E_V1L4I, d_activeV1L4E_V1L4I, d_delayV1L4E_V1L4I, 529, 2116, 529);
    pushMergedSynapseDynamicsGroup0ToDevice(7, d_denDelayV1L4I_V1L23E, d_denDelayPtrV1L4I_V1L23E, d_rV1L4I, d_wV1L4I_V1L23E, d_activeV1L4I_V1L23E, d_delayV1L4I_V1L23E, 2023, 529, 2023);
    pushMergedSynapseDynamicsGroup0ToDevice(8, d_denDelayV1L4I_V1L23I, d_denDelayPtrV1L4I_V1L23I, d_rV1L4I, d_wV1L4I_V1L23I, d_activeV1L4I_V1L23I, d_delayV1L4I_V1L23I, 578, 529, 578);
    pushMergedSynapseDynamicsGroup0ToDevice(9, d_denDelayV1L4I_V1L4E, d_denDelayPtrV1L4I_V1L4E, d_rV1L4I, d_wV1L4I_V1L4E, d_activeV1L4I_V1L4E, d_delayV1L4I_V1L4E, 2116, 529, 2116);
    pushMergedSynapseDynamicsGroup0ToDevice(10, d_denDelayV1L4I_V1L4I, d_denDelayPtrV1L4I_V1L4I, d_rV1L4I, d_wV1L4I_V1L4I, d_activeV1L4I_V1L4I, d_delayV1L4I_V1L4I, 529, 529, 529);
    pushMergedSynapseDynamicsGroup0ToDevice(11, d_denDelayV2L23E_V2L23I, d_denDelayPtrV2L23E_V2L23I, d_rV2L23E, d_wV2L23E_V2L23I, d_activeV2L23E_V2L23I, d_delayV2L23E_V2L23I, 500, 1600, 500);
    pushMergedSynapseDynamicsGroup0ToDevice(12, d_denDelayV2L23E_V2L4I, d_denDelayPtrV2L23E_V2L4I, d_rV2L23E, d_wV2L23E_V2L4I, d_activeV2L23E_V2L4I, d_delayV2L23E_V2L4I, 507, 1600, 507);
    pushMergedSynapseDynamicsGroup0ToDevice(13, d_denDelayV2L23I_V2L23E, d_denDelayPtrV2L23I_V2L23E, d_rV2L23I, d_wV2L23I_V2L23E, d_activeV2L23I_V2L23E, d_delayV2L23I_V2L23E, 1600, 500, 1600);
    pushMergedSynapseDynamicsGroup0ToDevice(14, d_denDelayV2L23I_V2L23I, d_denDelayPtrV2L23I_V2L23I, d_rV2L23I, d_wV2L23I_V2L23I, d_activeV2L23I_V2L23I, d_delayV2L23I_V2L23I, 500, 500, 500);
    pushMergedSynapseDynamicsGroup0ToDevice(15, d_denDelayV2L4E_V2L23I, d_denDelayPtrV2L4E_V2L23I, d_rV2L4E, d_wV2L4E_V2L23I, d_activeV2L4E_V2L23I, d_delayV2L4E_V2L23I, 500, 1690, 500);
    pushMergedSynapseDynamicsGroup0ToDevice(16, d_denDelayV2L4E_V2L4I, d_denDelayPtrV2L4E_V2L4I, d_rV2L4E, d_wV2L4E_V2L4I, d_activeV2L4E_V2L4I, d_delayV2L4E_V2L4I, 507, 1690, 507);
    pushMergedSynapseDynamicsGroup0ToDevice(17, d_denDelayV2L4I_V2L23E, d_denDelayPtrV2L4I_V2L23E, d_rV2L4I, d_wV2L4I_V2L23E, d_activeV2L4I_V2L23E, d_delayV2L4I_V2L23E, 1600, 507, 1600);
    pushMergedSynapseDynamicsGroup0ToDevice(18, d_denDelayV2L4I_V2L23I, d_denDelayPtrV2L4I_V2L23I, d_rV2L4I, d_wV2L4I_V2L23I, d_activeV2L4I_V2L23I, d_delayV2L4I_V2L23I, 500, 507, 500);
    pushMergedSynapseDynamicsGroup0ToDevice(19, d_denDelayV2L4I_V2L4E, d_denDelayPtrV2L4I_V2L4E, d_rV2L4I, d_wV2L4I_V2L4E, d_activeV2L4I_V2L4E, d_delayV2L4I_V2L4E, 1690, 507, 1690);
    pushMergedSynapseDynamicsGroup0ToDevice(20, d_denDelayV2L4I_V2L4I, d_denDelayPtrV2L4I_V2L4I, d_rV2L4I, d_wV2L4I_V2L4I, d_activeV2L4I_V2L4I, d_delayV2L4I_V2L4I, 507, 507, 507);
    pushMergedSynapseDynamicsGroup1ToDevice(0, d_denDelayV1L23E_V2L4E, d_denDelayPtrV1L23E_V2L4E, d_rV1L23E, d_wV1L23E_V2L4E, d_activeV1L23E_V2L4E, d_delayV1L23E_V2L4E, 1690, 2023, 1690);
    pushMergedSynapseDynamicsGroup1ToDevice(1, d_denDelayV2L23E_V1L23E, d_denDelayPtrV2L23E_V1L23E, d_rV2L23E, d_wV2L23E_V1L23E, d_activeV2L23E_V1L23E, d_delayV2L23E_V1L23E, 2023, 1600, 2023);
    pushMergedSynapseDynamicsGroup2ToDevice(0, d_denDelayLGN_V1L4E, d_denDelayPtrLGN_V1L4E, d_rLGN, d_wLGN_V1L4E, d_activeLGN_V1L4E, d_delayLGN_V1L4E, 2116, 2048, 2116);
    pushMergedSynapseDynamicsGroup2ToDevice(1, d_denDelayV1L23E_V2L4I, d_denDelayPtrV1L23E_V2L4I, d_rV1L23E, d_wV1L23E_V2L4I, d_activeV1L23E_V2L4I, d_delayV1L23E_V2L4I, 507, 2023, 507);
    pushMergedSynapseDynamicsGroup2ToDevice(2, d_denDelayV1L4E_V1L23E, d_denDelayPtrV1L4E_V1L23E, d_rV1L4E, d_wV1L4E_V1L23E, d_activeV1L4E_V1L23E, d_delayV1L4E_V1L23E, 2023, 2116, 2023);
    pushMergedSynapseDynamicsGroup2ToDevice(3, d_denDelayV2L23E_V1L23I, d_denDelayPtrV2L23E_V1L23I, d_rV2L23E, d_wV2L23E_V1L23I, d_activeV2L23E_V1L23I, d_delayV2L23E_V1L23I, 578, 1600, 578);
    pushMergedSynapseDynamicsGroup2ToDevice(4, d_denDelayV2L4E_V2L23E, d_denDelayPtrV2L4E_V2L23E, d_rV2L4E, d_wV2L4E_V2L23E, d_activeV2L4E_V2L23E, d_delayV2L4E_V2L23E, 1600, 1690, 1600);
    pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(0, d_glbSpkCntLGN);
    pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(1, d_glbSpkCntV1L23E);
    pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(2, d_glbSpkCntV1L23I);
    pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(3, d_glbSpkCntV1L4E);
    pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(4, d_glbSpkCntV1L4I);
    pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(5, d_glbSpkCntV2L23E);
    pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(6, d_glbSpkCntV2L23I);
    pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(7, d_glbSpkCntV2L4E);
    pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(8, d_glbSpkCntV2L4I);
    pushMergedSynapseDendriticDelayUpdateGroup0ToDevice(0, d_denDelayPtrV1L4E_V1L23E);
    pushMergedSynapseDendriticDelayUpdateGroup0ToDevice(1, d_denDelayPtrV2L23E_V1L23I);
    pushMergedSynapseDendriticDelayUpdateGroup0ToDevice(2, d_denDelayPtrLGN_V1L4E);
    pushMergedSynapseDendriticDelayUpdateGroup0ToDevice(3, d_denDelayPtrV2L4E_V2L23E);
    pushMergedSynapseDendriticDelayUpdateGroup0ToDevice(4, d_denDelayPtrV1L23E_V2L4I);
    pushMergedSynapseDendriticDelayUpdateGroup1ToDevice(0, d_denDelayPtrV2L23E_V1L23E);
    pushMergedSynapseDendriticDelayUpdateGroup1ToDevice(1, d_denDelayPtrV1L23E_V2L4E);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(0, d_denDelayPtrV1L4I_V1L23E);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(1, d_denDelayPtrV1L23I_V1L23E);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(2, d_denDelayPtrV1L4I_V1L23I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(3, d_denDelayPtrV1L23I_V1L23I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(4, d_denDelayPtrV1L23E_V1L23I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(5, d_denDelayPtrV1L4E_V1L23I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(6, d_denDelayPtrV1L4I_V1L4E);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(7, d_denDelayPtrV1L23E_V1L4I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(8, d_denDelayPtrV1L4I_V1L4I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(9, d_denDelayPtrV1L4E_V1L4I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(10, d_denDelayPtrLGN_V1L4I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(11, d_denDelayPtrV2L4I_V2L23E);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(12, d_denDelayPtrV2L23I_V2L23E);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(13, d_denDelayPtrV2L4I_V2L23I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(14, d_denDelayPtrV2L23I_V2L23I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(15, d_denDelayPtrV2L23E_V2L23I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(16, d_denDelayPtrV2L4E_V2L23I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(17, d_denDelayPtrV2L4I_V2L4E);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(18, d_denDelayPtrV2L23E_V2L4I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(19, d_denDelayPtrV2L4I_V2L4I);
    pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(20, d_denDelayPtrV2L4E_V2L4I);
}

void freeMem() {
    // ------------------------------------------------------------------------
    // global variables
    // ------------------------------------------------------------------------
    
    // ------------------------------------------------------------------------
    // timers
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    // local neuron groups
    // ------------------------------------------------------------------------
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkCntLGN));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkCntLGN));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkLGN));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkLGN));
    CHECK_CUDA_ERRORS(cudaFreeHost(rLGN));
    CHECK_CUDA_ERRORS(cudaFree(d_rLGN));
    CHECK_CUDA_ERRORS(cudaFreeHost(inputLGN));
    CHECK_CUDA_ERRORS(cudaFree(d_inputLGN));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkCntV1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkCntV1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkV1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkV1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(mV1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_mV1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(rV1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_rV1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(thetaV1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_thetaV1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(aV1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_aV1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkCntV1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkCntV1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkV1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkV1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(mV1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_mV1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(rV1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_rV1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(thetaV1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_thetaV1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(aV1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_aV1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkCntV1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkCntV1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkV1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkV1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(mV1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_mV1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(rV1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_rV1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(thetaV1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_thetaV1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(aV1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_aV1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkCntV1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkCntV1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkV1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkV1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(mV1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_mV1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(rV1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_rV1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(thetaV1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_thetaV1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(aV1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_aV1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkCntV2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkCntV2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkV2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkV2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(mV2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_mV2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(rV2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_rV2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(thetaV2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_thetaV2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(aV2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_aV2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkCntV2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkCntV2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkV2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkV2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(mV2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_mV2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(rV2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_rV2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(thetaV2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_thetaV2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(aV2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_aV2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkCntV2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkCntV2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkV2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkV2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(mV2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_mV2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(rV2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_rV2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(thetaV2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_thetaV2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(aV2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_aV2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkCntV2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkCntV2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(glbSpkV2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_glbSpkV2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(mV2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_mV2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(rV2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_rV2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(thetaV2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_thetaV2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(aV2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_aV2L4I));
    
    // ------------------------------------------------------------------------
    // custom update variables
    // ------------------------------------------------------------------------
    
    // ------------------------------------------------------------------------
    // pre and postsynaptic variables
    // ------------------------------------------------------------------------
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L4I_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L4I_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L4I_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L4I_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L4I_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(inSynV1L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_inSynV1L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(denDelayV1L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayV1L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_denDelayPtrV1L23E_V2L4I));
    
    // ------------------------------------------------------------------------
    // synapse connectivity
    // ------------------------------------------------------------------------
    
    // ------------------------------------------------------------------------
    // synapse variables
    // ------------------------------------------------------------------------
    CHECK_CUDA_ERRORS(cudaFreeHost(wLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_wLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayLGN_V1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_wLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayLGN_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L23E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L23E_V2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L23I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L23I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L4E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L4E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L4E_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L4I_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L4I_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L4I_V1L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV1L4I_V1L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L23E_V1L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L23E_V1L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L23E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L23E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L23I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L23I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L4E_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L4E_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L4E_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L4I_V2L23E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L4I_V2L23I));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L4I_V2L4E));
    CHECK_CUDA_ERRORS(cudaFreeHost(wV2L4I_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_wV2L4I_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(activeV2L4I_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_activeV2L4I_V2L4I));
    CHECK_CUDA_ERRORS(cudaFreeHost(delayV2L4I_V2L4I));
    CHECK_CUDA_ERRORS(cudaFree(d_delayV2L4I_V2L4I));
    
}

size_t getFreeDeviceMemBytes() {
    size_t free;
    size_t total;
    CHECK_CUDA_ERRORS(cudaMemGetInfo(&free, &total));
    return free;
}

void stepTime() {
    updateSynapses(t);
    updateNeurons(t); 
    denDelayPtrV1L4I_V1L23E = (denDelayPtrV1L4I_V1L23E + 1) % 1;
    denDelayPtrV2L23E_V1L23E = (denDelayPtrV2L23E_V1L23E + 1) % 3;
    denDelayPtrV1L23I_V1L23E = (denDelayPtrV1L23I_V1L23E + 1) % 1;
    denDelayPtrV1L4E_V1L23E = (denDelayPtrV1L4E_V1L23E + 1) % 2;
    denDelayPtrV1L4I_V1L23I = (denDelayPtrV1L4I_V1L23I + 1) % 1;
    denDelayPtrV2L23E_V1L23I = (denDelayPtrV2L23E_V1L23I + 1) % 2;
    denDelayPtrV1L23I_V1L23I = (denDelayPtrV1L23I_V1L23I + 1) % 1;
    denDelayPtrV1L23E_V1L23I = (denDelayPtrV1L23E_V1L23I + 1) % 1;
    denDelayPtrV1L4E_V1L23I = (denDelayPtrV1L4E_V1L23I + 1) % 1;
    denDelayPtrV1L4I_V1L4E = (denDelayPtrV1L4I_V1L4E + 1) % 1;
    denDelayPtrLGN_V1L4E = (denDelayPtrLGN_V1L4E + 1) % 2;
    denDelayPtrV1L23E_V1L4I = (denDelayPtrV1L23E_V1L4I + 1) % 1;
    denDelayPtrV1L4I_V1L4I = (denDelayPtrV1L4I_V1L4I + 1) % 1;
    denDelayPtrV1L4E_V1L4I = (denDelayPtrV1L4E_V1L4I + 1) % 1;
    denDelayPtrLGN_V1L4I = (denDelayPtrLGN_V1L4I + 1) % 1;
    denDelayPtrV2L4I_V2L23E = (denDelayPtrV2L4I_V2L23E + 1) % 1;
    denDelayPtrV2L23I_V2L23E = (denDelayPtrV2L23I_V2L23E + 1) % 1;
    denDelayPtrV2L4E_V2L23E = (denDelayPtrV2L4E_V2L23E + 1) % 2;
    denDelayPtrV2L4I_V2L23I = (denDelayPtrV2L4I_V2L23I + 1) % 1;
    denDelayPtrV2L23I_V2L23I = (denDelayPtrV2L23I_V2L23I + 1) % 1;
    denDelayPtrV2L23E_V2L23I = (denDelayPtrV2L23E_V2L23I + 1) % 1;
    denDelayPtrV2L4E_V2L23I = (denDelayPtrV2L4E_V2L23I + 1) % 1;
    denDelayPtrV2L4I_V2L4E = (denDelayPtrV2L4I_V2L4E + 1) % 1;
    denDelayPtrV1L23E_V2L4E = (denDelayPtrV1L23E_V2L4E + 1) % 3;
    denDelayPtrV2L23E_V2L4I = (denDelayPtrV2L23E_V2L4I + 1) % 1;
    denDelayPtrV2L4I_V2L4I = (denDelayPtrV2L4I_V2L4I + 1) % 1;
    denDelayPtrV2L4E_V2L4I = (denDelayPtrV2L4E_V2L4I + 1) % 1;
    denDelayPtrV1L23E_V2L4I = (denDelayPtrV1L23E_V2L4I + 1) % 2;
    iT++;
    t = iT*DT;
}

