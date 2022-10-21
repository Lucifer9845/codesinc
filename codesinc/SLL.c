#include<stdio.h>
#include<stdlib.h>

struct SLL
{
    char name[50], prog[20], usn[11];
    int sem;
    char phno[11]; 
    struct SLL *next;
};

typedef struct SLL node;
int count = 0;
node *start = NULL;

node* getnode()
{
    node *newnode = (node*)malloc(sizeof(node));
    printf("Enter name, sem, prog, phno, usn \n");
    scanf("%s%d%s%s%s", &newnode->name, &newnode->sem, &newnode->prog, &newnode->phno, &newnode->usn);
    // gets(newnode->name);
    
    // fflush(stdin);
    // gets(newnode->prog);
    // gets(newnode->phno);
    // gets(newnode->usn);
    // scanf("%d", &newnode->sem);
    newnode->next = NULL;
    return newnode;
}

void insbegin()
{
    node* newnode = getnode();
    if(start == NULL)
        start = newnode;
    else
    {
        newnode->next = start->next;
        start = newnode;
        count++;
    }
}

void insend()
{
    node *newnode = getnode(), *temp = start;
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        count++;
    }
}

void deletebeg()
{
    node *temp = start;
    if(start == NULL)
        printf("empty");
    else 
    {
        printf("deleted : %s", start->usn);
        start = start->next;
        free(temp);
        count--;
    }
}

void deletend()
{
    node *temp = start, *prev = start;
    if(start == NULL)
        printf("empty");
    else
    {
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        printf("delted : %s", temp->usn);
        prev->next = NULL;
        free(temp);
        count--;
    }
}

void display()
{
    node *temp = start;
    if(start == NULL)
        printf("empty");
    else
    {
        while(temp!= NULL)
        {
            printf("%s\t %s\t %s\t%d \t%ld", temp->name, temp->usn,temp->prog, temp->sem,temp->phno);
            temp = temp -> next;        
        }
    }
}

int main()
{
    int choice, i, n;
    
    while(1)
    {
        printf("Enter choice \n 1.Inser begin \n2.insert end\n 3.delete begin \n4. deleted end\n5. display\n6.exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 : printf("Enter no of student \n");
                    scanf("%d", &n);
                    for(i = 0; i<n; i++)
                    {
                        insbegin();
                    }
                    break;
            case 2 : insend();
                    break;
            case 3 : deletebeg();
                    break;
            case 4 : deletend();
                    break;
            case 5: display();
                    break;
            case 6 : exit(0);

            default : printf("invalid choice");
                    break;
        }
    }
    return 0;
}