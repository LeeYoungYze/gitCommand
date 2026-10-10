#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} LinkList;

void frontPush(LinkList **head, ElemType e) {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->data = e;
    p->next = *head;
    *head = p;
}

void rearPush(LinkList **head, ElemType e) {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->data = e;
    p->next = NULL;

    if (*head == NULL) {
        *head = p;
        return;
    }

    LinkList *t = *head;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = p;
}

void display(LinkList *head) {
    LinkList *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/* 只读，不需要二级指针 */
int is_empty(LinkList *head) {
    return head == NULL;
}

int getLength(LinkList *head) {
    int len = 0;
    LinkList *p = head;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

void deleteByIndex(LinkList **head, int index) {
    if (is_empty(*head)) {
        printf("链表为空\n");
        return;
    }
    if (index < 0 || index > getLength(*head) - 1) {
        printf("索引不规范\n");
        return;
    }

    /* 用二级指针统一处理，删头/删中间同一套 */
    LinkList **p = head;
    for (int i = 0; i < index; i++) {
        p = &(*p)->next;
    }
    LinkList *temp = *p;
    *p = (*p)->next;
    free(temp);
}

/* 重点修复：头部连续相同元素会漏删 */
void deleteTotalByElem(LinkList **head, ElemType e) {
    if (is_empty(*head)) {
        printf("链表为空\n");
        return;
    }

    int num = 0;
    LinkList **p = head;              /* 二级指针，从头到尾统一处理 */
    while (*p != NULL) {
        if ((*p)->data == e) {
            LinkList *temp = *p;
            *p = (*p)->next;          /* 不管是头还是中间，都是这一句 */
            free(temp);
            num++;
        } else {
            p = &(*p)->next;          /* 不删，才往后走 */
        }
    }

    if (num) {
        printf("已删除了链表里的%d个%d元素\n", num, e);
    } else {
        printf("链表里没有与%d相等的元素\n", e);
    }
}

void reverse(LinkList **head) {
    if (is_empty(*head)) {
        printf("链表为空\n");
        return;
    }
    LinkList *prev = NULL;
    LinkList *cur = *head;
    while (cur != NULL) {
        LinkList *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

/* 释放整条链表，好习惯 */
void destroy(LinkList **head) {
    LinkList *p = *head;
    while (p != NULL) {
        LinkList *temp = p;
        p = p->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    LinkList *head = NULL;

    rearPush(&head, 30);
    rearPush(&head, 20);
    frontPush(&head, 50);
    rearPush(&head, 30);
    rearPush(&head, 30);
    display(head);                 /* 50 30 20 30 30 */

    deleteByIndex(&head, 0);
    display(head);                 /* 30 20 30 30 */

    deleteTotalByElem(&head, 30);
    display(head);                 /* 20 */

    frontPush(&head, 10);
    rearPush(&head, 30);
    rearPush(&head, 40);
    rearPush(&head, 50);
    rearPush(&head, 60);
    display(head);                 /* 10 20 30 40 50 60 */

    reverse(&head);
    display(head);                 /* 60 50 40 30 20 10 */

    /* 额外测一下头部连续相同元素 */
    rearPush(&head, 30);
    rearPush(&head, 30);
    rearPush(&head, 30);
    display(head);                 /* 60 50 40 30 20 10 30 30 30 */
    deleteTotalByElem(&head, 30);
    display(head);                 /* 60 50 40 20 10 */

    destroy(&head);
    return 0;
}