//Gathering elements from different processes using MPI
#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int main(){
	int size,rank;
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	char processor_name[15];
	int name_len;
	MPI_Get_processor_name(processor_name,&name_len); 
	int sub[3]={1,2,3};
	int array[MAX];
	MPI_Gather(sub,3,MPI_INT,array,3,MPI_INT,0,MPI_COMM_WORLD);
	printf("P%d on %s has data: \n",rank,processor_name);
	int i;
	if(rank==0){
		for(i=0;i<size*3;i++)	
		printf("%d",array[i]);
		printf("\n");
	}
	else{
		for(i=0;i<3;i++)	
		printf("%d",sub[i]);
		printf("\n");	
	}
	
	MPI_Finalize();
	return 0;
}
