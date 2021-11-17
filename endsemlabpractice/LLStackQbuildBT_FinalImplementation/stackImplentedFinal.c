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

void push(struct node** top, int data){

	if(*top == NULL){
		struct node* v = newNode(data);
		*top = v;
		//return top;
	}else{
		struct node* v = newNode(data);
		v->next  = *top; //jo node function mein hi create kia hai..jaise ki v..uske aage * nai ayega
		//but 'top' jo ki main se aya hai uske aage * lagana padta hai...if you want its value to change
		*top = v;
		//return top;
	}
}

void pop(struct node** top){
	if(*top==NULL){
		printf("stack is empty\n");
		//return NULL;
	}else{
		struct node* v = *top;
		*top = (*top)->next;
		free(v);
		//return top;
	}
}

void PrintStack(struct node* top){

	struct node* head  = top;
	
	while(head->next != NULL){
		printf("%d->", head->data);
		head=head->next;
	}
	printf("%d", head->data);

}

int main(int argc, char const *argv[])
{
	struct node* top  = NULL;

	push(&top, 10); //whenever I push, the top pointer changes
	push(&top, 20);
	push(&top, 30);
	push(&top, 40);
	push(&top, 50);
	pop(&top);//50 will be removed //whenever I pop the pointer changes
	pop(&top);//40 will be removed

	PrintStack(top);
	return 0;
}