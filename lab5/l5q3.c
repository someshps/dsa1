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

void tweak_qs(int arr[], int low, int high, int k){
	if(low>=high){
		return;
	}

	int pivot = pivotIdx(arr, low, high);

	if(pivot == k-1){
		return;
	}

	tweak_qs(arr, low, pivot-1, k);
	tweak_qs(arr, pivot+1, high, k);
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int k;
	scanf("%d", &k);

	int arr[100];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}

	tweak_qs(arr, 0, n-1, k);

	printf("%d\n", arr[k-1]);

	return 0;
}