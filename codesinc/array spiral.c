#include<stdio.h>
#include<stdlib.h>

int A[50][50];
int size;
int Ar[50][50];
int Bk[50*50];

void entry(int n)
{
    int i, j;

    if((n%2) == 1)
    {
        printf("Enter the array elements \n");
        for(i = 0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d", &A[i][j]);
            }
        }
    }
    else
    {
        printf("wrong digit");
        exit(0);
    }
}

void display()
{
    int i, j;
    for(i = 0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("%d \t", A[i][j]);
        }
        
        printf("\n");
    }
}

void arrange()
{
    int k = size*size, i, j;
    int l=0, temp, left =-1, right = size -1, top = 0, bottom = size-1;
    int B[k], c=0;
    
    for(i = 0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            B[l++] = A[i][j];
        }
    }
        
    for(i = 0; i<k-1; i++)
    {
        for(j = 0; j<k-i-1; j++)
        {
            if(B[j]>B[j+1])
            {
                temp = B[j];
                B[j] = B[j+1];
                B[j+1] = temp;
            }
        }
    }



    while(left<=right && top<=bottom)
    {
        left++;
        
        for(i = left; i<=right; i++)
        {
            Ar[top][i] = B[c++];
        }
        
        top++;
        
        for(i =top; i<=bottom;i++)
        {
            Ar[i][right]= B[c++];
        }
        
        right--;
        
        for(i = right; i>= left; i--)
        {
            Ar[bottom][i] = B[c++];
        }
        bottom--;
        
        for(i = bottom; i>= top; i--)
        {
            Ar[i][left] = B[c++];
        }

        
    }

    for(int p = 0; p<size; p++){
            for(int q=0; q<size; q++) 
                printf("%d ", Ar[p][q]);
            printf("\n");
        }
        printf("\n");
}




int main()
{
    printf("\nEnter the size of the array in odd digits \n");
    scanf("%d", &size);
    entry(size);
    //display();
    arrange();
}
