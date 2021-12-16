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
  int j;

  for(i=0 ; i<n; i++)
  {
    if(A[i] == i+1)
      continue;
    else
      break;
  }

  for(j = n-1; j>=0; j--)
  {
    if(A[j] == j+1)
      continue;
    else
      break;
  }

  if (i >= n)
    printf("0");
  else
    printf("%d", j-i+1);
  return 0;
}
