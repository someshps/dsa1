#include<stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	scanf("%d", &n);
	int a[1000];
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}

	int c=0;
	int pivot=A[0];
	for(int i=0;i<n;i++){
		if(a[i]<pivot){
			c=c+1;
		}
	}
	pivot = a[c];
	//swap(a[0], a[c]);

	int temp = a[0];
	a[0]=a[c];
	a[c]=temp;

	//now I have placed the pivot element at its correct position
	//i now have to do swapping in left and right halves


	int i=0;
	int j=c+1;
	while(a[i]<pivot && i<=c){
		i++;
	}
	while(a[j]>pivot && j<n){
		j++;
	}
	swap(a[i], a[j]);


	return 0;
}