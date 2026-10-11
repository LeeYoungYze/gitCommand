#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef char ElemType;
typedef struct TreeNode {
    ElemType data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
void setGreen() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
}
void reset() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void createBinaryTree(TreeNode **root, char **str) {
    char ch = **str;
    (*str)++;
    if(ch == '#' || ch == '\0'){
        *root = NULL;
        return;
    }
    TreeNode *t = (TreeNode * )malloc(sizeof(TreeNode));
    t->data = ch;
    t->left = NULL;
    t->right = NULL;
    *root = t;
    createBinaryTree(&t->left,str);
    createBinaryTree(&t->right,str);
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
    setGreen();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    reset();
}
int main() {
    TreeNode *root = NULL;
    char str[] = "124##5##3##";
    //char str[] = "1(2(4,5),3)";
    char *point = str;
    createBinaryTree(&root,&point);
    start(root);
}