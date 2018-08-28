//PRINT THE NUMBER OF WORDS OCCURING MORE THAN TWICE IN A TEXT FILE USING OMP REDUCTION

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<string.h>
#include<ctype.h>

typedef char *string;
void main(){
	int i=0,num=0;
	int cur_size=0;
	FILE *fp;
	fp=fopen("textfile1.txt","r");
	char ch;
	ch=fgetc(fp);
	while(ch!=EOF){
		if(isspace(ch)|| ch=="\n")
			num++;
		ch=fgetc(fp);
	}
	fclose(fp);

	string array[num]; 

	fp=fopen("textfile1.txt","r");	
	for(i=0;i<num;i++){
		fscanf(fp,"%*s%n",&cur_size);
		array[i]=malloc((cur_size+1)*sizeof(*array[i]));

	}
	fclose(fp);

	fp=fopen("textfile1.txt","r");
	for(i=0;i<num;i++){
		fscanf(fp,"%s",array[i]);
	}
	fclose(fp);
	

	int sum=0;
	omp_set_num_threads(4);
	#pragma omp parallel for reduction(+:sum)
	for(i=0;i<num;i++){
		int temp_sum=0;
		int j=0;
		for(j=0;j<num;j++){
			if(strcmp(array[i],array[j])==0){
				if(j<i){
					temp_sum=0;
					break;
				}
				temp_sum++;
			}
		}
		if(temp_sum>2){
			printf("%s is repeated %d times\n",array[i],temp_sum );
			sum++;
		}
	}

	printf("total number of words occuring more than twice is: %d\n",sum );

	for(i=0;i<num;i++){
		free(array[i]);
	}
}
