#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
int queue[MAX];
int rear=-1;
int  front=-1;
void push(int val){
    if(rear>MAX-1){
        printf("Queue overflow");
        return;
    }
     if(front==-1 && rear==-1){
        front=0;
    }
    rear++;
    queue[rear]=val;
   
}
int pop(){
    if (front ==-1 || rear==-1){
        printf("Nothing here buddy..sad");
        return-1;
    }
    if(front>rear){
        ("Emptied..");
        return -1;
    }

    int data=queue[front];
    front++;
    return data;
}
void peek(){
    if(front > rear ){
        return;
    }
    while(front<=rear){
    printf("%d\t",queue[front]);
    front++;
    }
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    int item=pop();
    printf("%d",item);
    peek();
    return 0;
}
