#include<stdio.h>

int is_heap(int A[], int n, int i)
{
	if(2*i + 2 > n)
		return 1;
		
	int left_child = ((A[2 * i + 1] >= A[i]) && is_heap(A, n, 2*i + 1));
	
	int right_child = ((A[2 * i + 2] >= A[i]) && is_heap(A, n, 2*i+ 2 ));
	
	return (left_child&&right_child);	
}

int main()
{
	int heap[100],n, i, index;
	scanf("%d", &n);
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&heap[i]);
	}
	index = 0;
	if(is_heap(heap,n,index))
	{
		printf("YES");
	}	
	else
	{
		printf("NO");
	}
}
