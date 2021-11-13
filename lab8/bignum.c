#include<stdio.h>

int top;
int stack[1000];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int arr[1000];
	int ansarr[1000];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}

	top = -1;
	for(int i=n-1;i>=0;i--){
		if(top==-1){
			stack[++top] = arr[i];
			ansarr[top]=-1;
		}else{
			if(stack[top]>arr[i]){
//				printf("%d ", stack[top]);

				stack[++top]=arr[i];
				ansarr[top]=i;		
			}
			else{
				while(top!=-1 && stack[top]<arr[i]){
					top--;
				}
				
				stack[++top]=arr[i];
				ansarr[top]=i;
			}
		}

	}

	for(int i=0;i<n;i++){
		printf("%d ", ansarr[i]);
	}
	return 0;
}