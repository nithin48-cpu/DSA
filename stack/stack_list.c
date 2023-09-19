#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;

};

struct node* head;

void main()
{

   create();

}

void push(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;

    newNode->link=head;
    head=newNode;

    return;
}

int pop()
{
    int val;
    struct node* temp;
    temp=head;

    if(temp==NULL)
    {
        printf("Stack is empty");
        exit(1);
    }

    else{
    val=temp->data;
    head=head->link;
    free(temp);
    temp=NULL;
    return val;

    }
}

int isPeek()
{
     if(head==NULL)
     {
         printf("Stack is empty\n");
     }

     else
     {
     return head->data;
     }
}

int isEmpty()
{
    if(head==NULL)
        return 1;
    else
        return 0;

}

void print()
{
    struct node*ptr=head;
    if(ptr==NULL)
        printf("The Stack is Empty\n");
    else{
    printf("\n\n");
    while(ptr!=NULL)
    {
        printf("  |   %5d   |\n",ptr->data);
        ptr=ptr->link;
    }
    printf("  -------------\n");
    }

    return;
}



void create()
{
    int num,data;
    while(1)
    {


    printf("1)Print\n");
    printf("2)Push\n");
    printf("3)Pop\n");
    printf("4)isEmpty\n");
    printf("5)isFull\n");
    printf("6)isPeek\n");
    printf("7)exit\n");

    printf("Choose the Number\n");
    scanf("%d",&num);

    switch(num)
    {
    case 1:
        print();
        break;
    case 2:
        printf("Enter the data\n");
        scanf("%d",&data);
        push(data);
        break;
    case 3:
        printf("%d is poped out\n",pop());
        break;
    case 4:
        if(isEmpty())
            printf("Stack is empty\n");
        else
            printf("Stack is not empty\n");
        break;
    case 5:
        printf("Unlimited Storage\n");
        break;
    case 6:
        printf("%d is the Top most element of Stack\n",isPeek());
        break;
    case 7:
        exit(1);
        break;
    default :
        printf("Invalid number\n");

    }


    }

  return;

}


