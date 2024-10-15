#include<stdio.h>
void deletelement(int arr[],int *size,int indx){
    for(int i=indx;i< *size;i++){
        arr[i]=arr[i+1];
       
    }
     (*size)--;
}
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);

    }
}
int main(int argc, char const *argv[])
{
    int n ;
    int arr[ ]={1,2,3,4,5};
    n=sizeof(arr)/sizeof(arr[0]);
   printf("%d\n",n);
    int delete_indx;
    printf("Enter the the 0-based index you wanted to delete :\n");
    scanf("%d",&delete_indx);
    deletelement(arr,&n,delete_indx);
    printf("%d",n);
    printarray(arr,n);

    return 0;
}
