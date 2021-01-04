
 

#include<stdio.h>
#include<stdlib.h>

typedef struct myBintree
{
    int marks;
    struct myBintree *left;
    struct myBintree *right;
} myBintree;

myBintree *root = NULL;

myBintree *createBinTree()
{
    myBintree *ptr;
    int m;
    printf("Enter data(-1 for no data):");
    scanf("%d",&m);
    
    if(m==-1)
        return NULL;
    
    ptr=(myBintree*)malloc(sizeof(myBintree));
    ptr->marks=m;
    
    printf("Enter left child of %d:\n",m);
    ptr->left=createBinTree();
    
    printf("Enter right child of %d:\n",m);
    ptr->right=createBinTree();
    
    return ptr;
}

void BinTreePreorder(myBintree *temp)
{
    if(temp!=NULL)
    {
        printf("%d\t",temp->marks);        
        BinTreePreorder(temp->left);        
        BinTreePreorder(temp->right);        
    }
}

void BinTreeInorder(myBintree *temp)
{
    
    if(temp!=NULL)
    {
        BinTreeInorder(temp->left);
        printf("%d\t",temp->marks);
        BinTreeInorder(temp->right);
        
    }
    
}

void BinTreePostorder(myBintree *temp)
{
    
    if(temp!=NULL)
    {
        BinTreePostorder(temp->left);
        BinTreePostorder(temp->right);
        printf("%d\t",temp->marks);
        
    }
    
}

int main()
{
    
    root=createBinTree();
    printf("\nThe tree is:\n");
    
    printf("\nThe preorder traversal of tree is:\n");
    BinTreePreorder(root);
    printf("\nThe postorder traversal of tree is:\n");
    BinTreePostorder(root);
    printf("\nThe inorder traversal of tree is:\n");
    BinTreeInorder(root);
    printf("\n");
    return 0;
}




