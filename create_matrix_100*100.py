import numpy as np 
matrix1=np.random.randint(low=0,high=400,size=(100,100))
matrix2=np.random.randint(low=0,high=400,size=(100,100))
np.savetxt("matrix_100*100_1.txt",matrix1,fmt="%-3d")
np.savetxt("matrix_100*100_2.txt",matrix2,fmt="%-3d")