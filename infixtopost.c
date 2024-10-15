#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top=-1;

int isoperand(char ch){
    return isalnum(ch);
}
int precedence(char op){
    switch(op){
case '+':return 1;
case '-': return 1;
case '*':
case '/': return 2;
case '^': return 3;
default : return 0;

    }
}
int isrightassociative(char op){
    return op=='^';
}
void push(char op){
    if(top>MAX-1){
        printf("full stack.");
        return ;
    }
top++;
stack[top]=op;

}
char pop(){
    if(top==-1){
        printf("Empty stack");
        return -1;
    }
    char op=stack[top--];
    return op;
}
char peek(){
    if(top>=0){
        return stack[top];

    }
    return '\0';
}

void infixtopostfix(char* expression){
    char  result[MAX];
    int j=0;
    for (int i=0;i<strlen(expression);i++){
        char ch=expression[i];
        if(isoperand(ch)){
            result[j++]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if (ch==')'){
            while(top>=0&& peek()!= '('){
                result[j++]=pop();
            }
            pop();
        }
        else{
            while(top>=0 && precedence(peek())>= precedence((ch))){
                if(isrightassociative(ch) && precedence(peek())==precedence((ch))){
                    break;
                }
                else{
                    result[j++]=pop();
                }

               
            }
             push(ch);
        }
    }
    while(top>=0){
        result[j++]=pop();
    }
    result[j]='\0';
    printf("postfix expression %s",result);
    
    }

int main(int argc, char const *argv[])
{
    char expression[MAX];
    printf("Enter your infix expression");
    scanf("%s",expression);
    infixtopostfix( expression);
    return 0;
}
