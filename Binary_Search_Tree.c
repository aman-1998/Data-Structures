#include<stdio.h>
#include<stdlib.h>
int flag;
struct node
{
    int info;
    struct node *left,*right;
};
struct node *create_node(int data);
struct node *insert(struct node *root,int data);
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
int count_nodes(struct node *root);
int nLeaves(struct node *root);
int nHalfnodes(struct node *root);
int nFullnodes(struct node *root);
int search(struct node *root,int data);
int height(struct node *root);
struct node *delete_node(struct node *root,int data);
int isComplete(struct node *root);
int isFull(struct node *root);
int main()
{
    struct node *root=NULL;
    int ch,data,n;
    while(1)
    {
        printf("1.Insert\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.count nodes\n6.Count Leaves\n7.Count half-nodes\n8.Count full_nodes\n9.Height of the tree\n10.Search\n11.Delete any data\n12.Is complete or not ?\n13.Is Full or not ?\n14.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the data to be inserted: ");
                scanf("%d",&data);
                root=insert(root,data);
                system("PAUSE");
                system("CLS");
                break;
            case 2:
                if(root!=NULL)
                {
                    printf("\nPreorder traversal:-\n");
                    preorder(root);
                    printf("\n");
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 3:
                if(root!=NULL)
                {
                    printf("\nInorder traversal:-\n");
                    inorder(root);
                    printf("\n");
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 4:
                if(root!=NULL)
                {
                    printf("\nPost traversal:-\n");
                    postorder(root);
                    printf("\n");
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 5:
                if(root!=NULL)
                {
                    n=count_nodes(root);
                    printf("\nNo. of nodes in the tree = %d\n",n);
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 6:
                if(root!=NULL)
                {
                    n=nLeaves(root);
                    printf("\nNo. of leaves in the tree = %d\n",n);
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 7:
                if(root!=NULL)
                {
                    n=nHalfnodes(root);
                    printf("\nNo. of half-nodes in the tree = %d\n",n);
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 8:
                if(root!=NULL)
                {
                    n=nFullnodes(root);
                    printf("\nNo. of full-nodes in the tree = %d\n",n);
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 9:
                if(root!=NULL)
                {
                    n=height(root);
                    printf("\nHeight of the tree = %d\n",n);
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 10:
                printf("\nEnter the data to be searched: ");
                scanf("%d",&data);
                if(root!=NULL)
                {
                    n=search(root,data);
                    if(n==111)
                        printf("\n%d is not found\n",data);
                    else
                        printf("\n%d is found\n",data);
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 11:
                printf("\nEnter the data to be deleted: ");
                scanf("%d",&data);
                if(root!=NULL)
                {
                    flag=0;
                    root=delete_node(root,data);
                    if(flag==0)
                        printf("\n%d is not found in the BST\n",data);
                    else
                        printf("\n%d is deleted\n",data);
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 12:
                if(root!=NULL)
                {
                    n=isComplete(root);
                    if(n==1)
                        printf("\nThe BST is  a complete tree\n");
                    else
                        printf("\nThe BST is not a complete tree\n");
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 13:
                if(root!=NULL)
                {
                    n=isFull(root);
                    if(n==1)
                        printf("\nThe BST is a Full tree\n");
                    else
                        printf("\nThe BST is not a Full tree\n");
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 14:
                printf("\n-------------------------------------------------------------\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
                system("PAUSE");
                system("CLS");
                break;
        }
    }
    return 0;
}
struct node *create_node(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nMemory can't be allocated\n");
        exit(0);
    }
    temp->info=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    {
        root=create_node(data);
        return root;
    }
    else if(data<root->info)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->info);
        if(root->left!=NULL)
            preorder(root->left);
        if(root->right!=NULL)
            preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
            inorder(root->left);
        printf("%d ",root->info);
        if(root->right!=NULL)
            inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
            postorder(root->left);
        if(root->right!=NULL)
            postorder(root->right);
        printf("%d ",root->info);
    }
}
int count_nodes(struct node *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return 1+count_nodes(root->left)+count_nodes(root->right);
}
int nLeaves(struct node *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return nLeaves(root->left)+nLeaves(root->right);
}
int nHalfnodes(struct node *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 0;
    else if(root->left!=NULL && root->right!=NULL)
        return nHalfnodes(root->left)+nHalfnodes(root->right);
    else
        return 1+nHalfnodes(root->left)+nHalfnodes(root->right);
}
int nFullnodes(struct node *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 0;
    else if(root->left!=NULL && root->right!=NULL)
        return 1+nFullnodes(root->left)+nFullnodes(root->right);
    else
        return nFullnodes(root->left)+nFullnodes(root->right);
}
int height(struct node *root)
{
    int l,r;
    if(root==NULL)
        return 0;
    else if(root->left==NULL &&root->right==NULL)
        return 0;
    else
    {
        l=height(root->left);
        r=height(root->right);
        return (l>r?l:r)+1;
    }
}
int search(struct node *root,int data)
{
    if(root==NULL)
        return 111;
    else if(data<root->info)
        return search(root->left,data);
    else if(data>root->info)
        return search(root->right,data);
    else
        return 1;

}
struct node *delete_node(struct node *root,int data)
{
    if(root==NULL)
        return root;
    else if(data<root->info)
        root->left=delete_node(root->left,data);
    else if(data>root->info)
        root->right=delete_node(root->right,data);
    else
    {
        flag=1;
        //leaf node
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        //half-node
        else if(root->left!=NULL && root->right==NULL)
        {
            struct node *t;
            t=root;
            root=root->left;
            free(t);
            return root;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            struct node *t;
            t=root;
            root=root->right;
            free(t);
            return root;
        }
        //full-node
        else
        {
            struct node *t;
            t=root->left;
            while(t->right!=NULL)
                t=t->right;
            root->info=t->info;
            root->left=delete_node(root->left,t->info);
            return root;
        }
    }
    return root;
}
int isComplete(struct node *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    else if(root->left!=NULL && root->right!=NULL)
        return (isComplete(root->left) && isComplete(root->right));
    else
        return 0;
}
int isFull(struct node *root)
{
    if(isComplete(root)==1)
    {
        int n=nLeaves(root);
        return (n&(n-1))==0?1:0;
    }
    return 0;
}
