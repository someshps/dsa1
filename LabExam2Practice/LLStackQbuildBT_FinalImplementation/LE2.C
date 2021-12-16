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

	for(int i=0;i<=k;i++){
		if(a[i+1]>a[i]){
			push(&top, a[i]);
		}
		else{
			pop(&top);
		}
	}
	return 0;
}