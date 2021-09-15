#include <stdio.h>
#include <stdlib.h>
void swap (int*, int*);

int main(void) {
  int n,sum, max_so_far=0,arr[1000];

  scanf("%d",&n);
  
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);


  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {  
      sum=0;
      swap(&arr[i],&arr[j]);
      for(int k=0;k<n;k++)
        sum=sum+abs(arr[k]-(k+1));

      if (sum>max_so_far)
        max_so_far=sum;

      swap(&arr[i],&arr[j]);
    }

  }
  printf("%d",max_so_far);
  return 0;
}
void swap(int *x,int *y)
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}