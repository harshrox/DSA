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

void push(int element){

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
    push(5);
    push(3);
    push(8);
    display();
    printf("\n");
    printf("\n");
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    display();
    return 0;
}