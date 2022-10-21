#include<stdio.h>
#include<stdlib.h>

struct Slist
{
    int data;
    struct slist *next;
};

typedef struct slist node;

node *start = NULL;

node* getnode()
{
    node newnode = (node)malloc(sizeof(node));
    printf("Enter Data \n");
    scanf("%d", newnode->data);
    newnode->next = NULL;
    return newnode;
}

void Insertbegin()
{
    node newnode
}