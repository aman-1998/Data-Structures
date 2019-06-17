#include<stdio.h>
#include<stdlib.h>
int G[20][20];
int indegree[20]={0};
int queue[19]={0};
void Topological_sort_Adj_Mat(int n);
int main()
{
    int i,n,j,ch;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    printf("\nStoring graph in the form of Adjacency List\n\n");
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("Enter a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
            indegree[j]++;
        }
    }*/
    while(1)
    {
        printf("Enter \'0\' if you don't want to stay\nEnter any other key if you want to stay\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        system("CLS");
        if(ch==0)
            break;
        printf("Enter first index: ");
        scanf("%d",&i);
        printf("Enter second index: ");
        scanf("%d",&j);
        G[i][j]=1;
        indegree[j]++;
        system("CLS");
    }
    printf("\nAdjacency List:-\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",G[i][j]);
        printf("\n");
    }
    printf("\nTraversal:-\n");
    Topological_sort_Adj_Mat(n);
    return 0;
}
void Topological_sort_Adj_Mat(int n)
{
    int u,i,f=0,r=-1;
    for(i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            r++;
            queue[r]=i;
        }
    }
    while(f<=r)
    {
        u=queue[f];
        f++;
        indegree[u]=-1;
        printf("%d ",u);
        for(i=1;i<=n;i++)
        {
            if(G[u][i]==1)
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    r++;
                    queue[r]=i;
                }
            }
        }
    }
}
