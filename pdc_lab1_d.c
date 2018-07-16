//REVERSE A STRING AND REPLACING THE STRING LETTERS WITH THE NEXT LETTER IN ALPHABETS
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void *reverse(void *string_input){
	char *b=(char *)string_input;
	int i=0,j=strlen(b)-1;
	char temp;
	
	while(i<j){
		temp=b[i];
		b[i]=b[j];
		b[j]=temp;
		i++;
		j--;
	}
	
	printf("%s\n",b );
}

void *shift(void *string_input){
	char *b=(char *)string_input;
	
	for(int i=0;i<strlen(b)-1;i++){
		b[i]=(char)(b[i]+1);
	
	}
	
	printf("%s\n",b );
}

int main(){
	char string_input[200],string_input_cpy[200];
	printf("enter the string: ");
	fgets(string_input,200,stdin);
	strcpy(string_input_cpy,string_input); 
	
	/* copied the string because if passed same char array to both threads,
	 the string manipualates and thus the results
	*/

	pthread_t thread1,thread2;
	int p1,p2;
	p1=pthread_create(&thread1,NULL,reverse,string_input);
	
	if(p1){
		fprintf(stderr,"Error in pthread_create() with return code: %d\n",p1);
		exit(EXIT_FAILURE);
	}
	
	p2=pthread_create(&thread2,NULL,shift,string_input_cpy);
	
	if(p2){
		fprintf(stderr,"Error in pthread_create() with return code: %d\n",p2);
		exit(EXIT_FAILURE);
	}
	
	printf("pthread_create() for thread1 returns: %d\n",p1);
	printf("pthread_create() for thread2 returns: %d\n",p2);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	exit(EXIT_SUCCESS);

}

