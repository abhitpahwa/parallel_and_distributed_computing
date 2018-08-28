//GET SUM OF ELEMENTS OF A VECTOR USING OMP REDUCTION

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main(){
	int v1[10]={1,2,3,4,5,6,7,8,9,10};
	int sum=0,i;
	omp_set_num_threads(4);
	#pragma omp parallel for reduction(+:sum)
		for (i = 0; i < 10; ++i)
		{
			sum+=v1[i];
		}
	printf("%d",sum);
	
}
