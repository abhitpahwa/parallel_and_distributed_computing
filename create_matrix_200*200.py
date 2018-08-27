import numpy as np 
matrix1=np.random.randint(low=0,high=400,size=(200,200))
matrix2=np.random.randint(low=0,high=400,size=(200,200))
np.savetxt("matrix_200*200_1.txt",matrix1,fmt="%-3d")
np.savetxt("matrix_200*200_2.txt",matrix2,fmt="%-3d")
