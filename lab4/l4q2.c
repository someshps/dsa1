#include<stdio.h>

//rec program shows a seg fault => you forgot to write the base case 

void merge(int a[], int s, int e, int m){
	int i=s;
	int j=m+1;
	int k=s;

	int p[1000];

	while(i<=m && j<=e){
		if(a[i]<a[j]){
			p[k]=a[i];
			i++;
			k++;
		}
		else{
			p[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=m){
		p[k]=a[i];
		k++;
		i++;
	}
	while(j<=e){
		p[k]=a[j];
		j++;
		k++;
	}

	for(int k=s;k<=e;k++){
		a[k]=p[k]; //made mistake for variables here
	}


	return;
}

void merge_sort(int a[], int s, int e){
	// int s=0;
	// int e=n-1;
	if(s>=e){
		return;
	}

	int m=(s+e)/2;

	merge_sort(a, s, m);
	merge_sort(a, m+1, e);
	merge(a, s, e, m);

	return;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int a[1000];

	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}

	merge_sort(a, 0, n-1);

	for(int i=0;i<n-1;i++){
		printf("%d ", a[i]);
	}

	printf("%d", a[n-1]);

	return 0;
}