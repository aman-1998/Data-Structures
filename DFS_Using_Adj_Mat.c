#include<stdio.h>
#include<stdlib.h>
int G[20][20],visited[20];
void DFS_Using_Adj_Mat(int v,int n);
void DFT_Using_Adj_Mat(int v,int n);
int main()
{
    int v,n,i,j;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    printf("\nStoring the graph in the form of Adjacency Matrix:-\n\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            while(1)
            {
                printf("Enter G[%d][%d] ",i,j);
                scanf("%d",&G[i][j]);
                if(G[i][j]!=0 && G[i][j]!=1)
                {
                    printf("\nInvalid input given to the Adj. Matrix\n");
                    continue;
                }
                else
                    break;
            }
        }
    }
    printf("\nAdjacency Matrix:-\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",G[i][j]);
        printf("\n");
    }
    printf("\nEnter the vertex form which you want to start: ");
    scanf("%d",&v);
    DFT_Using_Adj_Mat(v,n);
    return 0;
}
void DFS_Using_Adj_Mat(int v,int n)
{
    int i;
    visited[v]=1;
    printf("%d ",v);
    for(i=1;i<=n;i++)
    {
        if(G[v][i]==1 && visited[i]==0)
            DFS_Using_Adj_Mat(i,n);
    }
}
void DFT_Using_Adj_Mat(int v,int n)
{
    int i;
    for(i=1;i<=n;i++)
        visited[i]=0;
    DFS_Using_Adj_Mat(v,n);
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            DFS_Using_Adj_Mat(i,n);
    }
    printf("\nAll nodes are visited\n");
}
