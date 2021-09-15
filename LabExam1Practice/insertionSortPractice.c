#include<stdio.h>

void insertionsort(int a[], int n){

	for(int i =1;i<n;i++){
		for(int j=i;j>=1;j--){
			if(a[j-1]>a[j]){
				//swap
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j]=temp;
			}
			else{
				break; //do nothing
			}
		}
	}

	return;

}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int a[100];

	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}

	insertionsort(a, n);

	for(int i=0;i<n-1;i++){
		printf("%d ", a[i]);
	}

	printf("%d", a[n-1]);



	return 0;
}