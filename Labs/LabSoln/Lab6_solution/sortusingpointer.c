#include<stdio.h>
void  InsertionSort(int *p, int n)
{
   for(int i=1; i<n; i++)
    for(int j=i; j>0; j--)
    {
      if(*(p+j) < *(p+j-1))
      {
        int temp = *(p+j);
        *(p+j) = *(p+j-1);
        *(p+j-1) = temp;
      }
      printf("Got here");
    }
}

int main()
{
    int arr[1000];
    int n,i;
    scanf("%d", &n);
    printf("Got here");
    for (i =0 ; i< n; i++)
    {
      scanf("%d", &arr[i]);
    }

    InsertionSort(arr,n) ;
    for (i =0 ; i< n-1; i++)
    {
      printf("%d ", arr[i]);
    }
    printf("%d", arr[n-1]);
    return 0;
}
