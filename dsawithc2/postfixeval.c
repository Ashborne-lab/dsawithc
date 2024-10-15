#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX][MAX];
int top=-1;
void push(char *val){
    if(top>MAX-1){
        printf("Stack overflow .");
        return;
    }
    top++;
   strcpy(stack[top],val);
}
char* pop(){
if(top==-1){
    printf("stack underflow");
    return "";
}
return  stack[top--];

}
char* peek(){
  if(top==-1){
    printf("stack underflow");
    return "";
}  
return stack[top];
}
// int precedence(char op){
//     if(op=='+' || op=='-'){
//         return 1;
//     }
//     else if(op=='*' || op== '/'){
//         return 2;
//     }
//     else if(op=='^'){
//         return 3;
//     }
//     else {
//         return 0;
//     }
// }
void postfixevaluation(char *expression){
    char op1[MAX],op2[MAX],result[MAX],temp[2];
    for(int i=0;i<strlen(expression);i++){
        char c=expression[i];
        if(isalnum(c)){
            temp[0]=c;
            temp[1]='\0';
            push(temp);
        }
        else{
            if(top!=-1){
            strcpy(op1,pop());
            strcpy(op2,pop());
            sprintf(result,"(%s %c %s)",op2,c,op1);
            push(result);
            }
            else{
                printf("No operands.");
            }
        }
    }
    printf("Infix expression : %s\n",pop());
}
int main(int argc, char const *argv[])
{
    char expression[MAX];
    printf("Enter your postfix expression. ");
    scanf("%s",expression);
    postfixevaluation(expression);
    return 0;
}
