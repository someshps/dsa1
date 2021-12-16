//This file contains the full implementation of linked lists
//It contains the following functions that can be used for LinkedLists
// 1. insertAtHead
// 2. deleteFromHead
// 3. insertAtTail
// 4. deleteFromTail
// 5. insertAtIndex
// 6. deleteFromIndex
// 7. getTail
// 8. getTailPrev
// 9. getNodeAtIndex
// 10. getIndexOfValue (when you know value inside a node)
// 11. lengthLL
// 12. printLL

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

	struct node* v = newNode(data);

	if(*head==NULL){
		*head = v;
	}else{
		v->next = *head;
		*head = v;
	}
}

struct node* getTail(struct node* head){
	struct node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	return temp; //if in while loop you do (temp!=NULL)
	//you would actually be returning NULL to the function every time
}


void insertAtTail(struct node** head, int data){
	struct node* v = newNode(data);
	if(*head==NULL){
		
		*head = v;
	}
	else if((*head)->next == NULL){

		(*head)->next = v;

	}else{
		
		struct node* tail = getTail(*head);
		tail->next = v;
		tail = v;
	}
}

struct node* getNodeAtIndex(struct node* head, int index){
	struct node* temp  = head;
	while(index!=0){
		temp = temp->next;
		index--;
	}
	return temp;
}

int getIndexOfValue(struct node* head, int value){
	if(head==NULL){
		return -1;
	}
	else{
		int i =0;
		while(head!=NULL && head->data != value){
			head = head->next;
			i++;
		}
		if(head==NULL){
			return -1;
		}else{
			return i;
		}
	}
}

void insertAtIndex(struct node** head, int index, int data){

	if(*head == NULL){
		struct node* v = newNode(data);
		*head = v;
		return;
	}
	else if(index == 0){
		insertAtHead(&(*head), data);
		return;
	}
	else if(head!=NULL && index !=0){
		struct node* u = getNodeAtIndex((*head), index);
		if(u->next == NULL){
			insertAtTail(&(*head), data);
		}
		else{
			struct node* v = newNode(data);
			v->next = u->next;
			u->next = v;
		}
	}
}

void deleteFromHead(struct node** head){
	if(*head==NULL){
		printf("You gave wrong instruction. The LL is empty, cannot delete anything\n");
	}
	else if((*head)->next == NULL){
		struct node* temp = *head;
		*head = NULL;
		free(temp);
	}
	else{
		struct node* temp1 = *head;
		*head = (*head)->next;
		free(temp1);
	}
}
struct node* getTailPrev(struct node* head){
	struct node* temp = head;
	while(((temp->next)->next)!=NULL){
		temp = temp->next;
	}
	return temp; 
}
void deleteFromTail(struct node** head){
	if(*head==NULL){
		printf("You gave wrong instruction. The LL is empty, cannot delete anything\n");
	}
	else if((*head)->next == NULL){
		struct node* temp = *head;
		*head = NULL;
		free(temp);
	}
	else{
		struct node* tailprev = getTailPrev(*head);
		//printf("The value in 2nd last node is %d\n", tailprev->data);
		//struct node* temp2 = tailprev->next;
		struct node* tail  = getTail(*head);
		tailprev->next = NULL; //aap kisi pointer ko null karte hain..toh tailprev->next=NULL
		free(tail);

	}
}

void deleteFromIndex(struct node** head, int index){
	if(head==NULL){
		printf("The linked list does not contain any nodes. Your command is wrong.\n");
	}
	else if((*head)->next==NULL){
		struct node* temp3  =  *head;
		*head = NULL;
		free(temp3);
	}
	else if(head!=NULL && index!=0){
		struct node* v = getNodeAtIndex(*head, index);
		struct node* u = getNodeAtIndex(*head, index-1);
		u->next = v->next;
		free(v);
	}
}

int lengthLL(struct node* head){
	if(head==NULL){
		return 0;
	}
	else{
		int i = 0;
		while(head!=NULL){
			i++;
			head = head->next;
		}
		return i;
	}
}

void printLL(struct node* head){
	if(head == NULL){
		printf("Linked List has no nodes, it is empty\n");
	}else{
		while(head->next != NULL){
			printf("%d->", head->data);
			head = head->next;
		}
		printf("%d\n", head->data); //not head->next->data because at second last node head->next was not 
		//null, so while loop executed and head became head->next i.e. when the while loop ended head
		//was pointing to the last node
	}
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;
	//struct node* tail = NULL;
	int index = 2;
	insertAtHead(&head, 10);
	insertAtHead(&head, 20);
	insertAtHead(&head, 30);
	insertAtHead(&head, 40);

	insertAtTail(&head, 50);
	insertAtTail(&head, 60);
	insertAtTail(&head, 70);
	insertAtTail(&head, 80);
	insertAtIndex(&head, index, 30);
	deleteFromHead(&head);
	deleteFromTail(&head);
	deleteFromIndex(&head, index);
	//deleteValue(&head, 20) ===> get index of 20 + deleteFromIndex
	int value = 20;
	int indexOfGivenValue = getIndexOfValue(head, value);
	deleteFromIndex(&head, indexOfGivenValue);
	int len  = lengthLL(head);
	printLL(head);
	printf("The length of the linked list is: %d\n", len);

	return 0;
}