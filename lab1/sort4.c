#include <stdio.h>

int main() {
  // int n;
  // scanf("%d", &n);

  int arr[4];

  for(int i =0;i<4;i++){
    scanf("%d", &arr[i]);
  }

  for(int i=0;i<3;i++){ //go only till 2nd last ele
    for(int j=i+1;j<4;j++){ //for every i go from i+1 till end
      if(arr[j]<arr[i]){ 
        //swap
          int c = arr[j];
          arr[j] =arr[i];
          arr[i]= c;
      }
    }
  }

  for(int i =0;i<4;i++){
    printf("%d ", arr[i]);
  }


  return 0;
}
q