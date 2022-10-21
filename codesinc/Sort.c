#include<stdio.h>
#include<stdlib.h>

int Array[100], n;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void input()
{
    int i;
    printf("Enter the array size less than 100\n");
    scanf("%d", &n);

    printf("Enter the array elements\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &Array[i]);
    }
    
}

void display()
{
    int i;
    printf("The array elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t",Array[i]);
    }
}

int main()
{
    int ch;
    printf("1. Insertion sort\n");
    scanf("%d", &ch);
    input();

    switch(ch)
    {
        case 1: insertionSort(Array, n);
    }

    display();
}