from itertools import izip, islice, tee

def slices(iterable, n):
    return izip(*(islice(it, i, None) for i, it in enumerate(tee(iterable, n))))


def findor(seq):
    s = 0
    for i in range(len(seq)-1):
        s += seq[i] | seq[i+1] 
    return s

def findxor(seq):
    s = 0
    for i in range(len(seq)-1):
        s += seq[i] ^ seq[i+1]
    return s

n,k1,k2 = raw_input().split()

k1 = int(k1)
n = int(n)
k2 = int(k2)

A = raw_input().split()

for i in range(0,len(A)):
    A[i] = int(A[i])

count=0
for i in range(len(A)):
    subsets = slices(A,i)
    # print subsets
    for j in subsets:
        print j
        if findor(j)>k1 and findxor(j)>k2:
            count+=1

print count
