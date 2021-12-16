#include<stdio.h>

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}

int min(int a, int b){
	if(a<b){
		return a;
	}
	return b;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int a[100]; //original array
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	int b[100];
	for(int i=0;i<n;i++){
		scanf("%d", &b[i]);
	}

	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int s=i;
			int e=j;
			int maxA=-1001;
			int minB=1001;
			for(int p=s;p<=e;p++){
				maxA=max(a[p], maxA);
			}
			// printf("%d\n", maxA);
			for(int p=s;p<=e;p++){
				minB=min(b[p], minB);
			}
			// printf("%d\n", minB);
			if(maxA<minB){
				ans=max(ans, e-s+1);

			}
		}
	}

	printf("%d\n", ans);
	return 0;
}