//MATRIX ADDITION AND SUBTRACTION 
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<ctype.h>

struct matrices{
		int matrix_1[200][200];
		int matrix_2[200][200];
	};

void *matrix_add(void *m){
	struct matrices *m1=(struct matrices*)m;
	int add_matrix[200][200];
	printf("Matrix addition result: \n");
	
	for(int x=0;x<200;x++){
		for(int y=0;y<200;y++){
			add_matrix[x][y]=m1->matrix_1[x][y]+m1->matrix_2[x][y];
			printf("%d ",add_matrix[x][y]);
		}
		printf("\n");
	}
}

void *matrix_subtract(void *m){
	struct matrices *m1=(struct matrices*)m;
	int sub_matrix[200][200];
	printf("Matrix addition result: \n");
	
	for(int x=0;x<200;x++){
		for(int y=0;y<200;y++){
			sub_matrix[x][y]=m1->matrix_1[x][y]-m1->matrix_2[x][y];
			printf("%d ",sub_matrix[x][y]);
		}
		printf("\n");
	}
}

int main(){
	FILE *fp;
	FILE *fp1;
	fp=fopen("matrix_200*200_1.txt","r");
	fp1=fopen("matrix_200*200_2.txt","r");
	
	if(fp==NULL){
		perror("error opening the file1 \n");
		exit(EXIT_FAILURE);
	}

	if(fp1==NULL){
		perror("error opening the file2 \n");
		exit(EXIT_FAILURE);
	}

	int row=0,col=0,matrix1[200][200],matrix2[200][200];

	while(1){		
		fscanf(fp,"%d",&matrix1[row][col]);		
		fscanf(fp1,"%d",&matrix2[row][col]);
		
		if(col==199){
			row=row+1;
			col=0;
		}
		else{ 
			col=col+1;
		}
		
		if(row==200)
			break;
	} 

	
	struct matrices *m=malloc(sizeof(struct matrices));
	
	for(int x=0;x<200;x++){
		for(int y=0;y<200;y++){
			m->matrix_1[x][y]=matrix1[x][y];
			m->matrix_2[x][y]=matrix2[x][y];
		}
	}

	fclose(fp);
	pthread_t thread1,thread2;
	int p1,p2;
	p1=pthread_create(&thread1,NULL,matrix_add,m);
	
	if(p1){
		fprintf(stderr,"Error in pthread_create() with return code: %d\n",p1);
		exit(EXIT_FAILURE);
	}
	
	p2=pthread_create(&thread2,NULL,matrix_subtract,m);
	
	if(p2){
		fprintf(stderr,"Error in pthread_create() with return code: %d\n",p1);
		exit(EXIT_FAILURE);
	}

	printf("pthread_create() for thread1 returns: %d\n",p1);
	printf("pthread_create() for thread2 returns: %d\n",p2);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	exit(EXIT_SUCCESS);

}