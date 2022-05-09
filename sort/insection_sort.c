#include<stdio.h>

void print_array(int A[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void insection_sort(int A[],int N){
    /* 挿入ソート(昇順) A:数字の配列,N:配列長*/
    int i,j,v;
    // i : 未整列の位置
    // j : 注目しているインデックス
    // v : A[i]
    for(i=0; i<N; i++){
        v = A[i];
        j = i-1;
        while((j>=0)&&(A[j]>v)){
            A[j+1] = A[j]; // 1つ後ろにずらす
            j--;
        }
        A[j+1] = v;
        print_array(A,N);
    }

}

int main(void){
    int N=6;
    int A[6] = {3,5,2,7,1,8};
    print_array(A,N);
    insection_sort(A,N);
    return 0;
}