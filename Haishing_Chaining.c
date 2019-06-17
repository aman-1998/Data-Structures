#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    int key;
    struct node *link;
};
int h(int k,int m);
struct node *create_node();
struct node **insert(struct node **HT,int data,int k,int m);
void search(struct node **HT,int data,int k,int m);
struct node **deletion(struct node **HT,int data,int k,int m);
void display(struct node **HT,int m);
int main()
{
    int m,data,key,ch,flag1=0,flag2=0,i;
    printf("Enter the size of hash table: ");
    scanf("%d",&m);
    struct node **HT=(struct node**)calloc(m,sizeof(struct node*));
    if(HT==NULL)
    {
        printf("\nMemory can't be allocated\n");
        return 0;
    }
    for(i=0;i<=m-1;i++)
        HT[i]=NULL;
    while(1)
    {
        printf("1.Insertion\n2.Searching\n3.Deletion of elements\n4.Display\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the data to be inserted and corresponding key: ");
                scanf("%d%d",&data,&key);
                HT=insert(HT,data,key,m);
                system("PAUSE");
                system("CLS");
                break;
            case 2:
                printf("\nEnter the data to be searched and corresponding key: ");
                scanf("%d%d",&data,&key);
                search(HT,data,key,m);
                system("PAUSE");
                system("CLS");
                break;
            case 3:
                printf("\nEnter the data to be deleted and corresponding key: ");
                scanf("%d%d",&data,&key);
                HT=deletion(HT,data,key,m);
                system("PAUSE");
                system("CLS");
                break;
            case 4:
                display(HT,m);
                system("PAUSE");
                system("CLS");
                break;
            case 5:
                printf("\n-----------------------------------------------------------\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
                system("PAUSE");
                system("CLS");
                break;
        }
    }
}
int h(int k,int m)
{
    return k%m;
}
struct node *create_node()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return n;
}
struct node **insert(struct node **HT,int data,int k,int m)
{
    struct node *temp;
    int index=h(k,m);
    if(HT[index]==NULL)
    {
        temp=create_node();
        temp->key=k;
        temp->info=data;
        temp->link=NULL;
        HT[index]=temp;
        return HT;
    }
    temp=create_node();
    temp->key=k;
    temp->info=data;
    temp->link=HT[index];
    HT[index]=temp;
    return HT;
}
void search(struct node **HT,int data,int k,int m)
{
    struct node *t;
    int index=h(k,m);
    if(HT[index]==NULL)
    {
        printf("\n%d not found with key %d\n\n",data,k);
        return;
    }
    int count=1;
    t=HT[index];
    while(t!=NULL)
    {
        if(t->info==data)
        {
            printf("\n%d is found at index %d and node no. %d\n\n",data,index,count);
            return;
        }
        count++;
        t=t->link;
    }
    printf("\n%d not found with key %d\n\n",data,k);
    return;
}
struct node **deletion(struct node **HT,int data,int k,int m)
{
    struct node *t,*temp;
    int index=h(k,m);
    if(HT[index]==NULL)
    {
        printf("\n%d not found with key %d\n\n",data,k);
        return HT;
    }
    t=HT[index];
    if(t->info==data)
    {
        HT[index]=t->link;
        free(t);
        printf("\n%d is deleted with key %d\n\n",data,k);
        return HT;
    }
    while(t->link!=NULL)
    {
        if(t->link->info==data)
        {
            temp=t->link;
            t->link=temp->link;
            free(temp);
            printf("\n%d is deleted with key %d\n\n",data,k);
            return HT;
        }
        t=t->link;
    }
    printf("\n%d not found with key %d\n\n",data,k);
    return HT;
}
void display(struct node **HT,int m)
{
    struct node *t;
    int i;
    printf("Index\n");
    for(i=0;i<=m-1;i++)
    {
        if(HT[i]==NULL)
            printf("  %d   Empty\n",i);
        else
        {
            t=HT[i];
            printf("  %d   ",i);
            while(t!=NULL)
            {
                printf("(Data=%d,Key=%d)  ",t->info,t->key);
                t=t->link;
            }
            printf("\n");
        }
    }
}
