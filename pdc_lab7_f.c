//PTHREAD PROGRAM TO COMPUTE PRIME NUMBERS USING SIEVE OF ERATOSTHENES

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int *primes;

void *prime(void *num){
	int *n=(int *)num;
	int i,j;
	for(i=2;i<*n;i++){
		if(primes[i]!=0){
			for(j=i;i*j<*n;j++){
				primes[i*j]=0;
			}
		}
	}
}

int main(){
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	primes=malloc((n+1)*sizeof(int));
	int i,j;
	for(i=2;i<n;i++){
		primes[i]=i;
	}
	pthread_t thread1;
	int p1,p2;
	p1=pthread_create(&thread1,NULL,prime,&n);
	if(p1){
		fprintf(stderr, "Error in pthread_create() with return code %d\n", p1);
		exit(EXIT_FAILURE);
	}
	printf("pthread_create() for thread1 returns: %d\n",p1);
	pthread_join(thread1,NULL);
	printf("Prime numbers from 1 to %d\n",n);
	for(i=2;i<n;i++){
		if(primes[i]!=0)
			printf("%d ",primes[i]);
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
