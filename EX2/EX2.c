#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>

#define STRLEN 100 //the length of input string
#define ARTLEN 4095 //the length of input article
#define DEBUG 1
#define initArr(arr, arrlen) 			\
	for(int i = 0; i <= arrlen; i++){	\
		arr[i] = '\0';					\
	}
#define validCase(caseNum) (caseNum != 2)
#define check_para(parameter, caseNum) \
	if(parameter == NULL){	\
		caseNum = 0;	\
	}	\
	else if(!(strncmp(parameter, "-i", 3))){	\
		caseNum = 1;	\
	}	\
	else{	\
		caseNum = 2;	\
	}

char *toLowercase(char str[]);//make string to lower case
int check_str(char *target); //check the format of string1 and string2
void PRINTRES(char word[], int repIndex, char *pattern, char *replacement); // print the word is replacemented
int countDelim(char article[]); //count the time that the special character appear
void findDelim(char article[], char tmp_da[], int count);//find the delim for the article
void handleCase0(char article[], const char *da, char *pattern, char *replacement); // handle case 0
void handleCase1(char article[], const char *da, char *pattern, char *replacement); // handle case 1

int main(void){
	int i;// use for loop
	char inputSTR[STRLEN + 1], article[ARTLEN + 1];//the input string and input article
	char *pattern = '\0', *replacement = '\0'; // the pattern and replacement
	char *parameter = '\0', *rest = NULL; // the parameter and it's default is NULL. The string after parameter
	int caseNum = 0;//save the case numer: 0-> no parameter, 1-> -i, 2->invalid

	//init the inputSTR and article
	initArr(inputSTR, STRLEN);
	initArr(article, ARTLEN);

	//read the inputSTR
	fgets(inputSTR, STRLEN, stdin);
	inputSTR[STRLEN] = '\0';

	/*handle the input string*/
	
	//get the pattern, replacement and parameter
	const char ds[] = " \n\r\t";//the delim for the string
	pattern = strtok(inputSTR, ds);
	replacement = strtok(NULL, ds);
	parameter = strtok(NULL, ds);
	rest = strtok(NULL, ds);// the rest input string

	//check the parameter and decided the case number
	check_para(parameter, caseNum);

	if( (check_str(pattern) && check_str(replacement) && validCase(caseNum) && (rest == NULL)) ){
		
		#if DEBUG
			printf("this is case %d\n", caseNum);
		#endif

		//read the article
		while( fgets(article, ARTLEN, stdin) != NULL ){

			article[ARTLEN] = '\0';//put \0 to the end of the article

			//count for the size of dilem to split the article
			int count = countDelim(article);

			char tmp_da[count];//the temp delim array for the article
			initArr(tmp_da, count-1);

			//find the char which is not alphabet, number and dash. And then put them into tmp_da
			findDelim(article, tmp_da, count);

			//strtok ask for const char
			const char *da;
			da = tmp_da;

			/*handle the article*/
			if(caseNum == 0){
				//if no input parameter
				
				handleCase0(article, da, pattern, replacement);
				

			}
			else if(caseNum == 1){
				//if the parameter is -i
				
				handleCase1(article, da, pattern ,replacement);

			}	
		}
	}
	else{
		
		printf("The input format: string1 string2 [parameter]\n");
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

void PRINTRES(char word[], int repIndex, char *pattern, char *replacement){
	int i;

	for(i = 0; i < repIndex; i++){
		//the characters before pattern in the word
		printf("%c",word[i]);
	}

	printf("%s", replacement);
						
	for(i = repIndex+strlen(pattern); i < strlen(word); i++){
	//the characters after the pattern in the word
		printf("%c",word[i]);
	}

	printf("\n");
}

void findDelim(char article[], char tmp_da[], int count){
	
	int i, j;

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
}

int countDelim(char article[]){
	int i, count = 0;
	for(i = 0; i < ARTLEN; i++){
		if(!(isalnum(article[i]) || article[i] == '-')){
			count++;
		}
	}

	return count;
}

void handleCase0(char article[], const char *da, char *pattern, char *replacement){
	//slice the article
	char *word = strtok(article, da);//the word in the article
	char *body; // the pattern should be replace
	int i;

	while(word != NULL){
					
		#if DEBUG
			printf("the word is: %s\n", word);
		#endif

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
			PRINTRES(word, i, pattern, replacement);
		}
		word = strtok(NULL, da);
	}
}

void handleCase1(char article[], const char *da, char *pattern, char *replacement){
	
	char *lower_pattern = toLowercase(pattern); //change pattern to lower case
	char *word = strtok(article, da); //the word in the article
	char *body; //the pattern should be replace
	int i;

	while(word != NULL){
					
		#if DEBUG
			printf("the word is: %s\n", word);
		#endif

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
			PRINTRES(o_word, i, pattern, replacement);

		}
		word = strtok(NULL, da);
	}
}
