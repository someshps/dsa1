#include<stdio.h>


int mod(int a, int b){
	if(a>b){
		return a-b;
	}
	return b-a;
}

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int a[100]; //original array
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	int sum=0;
	int maxSum=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			//swap(a[i], a[j]);
			int temp1=a[i];
			a[i]=a[j];
			a[j]=temp1;
			sum=0;
			for(int p=1;p<=n;p++){
				sum=sum+mod(a[p],p);
			}

			maxSum=max(maxSum, sum);
			//swap(a[j], a[i]);
			int temp2=a[j];
			a[j]=a[i];
			a[i]=temp2;
		}
	}

	printf("%d\n", maxSum);


	return 0;
}