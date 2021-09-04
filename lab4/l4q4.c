#include<stdio.h>

int max(int x, int y){
	if(x>y){
		return x;
	}
	else{
		return y;
	}
}

int mod(int a, int b){
	if(a>b){
		return a-b;
	}
	return b-a;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int arr[100];
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[i]);
	}

	int maxm = -3200;
	int maxIdx=0;

	for(int i=1; i<=n; i++){
		maxm=max(arr[i], maxm);
		maxIdx=max(maxIdx, i);
	}

	//swap(a[0], arr[maxIdx]);
	int temp=arr[1];
	arr[1]=arr[maxIdx];
	arr[maxIdx]=arr[1];

	// for(int i=0;i<n-1;i++){
	// 	printf("%d ", arr[i]);
	// }
	// printf("%d ", arr[n-1]);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum =  sum+mod(arr[i], i);
	}
	printf("%d", sum );


	return 0;
}