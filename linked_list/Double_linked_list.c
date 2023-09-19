#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    struct node* prev;
int data;
struct node *next;
};

struct node *head;

int  reverse();

int  Del_at_pos(int pos);

int  Del_last();

int  Del_beg();
int  create();

int  AddBeforpos(int pos,int data);
int  AddAfterpos(int pos,int data);
int  AddAtpos(int pos,int data);
int  print();

int  AddAtbeg(int data);
int  AddAtend(int data);
int  AddAtempty(int data);




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

    clrscr();
    while(1){
    create();
    getch();
    clrscr();
    }

   return 0;

}

int  AddAtempty(int data)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;
    head=newNode;
    printf("Created a Node Successfully\n");

    return 0;


}

int  AddAtend(int data)
{
    struct node* newNode,*ptr=head;

    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;                        //In case if we want use 2 nexted list then we have to pass head pointer to function then it work to that nexted list;

    if(head->next==NULL){
        head->next=newNode;
        return 0;
    }

    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=newNode;
  return 0;


}


int  AddAtbeg(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;

    newNode->next=head;
    head=newNode;

    return 0;

}
int  print()
{
    struct node* ptr;
    ptr=head;
    if(ptr==NULL)
        printf("nexted List Is Empty\n");

    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return 0;
}

int  AddAtpos(int pos,int data)
{
    struct node* ptr;
    ptr=head;
    /*
    for(int i=0;i<pos-2;i++)    //we can also use (i=2 ;i<pos;i++)
        ptr=ptr->next;
    */
    while(pos>2)
    {
        ptr=ptr->next;
        pos--;
    }

    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;

    newNode->next=ptr->next;
    newNode->prev=ptr;

    ptr->next=newNode;
    newNode->next->prev=newNode;

  return 0;

}

int  AddAfterpos(int pos,int data)
{
     struct node* ptr;
     ptr=head;

    /* for(int i=0;i<pos-1;i++)
        ptr=ptr->next;*/

     while(pos>1)
     {
         ptr=ptr->next;
         pos--;
     }

     struct node* newNode=(struct node*)malloc(sizeof(struct node));
     newNode->prev=NULL;
     newNode->data=data;
     newNode->next=NULL;

     newNode->next=ptr->next;
    newNode->prev=ptr;

    ptr->next=newNode;
    newNode->next->prev=newNode;

    return 0;
}

int  AddBeforpos(int pos,int data)
{
    struct node* ptr;
    ptr=head;

    /*for(int i=0;i<pos-3;i++)
        ptr=ptr->next;*/

    while(pos>3)
    {
        ptr=ptr->next;
        pos--;

    }

    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;

    newNode->next=ptr->next;
    newNode->prev=ptr;

    ptr->next=newNode;
    newNode->next->prev=newNode;

    return 0;
}

int  create()
{
    int num,data;


        printf("\t1)Print All Data In nexted List \n\n");
        printf("\t2)To Create New Double nexted List data \n\n");
        printf("\t3)Add at Beg\n\n");
        printf("\t4)Add at end\n\n");
        printf("\t5)delete first\n\n");
        printf("\t6)Delete last\n\n");
        printf("\t7)delete at postion\n\n");
        printf("\t8)Reverse the list\n\n");
        printf("\t9)Exit\n\n");

        printf("Enter the choice   : ");
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
            exit(1);
        default :
            printf("Enter the valid number\n");


        }
        printf("-------------------------------\n");



 return 0;

}

int  Del_beg()
{
    struct node *temp;

    if(head==NULL)
        printf("List is empty");
    else{

    temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    }
    return 0;
}

int  Del_last()
{
    struct node* ptr;
    ptr=head;
    if(head->next==NULL){
         free(head);
         head=NULL;
    }
    else if(head==NULL)
    {
        printf("List is empty");

    }


   else{
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
   }
  return 0;

}

int  Del_at_pos(int pos)
{
    struct node* ptr,*ptr2,*temp;
    int count=0;

    ptr=head;
    ptr2=head;

    while(ptr2!=NULL)
    {
        count++;
        ptr2=ptr2->next;

    }


    if(pos>count){
        printf("List is not that big\n");
        printf("size of list is %d\n",count);
    }
    else if(head==NULL)
        printf("List is empty");
    else if(pos==1)
    {
        Del_beg();
    }


    else{


    while(pos>2)
    {
        ptr=ptr->next;
        pos--;

    }
    /*
    ptr->next=ptr->next->next;
    free(ptr->next);*/

    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    temp=NULL;

    }
  return 0;
}

int  reverse()
{
    struct node* temp=NULL,*temp2=NULL;

    while(head!=NULL)
    {


    temp2=head->next;
    head->next=temp;
    temp=head;
    head=temp2;
    }
    head=temp;
   return 0;

}
