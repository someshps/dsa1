#include <stdio.h>
#include<stdlib.h>

int binarySearch(int A[], int low, int high)
{
  int mid = (low + high)/2;
  if (A[mid] > A[mid-1] && A[mid] > A[mid+1])
    return A[mid];
  else if (A[mid-1] < A[mid] && A[mid] < A[mid+1])
    return binarySearch(A, mid, high);
  else
    return  binarySearch(A, low, mid);
}

int findMax(int A[], int n)
{
  return binarySearch(A,0,n-1);
}

int main(void) {
  //write your code here
  int n;
  int A[1000];
  scanf("%d", &n);
  int i;
  int x;
  for(i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }

  printf("%d", findMax(A,n));
  return 0;
}
