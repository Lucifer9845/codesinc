#include<stdio.h>
#include<stdlib.h>

struct DLL
{
    int ssn, sal;
    char name[50], dept[50], desg[50], phno[11];
    struct DLL *next, *prev;
};
typedef struct DLL node;

node *start = NULL;

node* getnode()
{
    node *newnode = (node*)malloc(sizeof(node));
    printf("Enter SSN, name, department, designation, phone number and salary");
    scanf("%d%s%s%s%s%d", &newnode->ssn, newnode->name, newnode->desg, newnode->dept, newnode->phno, &newnode->sal);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertbgn()
{
    node *newnode = getnode();
    
    if(start == NULL)
        start = newnode;
    else
    {
        newnode->prev = start;
        start->prev = newnode;
        start = newnode;
    }
}

void insertend()
{
    node *newnode = getnode(), *temp = start;
    if(start == NULL)
        start = newnode;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deletbgn()
{
    node *temp = start;
    if(start == NULL)
        printf("list is empty");
    else
    {
        if(start->next == NULL)
        {
            printf("deleted: %d", temp->ssn);
            start = NULL;
            free(temp);
        }
        else
        {
            printf("deleted: %d", temp->ssn);
            start = temp->next;
            start->prev = NULL;
            free(temp);        
        }
        
    }   
}

void deletend()
{
    node *temp = start;

    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        if(start->next == NULL)
        {
            printf("deleted: %d", temp->ssn);
            start = NULL;
            free(temp);
        }
        else
        {
            while(temp->next=NULL)
                temp = temp->next;
            printf("deleted: %d", temp->ssn);
            (temp->prev)->next=NULL;
            free(temp);
        }   
    }
}

void display()
{
    node *temp = start;
    int count = 0;
    if(start == NULL)
        printf("list is empty");
    else
    {
        printf("lst elements are:\n");
        while(temp != NULL)
        {
            printf("%d\t%s\t%s\t%s\t%s\t%d\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->phno, temp->sal);
            temp = temp->next;
            count++;
        }
        printf("Number of employees : %d\n", count);
    }
}

int main()
{
    int ch;
    printf("\n1. Insert begin\n2. Insert end\n3.delete begin\n4. Delete end\n5. Display\n6.exit\n");
    

    while (1)
    {
        printf("enter choice\n");
        scanf("%d", &ch);

        switch(ch)
        {

            case 1 : insertbgn();
                    break;
            case 2 : insertend();
                    break;
            case 3 : deletbgn();
                    break;
            case 4 : deletend();
                    break;
            case 5 : display();
                    break;
            case 6 : exit(0);
            		break;
            default : printf("Wrong choice\n");
                    break;
        }
    }
    
}
