#include <stdio.h>
#include <stdlib.h>

#define n 10

int queue[1000];
int front = -1;
int rear = -1;

void enqueue(int value){
	if(rear==n-1){
		printf("overflow\n");
		return;
	}
	else if(front == -1 && rear == -1){
		front = 0;
		rear = 0;
		queue[rear] = value;
		return;
	}
	else{
		rear  = rear+1;
		queue[rear]  = value;
		return;
	}

	
}

void dequeque(){
	if(front == -1 && rear == -1){
		printf("Null\n");
		return;
	}
	else if(front == rear){
		front = -1;
		rear =  -1;
		return;
	}
	else{
		front++;
		return;
	}

	
}

void printQueue(){
	if(front == -1 && rear == -1){
		printf("Null\n");
		return;
	}
	else{
		for(int i=front;i<rear+1;i++){
			printf("%d ", queue[i]);
		}
		return;
	}
	
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	int x;
	char ch;

	while(t--){
		
		scanf("%c", &ch);
		scanf("%d", &x);
		
		if(ch=='e'){
			//enqueue(x);
					if(rear==n-1){
					printf("overflow\n");
					//return;
				}
				else if(front == -1 && rear == -1){
					front = 0;
					rear = 0;
					queue[rear] = x;
					//return;
				}
				else{
					rear  = rear+1;
					queue[rear]  = x;
					//return;
				}


		}
		else if(ch=='d'){
			//dequeque();
				if(front == -1 && rear == -1){
					printf("Null\n");
					//return;
				}
				else if(front == rear){
					front = -1;
					rear =  -1;
					//return;
				}
				else{
					front++;
					//return;
				}	
		}
				if(front == -1 && rear == -1){
					printf("Null\n");
					//return;
				}
				else{
					for(int i=front;i<rear+1;i++){
						printf("%d ", queue[i]);
					}
					//return;
				}
	}

	return 0;
}











