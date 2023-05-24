#ifndef SCENE_CC
#define SCENE_CC

#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <cmath>

#include "parameters.h"

using namespace std;

typedef vector<vector<vector<float>>> iMat;


class Scene {
    public:
        Scene(string path, int imgNo, bool tile) : iPath("../DATA/"+path+"/"), noImages(imgNo), tiling(tile) {
            currentImage = -1;
        }

        iMat patch() {
            iMat patch(side[LGN], vector<vector<float>>(side[LGN], vector<float>(2,.0)));
            if (tiling) { // Tiled images are always bigger
                for (int yo = 0; yo < side[LGN]; yo++) for (int xo = 0; xo < side[LGN]; xo++) for (int z = 0; z < 2; z++) {
                    if ((coord[1]+yo >= int(image.size())) || (coord[0]+xo >= int(image[0].size()))) continue;
                    patch[yo][xo][z] = image[coord[1]+yo][coord[0]+xo][z];
                }    
            } else { // Cut images are always smaller or same as, never bigger
                for (int yo = 0; yo < int(image[0].size()); yo++) for (int xo = 0; xo < int(image.size()); xo++) for (int z = 0; z < 2; z++) {
                    patch[coord[1]+yo][coord[0]+xo][z] = image[yo][xo][z];
                }
            }
            return patch;
        }

        int next() {
            if (currentImage == noImages-1) return -1;
            currentImage++;
            ifstream mat(iPath+to_string(currentImage));
            if (!mat.is_open()) throw runtime_error(iPath+to_string(currentImage)+" not found.");
            string sp;
            float maxValue;
            mat >> sp >> maxValue;
            int height; mat >> sp >> height;
            int width; mat >> sp >> width;
            image = iMat(height, vector<vector<float>>(width, vector<float>(2,.0)));  // this is because of indexing in flattened version y*width + 2x + z
            for (int y = 0; y < height; y++) for (int x = 0; x < width; x++) for (int z = 0; z < 2; z++) mat >> image[y][x][z];
            if (tiling) coord = vector<int>{0,-side[LGN]}; // initial for the tiling
            else coord = vector<int>{int(abs(height-side[LGN])/2),int(abs(width-side[LGN])/2)}; // coordinates for the cut
            return currentImage;
        }

        bool nextTile() {
            coord[1] += side[LGN]; // Slide x
            if (coord[1] >= int(image[0].size())) coord = vector<int>{coord[0]+=side[LGN], 0}; // Slide y
            return !(coord[0] >= int(image.size()));
        }


    private:
        // Set parameters
        string iPath;   // Where it is
        int noImages;   // How many images are in the set
        // Current scene
        iMat image;
        int currentImage;
        // Tiles
        bool tiling;
        vector<int> coord;
        vector<int> noTiles;

};

#endif
