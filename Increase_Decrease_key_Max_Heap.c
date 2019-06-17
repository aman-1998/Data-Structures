#include<stdio.h>
#include<stdlib.h>
int heap_size;
int *max_heapify(int A[],int i);
int *build_heap(int A[]);
int *increase_key(int A[],int i,int key);
int *decrease_key(int A[],int i,int key);
int main()
{
    int i,key;
    printf("Enter heap size: ");
    scanf("%d",&heap_size);
    int *A=(int*)malloc((heap_size+1)*sizeof(int));
    if(A==NULL)
    {
        printf("\nOops! Memory can't be allocated\n");
        exit(1);
    }
    for(i=1;i<=heap_size;i++)
    {
        printf("Enter A[%d] ",i);
        scanf("%d",&A[i]);
    }
    A=build_heap(A);
    printf("\nMax Heap:-\n");
    for(i=1;i<=heap_size;i++)
        printf("%d ",A[i]);
    printf("\nEnter the index whose value is to be increased: ");
    scanf("%d",&i);
    printf("Enter the key: ");
    scanf("%d",&key);
    A=increase_key(A,i,key);
    printf("\nMax Heap after increasing the key:-\n");
    for(i=1;i<=heap_size;i++)
        printf("%d ",A[i]);
    printf("\nEnter the index whose value is to be decreased: ");
    scanf("%d",&i);
    printf("Enter the key: ");
    scanf("%d",&key);
    A=decrease_key(A,i,key);
    printf("\nMax Heap after decreasing the key:-\n");
    for(i=1;i<=heap_size;i++)
        printf("%d ",A[i]);
    return 0;
}
int *max_heapify(int A[],int i)
{
    int l,r,largest,temp;
    l=2*i;
    r=2*i+1;
    if(l<=heap_size && A[l]>A[i])
        largest=l;
    else
        largest=i;
    if(r<=heap_size && A[r]>A[largest])
        largest=r;
    if(largest!=i)
    {
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        A=max_heapify(A,largest);
    }
    return A;
}
int *build_heap(int A[])
{
    int i;
    for(i=heap_size/2;i>=1;i--)
        A=max_heapify(A,i);
    return A;
}
int *increase_key(int A[],int i,int key)
{
    int temp;
    if(key<=A[i] || i<1)
    {
        printf("\nKya bhosdi hai kya?\n");
        return A;
    }
    A[i]=key;
    while(i>1 && A[i]>A[i/2])
    {
        temp=A[i];
        A[i]=A[i/2];
        A[i/2]=temp;
        i=i/2;
    }
    return A;
}
int *decrease_key(int A[],int i,int key)
{
    if(key>=A[i] || i<1)
    {
        printf("\nKya Bhosdi hai kya?\n");
        return A;
    }
    A[i]=key;
    A=max_heapify(A,i);
    return A;
}
