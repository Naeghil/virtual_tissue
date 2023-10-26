import liblinear.liblinearutil as lln
import scipy as sp
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from struct import unpack as unp

pops = ["V1L4E", "V1L4I", "V1L23E", "V1L23I", "V2L4E", "V2L4I", "V2L23E", "V2L23I"]
sets = ["MNIST_train","MNIST_test","CIFAR-10_test_gray","CIFAR-10_train_gray","SVHN_test","SVHN_train", "EMNIST_test","EMNIST_train","ETH80_gray_vector","CalTec101_subset"]
#sets = ["MNIST_train","MNIST_test","CIFAR-10_test_gray","CIFAR-10_train_gray","SVHN_test","SVHN_train", "ETH80_gray_vector","CalTec101_subset"]
noImgs = [60000,10000,10000,50000,26032,73257,18800,112800,3280,1233]
conditions = ["popAvg"] #["popAvg","ogTrace","slowTrace","midTrace","fastTrace", "constant"]
feedback = ["On","Off"]

def evaluateCalTec():
    labels = list(sp.io.loadmat("./DATA/CalTec101_subset_labels.mat").values())[-1].squeeze()
    for cond in conditions:
        dss = []
        conds = []
        iters = []
        fbs = []
        pps = []
        rts = []
        accs = []

        for f in feedback:
            for it in range(5):
                for p in pops:
                    evPath = "./RESULTS/"+cond+"/evaluation/CalTec101_subset/"+f+"It"+str(it)+"_"+p+"/"
                    for t in [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]:
                        print("Evaluating CalTec101 dataset in condition " + cond + "It" + str(it) + " with feedback "+f+" in population " +p+ " recorded at "+str(t)+"ms")
                        resp = np.array([np.fromfile(evPath+str(i)+"_t"+str(t), dtype=np.float32).flatten() for i in range(noImgs[9])])

                        #shuf = np.random.permutation(len(resp))
                        # Train/Test split
                        cat1 = np.where(labels == 2)[0]
                        cat1 = cat1[np.random.permutation(len(cat1))]
                        cat2 = np.where(labels == 5)[0]
                        cat2 = cat2[np.random.permutation(len(cat2))]
                        trI = np.concatenate([cat1[:200], cat2[:200]])
                        teI = np.concatenate([cat1[200:], cat2[200:]])
                                
                        trainL = labels[trI]
                        train = resp[trI]
                        testL = labels[teI]
                        test = resp[teI]
                        
                        mod = lln.train(trainL, train, '-s 1 -B 1 -m -10 -c 1 -q')
                        _1, acc, _2 = lln.predict(testL, test, mod)

                        dss.append("CalTec101")
                        conds.append(cond)
                        iters.append(it)
                        fbs.append(f)
                        pps.append(p)
                        rts.append(t)
                        accs.append(acc[0])
        pd.DataFrame({"Dataset":dss,"Condition":conds,"Iteration":iters,"Feedback":fbs,"Population":pps,"Recording Time":rts,"Accuracy":accs}).to_csv("./RESULTS/"+cond+"/CalTec101_subset_accuracies.csv")

def evaluateETH80():
    labels = list(sp.io.loadmat("./DATA/ETH80_vector_labels.mat").values())[-1].squeeze()
    for cond in conditions:
        dss = []
        conds = []
        iters = []
        fbs = []
        pps = []
        rts = []
        accs = []

        for f in feedback:
            for it in range(5):
                for p in pops:
                    evPath = "./RESULTS/"+cond+"/evaluation/ETH80_gray_vector/"+f+"It"+str(it)+"_"+p+"/"
                    for t in [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]:
                        print("Evaluating ETH80 dataset in condition " + cond + "It" + str(it) + " with feedback "+f+" in population " +p+ " recorded at "+str(t)+"ms")
                        resp = np.array([np.fromfile(evPath+str(i)+"_t"+str(t), dtype=np.float32).flatten() for i in range(noImgs[8])])
                        
                        # Train/Test split (even class)
                        trainL = []
                        train = []
                        testL = []
                        test = []
                        for l in np.unique(labels):
                            clidxs = np.where(labels == l)[0]
                            noEl = len(clidxs)
                            shuf = np.random.permutation(noEl)
                            clidxs = clidxs[shuf]
                            trainL.extend(labels[clidxs[:int(noEl*.7)]])
                            train.extend(resp[clidxs[:int(noEl*.7)]])
                            testL.extend(labels[clidxs[int(noEl*.7):]])
                            test.extend(resp[clidxs[int(noEl*.7):]])

                        mod = lln.train(trainL, train, '-s 1 -B 1 -m -10 -c 1 -q')
                        _1, acc, _2 = lln.predict(testL, test, mod)

                        dss.append("ETH80")
                        conds.append(cond)
                        iters.append(it)
                        fbs.append(f)
                        pps.append(p)
                        rts.append(t)
                        accs.append(acc[0])
        pd.DataFrame({"Dataset":dss,"Condition":conds,"Iteration":iters,"Feedback":fbs,"Population":pps,"Recording Time":rts,"Accuracy":accs}).to_csv("./RESULTS/"+cond+"/ETH80_accuracies.csv")

