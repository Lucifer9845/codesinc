#include<stdio.h>
#include<stdlib.h>

int Arr[10], n;

void insert()
{
    int i, pos, key;
    printf("Enter the array position and element\n");
    scanf("%d%d", &pos, &key);
    if(pos<0 || pos>n)
    {
        printf("position invalid\n");
    }
    else 
    {
        for(i = n; i >pos; i--)
        {
            Arr[i+1] = Arr[i];
        }
        Arr[pos] = key; 
    }
}

 void del()
 {
     int pos, i;
     printf("Enter the position to be deleted\n");
     scanf("%d", &pos);
     if(pos<0 || pos > n)
    {
        printf("position invalid\n");
    }
    else
    {
        for(i = pos; i<n;i++)
            Arr[i] = Arr[i+1];
    }
 }

 void display()
{
    int i;
    for(i = 0; i<n;i++)
    {
        printf("%d\t", Arr[i]);
    }
}

void createArr()
{
    int n, i, p;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    printf("Enter the number of elements to be inserted\n");
    scanf("%d", &p);

    printf("Enter array elements\n");
    for(i = 0; i<p; i++)
        scanf("%d", &Arr[i]);
}

int main()
{
    int ch;
    
    createArr();
    while(1)
    {
        printf("1. insert element\n2. delete element\n3. display\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: insert();
                break;
            case 2: del();
                break;
            case 3: display();
                break;
            default: printf("wrong choice\n");
                break;
        }
    }   
}