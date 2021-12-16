#include <stdio.h>
#include <stdlib.h>


int top=-1;
int arr[1000];

void push(int *arr,int *top, int val)
{
    *top=*top+1;
    arr[*top]=val;
}

void pop(int *top)
{
    *top=*top-1;
}

void solve()
{
    
    char command;
    scanf("%s",&command);
    
    if (command=='a')
    {
        int val;
        scanf("%d",&val);
        
        push(arr,&top,val);
        
    }
    
    else
    {
        pop(&top);
    }
    
    if (top>-1)
    {
        for (int i=top;i>-1;i--)
        {
            if (i==0)
            {
                printf("%d\n",arr[0]);
            }
            else
            {
                printf("%d ",arr[i]);
            }
        }
    }
    else
    {
        printf("NULL\n");
    }
}

int main(void) {
    
    int t;
    scanf("%d",&t);
    while (t--)
    {
        solve();
    }
    
	return 0;
}

