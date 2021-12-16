#include<stdio.h>

int main()
{
  int n,i;
  int A[10000],B[10000];


  scanf("%d", &n);

  for( i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }

  for( i=0; i<n; i++)
  {
    scanf("%d", &B[i]);
  }

  int front = 0 ;
  int top = 0;
  int scanned = 0;

  while(1)
  {
    if (top == n)
      break;
    if (B[front] == A[top])
    {
      B[front] = -1;
      top += 1;
      scanned = 1;
    }
    if (front == n-1)
      front = 0;
    else
      front += 1;

    if (front == 0 && scanned == 0)
      break;
    else if (front == 0 && scanned == 1)
      scanned = 0;

    /*for(i=0; i <n; i++)
      printf("%d ", A[i]);
    printf("\n");
    for(i=0; i <n; i++)
        printf("%d ", B[i]);
    printf("\n%d %d", front, top);

    printf("\n\n");*/

  }

  printf("%d", n-top);
  return 0;
}
