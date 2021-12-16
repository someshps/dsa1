#include<stdio.h>
#include<stdlib.h>

void push(int arr[], int val, int *top){

	*top=*top+1;
	arr[*top] = val;

	return;
}

void PrintStack(int arr[], int top){

	if(top>=0){
		for(int i=top;i>=1;i--){
			printf("%d ", arr[i]);
		}
		printf("%d\n", arr[0]);
	}
	else{
		printf("NULL");
	}

	return;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	int arr[1000];
	int top=-1;


	while(n--){

	    char str[4];
        scanf("%s",str);
        int val=0;
        for (int i=1;str[i]!='\0';i++)
        {
            val = val*10 + ((int)(str[i])-48);
            
        }
        
        if(str[0] == 'a'){
            push(arr, val, &top);
        }
        else{
            top--;
        }

        PrintStack(arr, top);

	}

	return 0;
}