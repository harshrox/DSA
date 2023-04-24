// Stack implementation using array (advanced version)
#include<stdio.h>
#include<stdlib.h>


int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull(int len)
{
    return top == len-1;
}

void push(int stack[],int len)
{
    int element;
    printf("Enter the element to push-");
    scanf("%d",&element);
    if(isFull(len))
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = element;
        printf("%d pushed into the stack\n",element);
    }
}

int pop(int stack[])
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        return 0;
    }
    else
    {
        int popped = stack[top];
        top--;
        return popped;
    }
}


void peek(int stack[])
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
        
    }
    else
    {
        printf("Peeked value- %d\n",stack[top]);
    }
}

void display(int stack[])
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack-> ");
        for(int i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);

        }
        printf("\n");
    }
}


int main()
{
    int len,ch;
    char choice='n';
    printf("Enter the length of stack-");
    scanf("%d",&len);
    int *stack = (int*)malloc(len*sizeof(int));
    
    do
    {
        
        printf("\nWhich operation do you want to perform-");
        printf("\n1 to push");
        printf("\n2 to pop");
        printf("\n3 to check if the stack is full");
        printf("\n4 to check if the stack is empty");
        printf("\n5 to check the topmost element");
        printf("\n6 to display the stack");
        printf("\n7 to exit");
        printf("\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n");
                push(stack,len);
                break;
            case 2:
                printf("\n");
                pop(stack);
                break;
            case 3:
                printf("\n");
                printf("%d",isFull(len));
                break;
            case 4:
                printf("\n");
                printf("%d",isEmpty());
                break;
            case 5:
                printf("\n");
                peek(stack);
                break;
            case 6:
                printf("\n");
                display(stack);
                break;
            case 7:
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
