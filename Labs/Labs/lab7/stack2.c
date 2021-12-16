#include<stdio.h>
#include <stdlib.h>

int arr[1000];
int top;

int main(void)
{
    int n;
    int x;
    char ch;

    top=-1;

    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        //printf("%d\n", n);
        scanf(" %c",&ch);
        scanf(" %d",&x);

        if(ch == 'a'){
            top++;
            arr[top]=x;
        }
        else if(ch == 'd'){
            top--;
        }

        if(top<0){
          printf("NULL");
        }
        else if(top==0){
          printf("%d", arr[0]);
        }
        else if (top>0){
          for(int i =top;i>=1;i--){
            printf("%d ", arr[i]);
          }
          printf("%d", arr[0]);
        }
        printf("\n");
    }

    return 0;
}