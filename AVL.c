#include<stdio.h>
#include<stdlib.h>
int flag=0;
struct node
{
    int info;
    struct node *left,*right;
};
struct node *create_node(int data);
struct node *insert(struct node *root,int data);
struct node *left_rotation(struct node *root);
struct node *right_rotation(struct node *root);
struct node *LL(struct node *root);
struct node *LR(struct node *root);
struct node *RR(struct node *root);
struct node *RL(struct node *root);
int BF(struct node *root);
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
int nLeaves(struct node *root);
int nHalfnodes(struct node *root);
int nFullnodes(struct node *root);
struct node *max(struct node *root);
struct node *min(struct node *root);
int height(struct node *root);
int isComplete(struct node *root);
int isFull(struct node *root);
int search(struct node *root,int data);
int count(struct node *root);
struct node *delete_particular(struct node *root,int data);
int main()
{
    struct node *root=NULL,*t;
    int ch,data,x;
    while(1)
    {
        printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Leaves\n6.Halfnodes\n7.Fullnodes\n8.Maximum\n9.Minimum\n10.Height\n11.isComplete\n12.isFull\n13.Search\n14.Count\n15.Delete\n16.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the data to be inserted: ");
                scanf("%d",&data);
                root=insert(root,data);
                printf("\n%d is inserted\n",data);
                break;
            case 2:
                printf("\nPreorder: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nInorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("\nPostorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                x=nLeaves(root);
                printf("\nNumber of leaves = %d\n",x);
                break;
            case 6:
                x=nHalfnodes(root);
                printf("\nNo. of half-nodes = %d\n",x);
                break;
            case 7:
                x=nFullnodes(root);
                printf("\nNo. of full-nodes = %d\n",x);
                break;
            case 8:
                t=max(root);
                if(t!=NULL)
                    printf("\nMaximum = %d\n",t->info);
                else
                    printf("\nTree is empty\n");
                break;
            case 9:
                t=min(root);
                if(t!=NULL)
                    printf("\nMinimum = %d\n",t->info);
                else
                    printf("\nTree is empty\n");
                break;
            case 10:
                x=height(root);
                printf("\nHeight = %d\n",x);
                break;
            case 11:
                x=isComplete(root);
                if(x==1)
                    printf("\nComplete binary tree\n");
                else
                    printf("\nNot a complete binary tree\n");
                break;
            case 12:
                x=isFull(root);
                if(x==1)
                    printf("\nFull binary tree\n");
                else
                    printf("\nNot a Full binary tree\n");
                break;
            case 13:
                printf("\nEnter the data to be searched: ");
                scanf("%d",&data);
                x=search(root,data);
                if(x==1)
                    printf("\n%d is found\n",data);
                else
                    printf("\n%d is not found\n",data);
                break;
            case 14:
                x=count(root);
                printf("\nNo. of nodes = %d\n",x);
                break;
            case 15:
                printf("\nEnter the data to be deleted: ");
                scanf("%d",&data);
                flag=0;
                root=delete_particular(root,data);
                if(flag==0)
                    printf("\n%d is not found\n");
                else
                    printf("\n%d is deleted\n");
                break;
            case 16:
                printf("\n---------------End Of The Program----------------\n");
                exit(0);
            default:
                printf("\nInvalid Choice\n");
                break;
        }
    }
    return 0;
}
struct node *create_node(int data)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->left=NULL;
    t->right=NULL;
    t->info=data;
    return t;
}
struct node *insert(struct node *root,int data)
{
    if(root==NULL)
        root=create_node(data);
    else if(data<=root->info)
    {
        root->left=insert(root->left,data);
        if(BF(root)==2)
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
        if(BF(root)==-2)
        {
            if(data>root->right->info)
                root=RR(root);
            else
                root=RL(root);
        }
    }
    return root;
}
struct node *left_rotation(struct node *root)
{
    struct node *t;
    t=root->right;
    root->right=t->left;
    t->left=root;
    return t;
}
struct node *right_rotation(struct node *root)
{
    struct node *t;
    t=root->left;
    root->left=t->right;
    t->right=root;
    return t;
}
struct node *LL(struct node *root)
{
    root=right_rotation(root);
    return root;
}
struct node *LR(struct node *root)
{
    root->left=left_rotation(root->left);
    root=right_rotation(root);
    return root;
}
struct node *RR(struct node *root)
{
    root=left_rotation(root);
    return root;
}
struct node *RL(struct node *root)
{
    root->right=right_rotation(root->right);
    root=left_rotation(root);
    return root;
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
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->info);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->info);
    }
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
        return nHalfnodes(root->left)+nHalfnodes(root->right)+1;
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
struct node *max(struct node *root)
{
    struct node *t;
    t=root;
    if(t==NULL)
        return t;
    while(t->right!=NULL)
        t=t->right;
    return t;
}
struct node *min(struct node *root)
{
    struct node *t;
    t=root;
    if(t==NULL)
        return t;
    while(t->left!=NULL)
        t=t->left;
    return t;
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
        return (l>r?l:r)+1;
    }
}
int isComplete(struct node *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    else if(root->left!=NULL && root->right!=NULL)
        return isComplete(root->left)&&isComplete(root->right);
    else
        return 0;
}
int isFull(struct node *root)
{
    int L;
    if(isComplete(root)==1)
    {
        L=nLeaves(root);
        return (L&(L-1))==0?1:0;
    }
    return 0;
}
int search(struct node *root,int data)
{
    if(root==NULL)
        return 0;
    else if(data<root->info)
        return search(root->left,data);
    else if(data>root->info)
        return search(root->right,data);
    else
        return 1;
}
int count(struct node *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return 1+count(root->left)+count(root->right);
}
struct node *delete_particular(struct node *root,int data)
{
    int bf;
    if(root==NULL)
        return root;
    else if(data<root->info)
    {
        root->left=delete_particular(root->left,data);
        if(BF(root)==-2)
        {
            bf=BF(root->right);
            if(bf==0 || bf==-1)
                root=RR(root);
            else
                root=RL(root);
            return root;
        }
    }
    else if(data>root->info)
    {
        root->right=delete_particular(root->right,data);
        if(BF(root)==2)
        {
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
        //Leaf Nodes
        if(root->left==NULL && root->right==NULL)
        {
            flag=1;
            free(root);
            root=NULL;
            return root;
        }
        //Half Nodes
        else if(root->left!=NULL && root->right==NULL)
        {
            flag=1;
            struct node *t;
            t=root;
            root=root->left;
            free(t);
            return root;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            flag=1;
            struct node *t;
            t=root;
            root=root->right;
            free(t);
            return root;
        }
        //Full Nodes
        else
        {
            struct node *t;
            t=max(root->left);
            root->info=t->info;
            root->left=delete_particular(root->left,t->info);
            if(BF(root)==-2)
            {
                bf=BF(root->right);
                if(bf==0 || bf==-1)
                    root=RR(root);
                else
                    root=RL(root);
                return root;
            }
        }
    }
    return root;
}

