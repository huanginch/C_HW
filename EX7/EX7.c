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

/*
quick sort:
select a node as pivot
if the node ID is smaller than pivot，move to the right of pivot
else move to the left of pivot
use the nodes at right of pivot as new list and sort again
use the nodes at left of pivot as new list and sort again
sort until the origin list is sorted
*/
struct student *_sort(struct student *head, struct student *tail); //sort by the student id in ascending order
struct student *find_tail(struct student *head);//find the last node
struct student *partition(struct student *head, struct student *tail, struct student **new_head, struct student **new_tail);//find the new pivot

int main(void){
    int n = 0;//the number of students
    int id = 0, score = 0, i;
    struct student *head = NULL;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d", &id, &score);
        add_record(&head, id, score);
    }

    head = _sort(head, find_tail(head));

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

    while (current->next != NULL){//traverse the lsit
        free(current);
        current = next;
        next = current->next;
    }

	free(current);//free the last node
}

struct student *_sort(struct student *head, struct student *tail){
    
    if(head == tail){
        //nothing to sort
        return head;
    }

    struct student *new_head = NULL, *new_tail = NULL;
    struct student *pivot = partition(head, tail, &new_head, &new_tail);
    if(pivot != new_head){//pivot is not the first node
        //sort the left list
        struct student *temp = new_head;
        //let the last node of left list point to NULL
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        new_head = _sort(new_head, temp);

        //link the sorted list to the origin list
        temp = find_tail(new_head);
        temp->next = pivot;

    }
    if(pivot != new_tail){//pivot is not the last node
        //sort right list
        pivot->next =  _sort(pivot->next, new_tail);

    }

    return new_head;
}

struct student *find_tail(struct student *head){
    struct student *current = head;
    while(current != NULL && current->next != NULL){
        //check if the list is empty and current is the last node or not
        current = current->next;
    }

    return current;
}

struct student *partition(struct student *head, struct student *tail, struct student **new_head, struct student **new_tail){
    struct student *pivot = head;//set the first node as pivot
    struct student *current = head;
    struct student *prev = NULL;

    while(current != NULL){

        if(current->ID < pivot->ID){
            //move the node to the left of pivot
            prev->next = current->next;
            current->next = head;
            head = current;
            current = prev;
        }
        else{
            //move tail，the node should be at the right of pivot
            tail = current;
        }

        
        prev = current;
        current = current->next;
    }

    (*new_head) = head;
    (*new_tail) = tail;

    return pivot;
}
