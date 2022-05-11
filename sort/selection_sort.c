#include<stdio.h>

void print_array(int A[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void selection_sort(int A[],int N){
    int i,j,minj,tmp;
    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        tmp=A[i];
        A[i]=A[minj];
        A[minj]=tmp;

        print_array(A,N);
    }
}

int main(void){
    int N=6;
    int A[6] = {3,5,2,7,1,8};
    print_array(A,N);
    selection_sort(A,N);
    return 0;
}