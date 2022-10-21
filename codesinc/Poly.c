#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct polynomial
{
    int coff, ex1, ex2, ex3, flag;
    struct polynomial *next;
};
typedef struct polynomial node;

void insend(node *head, int c, int x, int y, int z)
{
    node *temp = head->next;
    node *newnode = (node*)malloc(sizeof(node));
    newnode->coff = c;
    newnode->ex1 = x;
    newnode->ex2 = y;
    newnode->ex3 = z;
    newnode->flag = 0;

    while(temp->next != head)
        temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
}

void readpoly(node* head)
{
    int n, c, x, y, z,i;
    printf("Enter the no, of terms\n");
    scanf("%d", &n);
    for(i = 0; i<n; i++)
    {
        printf("Enter coff, ex1, ex2, ex3\n");
        scanf("%d%d%d%d", &c, &x, &y, &z);
        insend(head ,c, x, y, z);
    }   
}



void printpoly(node *head)
{
    node *temp = head->next;
    
    if(temp==head)
        printf("empty");
    else
    {
        while(temp->next != head)
        {
            printf("%dx^%dy^%dz^%d+", temp->coff, temp->ex1, temp->ex2, temp->ex3);
            temp = temp->next;
        }   
        printf("%dx^%dy^%dz^%d\n", temp->coff, temp->ex1, temp->ex2, temp->ex3);
    }
}

void evpoly(node *head)
{
    node *temp;
    int x, y, z, sum = 0;
    printf("Enter x, y, z\n");
    scanf("%d%d%d", &x, &y, &z);

    temp = head->next;
    while(temp != head)
    {
        sum = sum+temp->coff*pow(x, temp->ex1)*pow(y,temp->ex2)*pow(z,temp->ex3);
        temp = temp->next;
    }
    printf("sum = %d\n", sum);
}

void addpoly(node *h1, node *h2, node *h3)
{
    node *p1, *p2;
    int c;
    p1 = h1->next;
    p2 = h2->next;
    while(p1 != h1)
    {
        p2 = h2->next;
        while(p2!=h2)
        {
            if(p1->ex1==p2->ex1 && p1->ex2 == p2->ex2 && p1->ex3 == p2->ex3)
            {
                c = p1->coff + p2->coff;
                p2->flag = 1;
                p1->flag = 1;
                insend(h3, c, p1->ex1, p1->ex2, p1->ex3);
            }
            p2=p2->next;
        }
        p1 = p1->next;
    }
    p1 = h1->next;
    p2 = h2->next;

     while(p1 != h1)
    {
        if(p1->flag == 0)
        {
            insend(h3, p1->coff, p1->ex1, p1->ex2, p1->ex3);
        }
        p1 = p1->next;
    }
    while(p2 != h2)
    {
        if(p2->flag == 0)
        {
            insend(h3, p2->coff, p2->ex1, p2->ex2, p2->ex3);
        }
        p2 = p2->next;
    }
}


int main()
{
    node *h1, *h2, *h3;
    h1 = (node*)malloc(sizeof(node));
    h1->next = h1;
    h2 = (node*)malloc(sizeof(node));
    h2->next = h2;
    h3 = (node*)malloc(sizeof(node));
    h3->next = h3;
    printf("Enter the 1st polynomial\n");
    readpoly(h1);
    printf("Enter the 2nd polynomial\n");
    readpoly(h2);

    addpoly(h1, h2, h3);

    printf("first polynomial is \n");
    printpoly(h1);
    printf("second polynomial is \n");
    printpoly(h2);
    printf("resultant polynomial is \n");
    printpoly(h3);
    evpoly(h1);
}