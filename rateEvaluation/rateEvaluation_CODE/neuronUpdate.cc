#include "definitionsInternal.h"
#include "supportCode.h"

struct MergedNeuronUpdateGroup0
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
struct MergedNeuronUpdateGroup1
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
struct MergedNeuronUpdateGroup2
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
struct MergedNeuronUpdateGroup3
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
struct MergedNeuronUpdateGroup4
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
struct MergedNeuronUpdateGroup5
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
struct MergedNeuronUpdateGroup6
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
struct MergedNeuronUpdateGroup7
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
struct MergedNeuronUpdateGroup8
 {
    unsigned int* spkCnt;
    unsigned int* spk;
    scalar* r;
    scalar* input;
    unsigned int numNeurons;
    
}
;
struct MergedNeuronSpikeQueueUpdateGroup0
 {
    unsigned int* spkCnt;
    
}
;
__device__ __constant__ MergedNeuronSpikeQueueUpdateGroup0 d_mergedNeuronSpikeQueueUpdateGroup0[9];
void pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(unsigned int idx, unsigned int* spkCnt) {
    MergedNeuronSpikeQueueUpdateGroup0 group = {spkCnt, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronSpikeQueueUpdateGroup0, &group, sizeof(MergedNeuronSpikeQueueUpdateGroup0), idx * sizeof(MergedNeuronSpikeQueueUpdateGroup0)));
}
__device__ __constant__ MergedNeuronUpdateGroup0 d_mergedNeuronUpdateGroup0[1];
void pushMergedNeuronUpdateGroup0ToDevice(unsigned int idx, unsigned int* spkCnt, unsigned int* spk, scalar* m, scalar* r, scalar* theta, scalar* a, float* inSynInSyn0, float* denDelayInSyn0, unsigned int* denDelayPtrInSyn0, float* inSynInSyn1, float* denDelayInSyn1, unsigned int* denDelayPtrInSyn1, unsigned int numNeurons) {
    MergedNeuronUpdateGroup0 group = {spkCnt, spk, m, r, theta, a, inSynInSyn0, denDelayInSyn0, denDelayPtrInSyn0, inSynInSyn1, denDelayInSyn1, denDelayPtrInSyn1, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup0, &group, sizeof(MergedNeuronUpdateGroup0), idx * sizeof(MergedNeuronUpdateGroup0)));
}
__device__ __constant__ MergedNeuronUpdateGroup1 d_mergedNeuronUpdateGroup1[1];
void pushMergedNeuronUpdateGroup1ToDevice(unsigned int idx, unsigned int* spkCnt, unsigned int* spk, scalar* m, scalar* r, scalar* theta, scalar* a, float* inSynInSyn0, float* denDelayInSyn0, unsigned int* denDelayPtrInSyn0, float* inSynInSyn1, float* denDelayInSyn1, unsigned int* denDelayPtrInSyn1, float* inSynInSyn2, float* denDelayInSyn2, unsigned int* denDelayPtrInSyn2, unsigned int numNeurons) {
    MergedNeuronUpdateGroup1 group = {spkCnt, spk, m, r, theta, a, inSynInSyn0, denDelayInSyn0, denDelayPtrInSyn0, inSynInSyn1, denDelayInSyn1, denDelayPtrInSyn1, inSynInSyn2, denDelayInSyn2, denDelayPtrInSyn2, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup1, &group, sizeof(MergedNeuronUpdateGroup1), idx * sizeof(MergedNeuronUpdateGroup1)));
}
__device__ __constant__ MergedNeuronUpdateGroup2 d_mergedNeuronUpdateGroup2[1];
void pushMergedNeuronUpdateGroup2ToDevice(unsigned int idx, unsigned int* denDelayPtrInSyn0, unsigned int* denDelayPtrInSyn3, float* denDelayInSyn3, float* inSynInSyn3, unsigned int* denDelayPtrInSyn2, float* denDelayInSyn2, float* inSynInSyn2, unsigned int* denDelayPtrInSyn1, float* denDelayInSyn1, float* inSynInSyn1, float* denDelayInSyn0, float* inSynInSyn0, scalar* a, scalar* theta, scalar* r, scalar* m, unsigned int* spk, unsigned int* spkCnt, unsigned int numNeurons) {
    MergedNeuronUpdateGroup2 group = {denDelayPtrInSyn0, denDelayPtrInSyn3, denDelayInSyn3, inSynInSyn3, denDelayPtrInSyn2, denDelayInSyn2, inSynInSyn2, denDelayPtrInSyn1, denDelayInSyn1, inSynInSyn1, denDelayInSyn0, inSynInSyn0, a, theta, r, m, spk, spkCnt, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup2, &group, sizeof(MergedNeuronUpdateGroup2), idx * sizeof(MergedNeuronUpdateGroup2)));
}
__device__ __constant__ MergedNeuronUpdateGroup3 d_mergedNeuronUpdateGroup3[1];
void pushMergedNeuronUpdateGroup3ToDevice(unsigned int idx, float* denDelayInSyn1, unsigned int* denDelayPtrInSyn4, float* denDelayInSyn4, float* inSynInSyn4, unsigned int* denDelayPtrInSyn3, float* denDelayInSyn3, float* inSynInSyn3, unsigned int* denDelayPtrInSyn2, float* denDelayInSyn2, float* inSynInSyn2, unsigned int* denDelayPtrInSyn1, float* inSynInSyn1, unsigned int* denDelayPtrInSyn0, float* denDelayInSyn0, float* inSynInSyn0, scalar* a, scalar* theta, scalar* r, scalar* m, unsigned int* spk, unsigned int* spkCnt, unsigned int numNeurons) {
    MergedNeuronUpdateGroup3 group = {denDelayInSyn1, denDelayPtrInSyn4, denDelayInSyn4, inSynInSyn4, denDelayPtrInSyn3, denDelayInSyn3, inSynInSyn3, denDelayPtrInSyn2, denDelayInSyn2, inSynInSyn2, denDelayPtrInSyn1, inSynInSyn1, denDelayPtrInSyn0, denDelayInSyn0, inSynInSyn0, a, theta, r, m, spk, spkCnt, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup3, &group, sizeof(MergedNeuronUpdateGroup3), idx * sizeof(MergedNeuronUpdateGroup3)));
}
__device__ __constant__ MergedNeuronUpdateGroup4 d_mergedNeuronUpdateGroup4[1];
void pushMergedNeuronUpdateGroup4ToDevice(unsigned int idx, unsigned int* denDelayPtrInSyn0, unsigned int* denDelayPtrInSyn3, float* denDelayInSyn3, float* inSynInSyn3, unsigned int* denDelayPtrInSyn2, float* denDelayInSyn2, float* inSynInSyn2, unsigned int* denDelayPtrInSyn1, float* denDelayInSyn1, float* inSynInSyn1, float* denDelayInSyn0, float* inSynInSyn0, scalar* a, scalar* theta, scalar* r, scalar* m, unsigned int* spk, unsigned int* spkCnt, unsigned int numNeurons) {
    MergedNeuronUpdateGroup4 group = {denDelayPtrInSyn0, denDelayPtrInSyn3, denDelayInSyn3, inSynInSyn3, denDelayPtrInSyn2, denDelayInSyn2, inSynInSyn2, denDelayPtrInSyn1, denDelayInSyn1, inSynInSyn1, denDelayInSyn0, inSynInSyn0, a, theta, r, m, spk, spkCnt, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup4, &group, sizeof(MergedNeuronUpdateGroup4), idx * sizeof(MergedNeuronUpdateGroup4)));
}
__device__ __constant__ MergedNeuronUpdateGroup5 d_mergedNeuronUpdateGroup5[1];
void pushMergedNeuronUpdateGroup5ToDevice(unsigned int idx, unsigned int* denDelayPtrInSyn0, unsigned int* denDelayPtrInSyn3, float* denDelayInSyn3, float* inSynInSyn3, unsigned int* denDelayPtrInSyn2, float* denDelayInSyn2, float* inSynInSyn2, unsigned int* denDelayPtrInSyn1, float* denDelayInSyn1, float* inSynInSyn1, float* denDelayInSyn0, float* inSynInSyn0, scalar* a, scalar* theta, scalar* r, scalar* m, unsigned int* spk, unsigned int* spkCnt, unsigned int numNeurons) {
    MergedNeuronUpdateGroup5 group = {denDelayPtrInSyn0, denDelayPtrInSyn3, denDelayInSyn3, inSynInSyn3, denDelayPtrInSyn2, denDelayInSyn2, inSynInSyn2, denDelayPtrInSyn1, denDelayInSyn1, inSynInSyn1, denDelayInSyn0, inSynInSyn0, a, theta, r, m, spk, spkCnt, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup5, &group, sizeof(MergedNeuronUpdateGroup5), idx * sizeof(MergedNeuronUpdateGroup5)));
}
__device__ __constant__ MergedNeuronUpdateGroup6 d_mergedNeuronUpdateGroup6[1];
void pushMergedNeuronUpdateGroup6ToDevice(unsigned int idx, unsigned int* denDelayPtrInSyn0, unsigned int* denDelayPtrInSyn3, float* denDelayInSyn3, float* inSynInSyn3, unsigned int* denDelayPtrInSyn2, float* denDelayInSyn2, float* inSynInSyn2, unsigned int* denDelayPtrInSyn1, float* denDelayInSyn1, float* inSynInSyn1, float* denDelayInSyn0, float* inSynInSyn0, scalar* a, scalar* theta, scalar* r, scalar* m, unsigned int* spk, unsigned int* spkCnt, unsigned int numNeurons) {
    MergedNeuronUpdateGroup6 group = {denDelayPtrInSyn0, denDelayPtrInSyn3, denDelayInSyn3, inSynInSyn3, denDelayPtrInSyn2, denDelayInSyn2, inSynInSyn2, denDelayPtrInSyn1, denDelayInSyn1, inSynInSyn1, denDelayInSyn0, inSynInSyn0, a, theta, r, m, spk, spkCnt, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup6, &group, sizeof(MergedNeuronUpdateGroup6), idx * sizeof(MergedNeuronUpdateGroup6)));
}
__device__ __constant__ MergedNeuronUpdateGroup7 d_mergedNeuronUpdateGroup7[1];
void pushMergedNeuronUpdateGroup7ToDevice(unsigned int idx, unsigned int* spkCnt, unsigned int* spk, scalar* m, scalar* r, scalar* theta, scalar* a, float* inSynInSyn0, float* denDelayInSyn0, unsigned int* denDelayPtrInSyn0, float* inSynInSyn1, float* denDelayInSyn1, unsigned int* denDelayPtrInSyn1, unsigned int numNeurons) {
    MergedNeuronUpdateGroup7 group = {spkCnt, spk, m, r, theta, a, inSynInSyn0, denDelayInSyn0, denDelayPtrInSyn0, inSynInSyn1, denDelayInSyn1, denDelayPtrInSyn1, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup7, &group, sizeof(MergedNeuronUpdateGroup7), idx * sizeof(MergedNeuronUpdateGroup7)));
}
__device__ __constant__ MergedNeuronUpdateGroup8 d_mergedNeuronUpdateGroup8[1];
void pushMergedNeuronUpdateGroup8ToDevice(unsigned int idx, unsigned int* spkCnt, unsigned int* spk, scalar* r, scalar* input, unsigned int numNeurons) {
    MergedNeuronUpdateGroup8 group = {spkCnt, spk, r, input, numNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup8, &group, sizeof(MergedNeuronUpdateGroup8), idx * sizeof(MergedNeuronUpdateGroup8)));
}
// ------------------------------------------------------------------------
// merged extra global parameter functions
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// merged extra global parameter functions
// ------------------------------------------------------------------------
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID0[] = {0, };
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID1[] = {1696, };
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID2[] = {3296, };
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID3[] = {3840, };
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID4[] = {4448, };
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID5[] = {6496, };
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID6[] = {7008, };
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID7[] = {7520, };
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID8[] = {9664, };

