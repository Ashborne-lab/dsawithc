#include<stdio.h>
#include<stdlib.h>

int partition(int arr[],int s,int e){

    int pivot=arr[s];
    int count=0;
  
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot)count++;
    }
    int pivotindex=s+count;
    int temp=arr[s];
   arr[s]=arr[pivotindex];
   arr[pivotindex]=temp;
 
    int i=s,j=e;
    while(i<pivotindex&&j>pivotindex){

        while(arr[i]< pivot)i++;
        while(arr[j]>pivot)j--;
        if(i<pivotindex&&j>pivotindex){
            int temp1=arr[i];
            arr[i]=arr[j];
            arr[j]=temp1;
            i++;j--;
        }
    }
return pivotindex;
}


void quicksort(int arr[],int s,int e){
 
 if(s>=e)return;
 int p=partition(arr,s,e);
  quicksort(arr,s,p-1);
  quicksort(arr,p+1,e);

}

int main(){
 int arr[5]={2,4,1,6,9};
 int n=5;
quicksort(arr,0,n-1);
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}
    return 0;
}