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
  int B[1000];
  int C[1000];
  scanf("%d", &n);
  int i;
  int x;

  for(i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }
  ind = n-1;
  for(i=0; i<n; i++)
  {
    scanf("%d", &B[i]);
  }

  find(A,B,C,0,n-1,0,n-1);

  for(i=0 ; i<n-1; i++)
    printf("%d ", C[i]);
  printf("%d", C[n-1]);

  return 0;
}
