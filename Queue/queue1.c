#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1;
void insert(int queue[], int *front, int *rear, int maxQ, int item)
{
    if ((*front == 0 && *rear == maxQ - 1) || (*front == *rear + 1))
    {
        printf("Overflow\n");
    }
    else
    {
        if (*front == -1)
        {
            *front = 0;
            *rear = 0;
        }
        else if (*rear == maxQ - 1)
        {
            *rear = 0;
        }
        else
        {
            *rear = *rear + 1;
        }
        queue[*rear] = item;
    }
}


void delete(int queue[],int *front,int *rear,int maxQ)
{
    int item;
    if(*front==-1)
    {
        printf("Underflow\n");
        
    }
    else
    {
        item=queue[*front];
        if(*front==*rear)
        {
            *front=-1;
        }
        else if(*front==maxQ)
        {
            *front=0;
        }
        else
        {
            *front=*front+1;
        }
        printf("Deleted item-%d \n",item);

    }
    
}
void display(int queue[],int *front,int *rear)
{
    if(*front==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Queue: ");
        for(int i=*front;i<=*rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int len,ch,num;
    char choice='n';
    printf("Enter the length of queue-");
    scanf("%d",&len);
    int *queue = (int*)malloc(len*sizeof(int));
    
    do
    {
        
        printf("\nWhich operation do you want to perform-");
        printf("\n1 to insert");
        printf("\n2 to delete");
        printf("\n3 to display the queue");
        printf("\n4 to exit");
        printf("\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n");
                printf("Enter element-");
                scanf("%d",&num);
                insert(queue,&front,&rear,len,num);
                break;
            case 2:
                printf("\n");
                delete(queue,&front,&rear,len);
                break;
            case 3:
                printf("\n");
                display(queue,&front,&rear);
                break;
            case 4:
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
