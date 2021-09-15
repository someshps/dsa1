#include <stdio.h>

int partition(int arr[], int low, int high){

	int pivot = arr[low];

	int s =low+1;
	int e =high;

	while(s<e){
		if(pivot < arr[s] && pivot < arr[e]){
			e--; //end element need not be swapped
		}
		else if(pivot > arr[s] && pivot > arr[e]){
			s++; //start element need not be swapped
		}
		else if(pivot > arr[s] && pivot < arr[e]){
			s++;
			e--;

		}
		else if(pivot < arr[s] && pivot > arr[e]){
			//swap arr[s] and arr[e]
			int temp = arr[s];
			arr[s] = arr[e];
			arr[e] = temp;
			s++;
			e--;
		}
	}

	if(pivot > arr[s-1]){
		//swap the first element with the arr[s]
		int temp = arr[low];
		arr[low] = arr[s-1];
		arr[s-1] = temp;
		
	}

	return s-1;


}

void quicksort(int arr[], int low,int high){

	if(low==high){
		return;
	}

    while (low < high){
      int pivotIndex = partition(arr,low,high);
      quicksort(arr,low,pivotIndex-1);
      quicksort(arr,pivotIndex+1,high);
    }

}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int arr[100];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}

	quicksort(arr, 0, n-1);

	for(int i=0;i<n-1;i++){
		printf("%d ",arr[i]);
	}

	printf("%d ",arr[n-1]);

	return 0;
}