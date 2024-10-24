#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top=-1;

int isoperand(char ch) {
    return isalnum(ch);
}

int precedence(char op) {
    switch(op) {
        case '+': 
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default : return 0;
    }
}

int isrightassociative(char op) {
    return op == '^';
}

void push(char op) {
    if(top >= MAX - 1) {
        printf("Full stack.");
        return;
    }
    stack[++top] = op;
}

char pop() {
    if(top == -1) {
        printf("Empty stack");
        return '\0'; // returning '\0' for empty stack
    }
    return stack[top--];
}

char peek() {
    if(top >= 0) {
        return stack[top];
    }
    return '\0';
}

void infixtopostfix(char* expression) {
    char result[MAX];
    int j = 0;

    for(int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if(isoperand(ch)) {
            result[j++] = ch;
        }
        else if(ch == '(') {
            push(ch);
        }
        else if(ch == ')') {
            while(top >= 0 && peek() != '(') {
                result[j++] = pop();
            }
            pop(); // popping '('
        }
        else {
            while(top >= 0 && (precedence(peek()) > precedence(ch) || 
                   (precedence(peek()) == precedence(ch) && !isrightassociative(ch)))) {
                result[j++] = pop();
            }
            push(ch);
        }
    }

    while(top >= 0) {
        result[j++] = pop();
    }

    result[j] = '\0';
    printf("Postfix expression: %s\n", result);
}

int main() {
    char expression[MAX];
    printf("Enter your infix expression: ");
    scanf("%s", expression);

    infixtopostfix(expression);
    return 0;
}
