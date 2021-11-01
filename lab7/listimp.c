#include<stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

void insertAtHead(struct node* head, int val){
    
    struct node* n = (struct node *)malloc(sizeof(struct node));
    
    if(head==NULL){
        n->data = val;
        n->next = NULL;
        head = n;
        
    }else{
        n->data = val;
        n->next =  head;
        head =  n;
    }
    
    return;
}

void deletell(struct node* head, int val){
    if(head==NULL){
        return;
    }
    
    if(head->data == val){
        struct node* p = head;
        head = head->next;
        free(p);
        
    }
    else{
       struct node* v = head->next;
       struct node* u= head;
       while(v!=NULL){
           if(v->data == val){
               u->next = v->next;
               free(v);
           }else{
               u=v;
               v=v->next;
           }
       }
    }
    
    return;
}

void Print(struct node* head){
    while(head->next){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d", head->next->data);
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	
	struct node* head = (struct node *)malloc(sizeof(struct node));
	head  = NULL;

	while(n--){
	    char str[4];
        scanf("%s",str);
        int val=0;
        for (int i=1;str[i]!='\0';i++)
        {
            val = val*10 + ((int)(str[i])-48);
            
        }
        printf("%c" , str[0]);
        if(str[0] == 'a'){
            //printf("inside if %d", 1);
            insertAtHead(head, val);
            //printf("The inserted value is %d", head->data);
        }
        else{
            deletell(head, val);
        }

	}
	
	Print(head);
	free(head);
	return 0;
}