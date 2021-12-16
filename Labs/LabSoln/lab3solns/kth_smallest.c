#include<stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int A[], int n, int root)
{
	int largest = root;
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2;

	if (left_child <= n && A[left_child] > A[largest])
	{
		largest = left_child;
	}

	if (right_child <= n && A[right_child] > A[largest])
	{
		largest = right_child;
	}

	if (largest != root)
	{
		swap(&A[root],&A[largest]);
		max_heapify(A,n,largest);
	}

}


void build_heap(int A[], int k)
{
	int i;
	int last = k/2 - 1;
	for(i = last; i >= 0; i--)
	{
		max_heapify(A,k,i);
	}
}

void  delete_max(int A[], int end)
{
	swap(&A[0],&A[end]);
	max_heapify(A,end-1,0);
}

void add(int A[], int end)
{

	int parent = (end-1)/2;
	if (end > 0 && A[parent] < A[end])
	{
		swap(&A[end],&A[parent]);
		add(A, parent);

	}
}


int main()
{
	int n,k,i, index;
	int heap[100];
	scanf("%d%d",&n,&k);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&heap[i]);
	}

	build_heap(heap,k-1);
	int count = k-1;
	while(count < n)
	{
		printf("%d ",heap[0]);
		count++;
		if (heap[count] < heap[0])
		{
			delete_max(heap,k-1);
			heap[k-1] = heap[count];
			add(heap, k-1);
		}
	}
}
