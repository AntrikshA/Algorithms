import time
import numpy as np
from decimal import *
import pandas as pd
from pandas import Categorical
from scipy.sparse import csr_matrix

size = 875713

def PageRank():

    print "extracting file data..."
    start = time.time()
    webGoogle = pd.read_csv('web-Google.txt', sep='\t', comment='#', names=['from', 'to'],\
         )
    end = time.time()
    print "Time to read the file :", end - start

    print pd.Categorical(webGoogle['from']).Length
    # print webGoogle

    # while webGoogle:
    #     print "initialising matrices..."
    #     start = time.time()
    #     data = np.repeat(1, webGoogle.shape[0])
    #     categories = np.unique(webGoogle.values) # finds all unique elements in array

    #     col_ind = pd.Categorical(webGoogle['from'])
    #     row_ind = pd.Categorical(webGoogle['to'])
        
    #     M = M.multiply(csr_matrix(1 / M.sum(axis=0)))

    #     # M.todense()
    #     end = time.time()
    #     print "Time to initialise matrices :", end - start

    #     rank = np.full((size+1,), fill_value=(Decimal(1/Decimal(size))), dtype=np.float)

    #     start = time.time()
    #     while 1:
    #         prevrank = rank
    #         rank = M.dot(rank)
    #         if rank.all() == prevrank.all():
    #             break

    #     end = time.time()
    #     print "Time to calculate ranks :", end-start
    #     print rank

if __name__ == '__main__':
    PageRank()