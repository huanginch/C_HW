#include <stdio.h>
#include <math.h>

#define MAX_TERM 1000

typedef struct {
	int term;
	int cof[MAX_TERM];
	int exp[MAX_TERM];
} Poly; //struct polynominal

int check_zero(int target);//check the target is zero or not
void _printPoly(Poly p);//print the Poly
void calPoly(int x, Poly p);//calculate the Polynomial

int main(void){
	int i;//use for loop
	int calTime = 0;//calculate times
	Poly p;// polynomial p
	
	//get the term of p
	scanf("%d", &p.term);
	while(check_zero(p.term)){//check the validation of term	
		scanf("%d", &p.term);
	}

	//get the cof and exp of p
	for(i = 0; i < p.term; i++){
		scanf("%d %d", &p.cof[i], &p.exp[i]);
	}

	_printPoly(p);

	//get the number of calculate time
	scanf("%d", &calTime);
	while(check_zero(calTime)){//check the validation of calTime	
		scanf("%d", &calTime);
	}

	//calculation
	for(i = 0; i < calTime; i++){
		int x = 0;//x input by user
		scanf("%d", &x);
		while(check_zero(x)){//check the validation of x	
			scanf("%d", &x);
		}
		calPoly(x, p);
	}

	return 0;
}

int check_zero(int target){
	
	if(target == 0){
		printf("The number must be greater than zero!\n");
		return 1;
	}

	return 0;
}

void _printPoly(Poly p){
	int i;

	for(i = 0; i < p.term; i++){
		printf("%d", p.cof[i]);
		printf("x^");
		printf("%d", p.exp[i]);
		if(i != p.term - 1){
			printf(" + ");
		}
		else{
			printf(" = ");
		}
	}
	printf("\n");
}

void calPoly(int x, Poly p){
	long int res = 0;//the result of calculation
	int i;// use for the loop

	for(i = 0; i < p.term; i++){
		long int tmp_res = 0;
		tmp_res = (long int)pow(x, p.exp[i]);
		tmp_res *= p.cof[i]; 
		res += tmp_res;
	}

	printf("%ld\n", res);
}
