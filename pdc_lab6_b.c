//PRODUCER-CONSUMER PROBLEM USING SECTIONS AND LOCKS IN OMP

#include<stdio.h>
#include<unistd.h>
#include<omp.h>

int full=0,empty=7,x=0;
omp_lock_t update_lock;

void producer(){
	omp_set_lock(&update_lock);
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
	omp_unset_lock(&update_lock);
}

void consumer(){
	omp_set_lock(&update_lock);
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
	omp_unset_lock(&update_lock);
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