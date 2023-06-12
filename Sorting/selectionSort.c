// Selection Sort

#include<stdio.h>
#include<stdlib.h>

void selectionSort(int arr[],int len)
{
    int min;
    for(int i=0;i<=(len-2);i++)
    {
        min=i;
        for(int j=i+1;j<=(len-1);j++)
        {

            if(arr[j]<arr[min])
            {

                min=j;
            }
        }
        if(i!=min)
        {
            int temp = arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }


    }


}

void display(int arr[],int len)
{   
    printf("Sorted Array-");
    for(int i=0;i<len;i++)
    {

        printf("%d ",arr[i]);
    }
    printf("\n");

}

int main()
{
    int len;
    printf("Enter the array length-");
    scanf("%d",&len);
    int *arr=(int *)malloc(len*sizeof(int));
    for(int i=0;i<len;i++)
    {

        printf("Enter element number %d-> ",i+1);
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,len);
    display(arr,len);
    return 0;
}