#include <stdio.h>

int main(void) {
  int arr[1000];
  int n;
  scanf("%d", &n);

  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
  }

  for(int i=0;i<n;i++){
    if(arr[i]<0){
      printf("%d ", arr[i]);
    }
  }

  for(int i=0;i<n;i++){
    if(arr[i]>=0){
      printf("%d ", arr[i]);
    }
  }

  return 0;
}