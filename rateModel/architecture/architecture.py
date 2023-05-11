import pandas as pd
import numpy as np
import math

arch = pd.read_csv("./architecture_params.csv")
conn = pd.read_csv("./connectivity_params.csv")

# Coordinates to index
def ctoi(cs, d1, d2):
    return cs[0]*d1*d2 + cs[1]*d2 + cs[2]
# Index to coords
def itoc(i, d1, d2):
    cs = [0,0,0]
    cs[0] = math.floor(i/(d1*d2))
    i = i % (d1*d2)
    cs[1] = math.floor(i/d2)
    cs[2] = i % d2
    return cs
 
# From pseudocode 2.1 in Teichmann, 2018
def connect_populations(sPop, tPop, RFs, off, isself):
    cMat = np.zeros((sPop[0]*sPop[0]*sPop[1], tPop[0]*tPop[0]*tPop[1]), dtype=int)
    for xt in range(tPop[0]):
        for yt in range(tPop[0]):
            lowerx = max(xt + off, 0)
            upperx = min(xt + off + RFs, sPop[0])
            lowery = max(yt + off, 0)
            uppery = min(yt + off + RFs, sPop[0])
            for zt in range(tPop[1]):
                for xs in range(lowerx, upperx):
                    for ys in range(lowery, uppery):
                        for zs in range(sPop[1]):
                            sidx = ctoi([xs, ys, zs], sPop[0], sPop[1])
                            tidx = ctoi([xt, yt, zt], tPop[0], tPop[1])
                            cMat[sidx][tidx] = 1
    # No self connections
    if isself:
        for i in range(cMat.shape[0]):
            cMat[i][i] = 0
    return cMat

for connection in conn.values:
    tPop = arch.loc[arch["Population"] == connection[0]].values[0][1:]
    sPop = arch.loc[arch["Population"] == connection[1]].values[0][1:]
    mat = connect_populations(sPop, tPop, connection[2], connection[3], connection[0] == connection[1])
    np.savetxt("./matrics/"+connection[1]+"-"+connection[0], mat, delimiter=" ", fmt='%i')
