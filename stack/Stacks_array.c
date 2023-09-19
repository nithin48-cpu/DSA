#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

int stack_arr[MAX];
int top=-1;               //building stack using an array;


void create();
void print();
int isFull();
int isEmpty();
int isPeek();
int pop();
void push(int data);


int main()
{

/*
     push(10);
     push(20);
     push(30);
     push(40);
     pop();
     push(50);
    print();*/

    create();
}


void push(int data)
{
    if(isFull())
        printf("Stack is Full");
    top++;
    stack_arr[top]=data;

    return;
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is Empty");
        exit(1);
    }


 else
 {


    int val;
    val=stack_arr[top];
    top--;                        //here instead  of initialzing with zero we create an illusion that by decreasing top variable when we push then that will be supprsed;
    return val;

}
}

int isPeek()
{
    if(isEmpty())
        printf("Stack is Empty");
    else
    return stack_arr[top];
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;

}

int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

void print()
{
    if(top==-1)
        printf("The Stack is Empty\n");
    else{
    printf("\n\n");
    for(int i=top;i>-1;i--)
        printf("  |   %5d   |\n",stack_arr[i]);
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
        if(isFull)
           printf("Stack is full\n");
        else
            printf("Stack is not Full\n");
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
