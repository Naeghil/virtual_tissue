#include "definitionsInternal.h"
#include <iostream>
#include <random>
#include <cstdint>

struct MergedNeuronInitGroup0
 {
    unsigned int* denDelayPtrInSyn0;
    unsigned int* denDelayPtrInSyn3;
    float* denDelayInSyn3;
    float* inSynInSyn3;
    unsigned int* denDelayPtrInSyn2;
    float* denDelayInSyn2;
    float* inSynInSyn2;
    unsigned int* denDelayPtrInSyn1;
    float* denDelayInSyn1;
    float* inSynInSyn1;
    float* denDelayInSyn0;
    float* inSynInSyn0;
    scalar* a;
    scalar* theta;
    scalar* r;
    scalar* m;
    unsigned int* spk;
    unsigned int* spkCnt;
    unsigned int numNeurons;
    
}
;
struct MergedNeuronInitGroup1
 {
    unsigned int* spkCnt;
    unsigned int* spk;
    scalar* m;
    scalar* r;
    scalar* theta;
    scalar* a;
    float* inSynInSyn0;
    float* denDelayInSyn0;
    unsigned int* denDelayPtrInSyn0;
    float* inSynInSyn1;
    float* denDelayInSyn1;
    unsigned int* denDelayPtrInSyn1;
    unsigned int numNeurons;
    
}
;
struct MergedNeuronInitGroup2
 {
    unsigned int* spkCnt;
    unsigned int* spk;
    scalar* m;
    scalar* r;
    scalar* theta;
    scalar* a;
    float* inSynInSyn0;
    float* denDelayInSyn0;
    unsigned int* denDelayPtrInSyn0;
    float* inSynInSyn1;
    float* denDelayInSyn1;
    unsigned int* denDelayPtrInSyn1;
    float* inSynInSyn2;
    float* denDelayInSyn2;
    unsigned int* denDelayPtrInSyn2;
    unsigned int numNeurons;
    
}
;
struct MergedNeuronInitGroup3
 {
    unsigned int* denDelayPtrInSyn0;
    unsigned int* denDelayPtrInSyn3;
    float* denDelayInSyn3;
    float* inSynInSyn3;
    unsigned int* denDelayPtrInSyn2;
    float* denDelayInSyn2;
    float* inSynInSyn2;
    unsigned int* denDelayPtrInSyn1;
    float* denDelayInSyn1;
    float* inSynInSyn1;
    float* denDelayInSyn0;
    float* inSynInSyn0;
    scalar* a;
    scalar* theta;
    scalar* r;
    scalar* m;
    unsigned int* spk;
    unsigned int* spkCnt;
    unsigned int numNeurons;
    
}
;
struct MergedNeuronInitGroup4
 {
    unsigned int* spkCnt;
    unsigned int* spk;
    scalar* m;
    scalar* r;
    scalar* theta;
    scalar* a;
    float* inSynInSyn0;
    float* denDelayInSyn0;
    unsigned int* denDelayPtrInSyn0;
    float* inSynInSyn1;
    float* denDelayInSyn1;
    unsigned int* denDelayPtrInSyn1;
    unsigned int numNeurons;
    
}
;
struct MergedNeuronInitGroup5
 {
    float* denDelayInSyn1;
    unsigned int* denDelayPtrInSyn4;
    float* denDelayInSyn4;
    float* inSynInSyn4;
    unsigned int* denDelayPtrInSyn3;
    float* denDelayInSyn3;
    float* inSynInSyn3;
    unsigned int* denDelayPtrInSyn2;
    float* denDelayInSyn2;
    float* inSynInSyn2;
    unsigned int* denDelayPtrInSyn1;
    float* inSynInSyn1;
    unsigned int* denDelayPtrInSyn0;
    float* denDelayInSyn0;
    float* inSynInSyn0;
    scalar* a;
    scalar* theta;
    scalar* r;
    scalar* m;
    unsigned int* spk;
    unsigned int* spkCnt;
    unsigned int numNeurons;
    
}
;
struct MergedNeuronInitGroup6
 {
    unsigned int* denDelayPtrInSyn0;
    unsigned int* denDelayPtrInSyn3;
    float* denDelayInSyn3;
    float* inSynInSyn3;
    unsigned int* denDelayPtrInSyn2;
    float* denDelayInSyn2;
    float* inSynInSyn2;
    unsigned int* denDelayPtrInSyn1;
    float* denDelayInSyn1;
    float* inSynInSyn1;
    float* denDelayInSyn0;
    float* inSynInSyn0;
    scalar* a;
    scalar* theta;
    scalar* r;
    scalar* m;
    unsigned int* spk;
    unsigned int* spkCnt;
    unsigned int numNeurons;
    
}
;
struct MergedNeuronInitGroup7
 {
    unsigned int* spkCnt;
    unsigned int* spk;
    scalar* r;
    scalar* input;
    unsigned int numNeurons;
    
}
;
struct MergedSynapseInitGroup0
 {
    scalar* w;
    bool* active;
    uint8_t* delay;
    unsigned int rowStride;
    unsigned int numSrcNeurons;
    unsigned int numTrgNeurons;
    scalar constantdelay;
    
}
;
__device__ __constant__ MergedNeuronInitGroup0 d_mergedNeuronInitGroup0[1];
void pushMergedNeuronInitGroup0ToDevice(unsigned int idx, unsigned int* denDelayPtrInSyn0, unsigned int* denDelayPtrInSyn3, float* denDelayInSyn3, float* inSynInSyn3, unsigned int* denDelayPtrInSyn2, float* denDelayInSyn2, float* inSynInSyn2, unsigned int* denDelayPtrInSyn1, float* denDelayInSyn1, float* inSynInSyn1, float* denDelayInSyn0, float* inSynInSyn0, scalar* a, scalar* theta, scalar* r, scalar* m, unsigned int* spk, unsigned int* spkCnt, unsigned int numNeurons) {
    MergedNeuronInitGroup0 group = {denDelayPtrInSyn0, denDelayPtrInSyn3, denDelayInSyn3, inSynInSyn3, denDelayPtrInSyn2, denDelayInSyn2, inSynInSyn2, denDelayPtrInSyn1, denDelayInSyn1, inSynInSyn1, denDelayInSyn0, inSynInSyn0, a, theta, r, m, spk, spkCnt, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup0, &group, sizeof(MergedNeuronInitGroup0), idx * sizeof(MergedNeuronInitGroup0)));
}
__device__ __constant__ MergedNeuronInitGroup1 d_mergedNeuronInitGroup1[1];
void pushMergedNeuronInitGroup1ToDevice(unsigned int idx, unsigned int* spkCnt, unsigned int* spk, scalar* m, scalar* r, scalar* theta, scalar* a, float* inSynInSyn0, float* denDelayInSyn0, unsigned int* denDelayPtrInSyn0, float* inSynInSyn1, float* denDelayInSyn1, unsigned int* denDelayPtrInSyn1, unsigned int numNeurons) {
    MergedNeuronInitGroup1 group = {spkCnt, spk, m, r, theta, a, inSynInSyn0, denDelayInSyn0, denDelayPtrInSyn0, inSynInSyn1, denDelayInSyn1, denDelayPtrInSyn1, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup1, &group, sizeof(MergedNeuronInitGroup1), idx * sizeof(MergedNeuronInitGroup1)));
}
__device__ __constant__ MergedNeuronInitGroup2 d_mergedNeuronInitGroup2[1];
void pushMergedNeuronInitGroup2ToDevice(unsigned int idx, unsigned int* spkCnt, unsigned int* spk, scalar* m, scalar* r, scalar* theta, scalar* a, float* inSynInSyn0, float* denDelayInSyn0, unsigned int* denDelayPtrInSyn0, float* inSynInSyn1, float* denDelayInSyn1, unsigned int* denDelayPtrInSyn1, float* inSynInSyn2, float* denDelayInSyn2, unsigned int* denDelayPtrInSyn2, unsigned int numNeurons) {
    MergedNeuronInitGroup2 group = {spkCnt, spk, m, r, theta, a, inSynInSyn0, denDelayInSyn0, denDelayPtrInSyn0, inSynInSyn1, denDelayInSyn1, denDelayPtrInSyn1, inSynInSyn2, denDelayInSyn2, denDelayPtrInSyn2, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup2, &group, sizeof(MergedNeuronInitGroup2), idx * sizeof(MergedNeuronInitGroup2)));
}
__device__ __constant__ MergedNeuronInitGroup3 d_mergedNeuronInitGroup3[2];
void pushMergedNeuronInitGroup3ToDevice(unsigned int idx, unsigned int* denDelayPtrInSyn0, unsigned int* denDelayPtrInSyn3, float* denDelayInSyn3, float* inSynInSyn3, unsigned int* denDelayPtrInSyn2, float* denDelayInSyn2, float* inSynInSyn2, unsigned int* denDelayPtrInSyn1, float* denDelayInSyn1, float* inSynInSyn1, float* denDelayInSyn0, float* inSynInSyn0, scalar* a, scalar* theta, scalar* r, scalar* m, unsigned int* spk, unsigned int* spkCnt, unsigned int numNeurons) {
    MergedNeuronInitGroup3 group = {denDelayPtrInSyn0, denDelayPtrInSyn3, denDelayInSyn3, inSynInSyn3, denDelayPtrInSyn2, denDelayInSyn2, inSynInSyn2, denDelayPtrInSyn1, denDelayInSyn1, inSynInSyn1, denDelayInSyn0, inSynInSyn0, a, theta, r, m, spk, spkCnt, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup3, &group, sizeof(MergedNeuronInitGroup3), idx * sizeof(MergedNeuronInitGroup3)));
}
__device__ __constant__ MergedNeuronInitGroup4 d_mergedNeuronInitGroup4[1];
void pushMergedNeuronInitGroup4ToDevice(unsigned int idx, unsigned int* spkCnt, unsigned int* spk, scalar* m, scalar* r, scalar* theta, scalar* a, float* inSynInSyn0, float* denDelayInSyn0, unsigned int* denDelayPtrInSyn0, float* inSynInSyn1, float* denDelayInSyn1, unsigned int* denDelayPtrInSyn1, unsigned int numNeurons) {
    MergedNeuronInitGroup4 group = {spkCnt, spk, m, r, theta, a, inSynInSyn0, denDelayInSyn0, denDelayPtrInSyn0, inSynInSyn1, denDelayInSyn1, denDelayPtrInSyn1, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup4, &group, sizeof(MergedNeuronInitGroup4), idx * sizeof(MergedNeuronInitGroup4)));
}
__device__ __constant__ MergedNeuronInitGroup5 d_mergedNeuronInitGroup5[1];
void pushMergedNeuronInitGroup5ToDevice(unsigned int idx, float* denDelayInSyn1, unsigned int* denDelayPtrInSyn4, float* denDelayInSyn4, float* inSynInSyn4, unsigned int* denDelayPtrInSyn3, float* denDelayInSyn3, float* inSynInSyn3, unsigned int* denDelayPtrInSyn2, float* denDelayInSyn2, float* inSynInSyn2, unsigned int* denDelayPtrInSyn1, float* inSynInSyn1, unsigned int* denDelayPtrInSyn0, float* denDelayInSyn0, float* inSynInSyn0, scalar* a, scalar* theta, scalar* r, scalar* m, unsigned int* spk, unsigned int* spkCnt, unsigned int numNeurons) {
    MergedNeuronInitGroup5 group = {denDelayInSyn1, denDelayPtrInSyn4, denDelayInSyn4, inSynInSyn4, denDelayPtrInSyn3, denDelayInSyn3, inSynInSyn3, denDelayPtrInSyn2, denDelayInSyn2, inSynInSyn2, denDelayPtrInSyn1, inSynInSyn1, denDelayPtrInSyn0, denDelayInSyn0, inSynInSyn0, a, theta, r, m, spk, spkCnt, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup5, &group, sizeof(MergedNeuronInitGroup5), idx * sizeof(MergedNeuronInitGroup5)));
}
__device__ __constant__ MergedNeuronInitGroup6 d_mergedNeuronInitGroup6[1];
void pushMergedNeuronInitGroup6ToDevice(unsigned int idx, unsigned int* denDelayPtrInSyn0, unsigned int* denDelayPtrInSyn3, float* denDelayInSyn3, float* inSynInSyn3, unsigned int* denDelayPtrInSyn2, float* denDelayInSyn2, float* inSynInSyn2, unsigned int* denDelayPtrInSyn1, float* denDelayInSyn1, float* inSynInSyn1, float* denDelayInSyn0, float* inSynInSyn0, scalar* a, scalar* theta, scalar* r, scalar* m, unsigned int* spk, unsigned int* spkCnt, unsigned int numNeurons) {
    MergedNeuronInitGroup6 group = {denDelayPtrInSyn0, denDelayPtrInSyn3, denDelayInSyn3, inSynInSyn3, denDelayPtrInSyn2, denDelayInSyn2, inSynInSyn2, denDelayPtrInSyn1, denDelayInSyn1, inSynInSyn1, denDelayInSyn0, inSynInSyn0, a, theta, r, m, spk, spkCnt, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup6, &group, sizeof(MergedNeuronInitGroup6), idx * sizeof(MergedNeuronInitGroup6)));
}
__device__ __constant__ MergedNeuronInitGroup7 d_mergedNeuronInitGroup7[1];
void pushMergedNeuronInitGroup7ToDevice(unsigned int idx, unsigned int* spkCnt, unsigned int* spk, scalar* r, scalar* input, unsigned int numNeurons) {
    MergedNeuronInitGroup7 group = {spkCnt, spk, r, input, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup7, &group, sizeof(MergedNeuronInitGroup7), idx * sizeof(MergedNeuronInitGroup7)));
}
__device__ __constant__ MergedSynapseInitGroup0 d_mergedSynapseInitGroup0[28];
void pushMergedSynapseInitGroup0ToDevice(unsigned int idx, scalar* w, bool* active, uint8_t* delay, unsigned int rowStride, unsigned int numSrcNeurons, unsigned int numTrgNeurons, scalar constantdelay) {
    MergedSynapseInitGroup0 group = {w, active, delay, rowStride, numSrcNeurons, numTrgNeurons, constantdelay, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedSynapseInitGroup0, &group, sizeof(MergedSynapseInitGroup0), idx * sizeof(MergedSynapseInitGroup0)));
}
// ------------------------------------------------------------------------
// merged extra global parameter functions
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// merged extra global parameter functions
// ------------------------------------------------------------------------
__device__ unsigned int d_mergedNeuronInitGroupStartID0[] = {0, };
__device__ unsigned int d_mergedNeuronInitGroupStartID1[] = {576, };
__device__ unsigned int d_mergedNeuronInitGroupStartID2[] = {2304, };
__device__ unsigned int d_mergedNeuronInitGroupStartID3[] = {3936, 4512, };
__device__ unsigned int d_mergedNeuronInitGroupStartID4[] = {5088, };
__device__ unsigned int d_mergedNeuronInitGroupStartID5[] = {7296, };
__device__ unsigned int d_mergedNeuronInitGroupStartID6[] = {7968, };
__device__ unsigned int d_mergedNeuronInitGroupStartID7[] = {10080, };
__device__ unsigned int d_mergedSynapseInitGroupStartID0[] = {12192, 14400, 14976, 15648, 16224, 17952, 18528, 20640, 21312, 23424, 24096, 24672, 26784, 27456, 29664, 30240, 32352, 33024, 33600, 34176, 35808, 36384, 38016, 38592, 39168, 40800, 41376, 43104, };

