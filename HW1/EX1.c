#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>

#define STRLEN 100 //the length of input string
#define ARTLEN 4095 //the length of input article 

/*
   Upper case to lower case
	char c = 'A';
	c = c -'A' + 'a';
*/

/*char *strslice(char article[], char *stop){
	char word[];
	int i;
	my slice string func to fit the question
	
	for(i = 0; i < ARTLEN; i++){
		if(&article[i] == stop){
			break;
		}
	}
	
	for(i ; i < ARTLEN; i++){
		if(isalnum(article[i]) || article[i] == '-'){
			strcpy(word[i], article[i]);
		}
		else{
			break;
		}
	}
	stop = &article[i+1];
	word[i] = '\0'

	return word;
}*/

int main(void){
	int i, j;// use for loop
	char inputSTR[STRLEN], article[ARTLEN];//the input string and input article
	char *pattern, *replacement; // the pattern and replacement
	char *parameter = NULL; // the parameter and it's default is "\0"

	/*init the inputSTR and article*/
	for(i = 0; i < STRLEN; i++){
		inputSTR[i] = '\0';
	}
	for(i = 0; i < ARTLEN; i++){
		article[ARTLEN] ='\0';
	}

	/*read the inputSTR*/
	fprintf(stderr, "Enter pattern, replacement, and at most one parameter:\n");
	fgets(inputSTR, STRLEN, stdin);
	inputSTR[STRLEN - 1] = '\0';

	/*handle the input string*/
	
	//get the pattern, replacement and parameter
	const char ds[] = " !?@#$%^&*()_+={}[]\\\n\t\r;:";//the delim for the string
	pattern = strtok(inputSTR, ds);
	replacement = strtok(NULL, ds);
	parameter = strtok(NULL, ds);
	
	while( fgets(article, ARTLEN, stdin) != NULL ){
		
		article[ARTLEN - 1] = '\0';

		
		int count = 0; //count for the size f da
		
		for(i = 0; i < ARTLEN; i++){
			if(!(isalnum(article[i]) || article[i] == '-')){
				count++;
			}
		}

		char tmp_da[count];//the delim for the article
		char *word; //the word in the article
		char *body; // the pattern should be replace
		char *stop = article;

		for(i = 0; i < ARTLEN; i++){
			if(!(isalnum(article[i]) || article[i] == '-')){
				for(j = 0; j < count; j++){
					if(tmp_da[j] ==  article[i]){
						break;
					}
					if(j == strlen(tmp_da)){
						tmp_da[j] = article[i];
						break;
					}
				}
			}
		}

		const char *da;
		da = tmp_da;

		/*handle the article*/
		if(parameter == NULL){
			
			//printf("the parameter is null\n");
			//if no input parameter
			

			//slice the article

			word = strtok(article, da);

			while(word != NULL){
				
				//put the sliced word into an array
				char wordarr[strlen(word)];
				strcpy(wordarr, word);

				//handle the replace
				if( body = strstr(wordarr, pattern) ){
					for(i = 0; i < strlen(wordarr); i++){
						if(&wordarr[i] == body)
							break;
					}

					//print the word after replaced
					for(j = 0; j < i; j++){
						printf("%c",wordarr[j]);
					}
					printf("%s", replacement);
					for(j = i+strlen(pattern); j < strlen(wordarr); j++){
						printf("%c",wordarr[j]);
					}
					printf("\n");


				}
				word = strtok(NULL, da);
			}

					



		}
		else if(!(strncmp(parameter, "-i", 3))){
			printf("the parameter is -i\n");
			//if the parameter is -i
			/*pattern and article should be change to lower case to compare*/



			while(word != NULL){
				
				//put the sliced word into an array
				char wordarr[strlen(word)];
				strcpy(wordarr, word);

				/*handle the replace*/
				if( body = strstr(wordarr, pattern) ){
					for(i = 0; i < strlen(wordarr); i++){
						if(&wordarr[i] == body)
							break;
					}

					//print the word after replaced
					for(j = 0; j < i; j++){
						printf("%c",wordarr[j]);
					}
					printf("%s", replacement);
					for(j = i+strlen(pattern); j < strlen(wordarr); j++){
						printf("%c",wordarr[j]);
					}
					printf("\n");


				}
				word = strtok(NULL, da);
			}

		}
		else{
			//if invalid input parameter
			printf("The input format : string1 string2 [parameter]\n");
		}
		
	}


}
