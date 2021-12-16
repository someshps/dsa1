#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  int arr[1000];

  int a0[1000];
  int a1[1000];
  int a2[1000];

  int a0c=0;
  int a1c=0;
  int a2c=0;

  for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
    if(arr[i]==0){
      a0[a0c]=arr[i];
      a0c++;
    }
    else if(arr[i]==1){
      a1[a1c]=arr[i];
      a1c++;
    }
    else{
      a2[a2c]=arr[i];
      a2c++;
    }
  }

  for(int i =0;i<a0c;i++){
    printf("%d ", a0[i]);
  }

  for(int i =0;i<a1c;i++){
    printf("%d ", a1[i]);
  }

  for(int i =0;i<a2c;i++){
    printf("%d ", a2[i]);
  }
  
  return 0;
}