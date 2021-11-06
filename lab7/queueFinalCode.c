#include <stdio.h>
#include <stdlib.h>


int front=-1,rear=0;


int arr[1000];

void enqueue(int *arr, int *front, int val)
{
    *front=*front +1;
    arr[*front]=val;
}

void dequeue(int *rear)
{
    *rear=*rear+1;
}

void solve()
{
    char command;
    scanf("%s",&command);
    // printf("%c",command);
    
    if (command=='e')
    {
        int val;
        scanf("%d",&val);
        // printf("inputeed\n");
        enqueue(arr,&front,val);
        
    }
    else
    {
        dequeue(&rear);
    }
    
    if (rear>front)
    {
        printf("NULL\n");
    }
    else 
    {
      for (int i=rear;i<=front;i++)
      {
          if (i==front)
          {
            printf("%d\n",arr[i]);
          }
          else
          {
            printf("%d ",arr[i]);
          }
      }
    }
}

void solve_without_line_break()
{
    char command;
    scanf("%s",&command);
    // printf("%c",command);
    
    if (command=='e')
    {
        int val;
        scanf("%d",&val);
        // printf("inputeed\n");
        enqueue(arr,&front,val);
        
    }
    else
    {
        dequeue(&rear);
    }
    
    if (rear>front)
    {
        printf("NULL");
    }
    else 
    {
      for (int i=rear;i<=front;i++)
      {
          if (i==front)
          {
            printf("%d",arr[i]);
          }
          else
          {
            printf("%d ",arr[i]);
          }
      }
    }
}

int main(void) {
    int n;
    scanf("%d",&n);
    n--;
    while (n--)
    {
        solve();
    }
    solve_without_line_break();
	return 0;
}

