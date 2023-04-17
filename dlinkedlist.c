#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

}*start=NULL;


void create()
{
    struct Node *newnode,*p;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data-");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(start==NULL)
    {
        start=newnode;
           
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;

        }
        p->next=newnode;
        newnode->prev=p;
    }

}

void display()
{

    struct Node *p;
    
    if(start==NULL)
    {
        printf("No node in the linked list");
    }
    else
    {
        p=start;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;

        }
    }
}

void insertPosition()
{
    int i,k;
    struct Node *newnode,*p;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the data for new node-");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Enter the position after which you want to insert the newnode-");
    scanf("%d",&k);
    p=start;
    for(i=0;i<k-1;i++)
    {
        p=p->next;
    }
    newnode->next=p->next;
    p->next=newnode;
    newnode->prev=p;
}

void insertAfterValue()
{
    int k;
    struct Node *newnode,*p;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the data for new node-");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Enter the value after which you want to insert the newnode-");
    scanf("%d",&k);
    p=start;
    while(p->next!=NULL)
    {
        if(p->data==k)
        {
            break;
        }
        p=p->next;
    }
    newnode->next=p->next;
    p->next=newnode;
    newnode->prev=p;
}

void insertAtBeginning()
{
    
    struct Node *newnode;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the data for new node-");
    scanf("%d",&newnode->data);
    
    newnode->next=start;
    newnode->prev=NULL;
    start=newnode;

}

void deletePosition()
{
    int i,k;
    struct Node *p,*q;
    printf("Enter the position after which you want to delete the node-");
    scanf("%d",&k);
    p=start;
    for(i=0;i<k-1;i++)
    {
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    q->next->prev=p;
    q->next=NULL;
    free(q);
}

void deleteLastNode()
{
    
    struct Node *p;
    p=start;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    p->next=NULL;
}

void deleteFirstNode()
{
    struct Node *p;
    p=start;
    start=p->next;
    start->prev=NULL;
    p=start;
}

void midTerm()
{
    struct Node *p,*q;
    p=start;
    q=start;
    while (p->next!=NULL)
    {
        p=p->next->next;
        q=q->next;
    }
    printf("%d",q->data);
    
}

void linearSearch()
{
    int num,flag=0;
    struct Node *p;
    p=start;
    printf("Enter the number to be searched-");
    scanf("%d",&num);
    while (p!=NULL)
    {
        if(p->data==num)
        {
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==1)
    {
        printf("%d exists in the linked list\n",num);
    }
    else
    {
        printf("%d does not exist in the linked list\n",num);
    }
}

void sort()
{   
    int temp,flag=1;
    struct Node *p,*q=NULL;
    while(flag==1)
    {   
        p=start;
        flag=0;
        while(p->next!=q)
        {
            if(p->data > p->next->data)
            {
                p->data=(p->data)^(p->next->data);
                p->next->data=(p->data)^(p->next->data);
                p->data=(p->data)^(p->next->data);

                flag=1;
            }
            p=p->next;
        }
        q=p;
    }
}

void reverse()
{
    struct Node *p=NULL,*q=NULL;
    while(start!=NULL)
    {
        q=start->next;
        start->next=p;
        p=start;
        start=q;
    }
    start=p;
}

int main()
{
    int ch;
    char choice='n';
    do
    {
        
        printf("\nWhich operation do you want to perform-");
        printf("\n1 to create");
        printf("\n2 to display");
        printf("\n3 to insert after position");
        printf("\n4 to insert after value");
        printf("\n5 to insert at beginning");
        printf("\n6 to delete after position");
        printf("\n7 to delete last node");
        printf("\n8 to delete first node");
        printf("\n9 to find the mid-term");
        printf("\n10 to perform a linear search");
        printf("\n11 to sort the linked list");
        printf("\n12 to reverse the linked list");
        printf("\n13 to exit");
        printf("\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n");
                create();
                break;
            case 2:
                printf("\n");
                display();
                break;
            case 3:
                printf("\n");
                insertPosition();
                break;
            case 4:
                printf("\n");
                insertAfterValue();
                break;
            case 5:
                printf("\n");
                insertAtBeginning();
                break;
            case 6:
                printf("\n");
                deletePosition();
                break;
            case 7:
                printf("\n");
                deleteLastNode();
                break;
            case 8:
                printf("\n");
                deleteFirstNode();
                break;
            case 9:
                printf("\n");
                midTerm();
                break;
            case 10:
                printf("\n");
                linearSearch();
                break;
            case 11:
                printf("\n");
                sort();
                break;
            case 12:
                printf("\n");
                reverse();
                break;
            case 13:
                choice='y';
                break;
            default:
                printf("\n");
                printf("Wrong Input");
                break;
        }
        
    } while (choice=='n' || choice=='N');
    
    return 0;
}