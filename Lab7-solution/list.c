#include <stdio.h>
#include<stdlib.h>
struct node
{
  int value;
  struct node *next;
};


struct node* add(int x, struct node *head)
{
  //write the function here
  struct node *v = (struct node *)malloc(sizeof(struct node));
  v->value = x;
  v->next = head;
  head = v;
  return head;
}

struct node* delete(int x, struct node *head)
{
  //write the function here
  if(head == NULL)
  {
    printf("List Empty");
    return NULL;
  }
  else
  {
    if (head->value == x)
    {
      struct node *v = head;
      head = head->next;
      free(v);
      return head;
    }
    else
    {
      struct node *v = head->next;
      struct node *u = head;
      while( v != NULL)
      {
        if (v->value == x)
        {
          u->next = v->next;
          free(v);
        }
        else
        {
          u = v;
          v = v->next;
        }
        return head;
      }
    }
  }
  return head;
}

int main(void) {
  //initially the list is empty.
  struct node *head = NULL;

  //write your code here
  int n;
  scanf("%d", &n);
  int i;
  char action;
  int x;
  for(i=0; i<n; i++)
  {
    scanf(" %c %d", &action, &x);
    if(action == 'a')
    {
      head = add(x, head);
    }
    else
    {
      head = delete(x, head);
    }
  }

  if(head == NULL)
    printf("NULL");
  else
  {
    while(head != NULL)
    {
      if(head->next == NULL)
        printf("%d", head->value);
      else
        printf("%d ", head->value);
      head = head->next;
    }
  }
  return 0;
}
