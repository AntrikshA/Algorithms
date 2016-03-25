import numpy as np


def main():
    X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    Y = np.array([0, 1, 1, 1])
    W = np.array([-0.5,0.5])

    for i in xrange(X.shape[0]):
        o = sum(X[i]*W)
        if o>1:
            o=1
        else:
            o=0
        print o
        W[0] = W[0] + (Y[i]-o) * X[i,0]
        W[1] = W[1] + (Y[i]-o) * X[i,1]
        # print Y[i] - o

    print W

if __name__ == '__main__':
    main()
