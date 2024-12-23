#include <stdio.h>
#include <stdbool.h>
#define MAX 100
char stack[MAX];
int top = -1;
bool isEmpty()
{
    return top == -1;
}
void push(char item)
{
    if (top < MAX - 1)
    {
        stack[++top] = item;
    }
}

char pop()
{
    if (!isEmpty())
    {
        return stack[top--];
    }
    return '\0';
}
bool isValidExpression(const char *expression)
{
    char ch;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty())
            {
                return false;
            }
            char topChar = pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
            {
                return false;
            }
        }
    }
    return isEmpty();
}
int main()
{
    char expression[MAX];
    printf("Enter an expression: ");
    scanf("%s", expression);
    if (isValidExpression(expression))
    {
        printf("Expression: %s is valid\n", expression);
    }
    else
    {
        printf("Expression: %s is invalid\n", expression);
    }
    return 0;
}