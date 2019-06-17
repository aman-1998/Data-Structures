#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *prev,*next;
};
struct node *create_node()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return n;
}
struct node *create_list(struct node *start)
{
    int n,i;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    if(n==0)
        return start;
    start=add_beg(start);
    for(i=0;i<=n-2;i++)
        start=add_end(start);
    return start;
}
struct node *add_beg(struct node *start)
{
    start=create_node();
    start->prev=NULL;
    start->next=NULL;
    printf("Enter the data to be fetched: ");
    scanf("%d",&start->info);
    return start;
}
struct node *add_end(struct node *start)
{
    struct node *t,*temp;
    t=start;
    while(t->link!=NULL)
        t=t->link;
    temp=create_node();
    temp->next=NULL;
    temp->prev=t;
    t->next=temp;
    printf("Enter the data to be")
}
