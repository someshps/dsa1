#include<stdio.h>

int main()
{
  int n;
  int A[10000] = {0}, B[10000];


  scanf("%d", &n);
  int i;

  for( i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }

  int count = 1;
  int removed = 0;
  int steps = 0;
  while( removed < n)
  {
    int startcount = count;
    for(i = 0; i < n; i++)
    {

      if(A[i] == count)
      {
        count++;
      }
    }

    steps += n-removed;
    removed += count - startcount;
  }

  printf("%d", steps);
}
