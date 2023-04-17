#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coeff;
    int power;
    struct Node *next;

}*start1=NULL,*start2=NULL,*start3=NULL,*start4=NULL;

void create()
{
    struct Node *newnode1,*newnode2,*p,*q;
    int num;
    printf("Enter the highest degree-");
    scanf("%d",&num);
    for(int i=0;i<=num;i++){
        printf("FOR POLYNOMIAL 1\n");
        newnode1=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the power in decreasing order-\n");
        scanf("%d",&newnode1->power);
        printf("Enter the coefficient-");
        scanf("%d",&newnode1->coeff);
        newnode1->next=NULL;
        if(start1==NULL)
        {
            start1=newnode1;
        }
        else
        {
            p=start1;
            while(p->next!=NULL)
            {
                p=p->next;

            }
            p->next=newnode1;
        }
        
    }
    for(int i=0;i<=num;i++){
        printf("FOR POLYNOMIAL 2\n");
        newnode2=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the power in decreasing order-\n");
        scanf("%d",&newnode2->power);
        printf("Enter the coefficient-");
        scanf("%d",&newnode2->coeff);
        newnode2->next=NULL;
        if(start2==NULL)
        {
            start2=newnode2;
        }
        else
        {
            q=start2;
            while(q->next!=NULL)
            {
                q=q->next;

            }
            q->next=newnode2;
        }
        

    }
}

void display()
{

    struct Node *p,*q,*r,*s;
    
    if(start1==NULL && start2==NULL)
    {
        printf("No node in the linked list");
    }
    else
    {
        p=start1;
        q=start2;
        r=start3;
        s=start4;
        printf("\n");
        printf("Polynomial 1->");
        while(p!=NULL)
        {
            printf("%dx^%d + ",p->coeff,p->power);
            p=p->next;

        }
        printf("0");
        printf("\n");
        printf("Polynomial 2->");
        while(q!=NULL)
        {
            printf("%dx^%d + ",q->coeff,q->power);
            q=q->next;

        }
        printf("0");
        printf("\n");
        printf("Sum->");
        while(r!=NULL)
        {
            
            printf("%dx^%d + ",r->coeff,r->power);
            r=r->next;
        }
        printf("0");
        printf("\n");
        printf("Product->");
        while(s!=NULL)
        {
            
            printf("%dx^%d + ",s->coeff,s->power);
            s=s->next;
        }
        printf("0");


    }
}

void add()
{
    struct Node *newnode3,*p,*q,*r;
    p=start1;
    q=start2;
    newnode3=(struct Node *)malloc(sizeof(struct Node));
    newnode3->coeff=p->coeff+q->coeff;
    newnode3->power=p->power;
    newnode3->next=NULL;
    start3=newnode3;
    p=p->next;
    q=q->next;
    r=start3;
    while(p!=NULL){
        newnode3=(struct Node *)malloc(sizeof(struct Node));
        newnode3->coeff=p->coeff+q->coeff;
        newnode3->power=p->power;
        newnode3->next=NULL;
        r->next=newnode3;
        p=p->next;
        q=q->next;
        r=r->next;
    }


}

void mul()
{
    struct Node *newnode4,*p,*q,*s;
    p=start1;
    q=start2;
    newnode4=(struct Node *)malloc(sizeof(struct Node));
    newnode4->coeff=(p->coeff)*(q->coeff);
    newnode4->power=p->power+q->power;
    newnode4->next=NULL;
    start4=newnode4;
    p=p->next;
    q=q->next;
    s=start4;
    while(p!=NULL){
        newnode4=(struct Node *)malloc(sizeof(struct Node));
        newnode4->coeff=(p->coeff)*(q->coeff);
        newnode4->power=(p->power)+(q->power);
        newnode4->next=NULL;
        s->next=newnode4;
        p=p->next;
        q=q->next;
        s=s->next;
    }


}


int main()
{
    create();
    add();
    mul();
    display();
    return 0;
}