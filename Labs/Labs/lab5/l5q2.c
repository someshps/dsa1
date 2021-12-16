#include<stdio.h>

int pivotIdx(int arr[], int low, int high){
	int pivot = arr[low];

	int s=low+1;

	for(int i=s; i<=high; i++){
		if(pivot>arr[i]){
			//swap arr[s] and arr[i]
			int temp = arr[s];
			arr[s] = arr[i];
			arr[i] = temp;
			s++;	

		}

	}

	//now put pivot at its correct position
	//swap pivot with a[s-1]
	int temp = arr[s-1];
	arr[s-1] = arr[low];
	arr[low] = temp;

	return s-1;

}

void quicksort(int arr[], int low, int high){
	if(low>=high){
		return;
	}
	
	int pivot = pivotIdx(arr, low, high);
	quicksort(arr, low, pivot-1);
	quicksort(arr, pivot+1, high);

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
  	printf("%d",arr[n-1]);

	return 0;
}