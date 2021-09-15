#include<stdio.h>

int main()
{
  int n;
  scanf("%d ",&n);
  //printf("%d", n);
  int A[1000];
  int i;
  for(i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
    //printf("got here %d", i);
  }

  //printf("got here");
  int pivot = A[0];
  i=1;
  int j = n-1;

  int count=0;
  while(1)
  {
    //printf("%d %d", i,j );
    while(A[i] < pivot && i <j)
    {
      i++;
    }
    while(A[j] > pivot && j>i)
    {
      j--;
    }
    if( i >= j)
    {
      break;
    }
    else
    {
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      count++;
    }
  }

  if(A[i] < pivot)
  {
      int temp = A[1];
      A[1] = A[i];
      A[i] = temp;
      count++;
  }
  else if (i-1 >= 2)
  {
    int temp = A[1];
    A[1] = A[i-1];
    A[i-1] = temp;
    count++;
  }
  //printf("Got here \n");
  //for(i=0; i<n; i++)
  //{
    //printf("%d ", A[i]);
  //}
  //printf("Got here \n");
  printf("%d", count);
}
