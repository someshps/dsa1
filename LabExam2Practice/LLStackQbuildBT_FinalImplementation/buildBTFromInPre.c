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

struct node* buildTree(int pre[], int* i, int in[], int s, int e){

	if(s>e){
		return NULL;
	}


	int rootData = pre[*i];
	(*i)++;

	struct node* root  = newNode(rootData);
	int k = -1;
	for(int j=s;j<=e;j++){
		if(in[j]==rootData){
			k=j;
			break; 
		}
	}

	root->left = buildTree(pre, &(*i), in, s, k-1);
	root->right = buildTree(pre, &(*i), in, k+1, e);

	return root;

}

void postOrder(struct node* root){
	if(root==NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}


int main(int argc, char const *argv[])
{
	struct node* root = NULL;
	int in[100] = {1, 4, 6, 8, 10};
	int pre[100] = {8, 6, 1, 4, 10};

	int n = 5;
	int s =0;
	int e = n-1;
	int i = 0;

	root = buildTree(pre, &i, in, s, e);//this function would build the tree and return its root


	postOrder(root);
	
	return 0;
}