#include<stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int a[100]; //original array
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}

	int ac[1000]; //copy of the original array
	for(int i=1;i<=n;i++){
		ac[i]==a[i];
	}

	int c[1000];
	//c is the reverse sorted array
	for(int i=1;i<n;i++){
		for(int j=i+1)
	}

	int flag=0;
	for(int p=1;p<=n;p++){
		if(a[p]!=c[p]){ //check if the array is not rev sorted
			flag=1;
		}
	}

	int ans=0;
	if(flag){ //if the array is not rev sorted 
		for(int i=1;i<=n;i++){
			if(a[i]!=c[i]){
				for(int i=1;i<=n;i++){
					if(a[i]==c[i]){     // iterate from begining
						int idx =i;
					}
				}
				swap(a[i], a[idx]);
			}
		}

		//calculate sum1

		for(int i=n;i>=1;i--){
			if(a[i]!=c[i]){
				for(int i=n;i>=1;i--){
					if(a[i]==c[i]){  //iterate from end
						int idx =i;
					}
				}
				swap(a[i], a[idx]);
			}
		}

		//calculate sum2
		ans=max(sum1, sum2)
	}else{
		//ans is the sum of c  //if the array was rev sorted then sum is the ans
	}



	return 0;
}