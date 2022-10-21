#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 5

int stack[max], top = -1;

void push(int ele)
{   
    if(top == max-1)
        printf("stack overflow");
    else
    {   //printf("Enter the element:\n");
        //scanf("%d", &ele);
        stack[++top] = ele;
    }
    
}

int pop()
{   int item;
    if(top == -1)
        printf("stack underflow");
    else
    {   stack[top--] = item;
        printf("the popped element is : %d", stack[top--]);
    }
    return item;
}

void display()
{   int i;
    if(top == -1)
        printf("stack empty");
    else
    {   printf("\nthe elements are\n");
        for(i = top; i>=0; i--)
            printf("%d\n", stack[i]);
    }   
}

void pali()
{   int i;
    int bk, num, rcm;
    top = -1;
    printf("Enter the number\n");
    scanf("%d", &num);
    bk = num;
    while (num!=0)
    {
        rcm = num%10;
        push(rcm);
        num=num/10;
    }
    num = 0;
    for(i = 0; top!=-1;i++)
        num = pop()*pow(10,i) + num;
    if(bk = num)
        printf("\nit is a palindrome");
    else
        printf("\nit is not a palindrome");
}

int main()
{
    int ch, eln;

    while(1)
    {
        printf("\nEnter choice\n1.push\n2.pop\n3.display\n4.palindrome\n5.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1 : printf("Enter the element to be pushed\n");
                    scanf("%d", &eln); 
                    push(eln);
                    break;
            case 2 : pop();
                    break;
            case 3 : display();
                    break;
            case 4 : pali();
                    break;
            case 5 : exit(0);
            default : printf("Wrong choice");
                    break;
        }
    }
    return;
}