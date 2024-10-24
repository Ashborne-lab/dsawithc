#include<stdio.h>
void insertelement(int arr[],int *size,int idx,int val){
    for(int i=*size;i>=idx;i--){
         arr[i]=arr[i-1];
        
    }
     arr[idx]=val;
    (*size)++;
}
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d \t",arr[i]);
    }
}
int main(int argc, char const *argv[])
{int size=5;
    int arr[size];
    printf("Enter your array");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("After insertng element in the array\n");
    insertelement(arr,&size,3,4);
    printf("%d\n",size);
    printarray(arr,size);
    return 0;
}
