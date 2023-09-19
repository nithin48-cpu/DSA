#include<stdio.h>
struct node{
struct node *prev;
int data;
struct node *next;
};

struct node *tail;

int main()
{
    int data;

    /*
    tail=AddAtempty(12);
    AddAtend(10);
    tail=AddAtbeg(19);
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
    newNode->prev=newNode;
    newNode->data=data;
    newNode->next=newNode;
    tail=newNode;
    printf("Created a Node Successfully\n");


}

AddAtend(int data)
{
    struct node* newNode,*ptr=tail,*temp;

    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;                        //In case if we want use 2 nexted list then we have to pass tail pointer to function then it work to that nexted list;

    temp=tail->next;

    newNode->prev=tail;
    newNode->next=temp;

    tail->next=newNode;
    temp->prev=newNode;

    tail=newNode;



}


AddAtbeg(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;

    newNode->prev=tail;
    newNode->next=tail->next;

    tail->next->prev=newNode;
    tail->next=newNode;





}
print()
{
    struct node* ptr;
    if(tail==NULL)
        printf("Circluar List Is Empty\n");
    else{
        ptr=tail->next;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
    printf("\n");
    }

}

AddAtpos(int pos,int data)
{

    /*
    for(int i=0;i<pos-2;i++)    //we can also use (i=2 ;i<pos;i++)
        ptr=ptr->next;
    */
    struct node* ptr,*ptr2,*temp;
    int count=0;

    ptr=tail->next;
    ptr2=tail->next;

    do
    {
        count++;
        ptr2=ptr2->next;

    }while(ptr2!=tail->next);


    if(pos>count){
        printf("List is not that big\n");
        printf("size of list is %d\n",count);
    }
    else if(tail==NULL)
        printf("List is empty");
    else if(pos==1)
        AddAtbeg(data);
    else if(pos==count)
            AddAtend(data);
    else if(pos==0)
        return;
    else{
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

    ptr->next->prev=newNode;
    ptr->next=newNode;
    }


}

AddAfterpos(int pos,int data)
{
     struct node* ptr;
     ptr=tail->next;

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

    ptr->next->prev=newNode;
    ptr->next=newNode;

}

AddBeforpos(int pos,int data)
{
    struct node* ptr;
    ptr=tail->next;

    /*for(int i=0;i<pos-3;i++)
        ptr=ptr->next;*/

    while(pos>3)
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

    ptr->next->prev=newNode;
    ptr->next=newNode;



}

create()
{
    int num,data,pos;

    while(1)
    {
        printf("1)Print All Data In nexted List \n");
        printf("2)To Create New Circular Linked List data \n");
        printf("3)Add at Beg\n");
        printf("4)Add at end\n");
        printf("5)delete first\n");
        printf("6)Delete last\n");
        printf("7)Add at position \n");
        printf("8)delete at postion\n");
        printf("9)Reverse the list\n");
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
            printf("Enter the position and data you want add  : ");
            scanf("%d %d",&pos,&data);
            AddAtpos(pos,data);
            break;
        case 8:
            printf("Enter the position you want to delete : ");
            scanf("%d",&data);
            Del_at_pos(data);
            break;

        case 9:
            reverse();
            break;

        case 10:
            exit(1);
        default :
            printf("Enter the valid number\n");


        }
        printf("-------------------------------\n");

    }


}

Del_beg()
{
    struct node *temp;

    if(tail==NULL)
        printf("List is empty");
    else if(tail->next==tail){
        free(tail);
        tail=NULL;
    }
    else{

    temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    }
}

Del_last()
{
    struct node* ptr,*temp;


    if(tail==NULL)
        printf("List is empty");
    else if(tail->next==tail){
         free(tail);
         tail=NULL;
    }
    else
    {
        ptr=tail->next;
        temp=tail->next;
        while(ptr->next!=tail)
        {
              ptr=ptr->next;
        }

        free(tail);
        tail=ptr;
        tail->next=temp;
    }

}

Del_at_pos(int pos)
{
    struct node* ptr,*ptr2,*temp;
    int count=0;

    ptr=tail->next;
    ptr2=tail->next;

    do
    {
        count++;
        ptr2=ptr2->next;

    }while(ptr2!=tail->next);


    if(pos>count){
        printf("List is not that big\n");
        printf("size of list is %d\n",count);
    }
    else if(tail==NULL)
        printf("List is empty");
    else if(pos==1)
        Del_beg();
    else if(pos==count)
            Del_last();
    else if(pos==0)
        return;
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

}

reverse()
{
    struct node *ptr;
    ptr=tail;

    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }while(ptr!=tail);
    printf("\n");



}
