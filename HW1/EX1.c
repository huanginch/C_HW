#include <stdio.h>
#include<string.h>

#define STRLEN 100 //the length of input string
#define ARTLEN 4095 //the length of input article 

int main(void){
	int i;// use for loop
	char inputSTR[STRLEN], article[ARTLEN];//the input string and input article
	char *pattern, *replacement; // the pattern and replacement
	char *parameter = NULL; // the parameter and it's default is "\0"
	
	puts("Enter pattern, replacement, and at most one parameter:");
	fgets(inputSTR, STRLEN, stdin);

	/*handle the input string*/
	
	//get the pattern, replacement and parameter
	const char *d = " ";
	pattern = strtok(inputSTR, d);
	replacement = strtok(NULL, d);
	parameter = strtok(NULL, d);
	
	while( fgets(article, ARTLEN, stdin) != NULL ){
		/*handle the article*/
		if(parameter == NULL){
			//if no input parameter
			//strtok->strstr->strncpy-fprint

		}
		else if(!(strncmp(parameter, "-i", 2))){
			//if the parameter is -i
		}
		else{
			//if invalid input parameter
			puts("The input format : string1 string2 [parameter]");
		}
		
	}


}
