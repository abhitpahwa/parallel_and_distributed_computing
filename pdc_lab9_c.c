//P0 SENDS A STRING TO P1,P2. P1 COUNTS THE VOWELS FROM THE STRING AND SENDS THE COUNT TO P3. P2 COUNTS THE CONSONANTS AND SENDS THE COUNT TO P4.

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
		char *name;
		int len;
		name=malloc(sizeof(char)*(strlen("abhit pahwa")+1));
		strcpy(name,"abhit pahwa");
		len=strlen(name)+1;
		MPI_Send(&len,1,MPI_INT,1,0,MPI_COMM_WORLD);
		MPI_Send(name,len,MPI_CHAR,1,0,MPI_COMM_WORLD);	
		printf("Processor : %s ---> P0 sending %s to P1\n",processor_name,name);	
		MPI_Send(&len,1,MPI_INT,2,0,MPI_COMM_WORLD);
		MPI_Send(name,len,MPI_CHAR,2,0,MPI_COMM_WORLD);
		printf("Processor : %s ---> P0 sending %s to P2\n",processor_name,name);		
	}
	else if(process_rank==1){
		char *name;		
		int len;
		MPI_Recv(&len,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		name=malloc(sizeof(char)*len);
		MPI_Recv(name,len,MPI_CHAR,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Processor : %s ---> P1 received %s from P0\n",processor_name,name);	
		int i,vowels=0;
		for(i=0;i<len;i++){
			if(name[i]>='A' && name[i]<='z' && (name[i]=='a' || name[i]=='e' || name[i]=='i' || name[i]=='o' || name[i]=='u' || name[i]=='A' || name[i]=='E' || name[i]=='I' || name[i]=='O' || name[i]=='U')){
				vowels++;
			}
		}
		MPI_Send(&vowels,1,MPI_INT,3,0,MPI_COMM_WORLD);
	}
	else if(process_rank==2){
		char *name;		
		int len;
		MPI_Recv(&len,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		name=malloc(sizeof(char)*len);	
		MPI_Recv(name,len,MPI_CHAR,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Processor : %s ---> P2 received %s from P0\n",processor_name,name);
		int i,consonants=0;
		for(i=0;i<len;i++){
			if(name[i]>='A' && name[i]<='z' && !(name[i]=='a' || name[i]=='e' || name[i]=='i' || name[i]=='o' || name[i]=='u' || name[i]=='A' || name[i]=='E' || name[i]=='I' || name[i]=='O' || name[i]=='U')){
				consonants++;
			}
		}
		MPI_Send(&consonants,1,MPI_INT,4,0,MPI_COMM_WORLD);
	}
	else if(process_rank==3){
		int vowels;
		MPI_Recv(&vowels,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Processor : %s ---> P3 received from P1 that name contains %d vowels\n",processor_name,vowels);
	}
	else if(process_rank==4){
		int consonants;
		MPI_Recv(&consonants,1,MPI_INT,2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Processor : %s ---> P4 received from P2 that name contains %d consonants\n",processor_name,consonants);
	}
	MPI_Finalize();
}
