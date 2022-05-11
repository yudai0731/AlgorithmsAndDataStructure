#include<stdio.h>

#define STACK_LEN 10
#define STR_MAX 50

typedef struct{
    int S[STACK_LEN]; // stack
    int sp; // stack pointer
}stack;

int print_stack(stack *s){
    int i;
    printf("stack pointer : %d\n",s->sp);
    for(i=0;i<s->sp;i++){
        if(i!=0) printf(" ");
        printf("%d",s->S[i]);
    }
    printf("\n");
}

int is_empty(stack *s){
    /* stackが空か確認する関数 */
    if (s->sp == 0){
        return 1; // 空のとき
    }else{
        return 0; // 空でないとき
    }
}

int is_full(stack *s){
    /* stackが満杯か確認する関数*/
    if(s->sp == STACK_LEN){
        return 1; // 満杯のとき
    }else{
        return 0; // 満杯でないとき
    }
}

int push(stack *s,int num){
    /* stack s に値をpushする関数 返り値 成功1, 失敗0*/
    if(is_full(s)){
        return 0;
    }else{
        s->S[s->sp] = num;
        s->sp++;
        return 1;
    }
}

// 数値を扱うからstackが空のときの処理を書いていない
int pop(stack *s){
    /* stack sから値をpopする関数 返り値 通常はpopした値*/ 
    int pop_val;
    if(is_empty(s)){
        printf("stack is empty");
        // emptyのときの処理
        return -999;
    }else{
        s->sp--;
        pop_val = s->S[s->sp];
        return pop_val;
    }
}

int main(void){
    stack Stack;
    int i,pop_val1,pop_val2;
    char str[STR_MAX]; // 入力文字列
    Stack.sp=0; // init stack pointer
    printf("stack initialized\n");

    // input 
    printf("input reverse polish notation\n");
    scanf("%s",str);

    // 逆ポーランド記法の処理
    i=0;
    while(str[i]!='\0'){
        switch(str[i]){
            case '+':
            pop_val1 = pop(&Stack);
            pop_val2 = pop(&Stack);
            push(&Stack, pop_val1+pop_val2);
            break;

            case '-':
            pop_val1 = pop(&Stack);
            pop_val2 = pop(&Stack);
            push(&Stack, pop_val2-pop_val1);
            break;

            case '*':
            pop_val1 = pop(&Stack);
            pop_val2 = pop(&Stack);
            push(&Stack, pop_val1*pop_val2);
            break;

            default: //number
            push(&Stack,str[i]-'0');
        }
        i++;
        //print_stack(&Stack);
    }
    printf("result = %d\n",pop(&Stack));

    return 0;
}