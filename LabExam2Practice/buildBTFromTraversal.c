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
struct node* buildBT(){
	int x;
	scanf("%d", &x);

	struct node* root = newNode(x);

	root->left = buildBT();
	root->right = buildBT();

	return root;
}

int main(int argc, char const *argv[])
{
	struct node* root =  NULL;
	root = buildBT();
	preOrder(root);
	return 0;
}