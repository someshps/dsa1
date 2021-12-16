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

void enque(struct node** rear, struct node** front, int data){

	struct node* v = newNode(data);
	v->next = NULL;

	if(*rear==NULL){

		*rear = v;
		*front = v;
		
	}else{

		(*rear)->next = v;
		*rear =  v;
		
	}
}

void deque(struct node** front, struct node** rear){
	if(*front == NULL){
		printf("Queue is empty when I am trying to deque\n");
		
	}else{
		struct node* v = *front;
		if(*front == *rear){
			*front =  NULL;
			*rear = NULL;
			
		}
		else{
			*front = (*front)->next;
			free(v);
			
		}
	}
	
}

void PrintQ(struct node* front){
	struct node* head = front;

	if(head==NULL){
		printf("Queue is empty, head is NULL");
		return;
	}else{

		while(head->next!=NULL){
			printf("%d<-", head->data);
			head  =  head->next;
		}

		printf("%d", head->data);
		return;
	}
}

int main(int argc, char const *argv[])
{
	struct node* front = NULL;
	struct node* rear = NULL;

	enque(&rear, &front, 10);
	enque(&rear, &front, 20);
	enque(&rear, &front, 30);
	enque(&rear, &front, 40);
	enque(&rear, &front, 50);
	deque(&front, &rear);
	deque(&front, &rear); 

	PrintQ(front);

	return 0;
}