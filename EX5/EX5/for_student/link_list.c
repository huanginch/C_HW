#include "myDS.h"
#include "basic.h"

// HEAD is point to FOODPAPA (id: 0)
void my_insert(struct node* HEAD, int ID, char *Name, int node_id){
	// Please insert a new node(store Name & node_id)
	// after the node which id is ID
	// If it doesn't exit such ID, print "INVALID OPERATION"

	struct node *current = HEAD;
	
	while(current != NULL){
		if(current->id == ID){
			struct node *new_node = malloc(sizeof(struct node));
			strcpy(new_node->name, Name);
			new_node->id = node_id;
			new_node->next = current->next;
			current->next = new_node;
			break;
		}
		
		if(current->next == NULL){
			printf("INVALID OPERATION\n");
			return;
		}

		current = current->next;
	}
}
void my_delete(struct node* HEAD, char *Name){
	// Delete the node which store the Name.
	// If it doesn’t exit such Name, print “INVALID OPERATION”.

	struct node *current = HEAD;
	struct node *prev = NULL;

	while(current != NULL){
		if(!strcmp(current->name, Name)){
			prev->next = current->next;
			break;
		}

		if(current->next == NULL){
			printf("INVALID OPERATION\n");
			return;
		}

		prev = current;
		current = current->next;
	}
}
void my_swap(struct node *HEAD, char *Name1, char *Name2){
	// Swap the node which store Name1 and Name2
	// If either of the node doesn’t exit, print “INVALID OPERATION”
	// NOTICE: don't just swap the node's value
	// You need to break the link and recombine it

	struct node *node1 = NULL;
	struct node *node2 = NULL;
	struct node *current = HEAD;
	struct node *prev = NULL;
	struct node *prev1 = NULL;
	struct node *prev2 = NULL;

	while(current != NULL){
		if(!strcmp(current->name, Name1)){
			node1 = current;
			prev1 = prev;
		}

		if(!strcmp(current->name, Name2)){
			node2 = current;
			prev2 = prev;
		}

		prev = current;
		current = current->next;
	}

	if(node1 == NULL || node2 == NULL){
		printf("INVALID OPERATION\n");
		return;
	}
	
	prev1->next = node2;
	prev2->next = node1;

	struct node *temp_node = node2->next;
	node2->next = node1->next;
	node1->next = temp_node;

}
void my_print_id(struct node *HEAD, char *Name){
	// Print the id of the corresponding Name.
	// If Name doesn’t exit, print “INVALID OPERATION”

	struct node *current = HEAD;

	while(current != NULL){
		if(!strcmp(current->name, Name)){
			printf("%d\n", current->id);
			break;
		}

		if(current->next == NULL){
			printf("INVALID OPERATION\n");
			return;
		}

		current = current->next;
	}
}
void my_print_name(struct node *HEAD, int ID){
	// Print the name of the corresponding ID
	// If ID doesn’t exit, print “INVALID OPERATION”

	struct node *current = HEAD;

	while(current != NULL){
		if(current->id == ID){
			printf("%s\n", current->name);
			break;
		}

		if(current->next == NULL){
			printf("INVALID OPERATION\n");
			return;
		}

		current = current->next;
	}
}
void my_result(struct node* HEAD){
	// Print out all the information in the linked list orderly
	// in the format “ID NAME”. (start from HEAD)
	
	struct node *current = HEAD;
	
	while(current != NULL){
		
		printf("%d %s\n", current->id, current->name);

		current = current->next;
	}
}

