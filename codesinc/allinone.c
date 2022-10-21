#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 5

int a[50];
int n, val, i, pos;

void create()
{
	printf("Enter the size of the array: \n");
	scanf("%d", &n);
	
	printf("Enter the array elements: \n");
	
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
}

void display1()
{
	printf("The array elements are \n");
	
	for(i=0;i<n;i++)
		printf("%d \t", a[i]);
}

void insert()
{
	printf("Enter the position of the new Elements \n");
	scanf("%d", &pos);
	
	printf("Enter the element to be inserted: \t");
	scanf("%d", &val);
	
	for(i=n; i>=pos; i--)
	{
		a[i+1] = a[i];
	}
	a[pos] = val;
	
	n++;
}

void Delete()
{
	printf("Enter the position of the element to be deleted \n");
	scanf("%d", &pos);
	
	val = a[pos];
	
	for(i = pos; i<n; i++)
	{
		a[i] = a[i+1];
		
	}
	
	n--;
	
	printf("\n The deleted elements is = %d", val);
}

void Array()
{
	int choice;
	while(1)
	{
		printf("Enter choice \n");
		printf("\n 1.create \n 2. display \n 3. insert \n 4. delete \n 5. exit \n");
		
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: create();
					break;
			case 2: display1();
					break;
			case 3: insert();
					break;
			case 4: Delete();
					break;
			case 5: exit(0);
					break;
			default : printf("Wrong choice");
					break;
		}
	}
}

void Stringr()
{
	char STR[100], PAT[100], REP[100], ans[100];
	
	int i, j, c, m, k, flag =0;
	
	printf("Enter the main string: \n");
	gets(STR);
	gets(STR);
	printf("Enter the pattern \n");
	gets(PAT);

	printf("Enter the replace string \n");
	gets(STR);
	
	i=j=m=c=0;
	
	while(STR[c] != '\0')
	{
		if(STR[m] == PAT[i])
		{
			i++;
			m++;
			if(PAT[i] == '\0')
			{
				for(k =0; REP[k] != '\0'; k++, j++)
				{
					ans[j] = REP[k];
					flag = 1;
				}
				
				i =0;
				c = m;
			}
		}
		
		else
		{
			ans[j] = STR[c];
			j++;
			c++;
			m = c;
			i = 0;
		}
	}
	
	if(flag ==0)
		printf("\npattern doesn't exist\n");
	else
	{
		ans[j] = '\0';
		printf(" \n resultant string is %s \n", ans);
	}
}

int stack[max], top = -1;

void push(int ele)
{   if(top == max-1)
        printf("stack overflow");
    else
    {
        stack[++top] = ele;
    }
    
}

int pop()
{   int item;
    if(top == -1)
        printf("stack underflow");
    else
    {   item = stack[top--];
        // printf("the popped element is : %d", stack[top--]);
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
    printf("ENter the number");
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

int Stack()
{
    int ch, ele;

    while(1)
    {
        printf("\nEnter choice\n1.push\n2.pop\n3.display\n4.palindrome\n5.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1 : printf("\nenter the element to be pushed\n"); 
					scanf("%d", &ele);
					push(ele);
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
    return 0;
}

char stack2[20];

void push4(char sym)
{
    stack2[++top] = sym;
}

char pop2()
{
    char el;
    el = stack2[top--];
    return el;
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

char convertip(char *infix, char *postfix)
{   char symbol;
    int i, j = 0;
    push4('#');
    for(i = 0; i<strlen(infix); i++)
    {
        symbol = infix[i];
        switch(symbol)
        {
            case 'c': push4(symbol);
                    break;
            case ')': while(stack2[top] != '(')
                        postfix[j++] = pop2();
                    pop();
                    break;
            case '^':
            case '$':
            case '%':
            case '/':
            case '*':
            case '+':
            case '-': while(prec(symbol) <= prec(stack2[top]))
                        postfix[j++] = pop2();
                    push4(symbol);
                    break;
            default : postfix[j++] = symbol;
            break;
        }
    }

    while(stack2[top] != '#')
        postfix[j++] = pop2();
    postfix[j] = '\0';
    return postfix;
}

void itp()
{
    char infix[20], postfix[20];
    printf("\nEnter inifx expression");
    gets(infix);
    convertip(infix, postfix);
    printf("\npostfix expression is \n %s", postfix);
    
}

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
        if(isdigit(sym))
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

void evaluateexp()
{
    char postfix[50];
    printf("\nEnter the expression:\n");
    scanf("%s", postfix);
    evaluate(postfix);
}

#define MAX 10
char Q[MAX]; 
int rear = -1, front = 0, count = 0;

void enqueue(char Q[], char ch)
{
    if(count == MAX)
        printf("Queue Overflow\n");
    else
    {
        rear = (rear+1)%MAX;
        Q[rear] = ch; 
        count++;
    }
}

void dequeue()
{
    if(count == 0)
        printf("Queue underflow\n");
    else
    {
        printf("Deleted element is %c\n", Q[front]);
        front = (front +1)%MAX;
        count--;
    }
}

void displaycq()
{
    if(count == 0)
            printf("Queue empty\n");
    else
    {
        int i, j = front;
        for(i = 0; i<count; i++)
        {
            printf("%c\t", Q[j]);
            j = (j+1)%MAX;
        }
        printf("\n");
    }
}

void cqueue()
{
    int n;
    char ch;

    while(1)
    {
        printf("\n\nEnter choice for circular queue \n1.Insert \n2.Delete \n3.Display \n4.Exit\n");
        scanf("%d", &n);

        switch(n)
        {
            case 1 : printf("Enter element\n");
            fflush(stdin);
                     scanf("%c", &ch);
                     enqueue(Q, ch);
                     break;
            case 2 : dequeue();
                     break;
            case 3 : displaycq();
                     break;
            case 4 : exit(0);
            default : printf("Wrong choice\n");
                      break;
        }
    }
}

int main()
{   int choice;
    printf("\nEnter choice:\n");
    printf("1. Array \n2. String patter\n3.Stack \n4.infix to postfix\n5. evaluate postfix expression\n6.Circular Queue\n");
    scanf("%d", &choice);
    while(1)
    {
        switch(choice)
        {
            case 1 : Array();
                    break;
            case 2 : Stringr();
                    break;
            case 3 : Stack();
                    break;
			case 4: itp();
				    break;
            case 5: evaluateexp();
                    break;
            case 6 : cqueue();
                    break;
			default : printf("Wrong choice");
				break;
        }
    }
}