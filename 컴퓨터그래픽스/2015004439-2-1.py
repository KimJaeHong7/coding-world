import numpy as np

M = np.arange(2,27)
print(M)
print()
M=np.arange(2,27).reshape(5,5)
print(M)
print()
M[1:4,1:4]=0
print(M)
print()
M=M@M
print(M)
print()
N=M[0:1,:]
N=N*N
a=np.sum(N)
print(np.sqrt(a))

    
