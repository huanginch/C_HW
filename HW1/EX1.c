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

char *toLowercase(char str[]){

	int i;
	for(i = 0; i < strlen(str); i++){
		str[i] = tolower(str[i]);
	}
	return str;
}

int main(void){
	int i, j;// use for loop
	char inputSTR[STRLEN], article[ARTLEN];//the input string and input article
	char *pattern, *replacement; // the pattern and replacement
	char *parameter = NULL; // the parameter and it's default is "\0"

	//init the inputSTR and article
	for(i = 0; i < STRLEN; i++){
		inputSTR[i] = '\0';
	}
	for(i = 0; i < ARTLEN; i++){
		article[ARTLEN] ='\0';
	}

	//read the inputSTR
	fprintf(stderr, "Enter pattern, replacement, and at most one parameter:\n");
	fgets(inputSTR, STRLEN, stdin);
	inputSTR[STRLEN - 1] = '\0';

	/*handle the input string*/
	
	//get the pattern, replacement and parameter
	const char ds[] = " !?@#$%^&*()_+={}[]\\\n\t\r;:";//the delim for the string
	pattern = strtok(inputSTR, ds);
	replacement = strtok(NULL, ds);
	parameter = strtok(NULL, ds);

	//read the article
	while( fgets(article, ARTLEN, stdin) != NULL ){
		
		article[ARTLEN - 1] = '\0';//put \0 to the end of the article

		//count for the size of dilem to split the article
		int count = 0;
		
		for(i = 0; i < ARTLEN; i++){
			if(!(isalnum(article[i]) || article[i] == '-')){
				count++;
			}
		}

		char tmp_da[count];//the temp delim array for the article
		char *word; //the word in the article
		char *body; // the pattern should be replace
		
		//find the char which is not alphabet, number and dash. And then put them into tmp_da
		for(i = 0; i < ARTLEN; i++){
			if(!(isalnum(article[i]) || article[i] == '-')){
				for(j = 0; j < count; j++){
					if(tmp_da[j] ==  article[i]){ //if the char is already put in the tmp_da, skip it.
						break;
					}
					if(j == strlen(tmp_da)){ 
						//if all the elements of tmp_da is not as same as the char, put it into tmp_da
						tmp_da[j] = article[i];
						break;
					}
				}
			}
		}

		//strtok ask for const char
		const char *da;
		da = tmp_da;

		/*handle the article*/
		if(parameter == NULL){
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

					//print the word should be replaced
					for(j = 0; j < i; j++){
						//the characters before pattern in the word
						printf("%c",wordarr[j]);
					}
					printf("%s", replacement);
					for(j = i+strlen(pattern); j < strlen(wordarr); j++){
						//the characters after the pattern in the word
						printf("%c",wordarr[j]);
					}
					printf("\n");


				}
				word = strtok(NULL, da);
			}

					



		}
		else if(!(strncmp(parameter, "-i", 3))){
			//if the parameter is -i

			char *lower_pattern = toLowercase(pattern);
			strcpy(article, toLowercase(article));

			word = strtok(article, da);

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
			break;
		}
		
	}


}
