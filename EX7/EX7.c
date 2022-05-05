#include <stdio.h>
#include <stdlib.h>

struct student{
    int ID;
    int score;
    struct student *next;
};

void add_record(struct student **first, int id, int score); //add student record to the list
void print_record(struct student **first); //print the record
void clean(struct student **first); //free the memory

//quick sort
void _sort(struct student *head, struct student *tail); //sort by the student id in ascending order
struct student *find_tail(struct student *head);//find the last node
struct student *partition(struct student *head, struct student *tail);//find the pivot

int main(void){
    int n = 0;//the number of students
    int id = 0, score = 0, i;
    struct student *head = NULL;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d", &id, &score);
        add_record(&head, id, score);
        printf("add end\n");
    }

    _sort(head, find_tail(head));

    print_record(&head);

    clean(&head);

    return 0;
}

void add_record(struct student **first, int id, int score){
    //create new node
    struct student *new_student = malloc(sizeof(struct student));
    new_student->ID = id;
    new_student->score = score;
    new_student->next = NULL;

    if(*first == NULL){
        //if the list is empty
        *first = new_student;
    }
    else {
        struct student *current = *first;
        while(current->next != NULL){
            //find the last node
            current = current->next;
        }

        current->next = new_student;
    }
}

void print_record(struct student **first){
    struct student *current = *first;

    printf("ID\tscore\n");
    while (current != NULL){//traverse the lsit
        printf("%d\t%d\n", current->ID, current->score);
        current = current->next;
    }
    
}

void clean(struct student **first){
    struct student *current = *first;
    struct student *next = current->next;

    while (current != NULL){//traverse the lsit
        free(current);
        current = next;
        next = current->next;
    }
}

void _sort(struct student *head, struct student *tail){
    
    if(head == tail){
        //nothing to sort
        return;
    }

    //struct student *new_head = NULL, *new_tail = NULL;
    struct student *pivot = partition(head, tail);
    if(pivot != head && pivot != NULL){//pivot is not the first node
        //sort the left list
        _sort(head, pivot);
    }
    if(pivot != tail && pivot != NULL){//pivot is not the last node
         //sort right list
        _sort(pivot->next, tail);
    }
}

struct student *find_tail(struct student *head){
    struct student *current = head;
    while(current != NULL && current->next != NULL){
        //check if the list is empty and current is the last node or not
        current = current->next;
    }

    return current;
}

struct student *partition(struct student *head, struct student *tail){
    struct student *pivot = head;//set the first node as pivot
    struct student *current = tail;
    struct student *prev = NULL;
    struct student *temp = NULL;

    while(current != NULL && current != tail){

        if(current->ID < tail->ID){
            pivot = head;

            //swap the node
            temp = current;

        }
    }

}