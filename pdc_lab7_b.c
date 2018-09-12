//MATRIX MULTIPLICATION WITH OUTERMOST LOOP PARALLELIZED

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

	int row=0,col=0,matrix1[100][100],matrix2[100][100],mult_matrix[100][100];
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
	int i,j,k;
	//can use num_threads clause to view performance with varying number of threads

	#pragma omp parallel 
	#pragma omp for 
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			mult_matrix[i][j]=0;
			for(k=0;k<100;k++){
				mult_matrix[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			printf("%d ",mult_matrix[i][j] );
		}
		printf("\n");
	}
}