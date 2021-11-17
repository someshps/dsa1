#include <stdio.h>
int top;
int stack[1000];

int main(void) {

	int n;
	scanf("%d", &n);
	
	int arr[1000];
	int ansarr[1000];
	
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	top=n;
	for(int i=n-1;i>=0;i--){
	    if(top==n){
	        stack[--top]=i;
	        ansarr[i]=0;
	    }
	    else{
	        if(arr[i]<arr[stack[top]]){
	            ansarr[i]=stack[top];
	            stack[--top]=i;
	        }
	        else{
    	        while(top!=n && arr[i]>arr[stack[top]]){
    	            top++;
    	        }
    	        if(top==n){
    	            ansarr[i]=0;
    	            stack[--top]=i;
    	        }else{
    	            ansarr[i]=stack[top];
    	            stack[--top]=i;
    	        }
	        }
	    }
	    
	}
	
	for(int i=0;i<n-1;i++){
	    printf("%d ", ansarr[i]);
	}
	printf("%d", ansarr[n-1]);
	
	return 0;
}

 