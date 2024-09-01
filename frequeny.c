#include<stdio.h>

#define SIZE 10

void input_arr(int a[], int n, int MAX);
int LinearSerachV1(int a[], int n, int p, int MAX);
int frequency_array(int a[], int n, int element);

int main() {
    int arr[SIZE], n, p, element;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    if (n > SIZE) {
        printf("Number of elements exceeds the maximum size of the array.\n");
        return 1;
    }
    
    printf("Enter the element to find its frequency: ");
    scanf("%d", &element);
    
    input_arr(arr, n, SIZE);
    
    printf("Enter the value to be searched in the array: ");
    scanf("%d", &p);
    
    int pos = LinearSerachV1(arr, n, p, SIZE);
    
    if (pos == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at position %d.\n", pos + 1); // Adding 1 to make it 1-based index
    }
    
    int count = frequency_array(arr, n, element);
    printf("Count of element %d is %d.\n", element, count);
    
    return 0;
}

void input_arr(int a[], int n, int MAX) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

int LinearSerachV1(int a[], int n, int p, int MAX) {
    for (int i = 0; i < n; ++i) {
        if (p == a[i]) {
            return i;
        }
    }
    return -1;
}

int frequency_array(int a[], int n, int element) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == element) {
            count++;
        }
    }
    return count;
}
