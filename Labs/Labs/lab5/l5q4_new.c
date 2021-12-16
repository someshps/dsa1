#include<stdio.h>

int main(int argc, char const *argv[])
{
	//create an array that contains the powers of 2
	int power[10];
	power[0]=1;
	for(int i=1;i<=10;i++){
		power[i]=power[i-1]*2;
	}

	int n;
	scanf("%d", &n);
	int arr[100];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]); //take input the array
	}

	int max_power=1;
	for(int i=0;i<n;i++){
		if(arr[i]>max_power){
			max_power = arr[i]; //checking the max power of two present
		}
	}

	int p=0;
	while(power[p]<max_power){
		p++;
	}

	printf("%d\n", power[p]);
	return 0;
}