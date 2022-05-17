#include<stdio.h>

// 1/xの[1,2]の数値積分 理論値0.69315...
double f(double x){
    return 1/x;
}

double trapezoidal_rule(double a, double b,int n){
    int i;
    double h = (b-a)/n;
    double x0 = a;
    double S = 0.0;
    double x1;

    for(i=0;i<n;i++){
        x1 = x0 + h;
        S += h*(f(x0)+f(x1))/2;
        x0 = x1;
    }
    return S;
}

int main(void){
    double a = 1.0;
    double b = 2.0;
    int n = 20;
    double result = trapezoidal_rule(a,b,n);
    printf("result = %lf\n",result);
    return 0;
}