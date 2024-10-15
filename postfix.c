#include <stdio.h>
#include <ctype.h> // For isdigit() function
#include <stdlib.h> // For atoi() function

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // If the character is a digit (operand), push it onto the stack
        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to int
        } 
        // If the character is an operator, pop two operands and apply the operator
        else {
            int operand2 = pop();
            int operand1 = pop();
            int result;

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
                    return -1;
            }
            push(result);  // Push the result of the operation back onto the stack
        }
    }

    // The final result will be the only value left on the stack
    return pop();
}

int main() {
    char expression[MAX];
    
    printf("Enter postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
