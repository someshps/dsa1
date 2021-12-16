#include<stdio.h>
#include<stdlib.h>

int top;
int arr[1000];

void push(int arr[], int val, int top){

	top=top+1;
	arr[top] = val;

	return;
}

void PrintStack(int arr[], int top){

    int topp=top;

	if(topp>=0){
		for(int i=topp;i>=1;i--){
			printf("%d ", arr[i]);
		}
		printf("%d\n", arr[0]);
	}
	else{
		printf("NULL\n" );
	}

	return;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
    
	top=-1;


	for(int i=0;i<n;){
	    printf("now i is %d\n",i);

	    // char str[4];
      //   scanf("%s",str);
      //   int val=0;
      //   for (int i=1;str[i]!='\0';i++)
      //   {
      //       val = val*10 + ((int)(str[i])-48);
            
      //   }
      
      char what;
      scanf("%s",&what);
      char str[4];
      str[0]=what;
      printf("command is %c\n",what);
        if(str[0] == 'a'){
            int val;
            scanf("%d", &val);
            printf("value to be added is %d\n", val);
            // push(arr, val, top);
            
            arr[++top]=val;
            
            printf("The new array is :\n");
            for (int i=top;i>-1;i--){
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
        else{
            printf("value to be deleted\n");
            top--;
            printf("The new array is :\n");
            for (int i=top;i>-1;i--){
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
        // PrintStack(arr, top);
        i=i+1;

	}

	return 0;
}