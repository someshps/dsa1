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

void insertAtHead(struct node** head, int data){
	printf("Inside insertAtHead\n");
	struct node* v = newNode(data);

	if(*head==NULL){
		*head = v;
		if(*head==NULL){
			printf("head is still pointing to NULL\n");
		}else{
			printf("head is pointing to v\n");
		}
	}else{
		printf("Head is not NULL\n");
		v->next = *head;
		*head = v;
	}
}

void printLL(struct node* head){
	int i=1;
	if(head == NULL){
		printf("Linked List has no nodes, it is empty\n");
	}else{
		while(head->next != NULL){
			printf("head now points at node number %d ", i);
			printf("%d->", head->data);
			head = head->next;
			i++;
		}
		printf("%d", head->data); //not head->next->data because at second last node head->next was not 
		//null, so while loop executed and head became head->next i.e. when the while loop ended head
		//was pointing to the last node
	}
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;

	insertAtHead(&head, 10);
	insertAtHead(&head, 20);
	insertAtHead(&head, 30);
	insertAtHead(&head, 40);
	// insertAtTail(&head, 20);
	// deleteFromHead(&head);
	// deleteFromTail(&head);
	// insertAtIndex(&head, index, 30);
	// deleteFromIndex(&head, index);
	// deleteValue(&head, 20);
	// length(head);

	if(head==NULL){
		printf("head is still pointing to NULL\n");
	}else{
		printf("head is pointing to v\n");
	}
	printLL(head);

	return 0;
}