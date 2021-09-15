#include<stdio.h>

void merge(int a[], int s, int m, int e){
	int i=s;
	int j=m+1;
	int k=s;

	int b[100];

	while(i<=m && j<=e){
		if(a[i]<a[j]){
			b[k]=a[i];
			i++;
			k++;
		}
		else{
			b[k]=a[j];
			j++;
			k++;
		}
	}

	while(i<=m){
		b[k] = a[i];
		i++;
		k++;
	}

	while(j<=e){
		b[k] = a[i];
		j++;
		k++;
	}

	for(int p=s;p<=e;p++){
		a[p]=b[p];
	}

	return;

}

void mergesort(int a[], int s, int e){
	if(s>=e){
		return;
	}

	int m=(s+e)/2;

	mergesort(a, s, m);
	mergesort(a, m+1, e);
	merge(a, s, m, e);
}

int main(int argc, char const *argv[])
{
	
	int n;
	scanf("%d", &n);

	int a[100];

	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}

	mergesort(a, 0, n-1);

	//print the array
	for(int i=0;i<n-1;i++){
		printf("%d ", a[i]);
	}

	printf("%d", a[n-1]);


	return 0;
}