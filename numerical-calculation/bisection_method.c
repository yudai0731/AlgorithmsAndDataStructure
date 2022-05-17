#include<stdio.h>
#include<math.h> // コンパイルオプション -lm

// sqrt(2)の数値計算
double f(double x){
    // ans sqrt(2), -sqrt(2)
    return x*x-2;
}

double bisection_method(double init_a,double init_b, double epsilon){
    double c = 0.0;
    double a = init_a;
    double b = init_b;
    while(1){
        c= (a+b)/2;
        // 終了判定
        if(fabs(a-b)<epsilon){
            break;
        }
        if(f(c)<0){
            a = c;
        }else{
            b = c;
        }
        printf("a = %lf, b= %lf, c = %lf\n",a,b,c);
    }
    return c;
}

int main(void){
    double init_a = 1.0;
    double init_b = 2.0;
    double epsilon = 10e-5;
    double result = bisection_method(init_a,init_b,epsilon);
    printf("result : %lf\n",result);
    return 0;
}