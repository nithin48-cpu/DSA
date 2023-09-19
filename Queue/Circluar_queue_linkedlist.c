#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];


void Enqueue(int data);
int Dequeue();
int top();
int back();
void print();

struct node
{
    int data;
    struct node * link;

};

struct node *front;
struct node *rear;


void main()
{
     int choice,data;

    while(1)
    {
        printf("\n1)Print All elements");
        printf("\n2)Enqueue");
        printf("\n3)Dequeue");
        printf("\n4)Front Element");
        printf("\n5)Rear Element");
        printf("\n6)exit");

        printf("\nEnter choice  : ");
        scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        print();
        break;
    case 2:
        printf("\nEnter the data  : ");
        scanf("%d",&data);
        Enqueue(data);
        break;

    case 3:
        Dequeue();
        break;

    case 4:
        printf("\nTop most element is %d ",top());
        break;

    case 5:
        printf("\nRear element is %d",back());
        break;

    case 6:
        exit(1);
    default:
        printf("\nInvalid Number!!!");
        break;

    }

    }



}

void Enqueue(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node)) ;
    temp->data=data;
    temp->link=NULL;
    if(temp==NULL)
        printf("\nQueue is Overflow");

    if(front ==NULL && rear ==NULL)
    {
       front=temp;
       rear=temp;
       rear->link=front;
    }
    else
    {
        rear->link=temp;
        rear=temp;
        rear->link=front;
    }
    return;
}

int Dequeue()
{
    int value;
    if(front==NULL && rear ==NULL)
    {
        printf("\nQueue Underflow");

    }
    else if(front==rear)
    {
        value=front->data;
        free(front);
        front=NULL;
        rear=NULL;
        printf("The deleted number is %d",value);
        return value;
    }
    else
    {
        struct node *temp;
        temp=front;
        value=front->data;
        front=front->link;
        rear->link=front;
        free(temp);
        temp=NULL;
        printf("The deleted number is %d",value);
        return value;
    }


}

int top()
{
    if(front ==NULL && rear ==NULL)
    {
        printf("Queue is empty!");
        return;
    }
    return front->data;

}

int  back()
{
    if(front ==NULL && rear ==NULL)
    {
        printf("Queue is empty!");
        return;
    }
    return rear->data;
}

void print()
{
    if(front ==NULL && rear ==NULL)
    {
        printf("Queue is empty!");
        return;
    }
    struct node *temp;
    temp=front;
    do
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }while(temp!=front);


}
