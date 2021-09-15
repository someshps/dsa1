#include<stdio.h>

void heapify(int A[], int i, int n){
	//heapify is a rec program, so first we'll write the base case

	if(i>=n){
		return;  //if the idex in not in the array return
	}

	//the below piece of code deals with a node and its two children only
	//you begin by assuming the parent as smallest index
	//but if this is not the case, then either of the leftChildIdx or the rightChildIdx 
	//gets assigned as the smallestElementIdx.
	//Now you check whether the initially assumed parent is the smallest or not
	//if it is not, then you swap it with the smallest element and 
	//call heapify on the child which was swapped

	int smallestElementIdx =  i;
	int leftChildIdx = 2*i+1;
	int rightChildIdx = 2*i+2;

	if(leftChildIdx < n && A[leftChildIdx]<A[smallestElementIdx]){
		smallestElementIdx = leftChildIdx;
	}
	if(rightChildIdx < n && A[rightChildIdx]<A[smallestElementIdx]){
		smallestElementIdx = rightChildIdx;
	}

	if(smallestElementIdx != i){
		//swap a[sei] and a[i] and call heapify on sei
		int temp = A[smallestElementIdx];
		A[smallestElementIdx] = A[i];
		A[i] = temp;

		heapify(A, smallestElementIdx, n);
	}

	return;

}

int main(int argc, char const *argv[])
{
	
	int n;
	scanf("%d", &n);

	int A[100];

	for(int i=0;i<n;i++){
		scanf("%d", &A[i]);
	}

	for(int i=0;i<n;i++){ //go to every index in the array and heapify it
		heapify(A, i, n); //why we are heapifying every index and not only 0th index
	}
	
	//after the above 'for loop', you have an array that represents an implicit minheap

	//heap sort this array now ---->

	//1. swap last leaf with root
	//2. delete root--> this is done by calling heapify on n-1-i
	//3. heapify (0th index in array A which has n-1-i elements)

	for(int i=0;i<n;i++){
		printf("%d ", A[0]);

		int temp  = A[0];
		A[0] = A[n-1-i];  //do not just swap with n-1
		A[n-1-i] = temp;

		heapify(A, 0, n-1-i); //do not call only on n-1, call on n-1-i
	}
	return 0;
}