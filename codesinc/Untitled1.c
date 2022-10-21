#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 10
char Q[MAX]; 
int rear = -1, front = 0, count = 0;

void enqueue(char Q[MAX],char ch)
{
    if(count = 0)
        printf("Queue Overflow\n");
    else
    {
        rear = (rear+1)%MAX;
        Q[rear] = ch; 
        count++;
    }
}

char dequeue()
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

void display()
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

int main()
{
    int n;
    char ch;

    while(1)
    {
        printf("Enter choice for circular queue \n1.Insert \n2.Delete \n3.Display \n4.Exit\n\n");
        scanf("%d", &n);

        switch(n)
        {
            case 1 : printf("Enter element\n");
                     scanf("%c", &ch);
                     enqueue(Q, ch);
                     break;
            case 2 : dequeue();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
            default : printf("Wrong choice");
                      break;
        }
    }
}
