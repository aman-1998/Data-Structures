#include<stdio.h>
#include<stdlib.h>
int visited[20],queue[19];
struct node
{
    int info;
    struct node *link;
};
struct node *G[20];
void BFS_Using_Adj_List(int v,int n);
void BFT_Using_Adj_List(int v,int n);
struct node *create_node(int data);
int main()
{
    int i,v,n,data,ch;
    struct node *temp;
    printf("Enter no. of vertices in the graph: ");
    scanf("%d",&n);
    printf("\nStoring the graph in the form of Adjacency List:-\n");
    for(i=1;i<=n;i++)
        G[i]=NULL;
    system("PAUSE");
    system("CLS");
    for(i=1;i<=n;i++)
    {
        while(1)
        {
            printf("Enter the vertex adjacent to %d: ",i);
            scanf("%d",&data);
            if(G[i]==NULL)
                G[i]=create_node(data);
            else
            {
                temp=create_node(data);
                temp->link=G[i];
                G[i]=temp;
            }
            printf("\nEnter '0' if you don't want to stay with the same vertex\nEnter any other key to stay with the same vertex\n");
            printf("\nEnter your choice: ");
            scanf("%d",&ch);
            system("CLS");
            if(ch==0)
                break;
        }
    }
    printf("Enter the vertex from which you want to start: ");
    scanf("%d",&v);
    BFT_Using_Adj_List(v,n);
    return 0;
}
struct node *create_node(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nMemory can't be allocated\n");
        exit(0);
    }
    temp->info=data;
    temp->link=NULL;
    return temp;
}
void BFS_Using_Adj_List(int v,int n)
{
    int i,u,f=0,r=-1;
    struct node *t;
    u=v;
    visited[u]=1;
    printf("%d ",u);
    while(1)
    {
        t=G[u];
        while(t!=NULL)
        {
            if(visited[t->info]==0)
            {
                r++;
                queue[r]=t->info;
                visited[t->info]=1;
                printf("%d ",t->info);
            }
            t=t->link;
        }
        if(f>r)
            return;
        u=queue[f];
        f++;
    }
}
void BFT_Using_Adj_List(int v,int n)
{
    int i;
    for(i=1;i<=n;i++)
        visited[i]=0;
    BFS_Using_Adj_List(v,n);
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            BFS_Using_Adj_List(i,n);
    }
    printf("\nAll nodes are visited\n");
}
