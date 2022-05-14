#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 25
#define MAX_ATB_LEN 6

struct pokemon{
	char name[MAX_NAME_LEN];
	char attribute[MAX_ATB_LEN];
	int attack;
	int HP;
};

void _sort(struct pokemon arr[], char condition[], int k, int list_len);//sort the pokemon list
void printList(struct pokemon arr[], int len);//print the pokemon list
int cmpByName(const void *a, const void *b);//compare by name
int cmpByAtb(const void *a, const void *b);//compare by attribute
int cmpByAtk(const void *a, const void *b);//compare by attack
int cmpByHP(const void *a, const void *b);//compare by HP

int main(void){
	int i, n, k;//i: use for loop, n: number of pokemon, k: number of case
	
	scanf("%d %d", &n, &k);
	fflush(stdin);

	struct pokemon p_arr[n];
	char condition[10];//max length is length of attribute(9) + 1;

	for(i = 0; i < n; i++){
		scanf("%s", &p_arr[i].name);
		scanf("%s", &p_arr[i].attribute);
		scanf("%d", &p_arr[i].attack);
		scanf("%d", &p_arr[i].HP);

		//printf("%s %s %d %d\n", p_arr[i].name, p_arr[i].attribute, p_arr[i].attack, p_arr[i].HP);
	}

	for(i = 0; i < k; i++){
		scanf("%s", condition);
		_sort(p_arr, condition, i + 1, n);
	}

}

void _sort(struct pokemon arr[], char condition[], int k, int list_len){
	printf("Case #%d:\n", k);

	if(!strcmp(condition, "NAME")){
		qsort(arr, list_len, sizeof(struct pokemon), cmpByName);
	}
	else if (!strcmp(condition, "ATTRIBUTE")){
		qsort(arr, list_len, sizeof(struct pokemon), cmpByAtb);
	}
	else if(!strcmp(condition, "ATTACK")){
		qsort(arr, list_len, sizeof(struct pokemon), cmpByAtk);
	}
	else if(!strcmp(condition, "HP")){
		qsort(arr, list_len, sizeof(struct pokemon), cmpByHP);
	}

	printList(arr, list_len);
}

void printList(struct pokemon arr[], int len){
	int i;

	for(i = 0; i < len; i++){
		printf("%s %s %d %d\n", arr[i].name, arr[i].attribute, arr[i].attack, arr[i].HP);
	}
}

int cmpByName(const void *a, const void *b){

	struct pokemon *a_ptr = (struct pokemon *)a;
	struct pokemon *b_ptr = (struct pokemon *)b;

	return strcmp(a_ptr->name, b_ptr->name);

}

int cmpByAtb(const void *a, const void *b){
	
	struct pokemon *a_ptr = (struct pokemon *)a;
	struct pokemon *b_ptr = (struct pokemon *)b;

	//WATER: 0, FIRE: 1, EARTH: 2, LIGHT: 3, DARK: 4
	int a_atb = 0;
	int b_atb = 0;
	
	//a_atb
	if(!strcmp(a_ptr->attribute, "WATER")){
		a_atb = 0;
	}
	else if(!strcmp(a_ptr->attribute, "FIRE")){
		a_atb = 1;
	}
	else if(!strcmp(a_ptr->attribute, "EARTH")){
		a_atb = 2;
	}
	else if(!strcmp(a_ptr->attribute, "LIGHT")){
		a_atb = 3;
	}
	else if(!strcmp(a_ptr->attribute, "DARK")){
		a_atb = 4;
	}

	//b_atb
	if(!strcmp(b_ptr->attribute, "WATER")){
		b_atb = 0;
	}
	else if(!strcmp(b_ptr->attribute, "FIRE")){
		b_atb = 1;
	}
	else if(!strcmp(b_ptr->attribute, "EARTH")){
		b_atb = 2;
	}
	else if(!strcmp(b_ptr->attribute, "LIGHT")){
		b_atb = 3;
	}
	else if(!strcmp(b_ptr->attribute, "DARK")){
		b_atb = 4;
	}

	if(a_atb == b_atb){
		//same attribute
		return cmpByHP(a, b);
	}
	else{
		return (a_atb - b_atb);
	}

	return 0;

}

int cmpByAtk(const void *a, const void *b){

	int a_atk = ((struct pokemon *)a)->attack;
	int b_atk = ((struct pokemon *)b)->attack;

	return (b_atk - a_atk);
}

int cmpByHP(const void *a, const void *b){

	int a_HP = ((struct pokemon *)a)->HP;
	int b_HP = ((struct pokemon *)b)->HP;

	return (a_HP - b_HP);

}
