#include <stdio.h>
#include<stdlib.h>
struct node
{
  int value;
  struct node *next;
};

int main(void) {
  //initially the list is empty.
  struct node *front = NULL;
  struct node *rear = NULL;

  //write your code here
  int n;
  scanf("%d", &n);
  int i;
  char action;
  int x;
  for(i=0; i<n; i++)
  {
    scanf(" %c", &action);
    if(action == 'e')
    {
      scanf("%d", &x);
      struct node *v = (struct node *)malloc(sizeof(struct node));
      v->value = x;
      v->next = NULL;

      if(rear == NULL)
      {
        front = v;
        rear = v;
      }
      else
      {
        rear->next = v;
        rear = v;
      }
    }
    else
    {
      if(front == NULL)
        printf("Queue Empty");
      else
      {
        struct node* v = front;
        if (front == rear)
        {
          front = NULL;
          rear = NULL;
        }
        else
        {
          front = front->next;
        }
        free(v);
      }
    }
    struct node *head = front;
    if(head == NULL)
      printf("NULL");
    else
    {
      while(head != NULL)
      {
        if (head->next == NULL)
          printf("%d", head->value);
        else
          printf("%d ", head->value);
        head = head->next;
      }
    }
    printf("\n");
  }
  return 0;
}
