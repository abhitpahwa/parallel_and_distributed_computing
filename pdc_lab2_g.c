//ADD 2 MATRICES READ FROM FILES ; USING OMP WITH GUIDED SCHEDULING

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<ctype.h>

void main(){
	FILE *fp;
	FILE *fp1;
	fp=fopen("matrix_100*100_1.txt","r");
	fp1=fopen("matrix_100*100_2.txt","r");

	if(fp==NULL){
		perror("error opening the file1 \n");
		exit(EXIT_FAILURE);
	}

	if(fp1==NULL){
		perror("error opening the file2 \n");
		exit(EXIT_FAILURE);
	}	

	int row=0,col=0,matrix1[100][100],matrix2[100][100],add_matrix[100][100];
	while(1){
		fscanf(fp,"%d",&matrix1[row][col]);
		fscanf(fp1,"%d",&matrix2[row][col]);
		if(col==99){
			row=row+1;
			col=0;
		}
		else{
			col=col+1;
		}
		if(row==200)
			break;
	}

	int i,j;
	#pragma omp parallel 
	{
		int i,j;
		//schedule(guided,chunk_size)
		#pragma omp for collapse(2) schedule(guided,10)
			for(i=0;i<100;i++)
				for(j=0;j<100;j++)
					add_matrix[i][j]=matrix1[i][j]+matrix2[i][j];
		}

	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			printf("%d+%d=%d\n",matrix1[i][j],matrix2[i][j],add_matrix[i][j]);
}
