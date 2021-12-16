#include<stdio.h>
#include<stdlib.h>

int i;

struct node{
	int data;
	struct node *right;
	struct node *left;
};

struct node* buildTree(int* pre, int i, int* in, int s, int e){
	if(s>e){
		return NULL;
	}

	int rootData = pre[i];
	i++;

	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->data = rootData;

	int k=-1;
	for(int j=s;j<=e;j++){
		if(in[j]==rootData){
			k=j;
			break;
		}
		
	}

	n->left = buildTree(pre, i, in, s, k-1);
	n->right = buildTree(pre, i, in, k+1, e);

	return n;
}

void postOrder(struct node* root){
	if(root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);

}
struct node* build(int in[], int pre[], int n){
	int s=0;
	int e=n-1;
	int i=0;

	return buildTree( pre, i, in, s, e);
}
int main(int argc, char const *argv[])
{
	struct node* root  = NULL;
	//struct node *n = (struct node *)malloc(sizeof(struct node));
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

	root = build(pre, in, n);

	if(root==NULL){
		printf("Tree is empty\n");
	}else{
		postOrder(root);
	}
	

	return 0;
}