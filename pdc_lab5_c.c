//Reader writer problem using semaphores

#include<stdio.h>
#include<stdbool.h>

struct semaphore
{
	int mutex;
	int rcount;
	int rwait;
	bool wrt;
};

void add_reader(struct semaphore *s){
	if(s->mutex==0 && s->rcount==0){
		printf("\nSorry, file open in write mode\nNew reader added to queue\n");
		s->rwait++;
	}
	else{
		printf("\nReader process added\n");
		s->rcount++;
		s->mutex--;
	}
	return;
}

void add_writer(struct semaphore *s){
	if(s->mutex==1){
		s->mutex--;
		s->wrt=1;
		printf("\nWriter process added\n");
	}
	else if(s->wrt)
		printf("\nSorry, writer already engaged\n");
	else
		printf("\nfile open in read mode\n");
	return;
}

void remove_reader(struct semaphore *s){
	if(s->rcount==0)
		printf("\nno readers to remove\n");
	else{
		printf("\nReader removed\n");
		s->rcount--;
		s->mutex++;
	}
	return;
}

void remove_writer(struct semaphore *s){
	if(s->wrt==0)
		printf("\nNo writer to remove\n");
	else{
		printf("\nWrite removed\n");
		s->mutex++;
		s->wrt=0;
		if(s->rwait!=0){
			s->mutex=s->rwait;
			s->rcount=s->rwait;
			s->rwait=0;
			printf("\n%dwaiting readers added",s->rcount);
		}
	}
	return;
}
	
int main(){
	struct semaphore s={1,0,0};
	while(1)
	{
		printf("Options:-\n1. Add reader\n2. Add writer\n3. Remove reader\n4. Remove writer\n5. Exit\nChoice: ");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	add_reader(&s);
					break;
			case 2: add_writer(&s);
					break;
			case 3: remove_reader(&s);
					break;
			case 4: remove_writer(&s);
					break;
			case 5: printf("Exiting..");
					return;		
			default: printf("Enter a value\n");
					continue;
		}
		printf("\n\n<<<<<<<Current status>>>>>>>\n\tMutex\t\t:\t%d\n\tActive readers\t:\t%d\n\tWaiting readers\t:\t%d\n\tWriter active\t:\t%s\n\n",s.mutex,s.rcount,s.rwait,(s.mutex==0 
			&& s.rcount==0)?"yes":"no");
		//system("pause");
	}
	return 0;
}