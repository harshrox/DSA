// Quadratic Probing

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void quadraticProb(int hash[],int slots,int c1,int c2)
{
	int result,key;
	printf("Enter the key value-");
	scanf("%d",&key);
	for(int i=0;i<slots;i++)
    {
        result = (int)(key%slots + i*c1 + c2*pow(i,2))%slots;
        if(hash[result]==-1)
        {
            hash[result]=key;
            break;

        }
        else
        {
            continue;
        }

    }
	
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
	int slots,c1,c2,ch;
	char choice='n';
	
	printf("Enter the number of slots-");
	scanf("%d",&slots);
    printf("Enter the value of c1-");
    scanf("%d",&c1);
    printf("Enter the value of c2-");
    scanf("%d",&c2);
	
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
				quadraticProb(hash,slots,c1,c2);
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
