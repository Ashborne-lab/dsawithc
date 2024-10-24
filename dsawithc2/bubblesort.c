#include<stdio.h>
void bubblesort(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1])
{
    int temp=arr[j];
         arr[j]=arr[j+1];
         arr[j+1]=temp;
}       
 }
    }
     for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
  }
}

   

int main(int argc, char const *argv[])
{
    int arr[5]={0,1,2,5,4};
  bubblesort(arr,5);
   
    return 0;
}