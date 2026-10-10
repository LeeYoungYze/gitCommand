#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} LinkList;
void frontPush(LinkList **head, ElemType e) {
    LinkList *p = (LinkList * )malloc(sizeof(LinkList));
    p->data = e;
    p->next = *head;
    *head = p; 
}
void rearPush(LinkList **head, ElemType e) {
    LinkList *p = (LinkList * )malloc(sizeof(LinkList));
    if (*head == NULL) {
        p->data = e;
        p->next = *head;
        *head = p;
        return;
    }
    LinkList *t = *head;
    while(t->next != NULL) {
        t = t->next;
    }
    p->data = e;
    p->next = t->next;
    t->next = p;
}
void display(LinkList *head) {
    LinkList *p = head;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int is_empty(LinkList **head) {
    return *head == NULL;
}
int getLength(LinkList *head) {
    int len = 0;
    LinkList *p = head;
    while(p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}
void deleteByIndex(LinkList **head, int index) {
    if (is_empty(head)){
        printf("链表为空\n");
        return;
    }
    if (index < 0 || index > getLength(*head) - 1) {
        printf("索引不规范\n");
        return;
    }
    if (index == 0) {
        LinkList *temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }
    LinkList *p = *head;
    for (int i = 1; i < index; i++) {
        p = p->next;
    }
    LinkList *temp = p->next;
    p->next = temp->next;
    free(temp);
}
void deleteTotalByElem(LinkList **head, ElemType e) {
    if (is_empty(head)){
        printf("链表为空\n");
        return;
    }
    int num = 0;
    if ((*head)->data == e) {
        LinkList *temp = *head;
        *head = temp->next;
        free(temp);
        num++;
    }
    LinkList *prev = *head;
    LinkList *p = prev->next;
    while(p != NULL) {
        if (p->data == e) {
            LinkList *temp = p;
            prev->next = temp->next;
            free(temp);
            num++;
            p = prev->next;
        } else {
            prev = p;
            p = p->next;
        }
    }
    if(num) {
        printf("已删除了链表里的%d个%d元素\n", num, e);
    } else {
        printf("链表里没有与%d相等的元素\n", e);
    }
}
void reverse(LinkList **head) {
    if (is_empty(head)) {
        printf("链表为空\n");
        return;
    }
    LinkList *prev = NULL;
    LinkList *cur = *head;
    LinkList *next = cur->next;
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}
int main() {
    LinkList *head = NULL;
    rearPush(&head, 30);
    rearPush(&head, 20);
    frontPush(&head, 50);
    rearPush(&head, 30);
    rearPush(&head, 30);
    display(head);
    deleteByIndex(&head, 0);
    display(head);
    //deleteByIndex(&head, 3);
    display(head);
    deleteTotalByElem(&head, 30);
    display(head);
    frontPush(&head, 10);
    rearPush(&head, 30);
    rearPush(&head, 40);
    rearPush(&head, 50);
    rearPush(&head, 60);
    display(head);
    reverse(&head);
    display(head);
    return 0;
}