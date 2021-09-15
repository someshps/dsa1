#include<stdio.h>

void quicksort(int A[], int low, int high)
{
  if(low >= high)
  {
    return;
  }
  int pivot = A[low];
  int i=low+1;
  int j = high;

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

    }
  }
  int pivotindex;
  if(A[i] < pivot)
  {
      int temp = A[low];
      A[low] = A[i];
      A[i] = temp;
      pivotindex = i;

  }
  else
  {
    int temp = A[low];
    A[low] = A[i-1];
    A[i-1] = temp;
    pivotindex = i-1;

  }

  quicksort(A, low, pivotindex-1);
  quicksort(A, pivotindex+1,high);

}

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

  quicksort(A, 0, n-1);
  //printf("got here");
  //printf("Got here \n");
  for(i=0; i<n-1; i++)
  {

    printf("%d ", A[i]);
  }
  printf("%d", A[n-1]);

  return 0;
}
