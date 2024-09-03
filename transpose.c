#include<stdio.h>
void print_matrix(int matr[][3]);
void trans_matrix(int matr[][3]);
void rotate_matrix(int matr[][3]);
int main(int argc, char const *argv[])
{
    
    int arr[3][3]={{1,2,3},
                   {4,5,6},
                   {7,8,9}};
    
print_matrix(arr);
printf("\n");
trans_matrix(arr);
printf("\n");
rotate_matrix(arr);


    return 0;
}
void print_matrix(int matr[][3]){
for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",matr[i][j]);
        }
        printf("\n");
    }
}
void trans_matrix(int matr[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",matr[j][i]);
        }
        printf("\n");
    }
}
void rotate_matrix(int matr[][3]){
    for(int i=0;i<3;i++){
        for(int j=2;j>=0;j--){
            printf("%d ",matr[j][i]);
        }
        printf("\n");
    }
}