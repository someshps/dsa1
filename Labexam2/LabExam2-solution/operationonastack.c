#include<stdio.h>

int main()
{
  int n,k,i;
  int A[10000];


  scanf("%d %d", &n, &k);

  for( i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }


  if (k == 1)
    printf("%d", A[1]);
  else
  {
    int max = A[0];
    for(i = 1; i<= k-2; i++)
    {
      if (A[i] > max)
        max = A[i];
    }

    if (max > A[k])
      printf("%d", max);
    else
      printf("%d", A[k]);
  }
  return 0;
}
