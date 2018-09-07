//Reader writer problem using openmp


#include<stdio.h>
#include<omp.h>

omp_lock_t writelock;
omp_lock_t readlock;
char buf[10]="hello";
int num_readers=0;

void reader(){
	printf("How many readers: ");
	scanf("%d",&num_readers);
	int i=0;
	#pragma omp parallel num_threads(num_readers)
	#pragma omp critical
	{
		omp_set_lock(&writelock);
		omp_set_lock(&readlock);
		printf("Reading by thread id: %d\n",omp_get_thread_num());
		printf("Read content: %s\n",buf );
		omp_unset_lock(&readlock);
		omp_unset_lock(&writelock);
	}
}

void writer(){
	#pragma omp parallel 
	#pragma omp single
	{
	omp_set_lock(&writelock);
	omp_set_lock(&readlock);
	printf("enter the content: ");
	scanf("%s",buf);
	printf("\nwriting %s by thread id: %d\n",buf,omp_get_thread_num());
	omp_unset_lock(&readlock);
	omp_unset_lock(&writelock);
	}
}

int main(){
	omp_set_num_threads(8);
	omp_init_lock(&writelock);
	omp_init_lock(&readlock);
	while(1){
		printf("Options:-\n1. Read\n2. Write\n3. Exit\nEnter your choice: ");
		int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1: reader();
					break;
			case 2: writer();
					break;
			case 3: printf("exiting..\n");
					return 0;
			default: continue;
		}
	}
}