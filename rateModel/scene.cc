#ifndef SCENE_CC
#define SCENE_CC

#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <cmath>

#include "parameters.h"

#define IMAGE_PATCHES 10

using namespace std;

typedef vector<vector<vector<float>>> iMat;


class Scene {
    public:
        Scene(string path = "IMAGES_NORM2015", int imgNo = 10, bool norm = false) : iPath("../DATA/"+path+"/"), noImages(imgNo), toNorm(norm) {
            noCurrentPatch = IMAGE_PATCHES;  // First saccade draws a new image 
            rng = mt19937(random_device()());
            rDist = normal_distribution<double>(0, 2); // 0,2 in the original
            tDist = uniform_real_distribution<double>();
            coord = vector<int>(2,0);
        }

        iMat saccade() {
            if (noCurrentPatch >= IMAGE_PATCHES) newImage();   // Get patch from new image
            else changeSaccade();                           // Get new patch from same image
            iMat patch(side[LGN], vector<vector<float>>(side[LGN], vector<float>(2,.0)));
            for (int yo = 0; yo < side[LGN]; yo++) for (int xo = 0; xo < side[LGN]; xo++) for (int z = 0; z < 2; z++) patch[yo][xo][z] = image[coord[1]][coord[0]][z];
            noCurrentPatch++;
            return patch;
        }

        int getPatchNo() { return noCurrentPatch; }

    private:
        // Set parameters
        string iPath;   // Where it is
        int noImages;   // How many images are in the set
        bool toNorm;    // Is normalisation required
        // Current scene
        iMat image;
        double maxValue;
        int noCurrentPatch;
        // Saccades
        vector<int> coord;
        mt19937 rng;
        normal_distribution<double> rDist;
        uniform_real_distribution<double> tDist;

        void changeSaccade() {
            int y, x;
            do {
                double r =  rDist(rng); 
                double theta =  tDist(rng) * M_PI * 2;
                y = coord[0] + int(round(r * sin(theta)));
                x = coord[1] + int(round(r * cos(theta)));
            } while (x < 0 || y < 0 || x > (image[0].size() - side[LGN]) || y > (image.size() - side[LGN]) || (x == 0 && y == 0));
            coord[0] = y; coord[1] = x;
        }

        // TODO: re-evaluate when evaluation images are introduced, but it should be the preprocessing's responsibility to adapt to this
        void newImage() {
            int imgNo = rand()%noImages;
            ifstream mat(iPath+to_string(imgNo));
            if (!mat.is_open()) throw runtime_error(iPath+to_string(imgNo)+" not found.");
            string sp;
            mat >> sp >> maxValue;
            int height; mat >> sp >> height;
            int width; mat >> sp >> width;
            image = iMat(height, vector<vector<float>>(width, vector<float>(2,.0)));  // this is because of indexing in flattened version y*width + 2x + z
            for (int y = 0; y < height; y++) for (int x = 0; x < width; x++) for (int z = 0; z < 2; z++) {
                mat >> image[y][x][z];
                // if (toNorm) TODO: the thing ;
            } 
            noCurrentPatch = 0;
            do {  // Initial patch coordinates
                coord[0] = rand() % (image.size() - side[LGN]);
                coord[1] = rand() % (image[0].size() - side[LGN]);
            } while (coord[0] == 0 && coord[1] == 0);
        }

};

#endif
