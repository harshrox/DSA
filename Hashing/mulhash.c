// Hashing though multiplication

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void mulHash(int hash[],int slots)
{
	int result,key;
    double A=(sqrt(5)-1)/2;
	printf("Enter the key value-");
	scanf("%d",&key);
	result = floor(slots*((key*A)-(int)(key*A)));
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
				mulHash(hash,slots);
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
