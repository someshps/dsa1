#include<stdio.h>

int partition(int arr[], int low, int high){
	int pivotIndex;
	//the below vars are given indices in terms of variables (like low, high) and not 
	//constant (like 0, n-1) since this function is called again and again inside the quicksort 
	//function

	int pivot = arr[low]; //pivot is arr[low] and not arr[0]
	int i = low+1; //i always starts from low+1, not 0
	int j = high; //j start 

	while(i<j){
		while(arr[i] < pivot && i<j){  //the i<j check is important here 
			i++;
		}
		while(arr[j] > pivot && j>i){
			j--;
		}
		// if(i>=j){
		// 	break;
		// }
		if(i<j){
			//swap arr[i] and arr[j]
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	if(arr[i] < pivot){ //if arr[i] is less than pivot then i is the correct pivot index
		//swap arr[i]  and arr[low]
		int temp = arr[low];
		arr[low] =  arr[i];
		arr[i] = temp;
		pivotIndex = i;  // !!!IMPORTANT!!! do not redeclare int pivotindex here..it leads to seg fault and u 
		//wil keep looking for base case
	}
	
	else{ //if arr[i] is  not less than pivot then i-1 is the correct pivot index
		//swap low with i-1
		int temp = arr[low];
		arr[low] =  arr[i-1];
		arr[i-1] = temp;
		pivotIndex = i-1;
	}

	return pivotIndex;
}


void quicksort(int arr[], int low, int high){

	if(low>=high){ //base case 
		return;
	}

	int pivotIndex = partition(arr, low, high);  //find out the correct index of pivot

	quicksort(arr, low, pivotIndex-1); //about the correct index of pivot call 
	quicksort(arr, pivotIndex+1, high); //quicksort on right and left halves

}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n); //take in n

	int arr[1000];

	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]); //take in array elements
	}

	quicksort(arr, 0, n-1); //call quicksort

	for(int i=0;i<n-1;i++){
		printf("%d ", arr[i]); //print the  sorted array
	}

	printf("%d", arr[n-1]);

	return 0;
}