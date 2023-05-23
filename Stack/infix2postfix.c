#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull(int len)
{
    return top == len-1;
}

void push(char stack[],int len,char element)
{
    if(isFull(len))
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = element;
        
    }
}

char pop(char stack[])
{
    if(isEmpty())
    {
        printf("Stack underflow\n");
        return 0;
    }
    else
    {
        char popped = stack[top];
        top--;
        return popped;
    }
}

void display(char stack[])
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
            printf("%c ",stack[i]);

        }
        printf("\n");
    }
}
int operatorCheck(char stack[])
{
    char arr[5]={'+','-','*','/','^'};
    for(int i=0;i<5;i++)
    {
        if(arr[i]==stack[top])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int precedence(char stack[],char exp)
{

        

}

int main()
{
    int len=50,i=0;
    char expression[50],temp;
    char *stackCon = (char *)malloc(len*sizeof(char));
    char *stackExp = (char *)malloc(len*sizeof(char));
    printf("Enter the expression (use only +,-,*,/ and ^)-");
    scanf("%s",expression);
    push(stackCon,50,'(');
    display(stackCon);
    while(expression[i]!='\0')
    {
        if(isdigit(expression[i]))
        {
            push(stackExp,len,expression[i]);
        }
        else if(expression[i]=='(')
        {
            push(stackCon,len,'(');
        }
        else if(expression==')')
        {   
            temp=pop(stackCon);
            while(temp!='(')
            {
                push(stackExp,len,temp);
                temp=pop(stackCon);
            }
        }
        else
        {
            if(operator(stackCon))
            {

            }
            else
            {
                push(stackCon,len,expression[i]);
            }
        }
    }

    return 0;
}