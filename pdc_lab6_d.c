#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	int *primes;
	primes=malloc((n+1)*sizeof(int));
	int i,j;
	for(i=2;i<n;i++){
		primes[i]=i;
	}
	for(i=2;i<n;i++){
		if(primes[i]!=0){
			for(j=i;i*j<n;j++){
				primes[i*j]=0;
			}
		}
	}
	printf("Prime numbers from 1 to %d\n",n);
	for(i=2;i<n;i++){
		if(primes[i]!=0)
			printf("%d ",primes[i]);
	}
	printf("\n");
}