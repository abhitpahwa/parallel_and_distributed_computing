//PRINT THE NUMBER OF VOWELS AND CONSONANTS IN A GIVEN TEXT FILE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<ctype.h>

int size=0;

void *vowel(void *letters){
	char *b;
	b=(char *)letters;
	int total=0;
	for(int i=0;i<size;i++){
		if (((b[i]>='a' && b[i]<='z') || (b[i]>='A' && b[i]<='Z')) && (b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u')) {
		total++;
		}
	}
	printf("vowels: %d\n",total);
}

void *consonant(void *letters){
	char *b;
	b=(char *)letters;
	int total=0;
	for(int i=0;i<size;i++){
		if(((b[i]>='a' && b[i]<='z') || (b[i]>='A' && b[i]<='Z')) && !(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u')){
		total++;
		}	
	}
	printf("consonants: %d\n",total);
}

int main(){
	FILE *fp;
	char ch,letters[100];
	fp=fopen("textfile.txt","r");
	
	if(fp==NULL){
		perror("error opening the file \n");
		exit(EXIT_FAILURE);
	}
	
	int i=0;
	
	while((ch=fgetc(fp))!=EOF){
		letters[i++]=ch;
		size++;
	}
	
	fclose(fp);
	pthread_t thread1,thread2;
	int p1,p2;
	p1=pthread_create(&thread1,NULL,vowel,(void*)letters);
	
	if(p1){
		fprintf(stderr,"Error in pthread_create() with return code: %d\n",p1);
		exit(EXIT_FAILURE);
	}

	p2=pthread_create(&thread2,NULL,consonant,(void*)letters);

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

