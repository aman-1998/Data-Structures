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
int height(struct node *root);
int search(struct node *root,int data);
struct node *delete_node(struct node *root,int data);
int isComplete(struct node *root);
int isFull(struct node *root);
int BF(struct node *root);
struct node *right_rotate(struct node *root);
struct node *left_rotate(struct node *root);
struct node *RR(struct node *root);
struct node *RL(struct node *root);
struct node *LL(struct node *root);
struct node *LR(struct node *root);
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
                printf("\n%d is inserted\n",data);
                system("PAUSE");
                system("CLS");
                break;
            case 2:
                if(root!=NULL)
                {
                    printf("\nPreorder:-\n");
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
                    printf("\nInorder:-\n");
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
                    printf("\nPostorder:-\n");
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
                    printf("\nNo. of nodes = %d\n",n);
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
                    printf("\nNo. of leaves = %d\n",n);
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
                    printf("\nNo. of half-nodes = %d\n",n);
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
                    printf("\nNo. of full nodes = %d\n",n);
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
                printf("\nEnter the element to be searched: ");
                scanf("%d",&data);
                if(root!=NULL)
                {
                    n=search(root,data);
                    if(n==111)
                        printf("\n%d not found\n",data);
                    else
                        printf("\n%d found\n",data);
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 11:
                printf("\nEnter the element to be deleted: ");
                scanf("%d",&data);
                if(root!=NULL)
                {
                    flag=0;
                    root=delete_node(root,data);
                    if(flag==0)
                        printf("\n%d is not found\n",data);
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
                        printf("\nThe AVL tree is a complete tree\n");
                    else
                        printf("\nThe AVL tree is not a complete tree\n");
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
                        printf("\nThe AVL tree is a full tree\n");
                    else
                        printf("\nThe AVL tree is not a full tree\n");
                }
                else
                    printf("\nTree is empty\n");
                system("PAUSE");
                system("CLS");
                break;
            case 14:
                printf("\n--------------------------------------------------------\n");
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
    temp->info=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insert(struct node *root,int data)
{
    int bf;
    if(root==NULL)
    {
        root=create_node(data);
        return root;
    }
    else if(data<root->info)
    {
        root->left=insert(root->left,data);
        bf=BF(root);
        if(bf==2)
        {
            if(data<root->left->info)
                root=LL(root);
            else
                root=LR(root);
        }
    }
    else
    {
        root->right=insert(root->right,data);
        bf=BF(root);
        if(bf==-2)
        {
            if(data>root->right->info)
                root=RR(root);
            else
                root=RL(root);
        }
    }
    return root;
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
        return nFullnodes(root->left)+nFullnodes(root->right)+1;
    else
        return nFullnodes(root->left)+nFullnodes(root->right);
}
int height(struct node *root)
{
    int l,r;
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 0;
    else
    {
        l=height(root->left);
        r=height(root->right);
        return 1+(l>r?l:r);
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
    int bf,flag2;
    if(root==NULL)
        return root;
    else if(data<root->info)
    {
        root->left=delete_node(root->left,data);
        if(flag2==0)
        {
            flag2=1;
            bf=BF(root->right);
            if(bf==-1 || bf==0)
                root=RR(root);
            else
                root=RL(root);
            return root;
        }
    }
    else if(data>root->info)
    {
        root->right=delete_node(root->right,data);
        if(flag2==0)
        {
            flag2=1;
            bf=BF(root->left);
            if(bf==0 || bf==1)
                root=LL(root);
            else
                root=LR(root);
            return root;
        }
    }
    else
    {
        flag=1;
        //leaf node
        if(root->left==NULL && root->right==NULL)
        {
            flag2=0;
            free(root);
            return NULL;
        }
        //half-node
        else if(root->left!=NULL && root->right==NULL)
        {
            flag2=0;
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
            t=root->right;
            while(t->left!=NULL)
                t=t->left;
            root->info=t->info;
            root->right=delete_node(root->right,t->info);
            if(flag2==0)
            {
                flag2=1;
                bf=BF(root->left);
                if(bf==0 || bf==1)
                    root=LL(root);
                else
                    root=LR(root);
                return root;
            }
        }
    }
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
int BF(struct node *root)
{
    int lst,rst;
    if(root->left==NULL)
        lst=0;
    else
        lst=1+height(root->left);
    if(root->right==NULL)
        rst=0;
    else
        rst=1+height(root->right);
    return lst-rst;
}
struct node *right_rotate(struct node *root)
{
    struct node *t;
    t=root->left;
    root->left=t->right;
    t->right=root;
    return t;
}
struct node *left_rotate(struct node *root)
{
    struct node *t;
    t=root->right;
    root->right=t->left;
    t->left=root;
    return t;
}
struct node *RR(struct node *root)
{
    root=left_rotate(root);
    return root;
}
struct node *RL(struct node* root)
{
    root->right=right_rotate(root->right);
    root=left_rotate(root);
    return root;
}
struct node *LL(struct node *root)
{
    root=right_rotate(root);
    return root;
}
struct node *LR(struct node *root)
{
    root->left=left_rotate(root->left);
    root=right_rotate(root);
    return root;
}
