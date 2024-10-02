#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;
void push(int val);
int pop(void);

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow");
        return;
    }
    top++;
    stack[top] = val;
}
int pop(void)
{
    if (top == -1)
    {
        printf("stack underflow");
        return -1;
    }
    int item = stack[top--];
    return item;
}
int isempty()
{
    return top == -1;
}
int ismatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main()
{
    char str[50];
    int i;
    puts("Enter an exp with parentheses: ");
    scanf("%s", str);

    i = 0;
    while (str[i] != '\0')
    {
        // printf("Entered\n");
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
            // printf("pushed\n");
        }

        if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (isempty())
            {
                printf("empty stack\n");
                return -1;
            }
            char a = pop();
            if (!ismatching(a, str[i]))
            {
                printf("Invalid");
                return -1;
            }
        }

        i++;
    }

    if (isempty())
    {
        printf("valid matching");
    }
    else
    {
        printf("Invalid parenthes is matching");
    }
    return 0;
}