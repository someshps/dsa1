#include <stdio.h>
#include<stdlib.h>

int ind;

void find(int A[],int B[], int C[], int alow, int ahigh, int blow, int bhigh)
{
  //printf("%d %d %d %d \n", alow, ahigh, blow, bhigh);
  //find the first number in array B
  if (alow > ahigh)
    //do something
    return;
  else if (alow == ahigh)
  {
    C[ind] = B[blow];
    ind = ind - 1;
  }
  else
  {
    C[ind] = B[blow];
    ind = ind - 1;

    //find B[low] in A
    int i;
    for( i = alow; i <= ahigh ; i++)
    {
      if (A[i] == B[blow])
      {
        find(A,B,C,i+1,ahigh,blow+i-alow+1, bhigh);
        find(A,B,C,alow,i-1,blow+1, blow+i-alow);
      }
    }
  }
}

int main(void) {
  //write your code here
  int n;
  int A[1000];
  int stack[1000];
  int top = 0;
  int ans[1000];
  scanf("%d", &n);
  int i;

  for(i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }

  for (i = n-1; i>=0; i-- )
  {
    //find the top of the stack
    while(top > 0 && A[stack[top]] < A[i])
    {
        top = top -1;
    }
    if (top > 0)
      ans[i] = stack[top];
    else
      ans[i] = 0;

    top += 1;
    stack[top] = i;
  }

  for(i =0 ; i < n-1; i++)
  {
    if (ans[i] == 0)
      printf("0 ");
    else
      printf("%d ", ans[i]+1);
  }

  printf("0");


  return 0;
}
