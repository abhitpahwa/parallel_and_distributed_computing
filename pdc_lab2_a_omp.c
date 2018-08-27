//BASIC INTRODUCTION CODE TO OMP

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main(){
	int i=0;
	#pragma omp parallel
	{
		#pragma omp for
		for (i=0; i<10000; ++i)
			printf("%d\n",i+1);
	}	
}