def evaluateETH80uneven():
    labels = list(sp.io.loadmat("./DATA/ETH80_vector_labels.mat").values())[-1].squeeze()
    for cond in conditions:
        dss = []
        conds = []
        iters = []
        fbs = []
        pps = []
        rts = []
        accs = []

        for f in feedback:
            for it in range(5):
                for p in pops:
                    evPath = "./RESULTS/"+cond+"/evaluation/ETH80_gray_vector/"+f+"It"+str(it)+"_"+p+"/"
                    for t in [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]:
                        print("Evaluating ETH80 dataset in condition " + cond + "It" + str(it) + " with feedback "+f+" in population " +p+ " recorded at "+str(t)+"ms")
                        resp = np.array([np.fromfile(evPath+str(i)+"_t"+str(t), dtype=np.float32).flatten() for i in range(noImgs[8])])
                        
                        # Train/Test split (even class)
                        shuf = np.random.permutation(len(resp))

                        trainL = labels[shuf][:int(len(resp)*.7)]
                        train = resp[shuf][:int(len(resp)*.7)]
                        testL = labels[shuf][int(len(resp)*.7):]
                        test = resp[shuf][int(len(resp)*.7):]

                        mod = lln.train(trainL, train, '-s 1 -B 1 -m -10 -c 1 -q')
                        _1, acc, _2 = lln.predict(testL, test, mod)

                        dss.append("ETH80")
                        conds.append(cond)
                        iters.append(it)
                        fbs.append(f)
                        pps.append(p)
                        rts.append(t)
                        accs.append(acc[0])
        pd.DataFrame({"Dataset":dss,"Condition":conds,"Iteration":iters,"Feedback":fbs,"Population":pps,"Recording Time":rts,"Accuracy":accs}).to_csv("./RESULTS/"+cond+"/ETH80_accuracies_uneven.csv")

def evaluateEMNIST():
    testL = list(sp.io.loadmat("./DATA/EMNIST_test_labels.mat").values())[-1].squeeze()
    trainL = list(sp.io.loadmat("./DATA/EMNIST_train_labels.mat").values())[-1].squeeze()
    for cond in conditions:
        dss = []
        conds = []
        iters = []
        fbs = []
        pps = []
        rts = []
        accs = []
        for f in feedback:
            for it in range(5):
                for p in pops:
                    for t in [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]:
                        print("Evaluating EMNIST dataset in condition "+cond+"It"+str(it) + " with feedback "+f+" in population " + p + " recorded at "+str(t))
                        pathPre = "./RESULTS/"+cond+"/evaluation/EMNIST_"
                        pathPost = "/"+f+"It"+str(it)+"_"+p+"t"+str(t)
                        test = np.fromfile(pathPre+"test"+pathPost, dtype=np.float32).reshape(18800,-1)
                        train = np.fromfile(pathPre+"train"+pathPost, dtype=np.float32).reshape(112800,-1)

                        mod = lln.train(trainL, train, '-s 1 -B 1 -m -14 -c 1 -q')
                        _1, acc, _2 = lln.predict(testL, test, mod)

                        dss.append("EMNIST")
                        conds.append(cond)
                        iters.append(it)
                        fbs.append(f)
                        pps.append(p)
                        rts.append(t)
                        accs.append(acc[0])

        pd.DataFrame({"Dataset":dss,"Condition":conds,"Iteration":iters,"Feedback":fbs,"Population":pps,"Recording Time":rts,"Accuracy":accs}).to_csv("./RESULTS/"+cond+"/EMNIST_accuracies.csv")

