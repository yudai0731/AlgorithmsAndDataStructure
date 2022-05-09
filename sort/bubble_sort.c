#include<stdio.h>

void print_array(int A[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void bubble_sort(int A[],int N){
    int j,tmp;
    int flg=1;
    while(flg){
        flg=0;
        for(j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flg=1;
            }
        }
        print_array(A,N);
    }
}

int main(void){
    int N=6;
    int A[6] = {3,5,2,7,1,8};
    print_array(A,N);
    bubble_sort(A,N);
    return 0;
}