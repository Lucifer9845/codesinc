#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack2[20];
int top = -1;

void push4(char sym)
{
    stack2[++top] = sym;
}

char pop()
{
    return stack2[top--];
}

int prec(char sym)
{
    switch (sym)
    {
        case '^': 
        case '$': return 4;
        case '%':
        case '/':
        case '*': return 3;
        case '-':
        case '+': return 2;
        case '(':
        case ')':
        case '#':return 1;
    }
    return 0;
}

void convertip(char *infix, char *postfix)
{   char symbol;
    int i, j = 0;
    push4('#');
    for(i = 0; i<strlen(infix); i++)
    {
        symbol = infix[i];
        switch(symbol)
        {
            case '(': push4(symbol);
                    break;
            case ')': while(stack2[top] != '(')
                        postfix[j++] = pop();
                    pop();
                    break;
            case '^':
            case '$':
            case '%':
            case '/':
            case '*':
            case '+':
            case '-': while(prec(symbol) <= prec(stack2[top]))
                        postfix[j++] = pop();
                    push4(symbol);
                    break;
            default : postfix[j++] = symbol;
            break;
        }
    }

    while(stack2[top] != '#')
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int main()
{
    char infix[20], postfix[20];
    printf("\nEnter inifx expression");
    gets(infix);
    convertip(infix, postfix);
    printf("\npostfix expression is \n %s", postfix);
    
}