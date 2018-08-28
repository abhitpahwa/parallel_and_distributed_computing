//COUNT NUMBER OF VOWELS AND CONSONANTS IN A TEXT FILE USING OMP

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<string.h>
#include<sys/stat.h>

void main(){
	struct stat sb;
	stat("name.txt",&sb);
	FILE *fp = fopen("name.txt","r");
	char *content = malloc(sb.st_size+1);
	fread(content,1,sb.st_size,fp);
	fclose(fp);
	content[sb.st_size]=0;
	int vowels=0,consonants=0;

	#pragma omp parallel
	{
		#pragma omp sections
		{
			#pragma omp section
			{
				int i;

				for(i=0;i<sb.st_size;i++){
					if(((content[i]>='a' && content[i]<='z') || (content[i]>='A' && content[i]<='Z')) && ((content[i]=='a'||content[i]=='e'||content[i]=='i'||content[i]=='o'||content[i]=='u') || (content[i]=='A'||content[i]=='E'||content[i]=='I'||content[i]=='O'||content[i]=='U'))){
						vowels++;
					}
				}
			}

			#pragma omp section
			{
				int i;

				for(i=0;i<sb.st_size;i++){
					if(((content[i]>='a' && content[i]<='z') || (content[i]>='A' && content[i]<='Z')) && (!(content[i]=='a'||content[i]=='e'||content[i]=='i'||content[i]=='o'||content[i]=='u' || content[i]=='A'||content[i]=='E'||content[i]=='I'||content[i]=='O'||content[i]=='U'))){
						consonants++;
					}
				}
			}
		}
	}

	printf("Number of vowels: %d\n",vowels);
	printf("Number of consonants: %d\n",consonants);
}
