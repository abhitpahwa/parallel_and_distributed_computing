//Broadcasting message using MPI
#include<stdio.h>
#include<mpi.h>
#include<string.h>
int main(){
	int rank;
	char buffer[15];
	const int root=0;
	char processor_name[20];
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int name_len;
	MPI_Get_processor_name(processor_name,&name_len);
	int len;
	printf("P%d on %s: Before bcast, buffer is %s\n",rank,processor_name,buffer);
	if(rank==root){
		strcpy(buffer,"hello world");
		len=strlen(buffer);
	}
	MPI_Bcast(&len,1,MPI_INT,root,MPI_COMM_WORLD);
	MPI_Bcast(buffer,len,MPI_CHAR,root,MPI_COMM_WORLD);
	printf("P%d on %s: After bcast, buffer is %s\n",rank,processor_name,buffer);
	MPI_Finalize();
	return 0;
}
