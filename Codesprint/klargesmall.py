from collections import Counter

n,q = raw_input().split()

A = raw_input().split()

q = int(q)
n = int(n)

for i in range(0,len(A)):
    A[i] = int(A[i])

def distict(seq):
    seen = set()
    return [x for x in seq if x not in seen and not seen.add(x)]

A = distict(A)

def get_y(x,t):
    # y = []
    if x in A:
        # print A
        y = A.index(x)
        if t==0:
            y+=1
    elif x > max(A):
        y = len(A) # mistake was here
    elif x < min(A):
        y = 0 # and here
    else:
        for i in A:
            if i>x:
                # print A
                y = A.index(i)

                break

    # print y
    return y

def n_max(k, x):
    y = get_y(x,0)
    indices = A[(y):]
    try:
        return indices[k-1]
    except IndexError:
        return -1

def n_min(k, x):
    y = get_y(x,1)
    indices = A[:y]
    try:
        return indices[-(k)]
    except IndexError:
        return -1

while(q):
    x,k,t = raw_input().split()
    k = int(k) #kth element to be found
    x = int(x) # all elements greater/smaller than this
    t = int(t) # type

    if t==1:
        print n_min(k, x)
    else:
        print n_max(k, x)

    q -= 1