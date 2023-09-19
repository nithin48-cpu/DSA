#include<stdio.h>
struct node{
int data;
struct node *link;
};

struct node *head;

int main()
{
    int data;

    /*
    head=AddAtempty(12);
    AddAtend(10);
    head=AddAtbeg(19);
    AddAtpos(2,22);
    AddAfterpos(4,24);
    AddBeforpos(6,32);    //add before position 6 means 5;
    print();*/
    create();



}

AddAtempty(int data)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;
    head=newNode;
    printf("Created a Node Successfully\n");


}

AddAtend(int data)
{
    struct node* newNode,*ptr=head;

    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;                        //In case if we want use 2 linked list then we have to pass head pointer to function then it work to that linked list;

    if(head->link==NULL){
        head->link=newNode;
        return;
    }

    while(ptr->link!=NULL)
        ptr=ptr->link;
    ptr->link=newNode;



}


AddAtbeg(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;

    newNode->link=head;
    head=newNode;



}
print()
{
    struct node* ptr;
    ptr=head;
    if(ptr==NULL)
        printf("Linked List Is Empty\n");

    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");

}

AddAtpos(int pos,int data)
{
    struct node* ptr;
    ptr=head;
    /*
    for(int i=0;i<pos-2;i++)    //we can also use (i=2 ;i<pos;i++)
        ptr=ptr->link;
    */
    while(pos>2)
    {
        ptr=ptr->link;
        pos--;
    }

    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;

    newNode->link=ptr->link;
    ptr->link=newNode;



}

AddAfterpos(int pos,int data)
{
     struct node* ptr;
     ptr=head;

    /* for(int i=0;i<pos-1;i++)
        ptr=ptr->link;*/

     while(pos>1)
     {
         ptr=ptr->link;
         pos--;
     }

     struct node* newNode=(struct node*)malloc(sizeof(struct node));
     newNode->data=data;
     newNode->link=NULL;

     newNode->link=ptr->link;
     ptr->link=newNode;

}

AddBeforpos(int pos,int data)
{
    struct node* ptr;
    ptr=head;

    /*for(int i=0;i<pos-3;i++)
        ptr=ptr->link;*/

    while(pos>3)
    {
        ptr=ptr->link;
        pos--;

    }

    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;

    newNode->link=ptr->link;
    ptr->link=newNode;



}

create()
{
    int num,data;

    while(1)
    {
        printf("1)Print All Data In Linked List \n");
        printf("2)To Create New Linked List data \n");
        printf("3)Add at Beg\n");
        printf("4)Add at end\n");
        printf("5)delete first\n");
        printf("6)Delete last\n");
        printf("7)delete at postion\n");
        printf("8)Reverse the list\n");
        printf("9)search\n");
        printf("10)Exit\n");

        printf("Enter the choice  : ");
        scanf("%d",&num);

        switch(num)
        {
        case 1:
            print();
            break;
        case 2:
            printf("Enter the data : ");
            scanf("%d",&data);
            AddAtempty(data);
            break;
        case 3:
            printf("Enter the data : ");
            scanf("%d",&data);
            AddAtbeg(data);
            break;
        case 4:
            printf("Enter the data : ");
            scanf("%d",&data);
            AddAtend(data);
            break;

        case 5:
            Del_beg();
            break;
        case 6:
            Del_last();
            break;
        case 7:
            printf("Enter the position you want to delete : ");
            scanf("%d",&data);
            Del_at_pos(data);
            break;

        case 8:
            reverse();
            break;
        case 9:
            printf("Enter the number you want to be search  : ");
            scanf("%d",&data);
            search(data);
            break;
        case 10:
            exit(1);
        default :
            printf("Enter the valid number");


        }
        printf("-------------------------------\n");

    }


}

Del_beg()
{
    struct node *temp;

    if(head==NULL)
        printf("List is empty");
    else{

    temp=head;
    head=head->link;
    free(temp);
    }
}

Del_last()
{
    struct node* ptr;
    ptr=head;
    if(head->link==NULL){
         free(head);
    }
    else if(head==NULL)
    {
        printf("List is empty");

    }


   else{
    while(ptr->link->link!=NULL)
    {
        ptr=ptr->link;
    }
    free(ptr->link);
    ptr->link=NULL;
   }


}

Del_at_pos(int pos)
{
    struct node* ptr,*ptr2,*temp;
    int count=0;

    ptr=head;
    ptr2=head;

    while(ptr2!=NULL)
    {
        count++;
        ptr2=ptr2->link;

    }


    if(pos>count){
        printf("List is not that big\n");
        printf("size of list is %d\n",count);
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else if(head==NULL)
        printf("List is empty");

    else{


    while(pos>2)
    {
        ptr=ptr->link;
        pos--;

    }
    /*
    ptr->link=ptr->link->link;
    free(ptr->link);*/

    temp=ptr->link;
    ptr->link=temp->link;
    free(temp);

    }

}

reverse()
{
    struct node* temp=NULL,*temp2=NULL;

    while(head!=NULL)
    {


    temp2=head->link;
    head->link=temp;
    temp=head;
    head=temp2;
    }
    head=temp;


}

void search(int data)
{
    struct node* temp=head;
    if(temp==NULL)
    {
        printf("The List is Empty");
        return;
    }

    while(temp!=NULL)
    {
        if(temp->data==data)
            printf("%d is in the list\n",data);
        temp=temp->link;

    }


}
