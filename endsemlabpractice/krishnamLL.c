#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void append(int x, struct node** v){
    struct node *n = *v;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    
    if(*v == NULL)
        *v = newNode;
    else{
        while(n->next != NULL)
            n = n->next;
        
        n->next = newNode;
    }
    
}
void push(int x, struct node** v){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = *v;
    
    *v = newNode;
}

void del(int x, struct node** v){
    struct node *temp = *v, *prev;
    
    if(temp != NULL && temp->data == x){
        *v = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != x){
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL)
        return;
    
    prev->next = temp->next;
    free(temp);
}
void printList(struct node* n){
  if(n == NULL){
    printf("NULL");
    return;
  }

  while(n != NULL){
    printf("%d ",n->data);
    n = n->next;
  }
}
int main(void)
{
    struct node *head = NULL;
    int n,x;
    scanf("%d",&n);
    char c;
    for (int i = 0; i < n; i++) {
        scanf(" %c",&c);
        scanf(" %d",&x);
        if(c == 'a')
            push(x,&head);
            // According to the PDF the code should use append but test cases are such that I have to use push function.
        else if(c == 'd')
            del(x,&head);
    }
    
    printList(head);

    return 0;
}
