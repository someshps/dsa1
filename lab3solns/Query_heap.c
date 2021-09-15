#include<stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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

void heapify(int A[], int n, int i)
{
	int parent = (i - 1)/2;
	if(A[i] < A[parent])
	{
		swap(&A[i],&A[parent]);
		heapify(A,n,parent);
	}
	 
}

void add_in_heap(int A[], int key, int index)
{
	A[index] = key;
	heapify(A,index+1,index);
}

int delete_from_heap(int A[], int index)
{
	swap(&A[0],&A[index]);
	index--;
	min_heapify(A,index+1,0);
	return(index);
}

int main()
{
	int n,index = -1,i,heap[100];
	char operation;
		
	scanf("%d",&n);
	for(i = 0; i < n ; i++)
	{	
		operation = getchar();
		if(operation == 'a')
		{	
			int value;	
			scanf("%d",&value);
			index++;
			add_in_heap(heap,value,index);
		}
	
		else if(operation == 'q')
		{
			printf("%d\n",heap[0]);
		}
	
		else if(operation == 'd')
		{
			index = delete_from_heap(heap,index);
			
		}
		else
		{
			i--;
		}
	}
}
