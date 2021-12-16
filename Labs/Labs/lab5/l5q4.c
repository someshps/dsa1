#include <stdio.h>




int main(void) {
  int arr[11];
  arr[0] = 1;
  for(int i=1; i<11;i++){
    arr[i] =arr[i-1]*2;
  }

  int max =0;
  int n;
  scanf("%d",&n);
  int temp;
  for(int i=0;i<n;i++){
    scanf("%d",&temp);
    if(temp > max){
      max = temp;
    }
  }
  int a=0;
  while(arr[a] < max){
    a++;
  }
  printf("%d",arr[a]);

  return 0;
}