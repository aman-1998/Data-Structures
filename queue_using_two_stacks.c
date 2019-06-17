#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start1=NULL,*start2=NULL;
void enqueue(int data);
int dequeue();
int peep();
int main()
{
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
                printf("Enter the data to be entered: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                data=dequeue();
                if(data!=111)
                    printf("\n%d is dequeued\n",data);
                break;
            case 3:
                data=peep();
                if(data!=111)
                    printf("\n%d is in the front\n",data);
                break;
            case 4:
                printf("\n----------------End Of Program---------------\n");
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
void enqueue(int data)
{
    struct node *temp;
    if(start2==NULL)
    {
        temp=create_node();
        temp->info=data;
        temp->link=NULL;
        start2=temp;
        printf("\n%d is enqueued\n",data);
        return;
    }
    temp=create_node();
    temp->info=data;
    temp->link=start2;
    start2=temp;
    printf("\n%d is enqueued\n",data);
}
int dequeue()
{
    int x;
    struct node *temp;
    if(start1==NULL)
    {
        if(start2==NULL)
        {
            printf("\nUnderflow\n");
            return 111;
        }
        start1=start2;
        start2=start2->link;
        start1->link=NULL;
        while(start2!=NULL)
        {
            temp=start2->link;
            start2->link=start1;
            start1=start2;
            start2=temp;
        }
    }
    temp=start1;
    start1=start1->link;
    x=temp->info;
    free(temp);
    return x;
}
int peep()
{
    int x;
    struct node *temp;
    if(start1==NULL)
    {
        if(start2==NULL)
        {
            printf("\nUnderflow\n");
            return 111;
        }
        start1=start2;
        start2=start2->link;
        start1->link=NULL;
        while(start2!=NULL)
        {
            temp=start2->link;
            start2->link=start1;
            start1=start2;
            start2=temp;
        }
    }
    x=start1->info;
    return x;
}
