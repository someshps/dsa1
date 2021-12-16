#include<stdio.h>
#include<stdlib.h>
int count = 0;

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
int numberOfNodes(struct node* root){
	if(root==NULL){
		return 0;
	}

	int nL = numberOfNodes(root->left);
	int nR = numberOfNodes(root->right);

	return nL+nR+1;
}
void preOrder(struct node* root, int n){

	if(root == NULL){
		return;
	}

	if(count==n-1){
      printf("%d", numberOfNodes(root));
    }else{
	    printf("%d ", numberOfNodes(root));
	    count++;
    }
	preOrder(root->left, n);
	preOrder(root->right, n);
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
	struct node* root;
	int n;
  	scanf("%d", &n);
  
  	int arr[100];
  	arr[0] = 250;
  	for(int i=1;i<=(n+n);i++){
		scanf("%d", &arr[i]);
	}
// 	for(int i=0;i<=(n+n)+1;i++){
// 		printf("%d ", arr[i]);
// 	}
	//int arr[100] = {100, 2 , 3, 0, 0, 0, 0};
	int k= 0;
	root = buildBT(arr, &k);
	
	preOrder(root, n);
	return 0;
}