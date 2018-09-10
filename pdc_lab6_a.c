//PRODUCER-CONSUMER PROBLEM USING SECTIONS AND CRITICAL IN OMP

#include<stdio.h>
#include<unistd.h>
#include<omp.h>

int full=0,empty=7,x=0;

void producer(){
	#pragma omp critical 
	{
		if(full<=empty){
			x++;
			full++;
			empty--;
			printf("Producer: produced the item: %d\n",x);
		}
		else
			printf("Producer: Already full\n");
	}
}

void consumer(){
	#pragma omp critical
	{
		if(full>0){
			full--;
			empty++;
			printf("Consumer: consumed item: %d\n",x);
			x--;
		}
		else
			printf("Consumer: Already empty\n");
	}
}

int main(){
	int num_prod,num_cons;
	printf("Enter number of producers: ");
	scanf("%d",&num_prod);
	printf("Enter number of consumers: ");
	scanf("%d",&num_cons);
	#pragma omp parallel 
	#pragma omp sections 
	{
		#pragma omp section 
		{
			int i=0;
			for(i=0;i<num_prod;i++){
				producer();
				//sleep(0.01);
				//can add sleep to add delay in producer process to view different outputs because of scheduling and other overheads
			}		

		}
		#pragma omp section
		{
			int i;
			for(i=0;i<num_cons;i++){
				consumer();
				//sleep(0.01);  
				//can add sleep to make delay in consumer process to view different outputs because of scheuling and other overheads			
			}
		}
	}
}