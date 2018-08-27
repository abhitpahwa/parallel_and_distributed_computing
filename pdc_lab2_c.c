//ADD 2 MATRICES USING OMP COLLAPSE AND PRINT THE RESULT

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main(){
	int i,j,matrix1[100][100],matrix2[100][100],add_matrix[100][100];
	for(i=0;i<100;i++)
		for(j=0;j<100;j++){
			matrix1[i][j]=i*10+j+1;
			matrix2[i][j]=i*10+j+1;
		}

	#pragma omp parallel 
	{
		int i,j;
		#pragma omp for collapse(2)
			for(i=0;i<100;i++)
				for(j=0;j<100;j++)
					add_matrix[i][j]=matrix1[i][j]+matrix2[i][j];
		}

	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			printf("%d+%d=%d\n",matrix1[i][j],matrix2[i][j],add_matrix[i][j]);
}
