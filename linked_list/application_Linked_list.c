/*Application of linked list in writing the expressions and
adding them*/
/*
#include<stdio.h>
#include<conio.h>

struct node
{
    int co;
    int exp;
    struct node* link;
};

struct node* insert(struct node* head,int co,int exp);
print(struct node* head);

void main()
{
    struct node* head=NULL;
    int n,co,exp;
    printf("How many terms are there  : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter the coeff and exponenet  :  ");
        scanf("%d %d",&co,&exp);

        head=insert(head,co,exp);

    }
    print(head);



}



print(struct node* head)
{
    struct node*temp=head;
    if(temp==NULL)
        printf("No Polynomial");
    else
    {
    while(temp!=NULL)
    {
        printf("%dx^%d ",temp->co,temp->exp);
        temp=temp->link;
        if(temp!=NULL)
            printf("+");
        else
            printf("\n");
    }
    }
}

struct node* insert(struct node* head,int co,int exp)
{
    struct node* newP=(struct node*)malloc(sizeof(struct node));
    newP->co=co;
    newP->exp=exp;
    newP->link=NULL;

    struct node* temp=head;
    if(head==NULL || exp>head->exp)
    {
        newP->link=head;
        head=newP;
    }
    else{

    while(temp->link!=NULL && temp->link->exp>=exp)
        temp=temp->link;

        newP->link=temp->link;
        temp->link=newP;


    }
    return head;

}
*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int co;
    int exp;
    struct node* link;
};

struct node *head1=NULL;
struct node *head2=NULL;

struct node* insert(struct node* head,int co,int exp);
void print(struct node* head);
void create();
void Take_expresion(struct node *head);

void main()
{

    create();




}



void print(struct node *head)
{
    struct node*temp=head;
    if(temp==NULL)
        printf("No Polynomial");
    else
    {
    while(temp!=NULL)
    {
        printf("%dx^%d ",temp->co,temp->exp);
        temp=temp->link;
        if(temp!=NULL)
            printf("+");
        else
            printf("\n");
    }
    }
    return;
}

struct node* insert(struct node* head)
{
    int n,co,exp;
    static int i=1;
    printf("Enter the expression %d  ",i);
    printf("How many terms are there  : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter the coeff and exponenet  :  ");
        scanf("%d %d",&co,&exp);





    struct node* newP=(struct node*)malloc(sizeof(struct node));
    newP->co=co;
    newP->exp=exp;
    newP->link=NULL;

    struct node* temp=head;
    if(head==NULL || exp>head->exp)
    {
        newP->link=head;
        head=newP;
    }
    else{

    while(temp->link!=NULL && temp->link->exp>=exp)
        temp=temp->link;

        newP->link=temp->link;
        temp->link=newP;


    }
    }
    return head;

}

int Take_expression(struct node *head)
{
    int n,co,exp;
    static int i=1;
    printf("Enter the expression %d  ",i);
    printf("How many terms are there  : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter the coeff and exponenet  :  ");
        scanf("%d %d",&co,&exp);

        head=insert(head,co,exp);

    }
    print(head);

    return 0;

}

void create()
{
    int num;
    printf("1)Enter  and print the expression\n");
    printf("2)Adding 2 expressions\n");

    printf("Choose the choice  : ");
    scanf("%d,&num");

    switch(num)
    {
     case 1:
        insert(head1);
        break;
     case 2:
        insert()
        break;
     default:
        printf("Enter the invalid number ");
    }

}





