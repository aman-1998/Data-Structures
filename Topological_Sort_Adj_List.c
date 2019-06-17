#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
int indegree[20]={0};
int queue[19];
struct node *G[20]={NULL};
struct node *create_node(int data);
void topological_sort_Adj_List(int n);
int main()
{
    int n,i,data,ch;
    struct node *temp;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    printf("\nStoring graph in the form qof Adjacency List:-\n\n");
    system("PAUSE");
    system("CLS");
    for(i=1;i<=n;i++)
    {

        while(1)
        {
            printf("\nEnter \'0\' if you don't want to stay with vertex %d\nEnter any other key if you want to stay with vertex %d: ",i,i);
            printf("\nEnter your choice: ");
            scanf("%d",&ch);
            system("CLS");
            if(ch==0)
                break;
            printf("Enter the node adjacent to %d: ",i);
            scanf("%d",&data);
            indegree[data]++;
            if(G[i]==NULL)
                G[i]=create_node(data);
            else
            {
                temp=create_node(data);
                temp->link=G[i];
                G[i]=temp;
            }
        }
    }
    printf("\nAdjacency List:-\n");
    for(i=1;i<=n;i++)
    {
        printf("%d -> ",i);
        if(G[i]==NULL)
            printf("NULL");
        else
        {
            temp=G[i];
            while(temp!=NULL)
            {
                printf("%d ",temp->info);
                temp=temp->link;
            }
        }
        printf("\n");
    }
    printf("\nTraversal:-\n");
    topological_sort_Adj_List(n);
    return 0;
}
struct node *create_node(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nMemory can't be allocated\n");
        exit(1);
    }
    temp->info=data;
    temp->link=NULL;
    return temp;
}
void topological_sort_Adj_List(int n)
{
    int i,u,f=0,r=-1;
    struct node *t;
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
        struct node *t;
        u=queue[f];
        f++;
        indegree[u]=-1;
        printf("%d ",u);
        t=G[u];
        while(t!=NULL)
        {
            indegree[t->info]--;
            if(indegree[t->info]==0)
            {
                r++;
                queue[r]=t->info;
            }
            t=t->link;
        }
    }
}
