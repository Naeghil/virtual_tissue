#include "definitionsInternal.h"
#include "supportCode.h"

struct MergedSynapseDendriticDelayUpdateGroup0
 {
    unsigned int* denDelayPtr;
    
}
;
struct MergedSynapseDendriticDelayUpdateGroup1
 {
    unsigned int* denDelayPtr;
    
}
;
struct MergedSynapseDendriticDelayUpdateGroup2
 {
    unsigned int* denDelayPtr;
    
}
;
struct MergedSynapseDynamicsGroup0
 {
    float* denDelay;
    unsigned int* denDelayPtr;
    scalar* rPre;
    scalar* w;
    bool* active;
    uint8_t* delay;
    unsigned int rowStride;
    unsigned int numSrcNeurons;
    unsigned int numTrgNeurons;
    
}
;
struct MergedSynapseDynamicsGroup1
 {
    float* denDelay;
    unsigned int* denDelayPtr;
    scalar* rPre;
    scalar* w;
    bool* active;
    uint8_t* delay;
    unsigned int rowStride;
    unsigned int numSrcNeurons;
    unsigned int numTrgNeurons;
    
}
;
struct MergedSynapseDynamicsGroup2
 {
    float* denDelay;
    unsigned int* denDelayPtr;
    scalar* rPre;
    scalar* w;
    bool* active;
    uint8_t* delay;
    unsigned int rowStride;
    unsigned int numSrcNeurons;
    unsigned int numTrgNeurons;
    
}
;
__device__ __constant__ MergedSynapseDendriticDelayUpdateGroup0 d_mergedSynapseDendriticDelayUpdateGroup0[5];
void pushMergedSynapseDendriticDelayUpdateGroup0ToDevice(unsigned int idx, unsigned int* denDelayPtr) {
    MergedSynapseDendriticDelayUpdateGroup0 group = {denDelayPtr, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedSynapseDendriticDelayUpdateGroup0, &group, sizeof(MergedSynapseDendriticDelayUpdateGroup0), idx * sizeof(MergedSynapseDendriticDelayUpdateGroup0)));
}
__device__ __constant__ MergedSynapseDendriticDelayUpdateGroup1 d_mergedSynapseDendriticDelayUpdateGroup1[2];
void pushMergedSynapseDendriticDelayUpdateGroup1ToDevice(unsigned int idx, unsigned int* denDelayPtr) {
    MergedSynapseDendriticDelayUpdateGroup1 group = {denDelayPtr, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedSynapseDendriticDelayUpdateGroup1, &group, sizeof(MergedSynapseDendriticDelayUpdateGroup1), idx * sizeof(MergedSynapseDendriticDelayUpdateGroup1)));
}
__device__ __constant__ MergedSynapseDendriticDelayUpdateGroup2 d_mergedSynapseDendriticDelayUpdateGroup2[21];
void pushMergedSynapseDendriticDelayUpdateGroup2ToDevice(unsigned int idx, unsigned int* denDelayPtr) {
    MergedSynapseDendriticDelayUpdateGroup2 group = {denDelayPtr, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedSynapseDendriticDelayUpdateGroup2, &group, sizeof(MergedSynapseDendriticDelayUpdateGroup2), idx * sizeof(MergedSynapseDendriticDelayUpdateGroup2)));
}
__device__ __constant__ MergedSynapseDynamicsGroup0 d_mergedSynapseDynamicsGroup0[21];
void pushMergedSynapseDynamicsGroup0ToDevice(unsigned int idx, float* denDelay, unsigned int* denDelayPtr, scalar* rPre, scalar* w, bool* active, uint8_t* delay, unsigned int rowStride, unsigned int numSrcNeurons, unsigned int numTrgNeurons) {
    MergedSynapseDynamicsGroup0 group = {denDelay, denDelayPtr, rPre, w, active, delay, rowStride, numSrcNeurons, numTrgNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedSynapseDynamicsGroup0, &group, sizeof(MergedSynapseDynamicsGroup0), idx * sizeof(MergedSynapseDynamicsGroup0)));
}
__device__ __constant__ MergedSynapseDynamicsGroup1 d_mergedSynapseDynamicsGroup1[2];
void pushMergedSynapseDynamicsGroup1ToDevice(unsigned int idx, float* denDelay, unsigned int* denDelayPtr, scalar* rPre, scalar* w, bool* active, uint8_t* delay, unsigned int rowStride, unsigned int numSrcNeurons, unsigned int numTrgNeurons) {
    MergedSynapseDynamicsGroup1 group = {denDelay, denDelayPtr, rPre, w, active, delay, rowStride, numSrcNeurons, numTrgNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedSynapseDynamicsGroup1, &group, sizeof(MergedSynapseDynamicsGroup1), idx * sizeof(MergedSynapseDynamicsGroup1)));
}
__device__ __constant__ MergedSynapseDynamicsGroup2 d_mergedSynapseDynamicsGroup2[5];
void pushMergedSynapseDynamicsGroup2ToDevice(unsigned int idx, float* denDelay, unsigned int* denDelayPtr, scalar* rPre, scalar* w, bool* active, uint8_t* delay, unsigned int rowStride, unsigned int numSrcNeurons, unsigned int numTrgNeurons) {
    MergedSynapseDynamicsGroup2 group = {denDelay, denDelayPtr, rPre, w, active, delay, rowStride, numSrcNeurons, numTrgNeurons, };
    CHECK_CUDA_ERRORS(cudaMemcpyToSymbolAsync(d_mergedSynapseDynamicsGroup2, &group, sizeof(MergedSynapseDynamicsGroup2), idx * sizeof(MergedSynapseDynamicsGroup2)));
}
// ------------------------------------------------------------------------
// merged extra global parameter functions
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// merged extra global parameter functions
// ------------------------------------------------------------------------
__device__ __constant__ unsigned int d_mergedSynapseDynamicsGroupStartID0[] = {0, 1083456, 2252832, 3323040, 4492416, 4826592, 6049728, 7169184, 8239392, 8545248, 9664704, 9944640, 10744704, 11555904, 12355968, 12606048, 13451136, 14308032, 15119232, 15372768, 16229664, };
__device__ __constant__ unsigned int d_mergedSynapseDynamicsGroupStartID1[] = {16486752, 19905696, };
__device__ __constant__ unsigned int d_mergedSynapseDynamicsGroupStartID2[] = {23142528, 27476160, 28501824, 32782560, 33707424, };
extern "C" __global__ void synapseDendriticDelayUpdateKernel() {
    const unsigned int id = 32 * blockIdx.x + threadIdx.x;
    // merged0
    if(id < 5) {
        struct MergedSynapseDendriticDelayUpdateGroup0 *group = &d_mergedSynapseDendriticDelayUpdateGroup0[id - 0]; 
        *group->denDelayPtr = (*group->denDelayPtr + 1) % 2;
    }
    // merged1
    if(id >= 5 && id < 7) {
        struct MergedSynapseDendriticDelayUpdateGroup1 *group = &d_mergedSynapseDendriticDelayUpdateGroup1[id - 5]; 
        *group->denDelayPtr = (*group->denDelayPtr + 1) % 3;
    }
    // merged2
    if(id >= 7 && id < 28) {
        struct MergedSynapseDendriticDelayUpdateGroup2 *group = &d_mergedSynapseDendriticDelayUpdateGroup2[id - 7]; 
        *group->denDelayPtr = (*group->denDelayPtr + 1) % 1;
    }
    
}

