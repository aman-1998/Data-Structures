#include<stdio.h>
#include<stdlib.h>
int heap_size;
int *min_heapify(int A[],int i);
int *build_heap(int A[]);
int main()
{
    int i;
    printf("Enter heap size: ");
    scanf("%d",&heap_size);
    int *A=(int*)calloc(heap_size+1,sizeof(int));
    if(A==NULL)
    {
        printf("\nOops! Memory can't be allocated\n");
        exit(0);
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
        temp=A[smallest];
        A[smallest]=A[i];
        A[i]=temp;
        A=min_heapify(A,smallest);
    }
    return A;
}
int *build_heap(int A[])
{
    int i;
    for(i=heap_size/2;i>=1;i--)
        A=min_heapify(A,i);
    printf("\nHeap created\n");
    return A;
}
