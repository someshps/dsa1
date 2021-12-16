/*Heap Sort*/
#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void reverse(int A[], int n)
{
	int i = 0;
	while (i < n-1)
	{
		swap(&A[i], &A[n-1]);
		i++;
		n--;
	}
}

void min_heapify(int A[], int n, int root)
{
	int smallest = root;
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2;
	
	if (left_child < n && A[left_child] < A[smallest])
	{
		smallest = left_child;
	}
	
	if (right_child < n && A[right_child] < A[smallest])
	{
		smallest = right_child;
	}
	
	if (smallest != root)
	{	
		swap(&A[root],&A[smallest]);
		min_heapify(A,n,smallest);
	}
	 
}


void heap_sort(int A[], int n)
{
	int i,j,k;
	for(i = n-1; i >= 0 ; i--)
	{
		swap(&A[0],&A[i]);
		min_heapify(A,i,0);	
	}
	reverse(A, n);
}


int main() 
{
	int n,i, heap[100];
	scanf("%d",&n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d",&heap[i]);	
	}

	heap_sort(heap,n);
	
	for(i = 0 ; i < n; i++)
	{
		printf("%d ",heap[i]);
	}	
	
	return 0;
}
