from scipy.linalg import svd
import numpy as np

a = np.array([[1, 1, 1, 0, 0],\
	[3, 3, 3, 0, 0],\
	[4, 4, 4, 0, 0],\
	[5, 5, 5, 0, 0],\
	[0, 2, 0, 4, 4],\
	[0, 0, 0, 5, 5],\
	[0, 1, 0, 2, 2]])
U, s, Vh = svd(a)

print "U",U
print "Sigma",s
print "V transpose",Vh

# Ax = []

# for i in range(s.shape[0]):
# 	print np.multiply(U[i],Vh[i])

# print Ax