extern "C" __global__ void initializeKernel(unsigned long long deviceRNGSeed) {
    const unsigned int id = 96 * blockIdx.x + threadIdx.x;
    // ------------------------------------------------------------------------
    // Local neuron groups
    // merged0
    if(id < 576) {
        struct MergedNeuronInitGroup0 *group = &d_mergedNeuronInitGroup0[0]; 
        const unsigned int lid = id - 0;
        // only do this for existing neurons
        if(lid < group->numNeurons) {
            if(lid == 0) {
                group->spkCnt[0] = 0;
            }
            group->spk[lid] = 0;
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->m[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->r[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->theta[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (1.00000000000000000e+00f);
                group->a[lid] = initVal;
            }
             {
                group->inSynInSyn0[lid] = 0.000000000e+00f;
                group->denDelayInSyn0[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn0 = 0;
                }
            }
             {
                group->inSynInSyn1[lid] = 0.000000000e+00f;
                group->denDelayInSyn1[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn1 = 0;
                }
            }
             {
                group->inSynInSyn2[lid] = 0.000000000e+00f;
                group->denDelayInSyn2[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn2 = 0;
                }
            }
             {
                group->inSynInSyn3[lid] = 0.000000000e+00f;
                for(unsigned int d = 0; d < 2; d++) {
                    group->denDelayInSyn3[(d * group->numNeurons) + lid] = 0.000000000e+00f;
                }
                if(lid == 0) {
                    *group->denDelayPtrInSyn3 = 0;
                }
            }
            // current source variables
        }
    }
    // merged1
    if(id >= 576 && id < 2304) {
        struct MergedNeuronInitGroup1 *group = &d_mergedNeuronInitGroup1[0]; 
        const unsigned int lid = id - 576;
        // only do this for existing neurons
        if(lid < group->numNeurons) {
            if(lid == 0) {
                group->spkCnt[0] = 0;
            }
            group->spk[lid] = 0;
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->m[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->r[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->theta[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (1.00000000000000000e+00f);
                group->a[lid] = initVal;
            }
             {
                group->inSynInSyn0[lid] = 0.000000000e+00f;
                for(unsigned int d = 0; d < 3; d++) {
                    group->denDelayInSyn0[(d * group->numNeurons) + lid] = 0.000000000e+00f;
                }
                if(lid == 0) {
                    *group->denDelayPtrInSyn0 = 0;
                }
            }
             {
                group->inSynInSyn1[lid] = 0.000000000e+00f;
                group->denDelayInSyn1[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn1 = 0;
                }
            }
            // current source variables
        }
    }
    // merged2
    if(id >= 2304 && id < 3936) {
        struct MergedNeuronInitGroup2 *group = &d_mergedNeuronInitGroup2[0]; 
        const unsigned int lid = id - 2304;
        // only do this for existing neurons
        if(lid < group->numNeurons) {
            if(lid == 0) {
                group->spkCnt[0] = 0;
            }
            group->spk[lid] = 0;
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->m[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->r[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->theta[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (1.00000000000000000e+00f);
                group->a[lid] = initVal;
            }
             {
                group->inSynInSyn0[lid] = 0.000000000e+00f;
                group->denDelayInSyn0[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn0 = 0;
                }
            }
             {
                group->inSynInSyn1[lid] = 0.000000000e+00f;
                group->denDelayInSyn1[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn1 = 0;
                }
            }
             {
                group->inSynInSyn2[lid] = 0.000000000e+00f;
                for(unsigned int d = 0; d < 2; d++) {
                    group->denDelayInSyn2[(d * group->numNeurons) + lid] = 0.000000000e+00f;
                }
                if(lid == 0) {
                    *group->denDelayPtrInSyn2 = 0;
                }
            }
            // current source variables
        }
    }
    // merged3
    if(id >= 3936 && id < 5088) {
        unsigned int lo = 0;
        unsigned int hi = 2;
        while(lo < hi)
         {
            const unsigned int mid = (lo + hi) / 2;
            if(id < d_mergedNeuronInitGroupStartID3[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        struct MergedNeuronInitGroup3 *group = &d_mergedNeuronInitGroup3[lo - 1]; 
        const unsigned int groupStartID = d_mergedNeuronInitGroupStartID3[lo - 1];
        const unsigned int lid = id - groupStartID;
        // only do this for existing neurons
        if(lid < group->numNeurons) {
            if(lid == 0) {
                group->spkCnt[0] = 0;
            }
            group->spk[lid] = 0;
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->m[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->r[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->theta[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (1.00000000000000000e+00f);
                group->a[lid] = initVal;
            }
             {
                group->inSynInSyn0[lid] = 0.000000000e+00f;
                group->denDelayInSyn0[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn0 = 0;
                }
            }
             {
                group->inSynInSyn1[lid] = 0.000000000e+00f;
                group->denDelayInSyn1[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn1 = 0;
                }
            }
             {
                group->inSynInSyn2[lid] = 0.000000000e+00f;
                group->denDelayInSyn2[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn2 = 0;
                }
            }
             {
                group->inSynInSyn3[lid] = 0.000000000e+00f;
                group->denDelayInSyn3[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn3 = 0;
                }
            }
            // current source variables
        }
    }
    // merged4
    if(id >= 5088 && id < 7296) {
        struct MergedNeuronInitGroup4 *group = &d_mergedNeuronInitGroup4[0]; 
        const unsigned int lid = id - 5088;
        // only do this for existing neurons
        if(lid < group->numNeurons) {
            if(lid == 0) {
                group->spkCnt[0] = 0;
            }
            group->spk[lid] = 0;
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->m[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->r[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->theta[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (1.00000000000000000e+00f);
                group->a[lid] = initVal;
            }
             {
                group->inSynInSyn0[lid] = 0.000000000e+00f;
                group->denDelayInSyn0[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn0 = 0;
                }
            }
             {
                group->inSynInSyn1[lid] = 0.000000000e+00f;
                for(unsigned int d = 0; d < 2; d++) {
                    group->denDelayInSyn1[(d * group->numNeurons) + lid] = 0.000000000e+00f;
                }
                if(lid == 0) {
                    *group->denDelayPtrInSyn1 = 0;
                }
            }
            // current source variables
        }
    }
    // merged5
    if(id >= 7296 && id < 7968) {
        struct MergedNeuronInitGroup5 *group = &d_mergedNeuronInitGroup5[0]; 
        const unsigned int lid = id - 7296;
        // only do this for existing neurons
        if(lid < group->numNeurons) {
            if(lid == 0) {
                group->spkCnt[0] = 0;
            }
            group->spk[lid] = 0;
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->m[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->r[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->theta[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (1.00000000000000000e+00f);
                group->a[lid] = initVal;
            }
             {
                group->inSynInSyn0[lid] = 0.000000000e+00f;
                group->denDelayInSyn0[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn0 = 0;
                }
            }
             {
                group->inSynInSyn1[lid] = 0.000000000e+00f;
                group->denDelayInSyn1[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn1 = 0;
                }
            }
             {
                group->inSynInSyn2[lid] = 0.000000000e+00f;
                group->denDelayInSyn2[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn2 = 0;
                }
            }
             {
                group->inSynInSyn3[lid] = 0.000000000e+00f;
                group->denDelayInSyn3[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn3 = 0;
                }
            }
             {
                group->inSynInSyn4[lid] = 0.000000000e+00f;
                for(unsigned int d = 0; d < 2; d++) {
                    group->denDelayInSyn4[(d * group->numNeurons) + lid] = 0.000000000e+00f;
                }
                if(lid == 0) {
                    *group->denDelayPtrInSyn4 = 0;
                }
            }
            // current source variables
        }
    }
    // merged6
    if(id >= 7968 && id < 10080) {
        struct MergedNeuronInitGroup6 *group = &d_mergedNeuronInitGroup6[0]; 
        const unsigned int lid = id - 7968;
        // only do this for existing neurons
        if(lid < group->numNeurons) {
            if(lid == 0) {
                group->spkCnt[0] = 0;
            }
            group->spk[lid] = 0;
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->m[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->r[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->theta[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (1.00000000000000000e+00f);
                group->a[lid] = initVal;
            }
             {
                group->inSynInSyn0[lid] = 0.000000000e+00f;
                for(unsigned int d = 0; d < 3; d++) {
                    group->denDelayInSyn0[(d * group->numNeurons) + lid] = 0.000000000e+00f;
                }
                if(lid == 0) {
                    *group->denDelayPtrInSyn0 = 0;
                }
            }
             {
                group->inSynInSyn1[lid] = 0.000000000e+00f;
                group->denDelayInSyn1[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn1 = 0;
                }
            }
             {
                group->inSynInSyn2[lid] = 0.000000000e+00f;
                group->denDelayInSyn2[lid] = 0.000000000e+00f;
                if(lid == 0) {
                    *group->denDelayPtrInSyn2 = 0;
                }
            }
             {
                group->inSynInSyn3[lid] = 0.000000000e+00f;
                for(unsigned int d = 0; d < 2; d++) {
                    group->denDelayInSyn3[(d * group->numNeurons) + lid] = 0.000000000e+00f;
                }
                if(lid == 0) {
                    *group->denDelayPtrInSyn3 = 0;
                }
            }
            // current source variables
        }
    }
    // merged7
    if(id >= 10080 && id < 12192) {
        struct MergedNeuronInitGroup7 *group = &d_mergedNeuronInitGroup7[0]; 
        const unsigned int lid = id - 10080;
        // only do this for existing neurons
        if(lid < group->numNeurons) {
            if(lid == 0) {
                group->spkCnt[0] = 0;
            }
            group->spk[lid] = 0;
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->r[lid] = initVal;
            }
             {
                scalar initVal;
                initVal = (0.00000000000000000e+00f);
                group->input[lid] = initVal;
            }
            // current source variables
        }
    }
    
    // ------------------------------------------------------------------------
    // Synapse groups
    // merged0
    if(id >= 12192 && id < 43680) {
        unsigned int lo = 0;
        unsigned int hi = 28;
        while(lo < hi)
         {
            const unsigned int mid = (lo + hi) / 2;
            if(id < d_mergedSynapseInitGroupStartID0[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        struct MergedSynapseInitGroup0 *group = &d_mergedSynapseInitGroup0[lo - 1]; 
        const unsigned int groupStartID = d_mergedSynapseInitGroupStartID0[lo - 1];
        const unsigned int lid = id - groupStartID;
        if(lid < group->numTrgNeurons) {
            for(unsigned int i = 0; i < group->numSrcNeurons; i++) {
                 {
                    scalar initVal;
                    initVal = (0.00000000000000000e+00f);
                    group->w[(i * group->rowStride) + lid] = initVal;
                }
                 {
                    bool initVal;
                    initVal = (0.00000000000000000e+00f);
                    group->active[(i * group->rowStride) + lid] = initVal;
                }
                 {
                    uint8_t initVal;
                    initVal = group->constantdelay;
                    group->delay[(i * group->rowStride) + lid] = initVal;
                }
            }
        }
    }
    
    // ------------------------------------------------------------------------
    // Custom update groups
    
    // ------------------------------------------------------------------------
    // Custom WU update groups
    
    // ------------------------------------------------------------------------
    // Synapse groups with sparse connectivity
    
}
void initialize() {
    unsigned long long deviceRNGSeed = 0;
     {
        const dim3 threads(96, 1);
        const dim3 grid(455, 1);
        initializeKernel<<<grid, threads>>>(deviceRNGSeed);
        CHECK_CUDA_ERRORS(cudaPeekAtLastError());
    }
}

void initializeSparse() {
    copyStateToDevice(true);
    copyConnectivityToDevice(true);
    
}
