// Stack implementation using array
#include<stdio.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFUll()
{
    return top == MAX_SIZE-1;
}

void push(int element)
{
    if(isFUll())
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

int pop()
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

void peek()
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

void display()
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
    push(2);
    push(8);
    push(4);
    push(7);
    push(11);
    push(9);
    peek();
    printf("%d popped from the stack\n",pop());
    display();
    return 0;
}
