#include<stdio.h>

int binarySearch(int arr[], int n, int q){
	int s=0;
	int e=n-1;
	int m;// = (s+e)/2;
	while(s<=e){
		m = (s+e)/2;
		if(arr[m]==q){
			return 1;
		}
		else if(arr[m]>q){
			e=m-1;
		}
		else{
			s=m+1;
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int k; 
	scanf("%d", &k);
	int q;
	
	int arr[1000];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}

	int found;
	while(k--){
		scanf("%d", &q);
		found = binarySearch(arr, n, q);
		if(found){
			printf("Y\n");
		}
		else{
			printf("N\n");
		}
	}
	
	// int s, e;
	// while(k--){
	// 	scanf("%d", &q);
	// 	s=0;
	// 	e=n-1;
	// 	while(s<=e){
	// 		int m = (s+e)/2;
	// 		if(arr[m]>q){
	// 			e=m-1;
	// 		}
	// 		else if(arr[m]<q){
	// 			s=m+1;
	// 		}
	// 		else{
	// 			printf("Y\n");
	// 		}
	// 	}
	// 	if(s>=e){
	// 		printf("N\n");
	// 	}
	// }
	return 0;
}