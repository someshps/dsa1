#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data){
//this is a function which would create the box and fill it up with the 'data' and 
//initialise its pointers to NULL
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}

int numberOfNodes(struct node* root){
	if(root==NULL){
		return 0;
	}

	int nL = numberOfNodes(root->left);
	int nR = numberOfNodes(root->right);

	return nL+nR+1;
}

int main(void) {
  int n;
  scanf("%d", &n);
  
  struct node* root  = NULL;
  int numNodes = numberOfNodes(root);

  

  return 0;
}