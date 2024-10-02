#include<stdio.h>

#define MAX 100
int stack[MAX];


int top=-1;
void push(int val){
    if(top==MAX-1){
        printf("Stack overflow");
        return ;
    }
    top++;
    stack[top]=val;
}
int  pop(void){
    if (top==-1){
        printf("stack underflow");
        return -1;
    }
    int item=stack[top--];
    return item;
}
void display(){
    int t=top;
    while(t!=-1){
        printf("%d\n",stack[top]);
        t--;
    }
}

int main()
{
    int choice;
    int v;
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            	
            	//input v here 
                scanf("%d",&v);
                push(v);
                break;
            
            case 2:
                  int item =pop();
                printf("the popped value is : %d ",item);
                break;
            
           
            case 3:
                display();
                printf("\n\t EXIT POINT ");
                break;
          
            default:
            
                printf ("\n\t Please Enter a Valid Choice(1/2/3)");
           
                
        }
    }
    while(choice!=3);
    return 0;
}
