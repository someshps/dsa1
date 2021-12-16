#include<stdio.h>
int getMinimum( int *p, int n)
{
   int min = *p;
   int i;
   for( i =1; i<n; i++)
   {
     if (min > *(p+i))
     {
       min = *(p+i);
     }
   }
   return min;
}

int main()
{
  int arr [1000]; int min;
  int n;
  int i;
  scanf("%d", &n);
  for (i =0 ; i< n; i++)
  {
    scanf("%d", &arr[i]);
  }
  min = getMinimum(arr,n) ;
  printf("%d", min);
  return 0;
}
