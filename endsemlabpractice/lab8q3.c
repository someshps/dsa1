#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* newNode(int data){
//this is a function which would create the box and fill it up with the 'data' and 
//initialise its pointer to NULL
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data = data;
	Node->next = NULL;

	return Node;
}

struct node* push(struct node* top, int data){

	if(top == NULL){
		struct node* v = newNode(data);
		top = v;
		return top;
	}else{
		struct node* v = newNode(data);
		v->next  = top;
		top = v;
		return top;
	}
}

struct node* pop(struct node* top){
	if(top==NULL){
		printf("stack is empty\n");
		return NULL;
	}else{
		struct node* v = top;
		top = top->next;
		free(v);
		return top;
	}
}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	
	int arr[1000];
	int ansarr[1000];
	
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}


	struct node* top =  NULL;

	for(int i=n-1;i>=0;i--){
	    if(top==NULL){
	        top = push(top, i);
	        ansarr[i]=-1;
	    }
	    else{
	        if(arr[i]<arr[top->data]){
	            ansarr[i]=top->data;
	            top = push(top, i);
	        }
	        else{
    	        while(top!=NULL && arr[i]>arr[top->data]){
    	            top = pop(top);
    	        }
    	        if(top==NULL){
    	            ansarr[i]=-1;
    	            top = push(top, i);
    	        }else{
    	            ansarr[i]=top->data;
    	            top = push(top, i);
    	        }
	        }
	    }
	    
	}

	for(int i=0;i<n-1;i++){
	    printf("%d ", ansarr[i]+1);
	}
	printf("%d", ansarr[n-1]+1);

	
	return 0;
}