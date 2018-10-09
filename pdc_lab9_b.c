//P0 SENDS A NUMBER TO P1,P2,P3. P1 CHECKS WHETHER THE NUMBER IS ODD OR EVN AND SENDS THE RESULT TO P4. P2 CHECKS WHETHER THE NUMBER IS PRIME OR NOT AND SEND THE RESULT TO P5. P3 CHECKS WHETHER THE NUMBER IS ARMSTRONG OR NOT AND SENDS THE RESULT TO P6.

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
		int num=153,i;
		for(i=1;i<4;i++){
			printf("Processor : %s ---> P0 sending number %d to P%d\n",processor_name,num,i);					
			MPI_Send(&num,1,MPI_INT,i,0,MPI_COMM_WORLD);
		}
	}
	else if(process_rank==1){
		int num,len;
		MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);	
		printf("Processor : %s ---> P1 received number %d from P0\n",processor_name,num);
		char *odd_even;
		if(num%2==0){
			odd_even=malloc(sizeof(char)*(strlen("even")+1));
			strcpy(odd_even,"even");
		}
		else{
			odd_even=malloc(sizeof(char)*(strlen("odd")+1));
			strcpy(odd_even,"odd");
		}		
		len= strlen(odd_even)+1;
		MPI_Send(&len,1,MPI_INT,4,0,MPI_COMM_WORLD);
		MPI_Send(odd_even,len,MPI_CHAR,4,0,MPI_COMM_WORLD);
	}	
	else if(process_rank==2){
		int num,i,flag=0,len;
		char *prime;
		MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Processor : %s ---> P2 received number %d from P0\n",processor_name,num);
		if(num==0){
			prime=malloc(sizeof(char)*(strlen("neither prime nor odd")+1));
			strcpy(prime,"neither prime nor odd");
		}		
		else if(num==2){
			prime=malloc(sizeof(char)*(strlen("prime")+1));
			strcpy(prime,"prime");	
		}		
		else{
			for(i=2;i<=num/2;i++){
				if(num%i==0){
					prime=malloc(sizeof(char)*(strlen("not prime")+1));					
					strcpy(prime,"not prime");
					flag=1;
					break;
				}							
			}
			if(flag==0)
				prime=malloc(sizeof(char)*(strlen("prime")+1));
				strcpy(prime,"prime");
		}
		len= strlen(prime)+1;
		MPI_Send(&len,1,MPI_INT,5,0,MPI_COMM_WORLD);
		MPI_Send(prime,len,MPI_CHAR,5,0,MPI_COMM_WORLD);
	}
	else if(process_rank==3){
		int num;
		MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);	
		printf("Processor : %s ---> P3 received number %d from P0\n",processor_name,num);	
		int original_num=num,rem,result=0,len;
		while(original_num!=0){
			rem=original_num%10;
			result+=rem*rem*rem;
			original_num/=10;
		}
		char *armstrong;
		if(num==result){
			armstrong=malloc(sizeof(char)*(strlen("armstrong")+1));
			strcpy(armstrong,"armstrong");
		}
		else{
			armstrong=malloc(sizeof(char)*(strlen("not armstrong")+1));				
			strcpy(armstrong,"not armstrong");
		}
		len= strlen(armstrong)+1;
		MPI_Send(&len,1,MPI_INT,6,0,MPI_COMM_WORLD);		
		MPI_Send(armstrong,len,MPI_CHAR,6,0,MPI_COMM_WORLD);
		
	}
	else if(process_rank==4){
		char *odd_even;
		int len;
		MPI_Recv(&len,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		odd_even=malloc(sizeof(char)*len);
		MPI_Recv(odd_even,len,MPI_CHAR,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);					
		printf("Processor : %s ---> P4 received from P1 that the number is : %s\n",processor_name,odd_even);		
	}
	else if(process_rank==5){
		char *prime;
		int len;
		MPI_Recv(&len,1,MPI_INT,2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		prime=malloc(sizeof(char)*len);
		MPI_Recv(prime,len,MPI_CHAR,2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Processor : %s ---> P5 received from P2 that the number is : %s\n",processor_name,prime);
	}
	else if(process_rank==6){
		char *armstrong;
		int len;
		MPI_Recv(&len,1,MPI_INT,3,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		armstrong=malloc(sizeof(char)*len);
		MPI_Recv(armstrong,len,MPI_CHAR,3,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Processor : %s ---> P6 received from P3 that the number is :%s number\n",processor_name,armstrong);
	}
	MPI_Finalize();
}
