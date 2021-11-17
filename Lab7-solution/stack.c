#include <stdio.h>
#include<stdlib.h>
struct node
{
  int value;
  struct node *next;
};


struct node* push(int x, struct node *top)
{
  //write the function here
  struct node *v = (struct node *)malloc(sizeof(struct node));
  v->value = x;
  v->next = top;
  top = v;
  return top;
}

struct node* pop(int x, struct node *top)
{
  //write the function here
  if(top == NULL)
  {
    printf("Stack Empty");
    return NULL;
  }
  else
  {
    struct node* v = top;
    top = top->next;
    free(v);
    return top;
  }
}

int main(void) {
  //initially the list is empty.
  struct node *top = NULL;

  //write your code here
  int n;
  scanf("%d", &n);
  int i;
  char action;
  int x;
  for(i=0; i<n; i++)
  {
    scanf(" %c", &action);
    if(action == 'a')
    {
      scanf("%d", &x);
      top = push(x, top);
    }
    else
    {
      top = pop(x, top);
    }

    struct node *head = top;
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
