//PRINT PRIME NUMBERS FROM 1 TO 500 AND 501 TO 1000 USING 2 THREADS

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int prime(int n){
	for(int i=2;i<=n/2;i++){
	if(n%i==0)
		return 0;
	}
	return 1;
}

void *print500(){
	int i=1;
	for(i=1;i<=500;i++){
		if(prime(i)==1)
		printf("%d\n",i);
	}
	if(i==2)
		printf("%d\n",i);
}

void *print1000(){
	for(int i=501;i<=1000;i++){
		if(prime(i)==1)
		printf("%d\n",i);
	}
}

int main(){
	pthread_t thread1,thread2;
	int p1,p2;
	p1=pthread_create(&thread1,NULL,print500,NULL);

	if(p1){
		fprintf(stderr,"Error in pthread_create() with return code: %d\n",p1);
		exit(EXIT_FAILURE);
	}
	
	p2=pthread_create(&thread2,NULL,print1000,NULL);
	
	if(p2){
		fprintf(stderr,"Error in pthread_create() with return code: %d\n",p2);
		exit(EXIT_FAILURE);
	}

	printf("pthread_create() for thread1 returns: %d\n",p1);
	printf("pthread_create() for thread2 returns: %d\n",p2);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	exit(EXIT_SUCCESS);
}
