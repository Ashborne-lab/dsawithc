#include<stdio.h>

#define SIZE 10

void input_arr(int a[], int n);
void print_arr(int a[], int n);
void insert_element(int a[], int *n, int pos, int p);
void delete_element(int a[],int *n,int p);

int main() {
    int arr[SIZE], n, pos, p;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    if (n > SIZE) {
        printf("Number of elements exceeds the maximum size of the array.\n");
        return 1;
    }
    
    input_arr(arr, n);
    
    printf("Enter the position where you want to insert the element (1-based index): ");
    scanf("%d", &pos);
    
    if (pos < 1 || pos > n) {
        printf("Invalid position.\n");
        return 1;
    }
    
    printf("Enter the element to insert: ");
    scanf("%d", &p);
    
    insert_element(arr, &n, pos, p);
    print_arr(arr,n);
    int k;
    printf("Enter the position of element you want to delete: ");
    scanf("%d",&k);
    delete_element(arr,&n,k);

    print_arr(arr, n);

    return 0;
}

void input_arr(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void print_arr(int a[], int n) {
    printf("Array elements:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert_element(int a[], int *n, int pos, int p) {
    // Converting from 1-based index to 0-based index for the array
    pos = pos - 1;
    a[pos] = p;
}
void  delete_element(int a[], int *n,int p) {
    // Converting from 1-based index to 0-based index for the array
  if(p<1 || p> *n){
    printf("Invalid position");
  }
  else{
     for(int i=p-1;i<*n-1;i++){
    a[i]=a[i+1];
   }
   *n=*n-1;
  }
  
}
