#include<stdio.h>
#include<stdlib.h>
#define max 7
int a[max], count = 0;

void display()
{
    int i;
    printf("\n hastable contents are \n");
    printf("\n Index \t data");
    for(i = 0; i<max; i++)
    {
        printf("\n%d\t%d\n", i, a[i]);
    }
}

void linearprobe(int index, int num)
{
    int i;
    if(count == max)
    {
        printf("hash table is full");
        return;
    }
    else if(a[index] == -1)
    {
        a[index] = num;
        count++;
    }
    else
    {
        printf("collision \n, it is resolving linear probing technique\n");
        i= index;
        do
        {
            i = (i+1) % max;
            if(a[i] == -1)
            {
                a[i] = num;
                count++;
                return;
            }
        } while (i != index);
        
    }
}

int main()
{
    int i, num, index, input;

    for(i = 0; i<max; i++)
        a[i] = -1;
    
    do
    {
        printf("\n Enter the number");
        scanf("%4d", &num);
        index = num % max;
        linearprobe(index, num);
        display();
        printf("\n Enter 1 to continue");
        scanf("%d", &input);
    }while(input == 1);
    return 0;
}