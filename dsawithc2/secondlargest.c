#include<stdio.h>
void findsecondlargest(int arr[],int size){
    int largest=-1;
    int secondlargest=-1;
    for(int i=0;i<size;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
     for(int i=0;i<size;i++){
        if(arr[i]>secondlargest && arr[i]!=largest){
            secondlargest=arr[i];
        }
    }
    printf("Secondlargest in array is (%d)",secondlargest);
}
int main(int argc, char const *argv[])
{ 
    int arr[6]={5,6,8,7,9,10};
    findsecondlargest(arr,6);
    return 0;
}
