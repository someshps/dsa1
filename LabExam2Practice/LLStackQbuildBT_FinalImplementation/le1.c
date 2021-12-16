#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);
	int a[1000];

	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	int s=0;
	int e=n-1;
	int m;
	int ans;
	while(s<e){
		m = (s+e)/2;
		if(a[m]>a[e]){
			s=m;
		}
		else if(a[m]<a[e]){
			e=m;
		}
		else{
			ans = a[m];
		}
	}

	printf("%d\n", ans);
	return 0;
}