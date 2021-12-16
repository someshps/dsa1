#include<stdio.h>

int main(int argc, char const *argv[])
{
	int n1;
	int n2;
	scanf("%d", &n1);
	scanf("%d", &n2);

	int a[1000];
	int b[1000];
	int c[1000];


	for(int i=0;i<n1;i++){
		scanf("%d", &a[i]);
	}

	for(int i=0;i<n2;i++){
		scanf("%d", &b[i]);
	}

	int i=0;
	int j=0;
	int k=0;

	while(i<n1 && j<n2){
		if(a[i]<b[j]){
			c[k]=a[i];
			i++;
			k++;
		}
		else{
			c[k]=b[j];
			j++;
			k++;
		}
	}

	while(i<n1){
		c[k]=a[i];
		i++;
		k++;
	}	

	while(j<n2){
		c[k]=b[j];
		j++;
		k++;
	}
	printf("%d\n", c[0]);
	printf("%d\n", c[1]);
	for(int p=0; p<n1+n2; p++){

		printf("%d",c[p]);
	}

	return 0;
}