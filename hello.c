#include<stdio.h>
#define SIZE 10
void input_arr(int a[], int n, int MAX);
int LinearSerachV1(int a[], int n, int p, int MAX);
int frequency_array(int a[],int n,int element);
int main()
{
	int arr[SIZE],n,p;
	printf ("Enter no. of element in Array:");
	scanf ("%d",&n);
	
	input_arr(arr, n, SIZE);
	
	printf ("Enter value to be searched in Array:");
	scanf ("%d",&p);
	
	int pos=LinearSerachV1(arr, n, p, SIZE);
	
	if (pos==-1)
		printf("Element not found");
	else{
		printf("Element found at %d\n", pos);
    }
	int element;
	printf("Enter the element you want to search it's count : ");
	scanf("%d",&element);
        int count= frequency_array( arr, n, element);
		if(count==0){
			printf("Not found");
		}
		else{
        printf("Count is %d",count);
		}
	return 0;
}
void input_arr(int a[], int n, int MAX){
	int i;
	if (n>MAX){
        printf("You have exceeded the limit:)");
    }
	for (i=0;i<=n-1;++i)
	{
		printf ("Enter arr[%d]:", i);
		scanf ("%d",&a[i]);
	}
}

int LinearSerachV1(int a[], int n, int p, int MAX){
	int i;
	for (i=0;i<=n-1;++i)
	{
		if (p==a[i])
		return i;
	}
	return -1;

}
int frequency_array(int a[],int n,int element){
    int count=0;
    for (int i=0;i<n;i++){
        if(a[i]==element){
            count++;
        }

    }
    return count;
}