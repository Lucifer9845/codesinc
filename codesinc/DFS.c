#include<stdlib.h>
#include<stdio.h>
int a[10][10], visited[10], n;
void DFS(int s)
{
    int i;
    visited[s] = 1;
    printf("%dn\t", s);
    for(i = 0; i<n; i++)
    {
        if(a[s][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void BFS(int s)
{
    int i, f = 0, r = -1, q[n];
    visited[s] =  1;
    printf("%d\t", s);
    while(1)
    {
        for(i = 0; i<n; i++)
        {
            if(a[s][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[++r] = 1;
            }
        }
    }
    if(f>r)
            return i;
        s = q[f++];
    printf("%d\t", s);        

}

int main()
{
    int i, j, source;
    printf("Enter the no. of nodes");
    scanf("%d", &n);
    printf("Enter the graph in adjancy matrix");
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }


    for(i = 0; i<n; i++)
        visited[i] = 0;

    printf("Enter the source node\n");
    scanf("%d", &source);
    printf("DFS traversed is");
    DFS(source);
}

