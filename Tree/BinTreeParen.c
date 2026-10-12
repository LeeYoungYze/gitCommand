#include <stdio.h>
#include <stdlib.h>
typedef struct NodeTree {
    char data;
    struct NodeTree *left;
    struct NodeTree *right;
} NodeTree;
//char str[] = "A(B(D,),C(E,F(,G)))";
NodeTree *createBinaryTree(char **str) {
    if (**str == '\0' || **str == ',' || **str == ')') {
        //(*str)++;
        return NULL;
    }
    NodeTree *t = (NodeTree *)malloc(sizeof(NodeTree));
    t->data = **str;
    t->left = NULL;
    t->right = NULL;
    (*str)++;
    if(**str == '(') {
        (*str)++;
        t->left = createBinaryTree(str);
        if (**str == ',') {
            (*str)++;
            t->right = createBinaryTree(str);
        }
        if (**str == ')') {
            (*str)++;
        }
    }
    return t;
}
void preorder(NodeTree *root) {
    if(root == NULL){
        return;
    }
    printf("%c ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(NodeTree *root) {
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%c ",root->data);
    inorder(root->right);
}
void postorder(NodeTree *root) {
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}
void start(NodeTree *root) {
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}
int main() {
    char str[] = "A(B(D,),C(E,F(,G)))";
    char *p = str;
    NodeTree *root = createBinaryTree(&p);
    start(root);
    return 0;
}