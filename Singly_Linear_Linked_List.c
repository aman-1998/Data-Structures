#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *create_node(void);
struct node *create_list(struct node *start);
struct node *add_beg(struct node *start);
struct node *add_end(struct node *start);
struct node *insert_at(struct node *start,int pos);
void display(struct node *start);
struct node *insert_after(struct node *start,int data);
struct node *insert_before(struct node *start,int data);
struct node *delete_after(struct node *start,int data);
struct node *delete_before(struct node *start,int data);
struct node *delete_particular1(struct node *start,int data);
struct node *delete_particular2(struct node *start,int data);
struct node *delete_list(struct node *start);
void search(struct node *start,int data);
int main()
{
    struct node *start=NULL;
    int ch,pos,data;
    while(1)
    {
        printf("1.Create List\n2.Display\n3.Insert at any position\n4.Insert after any value\n5.Insert before any value\n6.Delete after any data\n7.Delete before any data\n8.Delete particular value using method 1\n9.Delete particular value using method 2\n10.Delete List\n11.Search for any value\n12.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(start==NULL)
                {
                    start=create_list(start);
                    printf("\nList is created\n\n");
                }
                else
                    printf("\nList is already created\n\n");
                system("PAUSE");
                system("CLS");
                break;
            case 2:
                display(start);
                system("PAUSE");
                system("CLS");
                break;
            case 3:
                printf("\nEnter the position at which you want to insert: ");
                scanf("%d",&pos);
                start=insert_at(start,pos);
                system("PAUSE");
                system("CLS");
                break;
            case 4:
                printf("\nEnter the data after which you want to insert: ");
                scanf("%d",&data);
                start=insert_after(start,data);
                system("PAUSE");
                system("CLS");
                break;
            case 5:
                printf("\nEnter the data before which you want to insert: ");
                scanf("%d",&data);
                start=insert_before(start,data);
                system("PAUSE");
                system("CLS");
                break;
            case 6:
                printf("\nEnter the data after which you want to delete: ");
                scanf("%d",&data);
                start=delete_after(start,data);
                system("PAUSE");
                system("CLS");
                break;
            case 7:
                printf("\nEnter the data before which you want to delete: ");
                scanf("%d",&data);
                start=delete_before(start,data);
                system("PAUSE");
                system("CLS");
                break;
            case 8:
                printf("\nEnter the data which you want to delete: ");
                scanf("%d",&data);
                start=delete_particular1(start,data);
                system("PAUSE");
                system("CLS");
                break;
            case 9:
                printf("\nEnter the data which you want to delete: ");
                scanf("%d",&data);
                start=delete_particular2(start,data);
                system("PAUSE");
                system("CLS");
                break;
            case 10:
                start=delete_list(start);
                system("PAUSE");
                system("CLS");
                break;
            case 11:
                printf("\nEnter the data to be searched: ");
                scanf("%d",&data);
                search(start,data);
                //system("PAUSE");
                //system("CLS");
                printf("Press any key to continue . . . ");
                getch();
                system("CLS");
                break;
            case 12:
                printf("\n----------------------------------------------------------------------\n");
                return 0;
            default:
                printf("\nInvalid choice!\n\n");
                system("PAUSE");
                system("CLS");
                break;
        }
    }
}
struct node *create_node(void)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return n;
}
struct node *create_list(struct node *start)
{
    int n,i;
    printf("\nEnter no. of nodes: ");
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
    if(start==NULL)
    {
        start=create_node();
        start->link=NULL;
        printf("Enter the data to be fetched: ");
        scanf("%d",&start->info);
        return start;
    }
    struct node *temp;
    temp=create_node();
    temp->link=start;
    start=temp;
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
    temp->link=NULL;
    printf("Enter the data to be fetched: ");
    scanf("%d",&temp->info);
    t->link=temp;
    return start;
}
void display(struct node *start)
{
    if(start==NULL)
    {
        printf("\nList is empty\n\n");
        return;
    }
    struct node *t=start;
    printf("\nList:-\n");
    while(t!=NULL)
    {
        printf("%d ",t->info);
        t=t->link;
    }
    printf("\n\n");
}
struct node *insert_at(struct node *start,int pos)
{
    if(start==NULL)
    {
        printf("\nList is empty\n\n");
        return start;
    }
    if(pos==1)
    {
        start=add_beg(start);
        printf("\nNode inserted at %d position\n\n",pos);
        return start;
    }
    int count=1;
    struct node *t,*temp;
    t=start;
    while(count!=pos-1)
    {
        t=t->link;
        count++;
    }
    temp=create_node();
    temp->link=t->link;
    t->link=temp;
    printf("Enter the data to be fetched: ");
    scanf("%d",&temp->info);
    printf("\nNode inserted at %d position\n\n",pos);
    return start;
}
struct node *insert_after(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("\nList is empty\n\n");
        return start;
    }
    struct node *t,*temp;
    t=start;
    while(t!=NULL)
    {
        if(t->info==data)
        {
            temp=create_node();
            temp->link=t->link;
            t->link=temp;
            printf("Enter the data to be fetched: ");
            scanf("%d",&temp->info);
            printf("\n%d is inserted after %d\n\n",temp->info,data);
            return start;
        }
        t=t->link;
    }
    printf("\n%d not found in the list\n\n",data);
    return start;
}
struct node *insert_before(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("\nList is empty\n\n");
        return start;
    }
    struct node *t,*temp;
    t=start;
    while(t->link!=NULL)
    {
        if(t->link->info==data)
        {
            temp=create_node();
            temp->link=t->link;
            t->link=temp;
            printf("Enter the data to be fetched: ");
            scanf("%d",&temp->info);
            printf("\n%d is inserted before %d\n\n",temp->info,data);
            return start;
        }
        t=t->link;
    }
    printf("\n%d not found in the list\n\n",data);
    return start;
}
struct node *delete_after(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("\nList is empty\n\n");
        return start;
    }
    struct node *t,*temp;
    t=start;
    while(t!=NULL)
    {
        if(t->info==data)
        {
            temp=t->link;
            t->link=t->link->link;
            printf("\nNode with info %d is deleted\n\n",temp->info);
            free(temp);
            return start;
        }
        t=t->link;
    }
    printf("\n%d is not found\n\n",data);
    return start;
}
struct node *delete_before(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("\nList is empty\n\n");
        return start;
    }
    struct node *t,*temp;
    t=start;
    if(t->info==data)
    {
        printf("\nThere is no node before the node with info %d\n\n",data);
        return start;
    }
    if(t->link->info==data)
    {
        start=start->link;
        printf("\nNode with info %d is deleted\n\n",t->info);
        free(t);
        return start;
    }
    while(t->link->link!=NULL)
    {
        if(t->link->link->info==data)
        {
            temp=t->link;
            t->link=t->link->link;
            printf("\nNode with %d info is deleted\n\n",temp->info);
            free(temp);
            return start;
        }
        t=t->link;
    }
    printf("\n%d not found\n\n",data);
    return start;
}
struct node *delete_particular1(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("\nList is empty\n\n");
        return start;
    }
    struct node *t,*temp;
    t=start;
    if(t->info==data)
    {
        start=start->link;
        printf("\nNode with info %d is deleted\n\n",t->info);
        free(t);
        return start;
    }
    while(t->link!=NULL)
    {
        if(t->link->info==data)
        {
            temp=t->link;
            t->link=t->link->link;
            printf("\nNode with info %d is deleted\n\n",temp->info);
            free(temp);
            return start;
        }
        t=t->link;
    }
    printf("\n%d not found\n\n",data);
    return start;
}
struct node *delete_particular2(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("\nList is empty\n\n");
        return start;
    }
    struct node *t,*temp,*prev;
    t=start;
    while(t->link!=NULL)
    {
        if(t->info==data)
        {
            printf("\nNode with info %d is deleted\n\n",t->info);
            t->info=t->link->info;
            temp=t->link;
            t->link=t->link->link;
            free(temp);
            return start;
        }
        prev=t;
        t=t->link;
    }
    if(t->info==data)
    {
        prev->link=NULL;
        printf("\nNode with info %d is deleted\n\n",t->info);
        free(t);
        return start;
    }
    printf("\n%d not fount\n\n",data);
    return start;
}
struct node *delete_list(struct node *start)
{
    if(start==NULL)
    {
        printf("\nList is empty\n\n");
        return start;
    }
    struct node *t;
    while(start!=NULL)
    {
        t=start;
        start=start->link;
        free(t);
    }
    printf("\nList is deleted\n\n");
    return start;
}
void search(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("\nList is empty\n\n");
        return;
    }
    int count=1;
    struct node *t;
    t=start;
    while(t!=NULL)
    {
        if(t->info==data)
        {
            printf("\n%d is found at node no. %d\n\n",data,count);
            return;
        }
        count++;
        t=t->link;
    }
    printf("\n%d not found\n\n",data);
}
