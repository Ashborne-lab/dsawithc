#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int val){
  if(top=MAX-1){
    printf("Stack overflow");
    return;
  }
  top++;
  stack[top]=val;
}
int pop(){
if(top==-1){
    printf("Stack underflow.\n");
    return -1;
}
int item=stack[top--];
return item;

}
void display(){

}
int main()
{


   return 0; 
}
