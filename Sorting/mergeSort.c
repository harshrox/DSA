// Merge Sort

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int arr[],int p,int q,int r){
    int n1=q-p+1 , n2=r-q;
    int *left=(int *)malloc((n1+1)*sizeof(int));
    int *right=(int *)malloc((n2+1)*sizeof(int));

    for(int i=0;i<n1;i++){
        left[i]=arr[p+i];
    }

    for(int j=0;j<n2;j++){
        right[j]=arr[q+j+1];
    }
    left[n1]=9999;
    right[n2]=9999;

    int i=0;
    int j=0;

    for(int k=p;k<=r;k++){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
    }

}

void mergeSort(int arr[],int p,int r){
    int q;
    if(p<r){
        q=floor((p+r)/2);
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
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
    mergeSort(arr,p,r);
    display(arr,len);
    return 0;
}