import numpy as np 
matrix1=np.random.randint(low=0,high=400,size=(300,300))
matrix2=np.random.randint(low=0,high=400,size=(300,300))
np.savetxt("matrix_300*300_1.txt",matrix1,fmt="%-3d")
np.savetxt("matrix_300*300_2.txt",matrix2,fmt="%-3d")
