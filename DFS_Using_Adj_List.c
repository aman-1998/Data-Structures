#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *G[20]={NULL};
int visited[20];
struct node *create_node(int data);
void DFS_Using_Adj_List(int v,int n);
void DFT_Using_Adj_List(int v,int n);
int main()
{
    int i,j,ch,n,data,v;
    struct node *temp;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    printf("\nStoring the graph in the form of \n\n");
    system("PAUSE");
    system("CLS");
    for(i=1;i<=n;i++)
    {
        while(1)
        {
            printf("Enter the node adjacent to %d: ",i);
            scanf("%d",&data);
            if(G[i]==NULL)
                G[i]=create_node(data);
            else
            {
                temp=create_node(data);
                temp->link=G[i];
                G[i]=temp;
            }
            printf("\nEnter \'0\' if you don't want to stay with the same node\nEnter any other key if you don't want to stay with the same node\n");
            printf("\nEnter your choice: ");
            scanf("%d",&ch);
            system("CLS");
            if(ch==0)
                break;
        }
    }
    printf("\nAdjacency List:-\n");
    for(i=1;i<=n;i++)
    {
        temp=G[i];
        printf("%d -> ",i);
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->link;
        }
        printf("\n");
    }
    printf("Enter the vertex from which you want to start: ");
    scanf("%d",&v);
    DFT_Using_Adj_List(v,n);
    return 0;
}
struct node *create_node(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    return temp;
}
void DFS_Using_Adj_List(int v,int n)
{
    int i;
    struct node *t;
    visited[v]=1;
    printf("%d ",v);
    t=G[v];
    while(t!=NULL)
    {
        if(visited[t->info]==0)
            DFS_Using_Adj_List(t->info,n);
        t=t->link;
    }
}
void DFT_Using_Adj_List(int v,int n)
{
    int i;
    for(i=1;i<=n;i++)
        visited[i]=0;
    DFS_Using_Adj_List(v,n);
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            DFS_Using_Adj_List(i,n);
    }
    printf("\nAll nodes are visited\n");
}
