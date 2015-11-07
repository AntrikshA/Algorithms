# Enter your code here. Read input from STDIN. Print output to STDOUT

n,m = raw_input().split()

n = int(n)
m=  int(m)

def convert(A):
    for i in range(0,len(A)):
        A[i] = int(A[i])
    return A

S = raw_input().split()
Q = raw_input().split()

S = convert(S)
Q = convert(Q)

OP = []
 
for line in range(len(S)):
    x = raw_input()
    OP += [[i for i in x]]

print OP

S=sorted(S)
Q=sorted(Q)

Q2=[]
for i in Q:
    Q2.append(i)

prod=0
minimum = 0
maximum = 0
for i in S:
    persons = []
    for j in Q:
        if OP[S.index(i)][Q.index(j)]=='y' or OP[S.index(i)][Q.index(j)]=='Y':
            prod = (i*j)
            persons += [prod]
    maximum += max(persons)
    minimum += min(persons)

print minimum,maximum

