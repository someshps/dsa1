#include <stdio.h>
#include <stdlib.h>

struct node{ //creating the structure of the node 
    int data; //the integer value
    struct node *next; //pointer to the next struct
};

void add(struct node** head, int x){ //function to add the value to the list 

    struct node *n = (struct node *)malloc(sizeof(struct node)); //create a new node
    n->data = x; //fill in x
    n->next = *head; //linking the new node to the list 
    
    *head = n; //making new node as the head

    return;
}

void Delete(struct node** v, int x){

    struct node *temp = *v;  //declaring two pointers: current and the one prev to it
    struct node *prev;
    
    if(temp != NULL && temp->data == x){  //when you have found the element to be deleted
        *v = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != x){ //loop to iterate 
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL){ //when ll has become empty
        return;
    }

    prev->next = temp->next; //breaking the link for temp node

    free(temp);
}

void Print(struct node* temp){//function to print the ll
  if(temp == NULL){
    printf("NULL"); //empty
    return;
  }

  while(temp != NULL){ //iterate and print
    printf("%d ",temp->data);
    temp = temp->next;
  }

}

int main(void)
{
    struct node *head = NULL;

    int n;
    int x;
    char c;

    scanf("%d",&n);
    
    while(n--){
        scanf(" %c",&c);
        scanf(" %d",&x);
        if(c == 'a')
            add(&head,x); //we will add at the front of the list
        else if(c == 'd')
            Delete(&head, x);
    }
    
    Print(head);

    return 0;
}