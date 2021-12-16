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

void PrintStack(struct node* top){

	struct node* head  = top;
	printf("Stack printed top to bottom\n");
	while(head->next != NULL){
		printf("%d->", head->data);
		head=head->next;
	}
	printf("%d", head->data);

}

int main(int argc, char const *argv[])
{
	struct node* top  = NULL;

	//these functions would add and delete elements from the stack, they would not print instantly

	top = push(top, 10); //whenever I push, the top pointer changes
	top = push(top, 20);
	top = push(top, 30);
	top = push(top, 40);
	top = push(top, 50);
	top = pop(top);//50 //whenever I pop the pointer changes
	top = pop(top);//40

	PrintStack(top);
	return 0;
}