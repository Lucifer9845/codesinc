#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int top = -1;
float stack3[20];

void push3(float ele)
{
    stack3[++top] = ele;
}

float pop3()
{
    return (stack3[top--]);
}

void evaluate(char postfix[50])
{
    int i;
    char sym;
    float op1, op2, result;

    for(i = 0; i<strlen(postfix); i++)
    {
        sym = postfix[i];
        if(isdigit(sym) == 1)
            push3(sym-'0');
        else
        {
            op2 = pop3();
            op1 = pop3();
            switch(sym)
            {
                case '+': push3(op1+op2);
                        break;
                case '-': push3(op1-op2);
                        break;
                case '*': push3(op1*op2);
                        break;
                case '/': push3(op1/op2);
                        break;
                case '%': push3((int)op1%(int)op2);
                        break;
                case '^':
                case '$': push3(pow(op1, op2));
                        break;
                default: printf("wrong input");
                        exit(0);
            }
        }
    }

    result = pop3();
    printf("\nResult : %f", result);
}

int main()
{
    char postfix[50];
    printf("\nEnter the expression:\n");
    gets(postfix);

    evaluate(postfix);
}