#include <stdio.h>
#include <stdlib.h>

struct tNode{
	int data;
	struct tNode *Lchild, *Rchild;
};

struct tNode *insert(struct tNode *curNode, int data){
	//insert
	if (curNode == NULL){
		//create new node
		struct tNode *newData = (struct tNode *) malloc(sizeof (struct tNode));
		newData->data = data;
		newData->Lchild = NULL;
		newData ->Rchild = NULL;
		return newData;
	}
	else{	//find proper position
		if (data < curNode -> data) curNode -> Lchild = insert(curNode -> Lchild, data);
		else curNode ->Rchild = insert(curNode -> Rchild, data);
	}
	return curNode;
}

void traverse(struct tNode *curNode){
//************************* You should write ***********************//
// if the current node is NULL means it goes to one of the branch end
// in-order means goes to all the node on left side until there's no other nodes,
// then print the current Node
// after printing, then goes to the right node

//hint: recursive is a good idea
//*************************** Don't forget *************************//
	if(curNode == NULL){
		//meet the end of the branch
		return;
	}
	
	traverse(curNode->Lchild);//traverse Lchild first
	printf("%d ", curNode->data);
	traverse(curNode->Rchild);//then traverse Rchild

}

int find(struct tNode *curNode, int target){
	//************************* You should write ***********************//
	// if find the target, return the sum of data contains in its Lchild and Rchild
	// NULL is seen as 0
	// if not, return "Not in tree\n"
	//*************************** Don't forget *************************//
	
	if(curNode == NULL){
		printf("Not in tree\n");
		return -1;
	}

	if(curNode->data == target){//target found
		//get Lchild node and Rchild node
		struct tNode *Lchild = curNode->Lchild;
		struct tNode *Rchild = curNode->Rchild;

		int sum = 0;
			
		//add left data
		if(Lchild == NULL){
			sum += 0;
		}
		else{
			sum += Lchild->data;
		}

		//add right data
		if(Rchild == NULL){
			sum += 0;
		}
		else{
			sum += Rchild->data;
		}

		return sum;
	}
	
	if(curNode->data > target){
		//the target is at left branch

		return find(curNode->Lchild, target);
	}
	
	if(curNode->data < target){
		//the target is at right branch

		return find(curNode->Rchild, target);
	}
}

void delete_tree(struct tNode* curNode){
	if (curNode == NULL) return;
	delete_tree(curNode->Lchild);
	delete_tree(curNode->Rchild);
	free(curNode);
}

int main(){
	int numData = 0;
	int tmpNum;
	scanf("%d", &numData);

	struct tNode *root = NULL;

	//insert every data, all data > 0
	for (int i = 0; i < numData; i++){
		scanf("%d", &tmpNum);
		root = insert(root, tmpNum);
	}

	//traverse
	traverse(root);
	puts("");

	//find
	while(scanf("%d", &tmpNum)!=EOF){
		int sum = find(root, tmpNum);
		if (sum != -1) printf("%d\n", sum);
	}

	//free memory
	delete_tree(root);
	return 0;
}
