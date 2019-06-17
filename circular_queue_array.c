#include<stdio.h>
#include<stdlib.h>
int N,f=1,r=0;
void enqueue(int queue[],int data);
int dequeue(int queue[]);
int peep(int queue[]);
int nextTo(int fr);
int main()
{
    int n,ch,data;
    printf("Enter the max size of queue: ");
    scanf("%d",&n);
    N=n;
    int *queue=(int*)calloc(n+1,sizeof(int));
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.peep\n4.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        system("PAUSE");
        system("CLS");
        switch(ch)
        {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d",&data);
                enqueue(queue,data);
                break;
            case 2:
                data=dequeue(queue);
                if(data!=0)
                    printf("\n%d is dequeued\n",data);
                break;
            case 3:
                data=peep(queue);
                if(data!=0)
                    printf("\n%d is in the front\n",data);
                break;
            case 4:
                printf("\n-----------------End Of Program------------------\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
    return 0;
}
int nextTo(int fr)
{
    if(fr==N)
        return 0;
    else
        return fr+1;
}
void enqueue(int queue[],int data)
{
    if(queue[nextTo(r)]==0 && queue[nextTo(nextTo(r))]==0)
    {
        r=nextTo(r);
        queue[r]=data;
        printf("\n%d is enqueued\n",data);
    }
    else
        printf("\noverflow\n");
}
int dequeue(int queue[])
{
    int x;
    if(queue[f]!=0)
    {
        x=queue[f];
        queue[f]=0;
        f=nextTo(f);
        return x;
    }
    printf("\nUnderflow\n");
    return 0;
}
int peep(int queue[])
{
    if(queue[f]!=0)
        return queue[f];
    printf("\nUnderflow\n");
    return 0;
}
