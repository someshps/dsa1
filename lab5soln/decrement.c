#include<stdio.h>

int main()
{
  int n;
  scanf("%d",&n);
  int A[1000];
  int i;
  for(i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
  }

  int B[11];
  for(i=0; i<11; i++)
  {
    B[i]=0;
  }

  for(i=0 ; i<n ;i++)
  {
    int poweroftwo=1;
    int exponent=0;

    while( A[i] >= poweroftwo)
    {
      poweroftwo = poweroftwo*2;
      exponent += 1;
    }

    if(A[i] == poweroftwo)
    {
      B[exponent]++;
    }
    else
    {
      B[exponent-1]++;
    }
  }


  int poweroftwo=1;
  i=0;
  int ipower = 1;
  while(1)
  {
    if (i >= 11)
    {
      printf("%d", poweroftwo);
      break;
    }
    if (B[i] == 0)
    {
      i++;
      ipower *= 2;
      continue;
    }
    else
    {
      B[i]--;
      poweroftwo *= 2;

      if(poweroftwo > ipower)
      {
        i++;
        ipower *= 2;
      }
    }

  }

  return 0;
}
