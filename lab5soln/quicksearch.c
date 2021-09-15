#include<stdio.h>

int quicksearch(int A[], int low, int high, int k)
{
  if(low == high)
  {
    return A[low];
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
  int lowelements = pivotindex-low+1;
  if (lowelements == k){
    return A[pivotindex];
  }
  else if (lowelements > k)
  {
     //printf("Recursing on [%d,%d] and %d \n", low,pivotindex-1, k);
     return quicksearch(A, low, pivotindex-1, k);
  }
  else
  {
      //printf("Recursing on [%d,%d] and %d \n", pivotindex+1,high, k-(lowelements));
      return quicksearch(A, pivotindex+1,high, k-(lowelements));
  }

}

int main()
{
  int n,k;
  scanf("%d %d ",&n, &k);
  int A[1000];
  int i;
  for(i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }

  int ans = quicksearch(A, 0, n-1, k);
  printf("%d", ans);

  return 0;
}
