#include <stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int val){
    if(top==MAX-1){
        printf("Stack is full");
        return;
    }
    stack[++top]=val;
}
int pop(){
    if(top==-1){
        printf("Stack is empty.");
        return -1;
    }
    return stack[top--];
}
int peek(){
    if(top==-1){
        printf("Stack is empty.");
        return -1;
    }
    return stack[top];
}
char isoperator(char ch){
    return ch=='+'|| ch == '-' || ch == '*' || ch == '/';
}
void postfixevaluation(char *express){
    int operand1,operand2,result;
    for(int i=0;i<strlen(express);i++){
        char ch=express[i];
        if(isalnum(ch)){
            ch=ch-'0';
            push(ch);
        }
        else{
          if(isoperator){
            operand2=pop();
            operand1=pop();
             switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Unknown operator: %c\n", ch);
                    return;
            }
            push(result); 
          }
        }
    }
    printf("result is %d ",pop());
}
int main(int argc, char const *argv[])
{
    char expression[MAX];
    
    printf("Enter postfix expression: ");
    scanf("%s", expression);
    postfixevaluation(expression);
    return 0;
}
