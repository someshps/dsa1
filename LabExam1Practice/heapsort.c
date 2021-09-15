#include<stdio.h>

void heapify(int A[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    if (l < n && A[l] < A[largest])
        largest = l;
  
    // If right child is larger than largest so far
    if (r < n && A[r] < A[largest])
        largest = r;
  
    // If largest is not root
    if (largest != i) {
        //swap(A[i], A[largest]);
        int temp  = A[i];
        A[i]=A[largest];
        A[largest]=temp;
  
        // Recursively heapify the affected sub-tree
        heapify(A, n, largest);
    }
}


void HeapSort(int A[], int n){

	int i = n-1;
	int v=n-1;

	if(n==0){
		return;
	}

	if(n==1){
		printf("%d ", A[0]);
	}

	while(i>=0){
		printf("%d ", A[0]);
		v=i;
		A[0] = A[v];
		// A[v]=-1;  //deleting the leaf node
		i--;
		heapify(A, n, 0);
	} 

	return;
}
void buildHeap(int A[], int n)
{
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;
  
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(A, n, i);
    }
}
// void BuildHeap(int A[], int i, int n){

// 	// if(A[2*i+1]==-1){ //array has only one element 
// 	// 	return;
// 	// }  

// 	// if(A[2*i+2]==-1 && A[2*i+1] != -1){  //array has two elemenets
// 	// 	if(A[i]<A[2*i+1]){
// 	// 		return;
// 	// 	}
// 	// 	else{
// 	// 		//swap 
// 	// 		int temp = A[i];
// 	// 		A[i] = A[2*i+1];
// 	// 		A[2*i+1] =temp;
// 	// 		return;
// 	// 	}
// 	// }

// 	if(i>=(n/2)){
// 		return;
// 	}

// 	BuildHeap(A, 2*i+1, n);
// 	BuildHeap(A, 2*i+2, n);

// 	heapify(A, i);
// }

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int A[100]={-1};

	for(int i=0;i<n;i++){
		scanf("%d", &A[i]);
	}

	buildHeap(A, n);
	
	HeapSort(A, n);


	return 0;
}