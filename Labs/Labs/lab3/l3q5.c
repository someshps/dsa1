#include <stdio.h>

int n = 0; //initially the heap is empty
int arr[1001]; 


void heapify(int index){

    //heapify after deletion

    int parent = index;

    int left = 2 * index + 1; 
    int right = 2 * index + 2; 

    if (left < n && arr[left] < arr[parent]){
        parent = left;
    }
    if (right < n && arr[right] < arr[parent]){
        parent = right;
    }

    if (parent != index) {

        int temp=arr[index];
        arr[index]=arr[parent];
        arr[parent]=arr[temp];

        heapify(parent);
    }
}

void delete_min_from_heap(){
    int last = arr[n - 1];
    arr[0] = last; //deletes the root
    n--;
    heapify(0);
}

void add_heap(int index){
    //place the new element at right position
    int parent = (index - 1) / 2;

    if (arr[index] < arr[parent]) {
        int temp=arr[index];
        arr[index]=arr[parent];
        arr[parent]=arr[temp];

        add_heap(parent);
    }
}

void insert_in_heap(int value){
    n = n + 1; //inc the size of heap
    arr[n - 1] = value;
    add_heap(n - 1);
}
 

int main() {

  int queries;
  scanf("%d", &queries);
  
  while(queries--){
    char a;
    scanf(" %c", &a);

    if(a == 'a'){
      //add an element 
      int x;
      scanf(" %d", &x);
      insert_in_heap(x);
    }

    else if(a == 'd'){
      //delete min from heap
      delete_min_from_heap();
    }

    else{
      //print the min element
      printf("%d\n", arr[0]);
    }

  }


  return 0;
}