#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int data;
    struct node *next;
} Node;
void push (Node  **start_ptr,int val){
   Node *temp=malloc(sizeof(Node));
   if(NULL==temp){
    printf("Node is not created.");
    return;
   }
   temp->data=val;
   temp->next=NULL;
   Node *ptr=(*start_ptr);
   if(ptr==NULL){
    *start_ptr=temp;
   }
  temp->next=ptr;
  *start_ptr=temp;
}
int pop(Node **start_ptr){
if(*start_ptr==NULL){
    printf("Stack is empty.");
    return -1;
}
Node *temp=(*start_ptr);
int val=temp->data;
*start_ptr=temp->next;
free(temp);
return val;
}
void display(Node **start_ptr){
if (*start_ptr==NULL){
    printf("Empty stack");
    return ;
}
Node *ptr=(*start_ptr);
while(ptr!=NULL){
     printf("%d\t",ptr->data);
    ptr=ptr->next;
   
}
}
int main(){
    Node *stack=NULL;
    push(&stack,4);
      push(&stack,5);
        push(&stack,6);
          push(&stack,7);
          printf(" The first popped value is : %d\n",pop(&stack));

       display(&stack);   
    return 0;
}