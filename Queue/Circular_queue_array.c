

//CIRCULAR QUEUE IMPLEMENTATION IN ARRRAY;
#include<stdio.h>

#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void Enqueue(int data);
int dequeue();
int top();
int back();
void print();
//void display();




void main()
{
     int choice,data;

    while(1)
    {
        printf("\n1)Print All elements");
        printf("\n2)Enqueue");
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
        Enqueue(data);
        break;

    case 3:
        dequeue();
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
    if(front ==-1 && rear ==-1)
    {
        front++;
        rear++;
        queue[rear]=data;
    }
    else if(front==0 && rear==MAX-1 || front==rear+1)
        printf("Queue Overflow!!!");
    else if(front!=0 && rear==MAX-1)
    {
        rear=0;
        queue[rear]=data;

    }
    else
    {
        rear++;
        queue[rear]=data;

    }
    return;
}

int dequeue()
{
    int value;
    if(front==-1 && rear ==-1)
    {
        printf("Queue underflow");
        //exit(1);
        return;

    }
    else if(front==rear)
    {
        value=queue[front];
        front=-1;
        rear=-1;
    }
    else if(front==MAX-1)
    {
       value=queue[front];
       front=0;

    }
    else
    {

        value=queue[front];
        front++;

    }
    printf("The deleted value is %d",value);
    return value;

}

int top()
{
    if(front ==NULL && rear ==NULL)
    {
        printf("Queue is empty!");
        return;
    }
    return queue[front];

}

int  back()
{
    if(front ==NULL && rear ==NULL)
    {
        printf("Queue is empty!");
        return;
    }
    return queue[rear];
}

void print()
{
    if(front ==-1 && rear ==-1)
    {
        printf("Queue is empty!");
        return;
    }
    else if(front<rear || rear==MAX-1)
    {
         for(int i=front;i<=rear;i++)
             printf("%d ",queue[i]);
    }
    else
    {
        for(int i=front;i<MAX;i++)
             printf("%d ",queue[i]);
        for(int i=0;i<=rear;i++)
            printf("%d ",queue[i]);


    }


}

/*
void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("\n Queue is empty..");
    }
    else
    {
        printf("\nElements in a Queue are :");
        while(i<=rear)
        {
            printf("queue[%d]=%d,",i, queue[i]);
            printf(" i= %d fornt=%d  rear=%d\n",i,front,rear);
            i++;

            getch();
        }
    }
}
*/
