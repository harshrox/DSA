// Insertion Sort

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[],int len)
{
    int key,i;
    for(int j=1;j<len;j++){
        key=arr[j];
        i=j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;

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
    insertionSort(arr,len);
    display(arr,len);
    return 0;
}