extern "C" __global__ void updateSynapseDynamicsKernel(float t)
 {
    const unsigned int id = 96 * blockIdx.x + threadIdx.x;
    // merged0
    if(id < 16486752) {
        unsigned int lo = 0;
        unsigned int hi = 21;
        while(lo < hi)
         {
            const unsigned int mid = (lo + hi) / 2;
            if(id < d_mergedSynapseDynamicsGroupStartID0[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        struct MergedSynapseDynamicsGroup0 *group = &d_mergedSynapseDynamicsGroup0[lo - 1]; 
        const unsigned int groupStartID = d_mergedSynapseDynamicsGroupStartID0[lo - 1];
        const unsigned int lid = id - groupStartID;
        if (lid < (group->numSrcNeurons * group->numTrgNeurons)) {
            if (group->active[lid]) atomicAdd(&group->denDelay[(((*group->denDelayPtr + group->delay[lid]) % 1) * group->numTrgNeurons) + (lid % group->rowStride)], group->w[lid]*group->rPre[(lid / group->rowStride)]);
        }
    }
    // merged1
    if(id >= 16486752 && id < 23142528) {
        unsigned int lo = 0;
        unsigned int hi = 2;
        while(lo < hi)
         {
            const unsigned int mid = (lo + hi) / 2;
            if(id < d_mergedSynapseDynamicsGroupStartID1[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        struct MergedSynapseDynamicsGroup1 *group = &d_mergedSynapseDynamicsGroup1[lo - 1]; 
        const unsigned int groupStartID = d_mergedSynapseDynamicsGroupStartID1[lo - 1];
        const unsigned int lid = id - groupStartID;
        if (lid < (group->numSrcNeurons * group->numTrgNeurons)) {
            if (group->active[lid]) atomicAdd(&group->denDelay[(((*group->denDelayPtr + group->delay[lid]) % 3) * group->numTrgNeurons) + (lid % group->rowStride)], group->w[lid]*group->rPre[(lid / group->rowStride)]);
        }
    }
    // merged2
    if(id >= 23142528 && id < 36411456) {
        unsigned int lo = 0;
        unsigned int hi = 5;
        while(lo < hi)
         {
            const unsigned int mid = (lo + hi) / 2;
            if(id < d_mergedSynapseDynamicsGroupStartID2[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        struct MergedSynapseDynamicsGroup2 *group = &d_mergedSynapseDynamicsGroup2[lo - 1]; 
        const unsigned int groupStartID = d_mergedSynapseDynamicsGroupStartID2[lo - 1];
        const unsigned int lid = id - groupStartID;
        if (lid < (group->numSrcNeurons * group->numTrgNeurons)) {
            if (group->active[lid]) atomicAdd(&group->denDelay[(((*group->denDelayPtr + group->delay[lid]) % 2) * group->numTrgNeurons) + (lid % group->rowStride)], group->w[lid]*group->rPre[(lid / group->rowStride)]);
        }
    }
}
void updateSynapses(float t) {
     {
        const dim3 threads(32, 1);
        const dim3 grid(1, 1);
        synapseDendriticDelayUpdateKernel<<<grid, threads>>>();
        CHECK_CUDA_ERRORS(cudaPeekAtLastError());
    }
     {
        const dim3 threads(96, 1);
        const dim3 grid(379286, 1);
        updateSynapseDynamicsKernel<<<grid, threads>>>(t);
        CHECK_CUDA_ERRORS(cudaPeekAtLastError());
    }
}
