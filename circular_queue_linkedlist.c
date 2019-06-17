#include<stdio.h>
#include<stdlib.h>
int x;
struct node
{
    int info;
    struct node *link;
};
struct node *create_node();
struct node *enqueue(struct node *last,int data);
struct node *dequeue(struct node *last);
void peep(struct node *last);
int main()
{
    struct node *last=NULL;
    int ch,data;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peep\n4.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        system("PAUSE");
        system("CLS");
        switch(ch)
        {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d",&data);
                last=enqueue(last,data);
                break;
            case 2:
                last=dequeue(last);
                if(x!=111)
                    printf("\n%d is dequeued\n",x);
                break;
            case 3:
                peep(last);
                break;
            case 4:
                printf("\n-------------------End Of Program-------------------\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
    return 0;
}
struct node *create_node()
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    return t;
}
struct node *enqueue(struct node *last,int data)
{
    struct node *temp;
    if(last==NULL)
    {
        temp=create_node();
        temp->link=temp;
        temp->info=data;
        last=temp;
        printf("\n%d is enqueued\n",data);
        return last;
    }
    temp=create_node();
    temp->info=data;
    temp->link=last->link;
    last->link=temp;
    last=temp;
    printf("\n%d is enqueued\n",data);
    return last;
}
struct node *dequeue(struct node *last)
{
    if(last==NULL)
    {
        printf("\nUnderflow\n");
        x=111;
        return last;
    }
    if(last->link==last)
    {
        x=last->info;
        free(last);
        last=NULL;
        return last;
    }
    struct node *temp;
    temp=last->link;
    last->link=temp->link;
    x=temp->info;
    free(temp);
    return last;
}
void peep(struct node *last)
{
    if(last==NULL)
        printf("\nUnderflow\n");
    else
        x=last->link->info;
}
