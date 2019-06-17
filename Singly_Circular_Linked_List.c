#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *create_node(void);
struct node *add_beg(struct node *last);
struct node *add_end(struct node *last);
void display(struct node *last);
struct node *create_list(struct node *last);
struct node *insert_at(struct node *last,int pos);
struct node *insert_after(struct node *last,int data);
struct node *insert_before(struct node *last,int data);
struct node *delete_list(struct node *last);
struct node *delete_after(struct node *last,int data);
struct node *delete_before(struct node *last,int data);
struct node *delete_particular1(struct node *last,int data);
struct node *delete_particular2(struct node *last,int data);
void search(struct node *last,int data);
int main()
{
    struct node *last=NULL;
    int ch,pos,data;
    while(1)
    {
        printf("1.Create List\n2.Display\n3.Insert by position\n4.Insert after any value\n5.Insert before any value\n6.Delete List\n7.Delete after any value\n8.Delete before any value\n9.Delete particular value using method 1\n10.Delete particular value using method 2\n11.Search for any value\n12.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(last==NULL)
                {
                    last=create_list(last);
                    printf("\nList is created\n\n");
                }
                else
                    printf("\nList is already created\n\n");
                system("PAUSE");
                system("CLS");
                break;
            case 2:
                display(last);
                system("PAUSE");
                system("CLS");
                break;
            case 3:
                printf("\nEnter any position: ");
                scanf("%d",&pos);
                last=insert_at(last,pos);
                system("PAUSE");
                system("CLS");
                break;
            case 4:
                printf("\nEnter the data after which you want to insert: ");
                scanf("%d",&data);
                last=insert_after(last,data);
                system("PAUSE");
                system("CLS");
                break;
            case 5:
                printf("\nEnter the data before which you want to insert: ");
                scanf("%d",&data);
                last=insert_before(last,data);
                system("PAUSE");
                system("CLS");
                break;
            case 6:
                last=delete_list(last);
                system("PAUSE");
                system("CLS");
                break;
            case 7:
                printf("\nEnter the data after which you want to delete: ");
                scanf("%d",&data);
                last=delete_after(last,data);
                system("PAUSE");
                system("CLS");
                break;
            case 8:
                printf("\nEnter the data before which you want to delete: ");
                scanf("%d",&data);
                last=delete_before(last,data);
                system("PAUSE");
                system("CLS");
                break;
            case 9:
                printf("\nEnter the data to be deleted from the list: ");
                scanf("%d",&data);
                last=delete_particular1(last,data);
                system("PAUSE");
                system("CLS");
                break;
            case 10:
                printf("\nEnter the data to be deleted from the list: ");
                scanf("%d",&data);
                last=delete_particular2(last,data);
                system("PAUSE");
                system("CLS");
                break;
            case 11:
                printf("\nEnter the data to be searched: ");
                scanf("%d",&data);
                search(last,data);
                system("PAUSE");
                system("CLS");
                break;
            case 12:
                printf("\n--------------------------------------------------------------------------\n");
                return 0;
            default:
                printf("\nInvalid Choice\n");
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
struct node *add_beg(struct node *last)
{
    struct node *temp;
    temp=create_node();
    printf("Enter the data to be fetched: ");
    scanf("%d",&temp->info);
    last=temp;
    last->link=last;
    return last;
}
struct node *add_end(struct node *last)
{
    struct node *temp;
    temp=create_node();
    printf("Enter the data to be fetched: ");
    scanf("%d",&temp->info);
    temp->link=last->link;
    last->link=temp;
    last=last->link;
    return last;
}
struct node *create_list(struct node *last)
{
    int n,i;
    printf("\nEnter no. of nodes: ");
    scanf("%d",&n);
    last=add_beg(last);
    for(i=0;i<=n-2;i++)
        last=add_end(last);
    return last;
}
void display(struct node *last)
{
    if(last==NULL)
    {
        printf("\nList is empty\n\n");
        return;
    }
    printf("\nList:-\n");
    struct node *t=last->link;
    do
    {
        printf("%d ",t->info);
        t=t->link;
    }
    while(t!=last->link);
    printf("\n\n");
}
struct node *insert_at(struct node *last,int pos)
{
    if(last==NULL)
    {
        printf("\nList is empty\n\n");
        return last;
    }
    struct node *t,*temp;
    if(pos==1)
    {
        temp=create_node();
        printf("Enter the data to be fetched: ");
        scanf("%d",&temp->info);
        temp->link=last->link;
        last->link=temp;
        printf("\nNode inserted at %d position\n\n",pos);
        return last;
    }
    int count=1;
    t=last->link;
    do
    {
        if(count==pos-1)
        {
            temp=create_node();
            printf("Enter the data to be fetched: ");
            scanf("%d",&temp->info);
            temp->link=t->link;
            t->link=temp;
            printf("\nNode inserted at %d position\n\n",pos);
            return last;
        }
        t=t->link;
        count++;
    }
    while(t!=last->link);
}
struct node *insert_after(struct node *last,int data)
{
    if(last==NULL)
    {
        printf("\nList is empty\n\n");
        return last;
    }
    struct node *t,*temp;
    t=last->link;
    do
    {
        if(t->info==data)
        {
            temp=create_node();
            temp->link=t->link;
            t->link=temp;
            printf("Enter the data to be fetched: ");
            scanf("%d",&temp->info);
            printf("\n%d inserted after %d\n\n",temp->info,data);
            if(t==last)
                last=temp;
            return last;
        }
        t=t->link;
    }
    while(t!=last->link);
    printf("\n%d not found\n\n",data);
    return last;
}
struct node *insert_before(struct node *last,int data)
{
    if(last==NULL)
    {
        printf("\nList is empty\n\n");
        return last;
    }
    struct node *t,*temp;
    if(last->link->info==data)
    {
        temp=create_node();
        temp->link=last->link;
        last->link=temp;
        printf("Enter the data to be fetched: ");
        scanf("%d",&temp->info);
        printf("\n%d is inserted before %d\n\n",temp->info,data);
        return last;
    }
    t=last->link;
    do
    {
        if(t->link->info==data)
        {
            temp=create_node();
            temp->link=t->link;
            t->link=temp;
            printf("Enter the data to be fetched: ");
            scanf("%d",&temp->info);
            printf("\n%d is inserted before %d\n\n",temp->info,data);
            return last;
        }
        t=t->link;
    }
    while(t!=last->link);
    printf("\n%d not found\n\n",data);
    return last;
}
struct node *delete_list(struct node *last)
{
    if(last==NULL)
    {
        printf("\nList is empty\n\n");
        return last;
    }
    struct node *t;
    t=last->link;
    while(t!=last)
    {
        last->link=t->link;
        free(t);
        t=last->link;
    }
    free(last);
    last=NULL;
    printf("\nList is deleted\n\n");
    return last;
}
struct node *delete_after(struct node *last,int data)
{
    if(last==NULL)
    {
        printf("\nList is empty\n\n");
        return last;
    }
    struct node *t,*temp;
    t=last->link;
    do
    {
        if(t->info==data)
        {
            temp=t->link;
            t->link=temp->link;
            printf("\nNode after %d is deleted\n\n",data);
            if(temp==last)
                last=t;
            free(temp);
            return last;
        }
        t=t->link;
    }
    while(t!=last->link);
    printf("\n%d not found\n\n",data);
    return last;
}
struct node *delete_before(struct node *last,int data)
{
    if(last==NULL)
    {
        printf("\nList is empty\n\n");
        return last;
    }
    struct node *t,*temp;
    t=last->link;
    if(t->link->info==data)
    {
        last->link=t->link;
        printf("\nNode before %d is deleted\n\n",data);
        free(t);
        return last;
    }
    if(t->info==data)
    {
        while(t->link!=last)
            t=t->link;
        t->link=last->link;
        printf("\nNode before %d is deleted\n\n",data);
        free(last);
        last=t;
        return last;
    }
    do
    {
        if(t->link->link->info==data)
        {
            temp=t->link;
            t->link=temp->link;
            printf("\nNode before %d is deleted\n\n",data);
            free(temp);
            return last;
        }
        t=t->link;
    }
    while(t!=last->link);
    printf("\n%d not found\n\n",data);
    return last;
}
struct node *delete_particular1(struct node *last,int data)
{
    if(last==NULL)
    {
        printf("\nList is empty\n\n");
        return last;
    }
    struct node *t,*temp;
    t=last->link;
    if(t->info==data)
    {
        last->link=t->link;
        printf("\nNode with info %d is deleted\n\n",data);
        if(t==last)
            last=NULL;
        free(t);
        return last;
    }
    do
    {
        if(t->link->info==data)
        {
            temp=t->link;
            t->link=temp->link;
            printf("\nNode with info %d is deleted\n\n",data);
            if(temp==last)
                last=t;
            free(temp);
            return last;
        }
        t=t->link;
    }
    while(t!=last);
    printf("\n%d is not found\n\n",data);
    return last;
}
struct node *delete_particular2(struct node *last,int data)
{
    if(last==NULL)
    {
        printf("\nList is empty\n\n");
        return last;
    }
    struct node *t,*temp;
    t=last->link;
    if(last->info==data)
    {
        if(t==last)
        {
            printf("\nNode with info %d is deleted\n\n",data);
            free(t);
            last=NULL;
            return last;
        }
        while(t->link!=last)
            t=t->link;
        t->link=last->link;
        printf("\nNode with info %d is deleted\n\n",data);
        free(last);
        last=t;
        return last;
    }
    do
    {
        if(t->info==data)
        {
            t->info=t->link->info;
            temp=t->link;
            t->link=temp->link;
            printf("\nNode with info %d is deleted\n\n",data);
            if(temp==last)
                last=t;
            free(temp);
            return last;
        }
        t=t->link;
    }
    while(t!=last);
    printf("\n%d is not found\n\n",data);
    return last;
}
void search(struct node *last,int data)
{
    if(last==NULL)
    {
        printf("\nList is empty\n\n");
        return;
    }
    struct node *t=last->link;
    int count=1;
    do
    {
        if(t->info==data)
        {
            printf("\n%d is found at node no. %d\n\n",data,count);
            return;
        }
        t=t->link;
        count++;
    }
    while(t!=last->link);
    printf("\n%d is not found\n\n",data);
}
