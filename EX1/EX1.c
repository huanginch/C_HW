#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>

#define STRLEN 100 //the length of input string
#define ARTLEN 4095 //the length of input article 

char *toLowercase(char str[]);//make string to lower case
int check_str(char *target); //check the format of string1 and string2


int main(void){
	int i, j;// use for loop
	char inputSTR[STRLEN + 1], article[ARTLEN + 1];//the input string and input article
	char *pattern = NULL, *replacement = NULL; // the pattern and replacement
	char *parameter = NULL, *rest = NULL; // the parameter and it's default is NULL. The string after parameter

	//init the inputSTR and article
	for(i = 0; i <= STRLEN; i++){
		inputSTR[i] = '\0';
	}
	for(i = 0; i <= ARTLEN; i++){
		article[i] ='\0';
	}

	//read the inputSTR
	//fprintf(stderr, "Enter pattern, replacement, and at most one parameter:\n");
	fgets(inputSTR, STRLEN, stdin);
	inputSTR[STRLEN] = '\0';

	/*handle the input string*/
	
	//get the pattern, replacement and parameter
	const char ds[] = " \n\0";//the delim for the string
	pattern = strtok(inputSTR, ds);
	replacement = strtok(NULL, ds);
	parameter = strtok(NULL, ds);
	rest = strtok(NULL, ds);

	//printf("pattern: %s\n", pattern);
	//printf("replacement: %s\n", replacement);
	
	if( (check_str(pattern) && check_str(replacement) && (rest == NULL)) ){

		//read the article
		while( fgets(article, ARTLEN, stdin) != NULL ){

			
			article[ARTLEN] = '\0';//put \0 to the end of the article

			//count for the size of dilem to split the article
			int count = 0;
			
			for(i = 0; i < ARTLEN; i++){
				if(!(isalnum(article[i]) || article[i] == '-')){
					count++;
				}
			}

			char tmp_da[count];//the temp delim array for the article
			for(i = 0; i < count; i++){
				tmp_da[i] = '\0';
			}
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
					
					int wordLEN = strlen(word); 

					//put the sliced word into an array
					char wordarr[wordLEN + 1];
					strcpy(wordarr, word);

					//handle the replace
					if( (body = strstr(wordarr, pattern)) != 0 ){
						for(i = 0; i < wordLEN; i++){
							if(&wordarr[i] == body)
								break;
						}

						//print the word should be replaced
						for(j = 0; j < i; j++){
							//the characters before pattern in the word
							printf("%c",wordarr[j]);
						}
						printf("%s", replacement);
						for(j = i+strlen(pattern); j < wordLEN; j++){
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
				
				//change pattern to lower case
				char *lower_pattern = toLowercase(pattern);

				word = strtok(article, da);

				while(word != NULL){

					int wordLEN = strlen(word);
					
					//put the sliced word into an array and it is the origin version
					char o_word[wordLEN + 1];
					strcpy(o_word, word);

					//change the word to lower case and save a lower case array version 
					toLowercase(word);
					char lower_word[wordLEN + 1];
					strcpy(lower_word, word);

					/*handle the replace*/
					if( (body = strstr(lower_word, lower_pattern)) != 0 ){
						for(i = 0; i < wordLEN; i++){
							if(&lower_word[i] == body)
								break;
						}

						//print the word after replaced(origin version)
						for(j = 0; j < i; j++){
							printf("%c",o_word[j]);
						}
						printf("%s", replacement);
						for(j = i+strlen(lower_pattern); j < wordLEN; j++){
							printf("%c",o_word[j]);
						}
						printf("\n");


					}
					word = strtok(NULL, da);
				}

			}
			else{
				//if invalid input parameter
				printf("The input format: string1 string2 [parameter]");
				break;
			}	
		}
	}
	else{
		printf("The input format: string1 string2 [parameter]");
	}

	return 0;

}

char *toLowercase(char str[]){

	int i;
	for(i = 0; i < strlen(str); i++){
		str[i] = tolower(str[i]);
	}
	return str;
}

int check_str(char *target){//valid->0 invalid->1

	int i = 0, is_valid = 1;

	if(target == NULL){

		is_valid = 0;

	}
	else{

		char str[strlen(target) + 1];
		strcpy(str, target);

		for(i = 0; i < strlen(str); i++){
			if(!(isalnum(str[i]) || str[i] == '-')){
				//the char is not alphabet, number or dash
				is_valid = 0;
			}
		}

	}

	return is_valid;
	
}
