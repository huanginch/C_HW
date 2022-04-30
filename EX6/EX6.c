#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 100

//circular linked list
struct circle{
	char name[NAME_LENGTH + 1];
	struct circle *next;
	struct circle *prior;
};

void create_list(struct circle **first); //create the circular linked list
void add_person(struct circle **first, struct circle **End, char name[]);//add people to the circular linked list
void kill(struct circle **first); //kill people

int main(void){
	
	struct circle *head = NULL;
	create_list(&head);

	kill(&head);

	return 0;
}

void create_list(struct circle **first){
	int i = 0;//use for the loop
	int n = 0; //the number of the courses
	scanf("%d\n", &n);
	
	struct circle *end;

	//create the linked list
	for(i = 0; i < n; i++){
		char input_name[NAME_LENGTH + 1];//name of the course

		scanf("%s", input_name);
		add_person(first, &end, input_name);
	}
	
	//circle the list
	(*first)->prior = end;
	end->next = *first;
	return;
}

void add_person(struct circle **first, struct circle **End, char name[]){
	//create new course node
	struct circle *new_person = malloc(sizeof(struct circle));
	strncpy(new_person->name, name, strlen(name));
	new_person->next = NULL;
	new_person->prior = NULL;

	if(*first == NULL){// if there is no node in the list
		*first = new_person;
		*End = *first;
	}
	else{
		//add new person the the end
		(*End)->next = new_person;
		new_person->prior = *End;
		*End = (*End)->next;
	}
}

void kill(struct circle **first){
	int k; //steps
	int max_d_size = 16; //max direction size is counterclockwise
	char *direction = malloc(max_d_size + 1);
	int i;
	
	fflush(stdin);
	scanf("%d %s\n", &k, direction);

	struct circle *current = *first;//the current person
	struct circle *prev = NULL;//the previous person
	
	while(current->next != current){

		if(!strcmp(direction, "CLOCKWISE")){

			//kill from clockwise

			for(i = 0; i < k; i++){
				//find the kill target
				prev = current;
				current = current->next;
			}

			prev->next = current->next;
			printf("%s KILLED\n", current->name);
			free(current);
			current = prev->next;
			current->prior = prev;
		}
		else if(!strcmp(direction, "COUNTERCLOCKWISE")){

			for(i = 0; i < k; i++){
				prev = current;
				current = current->prior;
			}

			prev->prior = current->prior;
			printf("%s KILLED\n", current->name);
			free(current);
			current = prev->prior;
			current->next = prev;
		}
		else{
			printf("wrong direction\n");
			break;
		}
	}

	free(direction);
	printf("%s SURVIVE\n", current->name);

}
