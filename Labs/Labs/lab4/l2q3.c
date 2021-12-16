#include<stdio.h>

//divide the array into two halves

// int min(int a, int b){
// 	if(a<b){
// 		return a;
// 	}
// 	return b;
// }

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}
// }

// int start_idx(int a[], int s, int e){
// 	//base case
// 	if(s>=e){
// 		return s;
// 	}

// 	int m=(s+e)/2;

// 	int x1=start_idx(a, s, m);
// 	int x2=start_idx(a, m+1, e);

// 	return min(x1, x2);

// }



// int end_idx(int a[], int s, int e){
// 	//base case
// 	if(s>=e){
// 		return s;
// 	}

// 	int m=(s+e)/2;

// 	int x1=end_idx(a, s, m);
// 	int x2=end_idx(a, m+1, e);

// 	return max(x1, x2);

// }

struct pair{
	int i, j;
};

struct pair max_cont(int a[], int s, int e){
	//base case
	if(s==e){
		struct pair p0={0, 0};
		return p0;
	}

	int m=(s+e)/2;

	struct pair p1 = max_cont(a, b, s, m);
	struct pair p2 = max_cont(a, b, m+1, e);
	printf("%d\n", p2.j);

	int l1=(p1.j)-(p1.i)+1;
	int l2=(p2.j)-(p2.i)+1;

	if((p2.i)==(p1.j)){
		struct pair p3={p1.i, p2.j};
			return p3;
	}else{
		if(l1>l2){
			return p1;
		}
		else{
			return p2;
		}
	}
	
	// struct pair p3 = {p1, p2};
	// return p3;

}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int a[1000];
	int b[1000];

	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}

	for(int i=0;i<n;i++){
		scanf("%d", &b[i]);
	}


	struct pair pans = max_cont(a, b, 0, n-1);
	printf("%d Start Index \n", pans.i);
	printf("%d End Index \n", pans.j);
	int l=(pans.j)-(pans.i)+1;
	printf("%d\n", l);



	return 0;
}