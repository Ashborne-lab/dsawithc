#include<stdio.h>
void input_matrix(int arr[][100],int rows,int columns){
for (int i=0;i<rows;i++){
    for (int j=0;j<columns;j++){
        scanf("%d",&arr[i][j]);
    }
}
}
int main(){
    int r1,c1;
    printf("Enter rwoes and columns for the matrix: ");
    scanf("%d%d",&r1,&c1);
    int arr[r1][c1];
    input_matrix(arr,r1,c1);
    return 0;
}