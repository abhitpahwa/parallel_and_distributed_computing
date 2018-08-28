//PRINT THE MAXIMUM VALUE OF A VECTOR USING REDUCTION

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>

void main(){
	int arr[100000];
	omp_set_num_threads(4);
	srand(time(0));
	int i;

	#pragma omp parallel for 
		for(i=0;i<100000;i++)
			arr[i]=rand();

	int maxval=arr[0];

	#pragma omp parallel for reduction(max:maxval)
		for(i=1;i<100000;i++){
			if(arr[i]>maxval)
				maxval=arr[i];
		}

	printf("%d\n", maxval);
}
