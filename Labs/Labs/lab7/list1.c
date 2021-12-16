#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void add(struct node** temp, int x){

    struct node *n= (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->next = *temp;
    
    *temp = n;

    return;
}

void Delete(struct node** head, int x){
    struct node *temp = *head;
    struct node *prev;

    if(temp==NULL) return;
    
    if(temp != NULL && temp->data == x){

        *head = temp->next;

        free(temp);

        return;
    }

    while(temp != NULL && temp->data != x){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;

    free(temp);
}

void Print(struct node* temp){
  if(temp == NULL){
    printf("NULL");
    return;
  }

  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
}

int main(void)
{
    struct node *head = NULL;

    int n;
    scanf("%d",&n);

    char ch;
    int x;

    for (int i = 0; i < n; i++) {
        scanf(" %c",&ch);
        scanf(" %d",&x);
        if(ch == 'a')
            add(&head, x);
        else{
            Delete(&head, x);
        }
    }
    
    Print(head);

    return 0;
}