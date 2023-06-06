// Hashing though division

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*start=NULL;

void divHash(int hash[],int slots)
{
	struct node *newnode,*p;
	int key,result;
	printf("Enter the key value-");
	scanf("%d",&key);
	result = (key)%(slots);
	// if(hash[result]==key)
	// {
	// 	if(start==NULL)
	// 	{
	// 		start=newnode;
	// 		start->data=hash[result];
	// 		hash[result]=start;
	// 	}
	// 	else
	// 	{
	// 	        p=start;
	// 	        while(p->next!=NULL)
	// 	        {
	// 	                p=p->next;
	// 	        }
	// 	        p->next=newnode;
		
	// 	}
	
	
	
		
	// }
	// else
	// {
	// 	hash[result]=key;
	// }
	hash[result]=key;
	
}

void display(int hash[],int slots)
{
	for(int i=0;i<slots;i++)
	{
		if(hash[i]!=-1)
		{
			printf("hash[%d] = %d\n",i,hash[i]);
		}
	
	}

}

int main()
{
	int slots,ch;
	char choice='n';
	
	printf("Enter the number of slots-");
	scanf("%d",&slots);
	
	int *hash = (int*)malloc(slots*sizeof(int));
	for(int i=0;i<slots;i++)
	{
		hash[i]=-1;
	}
	do
    {
        
		printf("\n1 to put data in hash table");
		printf("\n2 to view hash table");
		printf("\n3 to exit");
		printf("\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				divHash(hash,slots);
				break;
			case 2:
				display(hash,slots);
				break;
			case 3:
				choice='y';
				break;
			default:
				printf("\n");
				printf("Wrong input\n");
				break;
				
		
		}
        
    } while (choice=='n' || choice=='N');

}
