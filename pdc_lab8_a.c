//SEQUENTIAL PROGRAM FOR MATRIX MULTIPLICATION

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<ctype.h>

void main(){
	int choice;
	printf("Choose size of matrix\n1. 100*100\n2. 200*200\n3. 300*300\n");
	scanf("%d",&choice);
	FILE *fp;
	FILE *fp1;
	switch(choice){
		case 1:	fp=fopen("matrix_100*100_1.txt","r");
				fp1=fopen("matrix_100*100_2.txt","r");
				break;
		case 2:	fp=fopen("matrix_200*200_1.txt","r");
				fp1=fopen("matrix_200*200_2.txt","r");
				break;
		case 3:	fp=fopen("matrix_300*300_1.txt","r");
				fp1=fopen("matrix_300*300_2.txt","r");
				break;
 		default: printf("Not a correct choice.. exiting\n");
 				exit(0);
	}
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
	#pragma omp parallel for collapse(2)
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			#pragma omp critical
			{
				mult_matrix[i][j]=0;
				for(k=0;k<100;k++){
					mult_matrix[i][j]+=matrix1[i][k]*matrix2[k][j];
				}
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