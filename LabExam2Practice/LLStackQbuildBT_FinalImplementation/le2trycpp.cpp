#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int n;
	int k
	scanf("%d", &n);
	scanf("%d", &k);
	int arr[1000];

	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	int max= -1;
	for(int i=0;i<=k;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}

	printf("%d\n", max);
	return 0;
}