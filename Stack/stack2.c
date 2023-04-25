// Stack implementation using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
}*top=NULL;

int isEmpty(){
    return top==NULL;
}

void push(){

    int element;
    printf("Enter the element to push-");
    scanf("%d",&element);
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(top==NULL){
        newnode->data=element;
        newnode->next=NULL;
        top=newnode;
    }
    else{
        newnode->data=element;
        newnode->next=top;
        top=newnode;
    }
}

int pop(){
    int q;
    if(top==NULL){
        printf("Stack underflow\n");
        return 0;
    }
    else{
        q=top->data;
        top=top->next;
        return q;
    }
}

void display()
{

    struct node *p;
    
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        p=top;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;

        }
    }
}


int main(){
    int ch;
    char choice='n';
    do
    {
        
        printf("\nWhich operation do you want to perform-");
        printf("\n1 to push");
        printf("\n2 to pop");
        printf("\n3 to check if the stack is empty");
        printf("\n4 to display the stack");
        printf("\n5 to exit");
        printf("\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n");
                push();
                break;
            case 2:
                printf("\n");
                pop();
                break;
            case 3:
                printf("\n");
                printf("%d",isEmpty());
                break;
            case 4:
                printf("\n");
                display();
                break;
            case 5:
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