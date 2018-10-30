//MPI code to scatter elements of an array to all processes and print digits of number as name
#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
char * number_to_text(int num){
	char *test1,*test2="";
	char *name="";
	int array[MAX],rem,i=0,j;
	if(num==0){
		array[i++]=0;
	}
	else{
		while(num>0){
		rem=num%10;
		array[i++]=rem;
		num=num/10;
	}
	}
	char * cpy_name;
	for(j=i-1;j>=0;j--){
		cpy_name=malloc(strlen(name)+1);
		strcpy(cpy_name,name);
		switch(array[j]){
			case 0: 
			test2="zero ";
			name=malloc(strlen(name)+strlen(test2)+1);
			strcpy(name,cpy_name);
			strcat(name,test2);break;
			case 1: 
			test2="one ";
			name=malloc(strlen(name)+strlen(test2)+1);
			strcpy(name,cpy_name);
			strcat(name,test2);break;
			case 2: 
			test2="two ";
			name=malloc(strlen(name)+strlen(test2)+1);
			strcpy(name,cpy_name);
			strcat(name,test2);break;
			case 3: 
			test2="three ";
			name=malloc(strlen(name)+strlen(test2)+1);
			strcpy(name,cpy_name);
			strcat(name,test2);break;
			case 4: 
			test2="four ";
			name=malloc(strlen(name)+strlen(test2)+1);
			strcpy(name,cpy_name);
			strcat(name,test2);break;
			case 5: 
			test2="five ";
			name=malloc(strlen(name)+strlen(test2)+1);
			strcpy(name,cpy_name);
			strcat(name,test2);break;
			case 6: 
			test2="six ";
			name=malloc(strlen(name)+strlen(test2)+1);
			strcpy(name,cpy_name);
			strcat(name,test2);break;
			case 7: 
			test2="seven ";
			name=malloc(strlen(name)+strlen(test2)+1);
			strcpy(name,cpy_name);
			strcat(name,test2);break;
			case 8: 
			test2="eight ";
			name=malloc(strlen(name)+strlen(test2)+1);
			strcpy(name,cpy_name);
			strcat(name,test2);break;
			case 9: 
			test2="nine ";
			name=malloc(strlen(name)+strlen(test2)+1);
			strcpy(name,cpy_name);
			strcat(name,test2);break;
			default:break;
		}
	}
	name[strlen(name)-1]='\0';
	return (char *)name;
}
int main(){
	MPI_Init(NULL,NULL);
	int size,rank;
	char processor_name[15];
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int name_len;
	MPI_Get_processor_name(processor_name,&name_len);
	int array1[16];
	int sub_array;
	int r;
	if(rank==0){
		for(r=0;r<size;r++)
			array1[r]=r;
	}
	MPI_Scatter(array1,1,MPI_INT,&sub_array,1,MPI_INT,0,MPI_COMM_WORLD);
	printf("P%d on %s has data %d which is %s\n",rank,processor_name,sub_array,number_to_text(sub_array));
	MPI_Finalize();
	return 0;
}