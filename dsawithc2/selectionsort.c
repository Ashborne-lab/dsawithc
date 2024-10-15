#include<stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if (arr[j]<arr[min_idx]){
                min_idx=j;
               
            }
        }
         swap(&arr[min_idx],&arr[i]);
    }
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
int main(int argc, char const *argv[])
{
    int arr[5]={0,1,2,5,4};
    selectionsort(arr,5);
    printarr(arr,5);
    return 0;
}
