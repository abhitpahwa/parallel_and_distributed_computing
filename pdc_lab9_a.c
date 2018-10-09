//MPI PROGRAM TO SEND A NUMBER FROM ONE PROCESS TO ANOTHER WHICH CHECKS IF THE NUMBER IS ODD OR EVEN AND SEND THE RESULT TO ANOTHER PROCESS

#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char ** argv){
	MPI_Init(NULL,NULL);
	int process_rank;
	MPI_Comm_rank(MPI_COMM_WORLD,&process_rank);
	int num_process;
	MPI_Comm_size(MPI_COMM_WORLD,&num_process);
	char processor_name[MPI_MAX_PROCESSOR_NAME];
    	int name_len;
    	MPI_Get_processor_name(processor_name, &name_len);
	if(process_rank==0){
		int num=10;
		printf("Processor : %s ---> P0 sending number %d to P1\n",processor_name,num);
		MPI_Send(&num,1,MPI_INT,1,0,MPI_COMM_WORLD);
	}
	else if(process_rank==1)
	{
		int num; 
		char *ans;
		int len;
		MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Processor : %s ---> P1 received number %d from P1\n",processor_name,num);
		if(num%2==0){
			ans=malloc(sizeof(char)*(strlen("even")+1));
			strcpy(ans,"even");
		}					
		else{
			ans=malloc(sizeof(char)*(strlen("odd")+1));
			strcpy(ans,"odd");
		}		
		len=strlen(ans)+1;		
		MPI_Send(&len,1,MPI_INT,2,0,MPI_COMM_WORLD);
		MPI_Send(ans,len,MPI_CHAR,2,0,MPI_COMM_WORLD);
	}
	else if(process_rank==2){
		char *ans;
		int len;		
		MPI_Recv(&len,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		ans=malloc(sizeof(char)*(len));
		MPI_Recv(ans,len,MPI_CHAR,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Processor : %s ---> P2 received the answer: %s\n",processor_name,ans);
	}
	MPI_Finalize();
}
