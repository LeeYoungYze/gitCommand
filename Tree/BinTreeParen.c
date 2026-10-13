#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode *createBinaryTree(char **str) {
    if (**str == '\0' || **str == ',' || **str == ')') {
        return NULL;
    }
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
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
void preorder(TreeNode *root) {
    if(root == NULL){
        return;
    }
    printf("%c ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode *root) {
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%c ",root->data);
    inorder(root->right);
}
void postorder(TreeNode *root) {
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}
void start(TreeNode *root) {
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
    TreeNode *root = createBinaryTree(&p);
    start(root);
    return 0;
}