#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
   }Node;
int main(){
   Node *start=NULL;
   start= malloc(sizeof(Node));
start->next=malloc(sizeof(Node));
start->next->next=malloc(sizeof(Node));
start->data=-4;
start->next->data=8;
start->next->next->data=7;
start->next->next->next=NULL;
int count=0;
while(start!=NULL){
    printf("%d\n",start->data);
    start=start->next;
    count++;
    
}
printf("%d",count);

    return 0;

}