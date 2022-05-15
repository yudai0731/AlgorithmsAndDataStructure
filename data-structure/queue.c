#include<stdio.h>

#define QUEUE_LEN 10

// queueに格納される値は0より大きい整数
typedef struct{
    int Q[QUEUE_LEN]; // queue
    int head; // 先頭の要素のインデックス
    int tail; // 末尾の要素のインデックス
    int cnt;
}Queue;

void init_queue(Queue *q){
    int i;
    q->head=0;
    q->tail=0;
    q->cnt=0;
    for(i=0;i<QUEUE_LEN;i++){
        q->Q[i] = 0;
    }
    printf("queue initialized\n");
}

void print_queue(Queue *q){
    int i;
    printf("head : %d tail : %d\n",q->head,q->tail);
    for(i=0;i<QUEUE_LEN;i++){
        if(q->Q[i]>0){
            printf("%d ",q->Q[i]);
        }
    }
    printf("\n");   
}

int is_empty(Queue *q){
    if(q->cnt==0){
        return 1;
    }else{
        return 0;
    }
}

int is_full(Queue *q){
    if(q->cnt==QUEUE_LEN){
        return 1;
    }else{
        return 0;
    }
}

int enqueue(Queue *q,int num){
    // enqueue func 返り値 成功:0,失敗:-1
    if(is_full(q)){
        printf("queue overflow\n");
        return -1;
    }else{
        q->Q[q->tail] = num;
        q->cnt++;
        q->tail = (q->tail+1)%QUEUE_LEN;
        return 0;
    }
}

int dequeue(Queue *q){
    int dequeue_val;
    if(is_empty(q)){
        printf("queue underflow\n");
        return -999; // -999を返すように設定
    }else{
        dequeue_val = q->Q[q->head];
        q->Q[q->head] = 0; // 使用されていないのが分かりやすいように
        q->cnt--;
        q->head = (q->head+1)%QUEUE_LEN;
        return dequeue_val;
    }
}

int main(void){
    Queue q;
    int process_num = 5;
    int process[] = {150,80,200,350,20};
    int quantum=10;
    int i,dequeue_val;

    // init queue
    init_queue(&q);

    // ラウンドロビンスケジューリング
    // queueにプロセスを代入
    for(i=0;i<process_num;i++){
        enqueue(&q,process[i]);
    }
    print_queue(&q);
    // ラウンドロビンスケジューリングを実行
    printf("\n===start round robin scheduling===\n");
    while(q.cnt>0){
        dequeue_val=dequeue(&q);
        if(dequeue_val-quantum>0){
            enqueue(&q,dequeue_val-quantum);
        }
        print_queue(&q);
    }
    return 0;
}