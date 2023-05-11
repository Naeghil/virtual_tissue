#ifndef PARAMETERS_H
#define PARAMETERS_H

// DEFINITIONS
// Names
enum Populations {V1L4E, V1L4I, V1L23E, V1L23I, V2L4E, V2L4I, V2L23E, V2L23I, LGN, PMax,}; // All excitatories are even
enum Layers {V1L4, V1L23, V2L4, V2L23, LMax}; // Population/2, LGN is meaningless
const char *PName[PMax] = {"V1L4E", "V1L4I", "V1L23E", "V1L23I", "V2L4E", "V2L4I", "V2L23E", "V2L23I", "LGN"};

// ARCHITECTURAL PARAMETERS
// Population numbers from Table 1a Teichmann, et al., 2021; for each layer there is a square geometry (d1) and a 3D geometry (d2)
const int side[PMax] = {23,23,17,17,13,13,10,10,32};
const int depth[PMax] = {4,1,7,2,10,3,16,5,2};
const float expR[PMax] = {.1, .1, .1, .1, .1, .1, .1, .1, 1.057};

// SYNAPSE PARAMETERS
enum STypes {FF, Lat, FB, STMax,};
/// RF sizes: for meaningless values, 0 is used
const int RF[STMax][LMax] = {{10, 7, 5, 4},  // FF
                             {11, 9, 7, 5},  // Lat
                             { 7, 8, 4, 0}}; // FB

const int noSynapses = 28;
const int Synapses[noSynapses][3] = { 
    {LGN, V1L4E, FF}, {LGN, V1L4I, FF}, {V1L4E, V1L23E, FF}, {V1L4E, V1L23I, FF}, 
    {V1L23E, V2L4E, FF}, {V1L23E, V2L4I, FF}, {V2L4E, V2L23E, FF}, {V2L4E, V2L23I, FF},
    {V1L4E, V1L4I, Lat}, {V1L4I, V1L4E, Lat}, {V1L4I, V1L4I, Lat}, {V1L23E, V1L23I, Lat},
    {V1L23I, V1L23E, Lat}, {V1L23I, V1L23I, Lat}, {V2L4E, V2L4I, Lat}, {V2L4I, V2L4E, Lat}, 
    {V2L4I, V2L4I, Lat}, {V2L23E, V2L23I, Lat}, {V2L23I, V2L23E, Lat}, {V2L23I, V2L23I, Lat}, 
    {V2L23E, V1L23E, FB}, {V2L23E, V1L23I, FB},  {V1L23E, V1L4I, FB}, {V2L23E, V2L4I, FB}, 
    {V1L4I, V1L23E, FF}, {V1L4I, V1L23I, FF}, {V2L4I, V2L23E, FF}, {V2L4I, V2L23I, FF}};



#endif