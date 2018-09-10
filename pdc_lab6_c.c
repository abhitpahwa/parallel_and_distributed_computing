//CREATE 2 CHILD PROCESS AND PRINT PRIME NUMBER AND ARMSTRONG NUMBER FROM 1 TO 1000 USING THOSE 2 CHILD PROCESSES

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

void check_prime(int i){
	int x;
	for(x=2;x<=i/2+1;x++){
		if(i%x==0)
			return;
	}
	printf("%d ",i);
	return;
}

void prime(){
	int i;
	printf("2 ");
	for(i=3;i<1000;i++)
		check_prime(i);
	printf("\n");
}

void check_armstrong(int i){
	int num=i,sum=0,digits=0;
	while(num!=0){
		int n=num%10;
		sum+=n*n*n;
		num=num/10;
	}
	if(sum==i)
		printf("%d ",i);
}

void armstrong(){
	int i;
	for(i=1;i<1000;i++)
		check_armstrong(i);
}

int main(){
	pid_t pid_a = fork();
	if(pid_a==0){
		printf("Child process 1 will now print prime numbers from 1 to 1000: \n");
		prime();
		// printf("TEST\n");
		pid_t pid_b = fork();
		if(pid_b==0){
			printf("\nChild process 2 will now print armstrong numbers from 1 to 1000: \n");
			armstrong();
			// kill(pid_b,SIGTERM);
		}
		wait(0);
		// kill(pid_a,SIGTERM);
	}
	wait(0);
}