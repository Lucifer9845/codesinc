
#include <stdio.h>
// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char source, char dest, char temp)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from %c to %c", source, dest);
        return;
    }
    towerOfHanoi(n-1, source, temp, dest);
    printf("\n Move disk %d from %c to %c", n, source, dest);
    towerOfHanoi(n-1, temp, dest, source);
}
  
int main()
{
    int n;
    printf("Enter number of disks\n"); // Number of disks
    scanf("%d", &n);
    towerOfHanoi(n, 's', 'd', 't');  // A, B and C are names of rods
    return 0;
}