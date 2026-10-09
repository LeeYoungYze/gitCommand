#include <stdio.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct Queue {
    ElemType data[MAXSIZE];
    int front;
    int rear;
} Queue;
void init(Queue *q) {
    q->front = 0;
    q->rear = 0;
}
int is_full(Queue *q) {
    return (q->rear + 1) % MAXSIZE == q->front;
}
int is_empty(Queue *q) {
    return q->rear == q->front;
}
void enqueue(Queue *q, ElemType e) {
    if(is_full(q)) {
        printf("队列满了\n");
        return;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
}
void dequeue(Queue *q, ElemType *e) {
    if(is_empty(q)) {
        printf("队列为空\n");
        return;
    }
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
}
int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);//rear = 1; (0 + 1) % 5 = 1
    enqueue(&q, 20);//rear = 2; (1 + 1) % 5 = 2
    enqueue(&q, 30);//rear = 3; (2 + 1) % 5 = 3
    enqueue(&q, 40);//rear = 4; (3 + 1) % 5 = 4
    enqueue(&q, 50);//rear = 0; (4 + 1) % 5 = 0 此时 front = 0 所以 rear == front(队列满了)
    //装不了5个(只能装 MAXSIZE - 1 个)
    ElemType e = 0;
    dequeue(&q, &e);//front = 1; 此时 rear != front(队列有空余位置了)
    printf("第一个数:%d\n", e);
    enqueue(&q, 50);//rear = 1; (0 + 1) % 5 无须担心出队会先出50,因为front已经为1了，所以第二个出队的是20
    dequeue(&q, &e);//front = 2;
    printf("第二个数:%d\n", e);
    dequeue(&q, &e);//front = 3;
    dequeue(&q, &e);//front = 4;
    dequeue(&q, &e);// front = 0; (4 + 1) % 5 = 0
    printf("第五个数:%d\n", e);
    //又回到0了,现在可以打印50了，不要误解，这是第一次出队函数dequeue(&q, &e)执行后才加入的数，容量依旧保持 MAXSIZE - 1
    return 0;
}