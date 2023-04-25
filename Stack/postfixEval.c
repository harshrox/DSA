// Postfix Evaluation using stack

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

void push(int stack[],int len,int element)
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

int main()
{
    int i=0,len=50,operand1,operand2,result,flag=1;
    char expression[50];
    int *stack = (int *)malloc(len*sizeof(int));
    printf("Enter the expression (use only +,-,*,/ and ^)-");
    scanf("%s",expression);
    while(expression[i]!='\0')
    {
        if(isdigit(expression[i]))
        {
            push(stack,len,(expression[i]-'0'));
        }
        else
        {
            operand1=pop(stack);
            operand2=pop(stack);
            flag=operand2;
            if(expression[i]=='+')
            {
                result=operand2+operand1;
                push(stack,len,result);
            }
            else if(expression[i]=='-')
            {
                result=operand2-operand1;
                push(stack,len,result);
            }
            else if(expression[i]=='*')
            {
                result=operand2*operand1;
                push(stack,len,result);
            }
            else if(expression[i]=='/')
            {
                result=operand2/operand1;
                push(stack,len,result);    
            }
            else if(expression[i]=='^')
            {
                result=pow(operand2,operand1);
                push(stack,len,result);    
            }
            else
            {
                flag=0;
                break;
            }
        }
        i++;
    }
    if(!flag)
    {
        printf("Incorrect expression\n");
        printf("Process terminated\n");
    }
    else
    {
        printf("Result: %d",pop(stack));
    }
    

    return 0;
}