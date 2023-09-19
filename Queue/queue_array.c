#include<stdio.h>

#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;

void insert(int data);
int delete1();
int top();
int back();
void print();


void main()
{
     int choice,data;

    while(1)
    {
        printf("\n1)Print All elements");
        printf("\n2)Insert");
        printf("\n3)Delete");
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
        insert(data);
        break;

    case 3:
        delete1();
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

void insert(int data)
{
    if(front ==-1 && rear ==-1)
    {
        front++;
        rear++;
        queue[front]=data;

    }
    else if(rear==MAX-1)
    {
        printf("Queue overflow");
        //exit(1);
        return;
    }
    else
    {
        rear++;
        queue[rear]=data;

    }
    return;
}

int delete1()
{
    if(front==-1 && rear ==-1 || front>rear)
    {
        printf("Queue underflow");
        //exit(1);
        return;

    }
    else
    {
        int value;
        value=queue[front];
        front++;
        printf("The deleted value is %d",value);
        return value;

    }

}

int top()
{
    return queue[front];

}

int  back()
{
    return queue[rear];
}

void print()
{
    if(front ==-1 && rear ==-1)
    {
        printf("Queue is empty!");
        return;
    }
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);

}
