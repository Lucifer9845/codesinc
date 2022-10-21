#include<stdio.h>

int A[10], n;

void cre(int s)
{   int i;

    printf("Enter the array elements\n");
    for(i = 0; i <s; i++)
        scanf("%d", &A[i]);
}

void ins()
{
    int pos, ele, i;
    printf("Enter the element and the position to be placed at.\n");
    scanf("%d %d", &ele, &pos);
    
    for(i = n; i>=pos; i--)
       A[i+1] = A[i];
    A[pos] = ele;
}

void del()
{   int i, pos;
    printf("Enter the position to be deleted \n");
    scanf("%d", &pos);
    printf("deleted element is %d", A[pos]);
    for(i =  pos; i <n-1; i++)
        A[i] = A[i+1];
}

void display()
{
    int i;
    printf("the elements are :\n");
    for(i = 0; i < n; i++)
        printf("%d\t", A[i]);
}

int main()
{
    int ch; 
    printf("1.create array\n2.insert element\n3.delete element\n4.display array\n5.exit");

    while(1)
    {
        printf("Enter choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("enter the size of the array\n");
                    scanf("%d", &n);
                    cre(n);
                    break;
            case 2: ins();
                    break;
            case 3: del();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);

            default : printf("wrong input \n");
                     break;
        }
    }
}