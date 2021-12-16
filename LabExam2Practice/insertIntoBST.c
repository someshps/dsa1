// C program to demonstrate insert
// operation in binary
// search tree.
#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}


void insert(struct node** root, int key)
{

	printf("Inside the insert function\n");
	if (*root == NULL){
		struct node* v  = newNode(key);
		*root = v;
	
	}
	
	if (key < ((*root)->key))
		insert(&((*root)->left), key);

	else if (key > (*root)->key)
		insert(&((*root)->right), key);

	
}

int main()
{
	
	struct node* root = NULL;

	insert(&root, 50);
	insert(&root, 30);
	insert(&root, 20);
	insert(&root, 40);
	insert(&root, 70);
	insert(&root, 60);
	insert(&root, 80);

	// print inoder traversal of the BST
	inorder(root);

	return 0;
}

