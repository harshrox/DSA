// Quick Sort

#include<stdio.h>
#include<stdlib.h>

int partition(int arr[],int p,int q){
    int x=arr[p];  // Pivot=arr[p]
    int i=p;

    for(int j=p+1;j<=q;j++){
        if(arr[j]<=x){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }
    }
    
    int temp = arr[p];
    arr[p] = arr[i];
    arr[i] = temp;

    return i;

}


void quickSort(int arr[],int p,int r){
    if(p<r){
        int q=partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
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
    int p=0,r=len-1;
    quickSort(arr,p,r);
    display(arr,len);
    return 0;
}