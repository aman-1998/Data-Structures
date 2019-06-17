#include<stdio.h>
#include<stdlib.h>
int h(int k,int m);
int *insert(int HT[],int data,int k,int m);
void search(int HT[],int data,int k,int m);
int *deletion(int HT[],int data,int k,int m);
void display(int HT[],int m);
int key[100]={0};
int main()
{
    int ch,m,data,k;
    printf("Enter the size of hash table: ");
    scanf("%d",&m);
    int *HT=(int*)calloc(m,sizeof(int));
    while(1)
    {
        printf("1.Insertion\n2.Search\n3.Deletion\n4.Display\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter data to be inserted and key: ");
                scanf("%d%d",&data,&k);
                HT=insert(HT,data,k,m);
                system("PAUSE");
                system("CLS");
                break;
            case 2:
                printf("\nEnter data to be searched and key: ");
                scanf("%d%d",&data,&k);
                search(HT,data,k,m);
                system("PAUSE");
                system("CLS");
                break;
            case 3:
                printf("\nEnter data to be deleted and key: ");
                scanf("%d%d",&data,&k);
                HT=deletion(HT,data,k,m);
                system("PAUSE");
                system("CLS");
                break;
            case 4:
                display(HT,m);
                system("PAUSE");
                system("CLS");
                break;
            case 5:
                printf("\n------------------------------------------------------\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
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
int *insert(int HT[],int data,int k,int m)
{
    int index=h(k,m),p,i;
    if(HT[index]==0 || HT[index]==-1)
    {
        HT[index]=data;
        key[index]=k;
        return HT;
    }
    else
    {
        for(i=0;i<=m-1;i++)
        {
            p=(index+i)%m;
            if(HT[p]==0 || HT[p]==-1)
            {
                HT[p]=data;
                key[p]=k;
                return HT;
            }
        }
    }
    printf("\nOverflow\n\n",data);
    return HT;
}
void search(int HT[],int data,int k,int m)
{
    int index=h(k,m),p,i;
    if(HT[index]==0)
    {
        printf("\n%d not found\n\n",data);
        return;
    }
    else
    {
        for(i=0;i<=m-1;i++)
        {
            p=(index+i)%m;
            if(HT[p]==0)
            {
                printf("\n%d not found\n\n",data);
                return;
            }
            else if(HT[p]==data)
            {
                printf("\n%d is found at %d\n\n",data,p);
                return;
            }
        }
    }
    printf("\n%d not found\n\n",data);
}
int *deletion(int HT[],int data,int k,int m)
{
    int index=h(k,m),p,i;
    if(HT[index]==0)
    {
        printf("\n%d not found\n\n",data);
        return HT;
    }
    else
    {
        for(i=0;i<=m-1;i++)
        {
            p=(index+i)%m;
            if(HT[p]==0)
            {
                printf("\n%d not found\n\n",data);
                return HT;
            }
            else if(HT[p]==data)
            {
                HT[p]=-1;
                key[p]=-1;
                return HT;
            }
        }
    }
    printf("\n%d not found\n\n",data);
    return HT;
}
void display(int HT[],int m)
{
    int i;
    printf("\nIndex   key    Data\n");
    for(i=0;i<=m-1;i++)
        printf("%d\t%d\t%d\n",i,key[i],HT[i]);
    printf("\n");
}
