#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int data)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

struct Node* insert(struct Node* root,int data)
{
    if(root==NULL)
    {
        return create_node(data);
    }

    if(data<root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}

int inordertraversal(struct Node* root)
{
    if(root!=NULL)
    {
        inordertraversal(root->left);
        printf("%d ",root->data);
        inordertraversal(root->right);
    }
    return 0;
}

int preordertraversal(struct Node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
    return 0;
}


int postordertraversal(struct Node* root)
{
    if(root!=NULL)
    {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%d ",root->data);

    }
    return 0;
}




int main()
{
    struct Node* root=NULL;

    root=insert(root,15);
    insert(root,16);
    insert(root,14);
    inordertraversal(root);
    printf("\n");
    preordertraversal(root);

    return 0;
}
