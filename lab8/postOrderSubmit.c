#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
 
    return node;
}

struct Node* construct(int in[], int pre[], int s, int e, int* index)
{
    if (s > e) {
        return NULL;
    }
 	
 	int rootdata = pre[*index];
 	(*index)++;

    struct Node* node = newNode(rootdata);
 
    
    int k;
    for (k = s; k <= e; k++)
    {
        if (in[k] == node->data) {
            break;
        }
    }
 
    //int in[], int pre[], int s, int e, int index
    node->left = construct(in, pre, s, k - 1, index);
    node->right = construct(in, pre, k + 1, e, index);
 
    return node;
}

struct Node* buildTree(int in[], int pre[], int n)
{
    
    int index = 0;
 
    return construct(in, pre, 0, n-1, &index);
}

void postOrder(struct Node* root)
{
    if (root == NULL) {
        return;
    }
 
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}



int main(int argc, char const *argv[])
{

	int in[100];
	int pre[100];

	int n;
	scanf("%d ", &n);

	for(int i=0;i<n;i++){
		scanf("%d", &in[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d", &pre[i]);
	}

	struct Node* root = buildTree(in, pre, n);

	postOrder(root);
	

	return 0;
}