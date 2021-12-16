#include<stdio.h>
#include<stdlib.h>
int find(int a[], int n){
	int s=0;
	int e=n-1;
	int m;
	while(s<e){
	    
	    
		m = (s+e)/2;
		
		if(s==e){
		    return s;
		}
		if(a[m]>a[m+1] && a[m]>a[m-1]){
			return m;
		}
		else if(a[m]<a[m-1]){
			e=m-1;
		}
    else if(a[m]<a[m+1]){
			s=m+1;
		}
// 		else{
// 			return m;
// 		}
	}
  
	return s;
}

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);
	int a[1000];

	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}

	int k = find(a, n);
	// int s=0;
	// int e=n-1;
	// int m;
	// int ans;
	// while(s<e){
	// 	m = (s+e)/2;
	// 	if(a[m]>a[e]){
	// 		s=m;
	// 	}
	// 	else if(a[m]<a[e]){
	// 		e=m;
	// 	}
	// 	else{
	// 		ans = a[m];
	// 	}
	// }

	printf("%d\n", a[k]);
	return 0;
}