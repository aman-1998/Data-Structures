#include<stdio.h>
#include<stdlib.h>
int heap_size,min;
int *min_heapify(int A[],int i);
int *build_heap(int A[]);
int *delete_min(int A[]);
int main()
{
    int i;
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
    printf("\nMin Heap:-\n");
    for(i=1;i<=heap_size;i++)
        printf("%d ",A[i]);
    A=delete_min(A);
    if(min!=111)
    {
        printf("\nMin = %d\n",min);
        printf("\nNew Min Heap:-\n");
        for(i=1;i<=heap_size;i++)
            printf("%d ",A[i]);
    }
    return 0;
}
int *min_heapify(int A[],int i)
{
    int l,r,smallest,temp;
    l=2*i;
    r=2*i+1;
    if(l<=heap_size && A[l]<A[i])
        smallest=l;
    else
        smallest=i;
    if(r<=heap_size && A[r]<A[smallest])
        smallest=r;
    if(smallest!=i)
    {
        temp=A[i];
        A[i]=A[smallest];
        A[smallest]=temp;
        A=min_heapify(A,smallest);
    }
    return A;
}
int *build_heap(int A[])
{
    int i;
    for(i=heap_size/2;i>=1;i--)
        A=min_heapify(A,i);
    return A;
}
int *delete_min(int A[])
{
    if(heap_size==0)
    {
        printf("\nHeap underflow\n");
        min=111;
        return A;
    }
    min=A[1];
    A[1]=A[heap_size];
    heap_size--;
    A=min_heapify(A,1);
    return A;
}
