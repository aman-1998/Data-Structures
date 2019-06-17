#include<stdio.h>
#include<stdlib.h>
int G[20][20],visited[20],queue[19];
void BFS_using_Adj_Mat(int v,int n);
void BFT_using_Adj_Mat(int v,int n);
int main()
{
    int i,n,j,v;
    printf("Enter no. of vertices in the graph: ");
    scanf("%d",&n);
    printf("\nStoring graph in the form of Adjacency Matrix:-\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            while(1)
            {
                printf("Enter a[%d][%d] ",i,j);
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
    printf("\nEnter the vertex from which you want to start: ");
    scanf("%d",&v);
    BFT_using_Adj_Mat(v,n);
    return 0;
}
void BFS_using_Adj_Mat(int v,int n)
{
    int u,i,f=0,r=-1;
    //initialization
    /*for(i=1;i<=n;i++)
        visited[i]=0;*/
    u=v;
    visited[v]=1;
    printf("%d ",v);
    while(1)
    {
        for(i=1;i<=n;i++)
        {
            if(G[u][i]==1 && visited[i]==0)
            {
                r++;
                queue[r]=i;
                visited[i]=1;
                printf("%d ",i);
            }
        }
        if(f>r)
            return;
        u=queue[f];
        f++;
    }
}
void BFT_using_Adj_Mat(int v,int n)
{
    int i;
    for(i=1;i<=n;i++)
        visited[i]=0;
    BFS_using_Adj_Mat(v,n);
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            BFS_using_Adj_Mat(i,n);
    }
    printf("\nAll nodes are visited\n");
}
