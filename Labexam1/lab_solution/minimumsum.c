#include<stdio.h>

int main()
{
  int n;
  int A[10000];


  scanf("%d", &n);
  int i;

  for( i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }
  int low = A[0];
  int secondlow = A[1];
  if (A[0] < A[1])
  {
    low = A[0];
    secondlow = A[1];
  }
  else
  {
    low = A[1];
    secondlow = A[0];
  }


  for(i=2 ; i < n ;i++)
  {
    if( A[i] < low)
    {
      secondlow = low;
      low = A[i];

    }
    else if(A[i] < secondlow)
    {
      secondlow = A[i];
    }
  }

  printf("%d", low+secondlow);
  return 0;
}
