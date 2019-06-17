#include<stdio.h>
#include<stdlib.h>
int heap_size;
int *max_heapify(int A[],int i);
int *build_heap(int A[]);
int main()
{
    int n,i;
    printf("Enter heap size: ");
    scanf("%d",&heap_size);
    int *A=(int*)malloc((heap_size+1)*sizeof(int));
    if(A==NULL)
    {
        printf("\nOops! Memory can't be allocated\n");
        exit(0);
    }
    printf("\n");
    for(i=1;i<=heap_size;i++)
    {
        printf("Enter A[%d] ",i);
        scanf("%d",&A[i]);
    }
    A=build_heap(A);
    printf("\nMax Heap:-\n");
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
        max_heapify(A,largest);
    }
    return A;
}
int *build_heap(int A[])
{
    int i;
    for(i=heap_size/2;i>=1;i--)
        max_heapify(A,i);
    printf("\nHeap is created\n");
    return A;
}
