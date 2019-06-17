#include<stdio.h>
#include<stdlib.h>
int heap_size;
int *max_heapify(int A[],int i);
int *build_heap(int A[]);
int *heap_sort_max_heap(int A[]);
int main()
{
    int i,n;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    heap_size=n;
    int *A=(int*)malloc((heap_size+1)*sizeof(int));
    if(A==NULL)
    {
        printf("\nOops! Memory can't be allocated\n");
        exit(1);
    }
    for(i=1;i<=n;i++)
    {
        printf("Enter A[%d] ",i);
        scanf("%d",&A[i]);
    }
    A=build_heap(A);
    A=heap_sort_max_heap(A);
    printf("\nSorted:-\n");
    for(i=1;i<=n;i++)
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
int *heap_sort_max_heap(int A[])
{
    int max;
    while(heap_size>=1)
    {
        max=A[1];
        A[1]=A[heap_size];
        A[heap_size]=max;
        heap_size--;
        A=max_heapify(A,1);
    }
    return A;
}
