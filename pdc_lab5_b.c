//Producer consumer problem using openmp

#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty=10,x=0;

int main(){
	int n;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);
	printf("\n1.Producer\n2.Consumer\n3.Exit");
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d",&n);
		switch(n){
			case 1: if((mutex==1) && (empty!=0))
						producer();
					else
						printf("\nBuffer is full");
					break;
			case 2:	if((mutex==1) && (full!=0))
						consumer();
					else
						printf("\nBuffer is empty");
					break;
			case 3: exit(0);
					break;
		}
	}
}
int wait(int s){
	return --s;
}
int signal(int s){
	return ++s;
}
void producer(){
	#pragma omp parallel
	{
		#pragma omp single
		{
			mutex=wait(mutex);
			full=signal(full);
			empty=wait(empty);
			x++;
			printf("\nProducer produces the item %d",x);
			mutex=signal(mutex);
		}
	}
}
void consumer(){
	#pragma omp parallel
	{
		#pragma omp critical
		{
			mutex=wait(mutex);
			if(full!=0)
			{	
				full=wait(full);
				empty=signal(empty);
				printf("\n Consumer consumes item %d",x);
				x--;	
			}
			mutex=signal(mutex);
		}
	}
}