#include <stdio.h>
#include<string.h>

#define STRLEN 100 //the length of input string
#define ARTLEN 4095 //the length of input article 

/*
   Upper case to lower case
	char c = 'A';
	c = c -'A' + 'a';
*/

int strcpy_hw(char *str1, char *str2){
	/*my strcpy to fit the question*/
}

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

		/*handle the article*/
		if(parameter == NULL){
			
			//printf("the parameter is null\n");
			//if no input parameter
			
			const char da[] = " !?@#$%^&*()_+={[}]\\\n\t\r;:"; //the delim for the article
			char *word; //the word in the article
			char *body; // the pattern should be replace

			//slice the article
			word = strtok(article, da);

			while(word != NULL){
				
				//put the sliced word into the array
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
		else if(!(strncmp(parameter, "-i", 3))){
			printf("the parameter is -i\n");
			//if the parameter is -i
			/*pattern and article should be change to lower case to compare*/
		}
		else{
			//if invalid input parameter
			printf("The input format : string1 string2 [parameter]\n");
		}
		
	}


}
