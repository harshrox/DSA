// Bubble Sort

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[],int len)
{
    int flag;
    for(int i=0;i<len;i++){
        flag=0;
        for(int j=0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                int num=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=num;
                flag=1;
            }
        }
        if(flag==0){
            break;
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
    bubbleSort(arr,len);
    display(arr,len);
    return 0;
}