extern "C" __global__ void neuronSpikeQueueUpdateKernel() {
    const unsigned int id = 32 * blockIdx.x + threadIdx.x;
    if(id < 9) {
        struct MergedNeuronSpikeQueueUpdateGroup0 *group = &d_mergedNeuronSpikeQueueUpdateGroup0[id - 0]; 
        group->spkCnt[0] = 0;
    }
}

extern "C" __global__ void updateNeuronsKernel(float t)
 {
    const unsigned int id = 32 * blockIdx.x + threadIdx.x; 
    __syncthreads();
    // merged0
    if(id < 1696) {
        struct MergedNeuronUpdateGroup0 *group = &d_mergedNeuronUpdateGroup0[0]; 
        const unsigned int lid = id - 0;
        
        if(lid < group->numNeurons) {
            scalar lm = group->m[lid];
            scalar lr = group->r[lid];
            scalar ltheta = group->theta[lid];
            scalar la = group->a[lid];
            
            scalar excFF = 0;
            scalar excFB = 0;
            scalar inh = 0;
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn0[lid];
                float *denDelayFront = &group->denDelayInSyn0[(*group->denDelayPtrInSyn0 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn0[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn1[lid];
                float *denDelayFront = &group->denDelayInSyn1[(*group->denDelayPtrInSyn1 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn1[lid] = linSyn;
            }
            // calculate membrane potential
            lm += ( la * ( excFF + excFB - inh - ltheta ) - lm ) / 10.f;
            lr = min(3.f, max(.0f, lm));
            
            group->m[lid] = lm;
            group->r[lid] = lr;
            group->theta[lid] = ltheta;
            group->a[lid] = la;
        }
        __syncthreads();
    }
    // merged1
    if(id >= 1696 && id < 3296) {
        struct MergedNeuronUpdateGroup1 *group = &d_mergedNeuronUpdateGroup1[0]; 
        const unsigned int lid = id - 1696;
        
        if(lid < group->numNeurons) {
            scalar lm = group->m[lid];
            scalar lr = group->r[lid];
            scalar ltheta = group->theta[lid];
            scalar la = group->a[lid];
            
            scalar excFF = 0;
            scalar excFB = 0;
            scalar inh = 0;
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn0[lid];
                float *denDelayFront = &group->denDelayInSyn0[(*group->denDelayPtrInSyn0 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn0[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn1[lid];
                float *denDelayFront = &group->denDelayInSyn1[(*group->denDelayPtrInSyn1 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn1[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn2[lid];
                float *denDelayFront = &group->denDelayInSyn2[(*group->denDelayPtrInSyn2 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn2[lid] = linSyn;
            }
            // calculate membrane potential
            lm += ( la * ( excFF + excFB - inh - ltheta ) - lm ) / 10.f;
            lr = min(3.f, max(.0f, lm));
            
            group->m[lid] = lm;
            group->r[lid] = lr;
            group->theta[lid] = ltheta;
            group->a[lid] = la;
        }
        __syncthreads();
    }
    // merged2
    if(id >= 3296 && id < 3840) {
        struct MergedNeuronUpdateGroup2 *group = &d_mergedNeuronUpdateGroup2[0]; 
        const unsigned int lid = id - 3296;
        
        if(lid < group->numNeurons) {
            scalar lm = group->m[lid];
            scalar lr = group->r[lid];
            scalar ltheta = group->theta[lid];
            scalar la = group->a[lid];
            
            scalar excFF = 0;
            scalar excFB = 0;
            scalar inh = 0;
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn0[lid];
                float *denDelayFront = &group->denDelayInSyn0[(*group->denDelayPtrInSyn0 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn0[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn1[lid];
                float *denDelayFront = &group->denDelayInSyn1[(*group->denDelayPtrInSyn1 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn1[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn2[lid];
                float *denDelayFront = &group->denDelayInSyn2[(*group->denDelayPtrInSyn2 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFB += linSyn; linSyn = 0;
                
                group->inSynInSyn2[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn3[lid];
                float *denDelayFront = &group->denDelayInSyn3[(*group->denDelayPtrInSyn3 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn3[lid] = linSyn;
            }
            // calculate membrane potential
            lm += ( la * ( excFF + excFB - inh - ltheta ) - lm ) / 10.f;
            lr = max(.0f, lm);
            
            group->m[lid] = lm;
            group->r[lid] = lr;
            group->theta[lid] = ltheta;
            group->a[lid] = la;
        }
        __syncthreads();
    }
    // merged3
    if(id >= 3840 && id < 4448) {
        struct MergedNeuronUpdateGroup3 *group = &d_mergedNeuronUpdateGroup3[0]; 
        const unsigned int lid = id - 3840;
        
        if(lid < group->numNeurons) {
            scalar lm = group->m[lid];
            scalar lr = group->r[lid];
            scalar ltheta = group->theta[lid];
            scalar la = group->a[lid];
            
            scalar excFF = 0;
            scalar excFB = 0;
            scalar inh = 0;
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn0[lid];
                float *denDelayFront = &group->denDelayInSyn0[(*group->denDelayPtrInSyn0 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFB += linSyn; linSyn = 0;
                
                group->inSynInSyn0[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn1[lid];
                float *denDelayFront = &group->denDelayInSyn1[(*group->denDelayPtrInSyn1 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn1[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn2[lid];
                float *denDelayFront = &group->denDelayInSyn2[(*group->denDelayPtrInSyn2 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn2[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn3[lid];
                float *denDelayFront = &group->denDelayInSyn3[(*group->denDelayPtrInSyn3 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn3[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn4[lid];
                float *denDelayFront = &group->denDelayInSyn4[(*group->denDelayPtrInSyn4 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn4[lid] = linSyn;
            }
            // calculate membrane potential
            lm += ( la * ( excFF + excFB - inh - ltheta ) - lm ) / 10.f;
            lr = max(.0f, lm);
            
            group->m[lid] = lm;
            group->r[lid] = lr;
            group->theta[lid] = ltheta;
            group->a[lid] = la;
        }
        __syncthreads();
    }
    // merged4
    if(id >= 4448 && id < 6496) {
        struct MergedNeuronUpdateGroup4 *group = &d_mergedNeuronUpdateGroup4[0]; 
        const unsigned int lid = id - 4448;
        
        if(lid < group->numNeurons) {
            scalar lm = group->m[lid];
            scalar lr = group->r[lid];
            scalar ltheta = group->theta[lid];
            scalar la = group->a[lid];
            
            scalar excFF = 0;
            scalar excFB = 0;
            scalar inh = 0;
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn0[lid];
                float *denDelayFront = &group->denDelayInSyn0[(*group->denDelayPtrInSyn0 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn0[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn1[lid];
                float *denDelayFront = &group->denDelayInSyn1[(*group->denDelayPtrInSyn1 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFB += linSyn; linSyn = 0;
                
                group->inSynInSyn1[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn2[lid];
                float *denDelayFront = &group->denDelayInSyn2[(*group->denDelayPtrInSyn2 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn2[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn3[lid];
                float *denDelayFront = &group->denDelayInSyn3[(*group->denDelayPtrInSyn3 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn3[lid] = linSyn;
            }
            // calculate membrane potential
            lm += ( la * ( excFF + excFB - inh - ltheta ) - lm ) / 10.f;
            lr = min(3.f, max(.0f, lm));
            
            group->m[lid] = lm;
            group->r[lid] = lr;
            group->theta[lid] = ltheta;
            group->a[lid] = la;
        }
        __syncthreads();
    }
    // merged5
    if(id >= 6496 && id < 7008) {
        struct MergedNeuronUpdateGroup5 *group = &d_mergedNeuronUpdateGroup5[0]; 
        const unsigned int lid = id - 6496;
        
        if(lid < group->numNeurons) {
            scalar lm = group->m[lid];
            scalar lr = group->r[lid];
            scalar ltheta = group->theta[lid];
            scalar la = group->a[lid];
            
            scalar excFF = 0;
            scalar excFB = 0;
            scalar inh = 0;
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn0[lid];
                float *denDelayFront = &group->denDelayInSyn0[(*group->denDelayPtrInSyn0 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn0[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn1[lid];
                float *denDelayFront = &group->denDelayInSyn1[(*group->denDelayPtrInSyn1 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn1[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn2[lid];
                float *denDelayFront = &group->denDelayInSyn2[(*group->denDelayPtrInSyn2 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFB += linSyn; linSyn = 0;
                
                group->inSynInSyn2[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn3[lid];
                float *denDelayFront = &group->denDelayInSyn3[(*group->denDelayPtrInSyn3 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn3[lid] = linSyn;
            }
            // calculate membrane potential
            lm += ( la * ( excFF + excFB - inh - ltheta ) - lm ) / 10.f;
            lr = max(.0f, lm);
            
            group->m[lid] = lm;
            group->r[lid] = lr;
            group->theta[lid] = ltheta;
            group->a[lid] = la;
        }
        __syncthreads();
    }
    // merged6
    if(id >= 7008 && id < 7520) {
        struct MergedNeuronUpdateGroup6 *group = &d_mergedNeuronUpdateGroup6[0]; 
        const unsigned int lid = id - 7008;
        
        if(lid < group->numNeurons) {
            scalar lm = group->m[lid];
            scalar lr = group->r[lid];
            scalar ltheta = group->theta[lid];
            scalar la = group->a[lid];
            
            scalar excFF = 0;
            scalar excFB = 0;
            scalar inh = 0;
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn0[lid];
                float *denDelayFront = &group->denDelayInSyn0[(*group->denDelayPtrInSyn0 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn0[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn1[lid];
                float *denDelayFront = &group->denDelayInSyn1[(*group->denDelayPtrInSyn1 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn1[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn2[lid];
                float *denDelayFront = &group->denDelayInSyn2[(*group->denDelayPtrInSyn2 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn2[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn3[lid];
                float *denDelayFront = &group->denDelayInSyn3[(*group->denDelayPtrInSyn3 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn3[lid] = linSyn;
            }
            // calculate membrane potential
            lm += ( la * ( excFF + excFB - inh - ltheta ) - lm ) / 10.f;
            lr = max(.0f, lm);
            
            group->m[lid] = lm;
            group->r[lid] = lr;
            group->theta[lid] = ltheta;
            group->a[lid] = la;
        }
        __syncthreads();
    }
    // merged7
    if(id >= 7520 && id < 9664) {
        struct MergedNeuronUpdateGroup7 *group = &d_mergedNeuronUpdateGroup7[0]; 
        const unsigned int lid = id - 7520;
        
        if(lid < group->numNeurons) {
            scalar lm = group->m[lid];
            scalar lr = group->r[lid];
            scalar ltheta = group->theta[lid];
            scalar la = group->a[lid];
            
            scalar excFF = 0;
            scalar excFB = 0;
            scalar inh = 0;
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn0[lid];
                float *denDelayFront = &group->denDelayInSyn0[(*group->denDelayPtrInSyn0 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                excFF += linSyn; linSyn = 0;
                
                group->inSynInSyn0[lid] = linSyn;
            }
             {
                // pull inSyn values in a coalesced access
                float linSyn = group->inSynInSyn1[lid];
                float *denDelayFront = &group->denDelayInSyn1[(*group->denDelayPtrInSyn1 * group->numNeurons) + lid];
                linSyn += *denDelayFront;
                *denDelayFront = 0.000000000e+00f;
                inh += linSyn; linSyn = 0;
                
                group->inSynInSyn1[lid] = linSyn;
            }
            // calculate membrane potential
            lm += ( la * ( excFF + excFB - inh - ltheta ) - lm ) / 10.f;
            lr = min(3.f, max(.0f, lm));
            
            group->m[lid] = lm;
            group->r[lid] = lr;
            group->theta[lid] = ltheta;
            group->a[lid] = la;
        }
        __syncthreads();
    }
    // merged8
    if(id >= 9664 && id < 11712) {
        struct MergedNeuronUpdateGroup8 *group = &d_mergedNeuronUpdateGroup8[0]; 
        const unsigned int lid = id - 9664;
        
        if(lid < group->numNeurons) {
            scalar lr = group->r[lid];
            scalar linput = group->input[lid];
            
            // calculate membrane potential
            lr += (linput - lr) / 10.f;
            
            group->r[lid] = lr;
            group->input[lid] = linput;
        }
        __syncthreads();
    }
}
void updateNeurons(float t) {
     {
        const dim3 threads(32, 1);
        const dim3 grid(1, 1);
        neuronSpikeQueueUpdateKernel<<<grid, threads>>>();
        CHECK_CUDA_ERRORS(cudaPeekAtLastError());
    }
     {
        const dim3 threads(32, 1);
        const dim3 grid(366, 1);
        updateNeuronsKernel<<<grid, threads>>>(t);
        CHECK_CUDA_ERRORS(cudaPeekAtLastError());
    }
}