def evaluateSVHN():
    testL = list(sp.io.loadmat("./DATA/SVHN_test_labels.mat").values())[-1].squeeze()
    trainL = list(sp.io.loadmat("./DATA/SVHN_train_labels.mat").values())[-1].squeeze()
    for cond in conditions:
        dss = []
        conds = []
        iters = []
        fbs = []
        pps = []
        rts = []
        accs = []
        for f in feedback:
            for it in range(5):
                for p in pops:
                    for t in [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]:
                        print("Evaluating SVHN dataset in condition "+cond+"It"+str(it) + " with feedback "+f+" in population " + p + " recorded at "+str(t))
                        pathPre = "./RESULTS/"+cond+"/evaluation/SVHN_"
                        pathPost = "/"+f+"It"+str(it)+"_"+p+"t"+str(t)
                        test = np.fromfile(pathPre+"test"+pathPost, dtype=np.float32).reshape(26032,-1)
                        train = np.fromfile(pathPre+"train"+pathPost, dtype=np.float32).reshape(73257,-1)

                        mod = lln.train(trainL, train, '-s 1 -B 1 -m -14 -c 1 -q')
                        _1, acc, _2 = lln.predict(testL, test, mod)

                        dss.append("SVHN")
                        conds.append(cond)
                        iters.append(it)
                        fbs.append(f)
                        pps.append(p)
                        rts.append(t)
                        accs.append(acc[0])

        pd.DataFrame({"Dataset":dss,"Condition":conds,"Iteration":iters,"Feedback":fbs,"Population":pps,"Recording Time":rts,"Accuracy":accs}).to_csv("./RESULTS/"+cond+"/SVHN_accuracies.csv")

def evaluateCIFAR10():
    testL = list(sp.io.loadmat("./DATA/CIFAR-10_test_labels.mat").values())[-1].squeeze()
    trainL = list(sp.io.loadmat("./DATA/CIFAR-10_train_labels.mat").values())[-1].squeeze()
    for cond in conditions:
        dss = []
        conds = []
        iters = []
        fbs = []
        pps = []
        rts = []
        accs = []
        for f in feedback:
            for it in range(5):
                for p in pops:
                    for t in [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]:
                        print("Evaluating CIFAR10 dataset in condition "+cond+"It"+str(it) + " with feedback "+f+" in population " + p + " recorded at "+str(t))
                        pathPre = "./RESULTS/"+cond+"/evaluation/CIFAR-10_"
                        pathPost = "_gray/"+f+"It"+str(it)+"_"+p+"t"+str(t)
                        test = np.fromfile(pathPre+"test"+pathPost, dtype=np.float32).reshape(10000,-1)
                        train = np.fromfile(pathPre+"train"+pathPost, dtype=np.float32).reshape(50000,-1)

                        mod = lln.train(trainL, train, '-s 1 -B 1 -m -14 -c 1 -q')
                        _1, acc, _2 = lln.predict(testL, test, mod)

                        dss.append("CIFAR10")
                        conds.append(cond)
                        iters.append(it)
                        fbs.append(f)
                        pps.append(p)
                        rts.append(t)
                        accs.append(acc[0])

        pd.DataFrame({"Dataset":dss,"Condition":conds,"Iteration":iters,"Feedback":fbs,"Population":pps,"Recording Time":rts,"Accuracy":accs}).to_csv("./RESULTS/"+cond+"/CIFAR10_accuracies.csv")

def evaluateMNIST():
    testL = list(sp.io.loadmat("./DATA/MNIST_test_labels.mat").values())[-1].squeeze()
    trainL = list(sp.io.loadmat("./DATA/MNIST_train_labels.mat").values())[-1].squeeze()
    for cond in conditions:
        dss = []
        conds = []
        iters = []
        fbs = []
        pps = []
        rts = []
        accs = []
        for f in feedback:
            for it in range(5):
                for p in pops:
                    for t in [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]:
                        print("Evaluating MNIST dataset in condition "+cond+"It"+str(it) + " with feedback "+f+" in population " + p + " recorded at "+str(t))
                        pathPre = "./RESULTS/"+cond+"/evaluation/MNIST_"
                        pathPost = "/"+f+"It"+str(it)+"_"+p+"t"+str(t)
                        test = np.fromfile(pathPre+"test"+pathPost, dtype=np.float32).reshape(10000,-1)
                        train = np.fromfile(pathPre+"train"+pathPost, dtype=np.float32).reshape(60000,-1)

                        mod = lln.train(trainL, train, '-s 1 -B 1 -m -14 -c 1 -q')
                        _1, acc, _2 = lln.predict(testL, test, mod)

                        dss.append("MNIST")
                        conds.append(cond)
                        iters.append(it)
                        fbs.append(f)
                        pps.append(p)
                        rts.append(t)
                        accs.append(acc[0])

        pd.DataFrame({"Dataset":dss,"Condition":conds,"Iteration":iters,"Feedback":fbs,"Population":pps,"Recording Time":rts,"Accuracy":accs}).to_csv("./RESULTS/"+cond+"/MNIST_accuracies.csv")


#evaluateCalTec()
#evaluateETH80()
#evaluateETH80uneven()
#evaluateEMNIST()
#evaluateSVHN()
#evaluateCIFAR10()
evaluateMNIST()

