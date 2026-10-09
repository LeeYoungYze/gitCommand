#include <stdio.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct Stack {
    ElemType data[MAXSIZE];
    int top;
} Stack;
void init(Stack *s) {
    s->top = 0;
}
int is_full(Stack *s) {
    return s->top == MAXSIZE;
}
int is_empty(Stack *s) {
    return s->top == 0;
}
void push(Stack *s, ElemType e) {
    if(is_full(s)) {
        printf("栈满了\n");
        return;
    }
    s->data[s->top] = e;
    s->top++;
}
void pop(Stack *s, ElemType *e) {
    if(is_empty(s)) {
        printf("栈为空\n");
        return;
    }
    s->top--;
    *e = s->data[s->top];
}
int main() {
    Stack s;
    init(&s);
    push(&s, 10);//top = 1; 0 + 1 = 1
    push(&s, 20);//top = 2; 1 + 1 = 2
    push(&s, 30);//top = 3; 2 + 1 = 3
    push(&s, 40);//top = 4; 3 + 1 = 4
    push(&s, 50);//top = 5; 4 + 1 = 5
    push(&s, 60);//top = 5;栈已满，一直锁在这里了，除非你出栈
    //有一个问题呢
    //top == 5,数组下标只能到4,所以此时已经越界了,所以pop(&s, &e)函数是先自减再使用的
    ElemType e = 0;
    pop(&s, &e);//top = 4; 5 - 1 = 4 然后再通过下标打印出来数据
    printf("第一个数:%d\n", e);//50 
    pop(&s, &e);//top = 3
    printf("第二个数:%d\n", e);//40
    //后进先出
    push(&s, 60);//放个60进去  放到数组的下标3的位置，会占其他数据的位置嘛？
    //top = 4; 3 + 1 = 4
    //不会，刚刚下标3的位置是第二个数40，此时放60刚好是放在它的位置上，刚好它才刚走
    pop(&s, &e);//top = 3; 4 - 1 = 3
    printf("第三个数:%d\n", e);//60
    pop(&s, &e);//top = 2; 3 - 1 = 2
    pop(&s, &e);//top = 1; 2 - 1 = 1
    printf("第五个数:%d\n", e);//20
    pop(&s, &e);//top = 0; 1 - 1 = 0
    printf("第六个数:%d\n", e);//10
    //容量MAXSIZE 有六个数据能够打印出来，是因为我出栈两次后又入栈了一次
    return 0;
}