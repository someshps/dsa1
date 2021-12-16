#include <stdio.h>

int findinterval(int A[], int B[], int low, int high )
{
  if (low == high)
  {
    if (A[low] < B[low])
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    int A_max[100], B_min[100];

    int mid = (low+high)/2;

    int i;
    int current_max = A[mid];
    int current_min = B[mid];
    for (i = mid; i >= low; i--)
    {
       if(A[i] < B[i])
       {
         if (A[i] > current_max )
         {
           current_max = A[i];
         }


         if(B[i] < current_min)
         {
           current_min = B[i];
         }

         if (current_max < current_min)
         {
           A_max[i] = current_max;
           B_min[i] = current_min;
         }
         else
         {
           break;
         }
       }
       else
       {
         break;
       }
    }
    int min = i+1;

    current_max = A[mid+1];
    current_min = B[mid+1];
    for (i = mid+1; i >= low; i++)
    {
       if(A[i] < B[i])
       {
         if (A[i] > current_max )
         {
           current_max = A[i];
         }

         if(B[i] < current_min)
         {
           current_min = B[i];
         }

         if (current_max < current_min)
         {
           A_max[i] = current_max;
           B_min[i] = current_min;
         }
         else
         {
           break;
         }
       }
       else
       {
         break;
       }
    }

    int max = i-1;
    int answer = 0;

    int j = min;
    for(i = mid+1; i<=max; i++)
    {
      while( j <= mid && B_min[j] < A_max[i])
      {
        j++;
      }

      if (j> mid)
      {
        break;
      }
      else
      {
        if (i-j+1 > answer)
        {
          answer = i-j+1;
        }
      }
    }

    int ans1 = findinterval(A,B, low, mid);
    int ans2 = findinterval(A,B, mid+1,high);

    if (ans1 > answer)
    {
      answer = ans1;
    }

    if (ans2 > answer)
    {
      answer = ans2;
    }

    return answer;
  }
}
int main()
{
    int arr1[100] = {}, arr2[100] = {0}, max_interval = 0, ptr = -1, size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr2[i]);

    int ans = findinterval(arr1,arr2,0,size-1);
    printf("%d", ans);
}
