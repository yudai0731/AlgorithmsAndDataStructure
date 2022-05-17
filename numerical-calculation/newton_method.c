#include<stdio.h>
#include<math.h> // コンパイルオプション -lm

// sqrt(2)の数値計算
double f(double x){
    // ans sqrt(2), -sqrt(2)
    return x*x-2;
}

double f_diff(double x){
    return 2*x;
}

double newton_method(double x0,double epsilon){
    double x1;
    while(1){
        x1 = x0 - f(x0)/f_diff(x0);
        if(fabs(x1-x0)<epsilon){
            break;
        }
        printf("x0 = %lf, x1 = %lf\n",x0,x1);
        x0 = x1; // 値の更新
    }
    return x1;
}

int main(void){
    double x0 = 2.0;
    double epsilon = 10e-5;
    double result = newton_method(x0,epsilon);
    printf("result : %lf\n",result);
    return 0;
}