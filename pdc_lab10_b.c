//Scattering elements of array using MPI
#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	int size,rank;
	char processor_name[15];
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int name_len;
	MPI_Get_processor_name(processor_name,&name_len);
	int array[16];
	int sub_array;
	int i;
	if(rank==0){
		for(i=0;i<size;i++)
			array[i]=i;
		printf("1. P%d on %s has data: ",rank,processor_name);
		for(i=0;i<size;i++)
			printf("%d",array[i]);
		printf("\n");
	}
	MPI_Scatter(array,1,MPI_INT,&sub_array,1,MPI_INT,0,MPI_COMM_WORLD);
	printf("2. P%d on %s has data %d\n",rank,processor_name,sub_array);
	MPI_Finalize();
	return 0;
}
