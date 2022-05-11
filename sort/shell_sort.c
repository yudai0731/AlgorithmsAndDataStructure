#include<stdio.h>

void print_array(int A[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void insertion_sort(int A[],int N,int g){
    /* 挿入ソート(昇順) g個飛ばし*/
    int i,j,v;
    for(i=g; i<N; i++){
        v = A[i];
        j = i-g;
        while((j>=0)&&(A[j]>v)){
            A[j+g] = A[j]; // 1つ後ろにずらす
            j-=g;
        }
        A[j+g] = v;
        print_array(A,N);
    }

}

void shell_sort(int A[],int N){
    int i;
    int m = 4;
    int G[] = {4,3,1};

    for(i=0;i<m;i++){
        insertion_sort(A,N,G[i]);
    }
}

int main(void){
    int N=10;
    int A[] = {4,8,9,1,10,6,2,5,3,7};
    print_array(A,N);
    shell_sort(A,N);
    return 0;
}