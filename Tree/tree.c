#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <stdarg.h>
#include<math.h>

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

/*
int levelordertraversal(struct Node* root)
{
    Queue q;  // c is not object oriented language so it not have the queue library in c,but have in c++
    q.add(root);
    while()
    if(root!=NULL)
    {

    }
    return 0;
}
*/

int NumofNode(struct Node* root)
{
    if(root==NULL)
        return 0;
    else{
        int left=NumofNode(root->left);
        int right=NumofNode(root->right);
        return left+right+1;
    }
}

int SumofNode(struct Node* root)
{
    if(root==NULL)
        return 0;
    else{
        int left=SumofNode(root->left);
        int right=SumofNode(root->right);
        return left+right+root->data;
    }
}

int height(struct Node* root)
{
    if(root==NULL)
        return 0;
    else{
        int left=height(root->left);
        int right=height(root->right);
        return fmax(left,right)+1;
    }

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
    printf("\nNumber of Node: %d",NumofNode(root));
    printf("\nSum of Node: %d",SumofNode(root));
    printf("\nHeight of Tree: %d",height(root));
    return 0;
}
