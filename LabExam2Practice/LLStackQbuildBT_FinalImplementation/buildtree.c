#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data){
//this is a function which would create the box and fill it up with the 'data' and 
//initialise its pointer to NULL
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}

void preOrder(struct node* root){

	if(root == NULL){
		return;
	}

	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}
struct node* buildBT(int arr[], int* i){
	if(arr[*i] == 0){
		return NULL;
	}

	struct node* root = newNode(arr[*i]);

	int ri = 2*(*i)+1;
	int li = 2*(*i)+2;

	root->left = buildBT(arr, &ri);
	root->right = buildBT(arr, &li);

	return root;
}

int main(int argc, char const *argv[])
{
	struct node* root =  NULL;
	int arr[100] = {100, 2 , 3, 0, 0};
	int i= 0;
	root = buildBT(arr, &i);

	preOrder(root);
	return 0;
}