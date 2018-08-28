//ADD SUM OF ELEMENTS OF VECTOR USING OMP SECTIONS

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main(){
	int v1[10]={1,2,3,4,5,6,7,8,9,10};
	int v2[10]={11,12,13,14,15,16,17,18,19,20};
	omp_set_num_threads(2);
	int sum_v1=0,sum_v2=0;

	#pragma omp parallel sections
	{
		#pragma omp section
		{
			int i;
			#pragma omp parallel for num_threads(2)
				for(i=0;i<10;i++)
					sum_v1+=v1[i];
		}

		#pragma omp section
		{
			int i;
			#pragma omp parallel for num_threads(2)
				for(i=0;i<10;i++)
					sum_v2+=v2[i];
		}		
	}

	printf("Sum of v1: %d\nSum of v2: %d",sum_v1,sum_v2);
}
