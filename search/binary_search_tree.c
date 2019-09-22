/*
二叉搜索树进行搜索
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node{
    int value;
    struct tree_node *lchild;
    struct tree_node *rchild;
}TreeNode;

TreeNode *BST_insert(TreeNode *root, int number);
void LDR(TreeNode *root);
TreeNode *BST_search_elem(TreeNode *root, int elem);


int main()
{
    //首先构造根节点
    TreeNode *root;
    root = (TreeNode *)malloc(sizeof(TreeNode));
    root->value = 0;
    root->lchild = NULL;
    root->rchild = NULL;
    root = BST_insert(root,12);
    root = BST_insert(root,3);
    root = BST_insert(root,41);
    root = BST_insert(root,7);
    root = BST_insert(root,18);
    LDR(root);
    printf("\n");
    TreeNode *result;
    result = BST_search_elem(root,7);
    if (result != NULL) printf("%d\n",result->value);
    else printf("can not find this element!");
    return 0;
}

TreeNode *BST_insert(TreeNode *root, int number)
{
    if (root->value == 0){
        root->value = number;
        return root;
    }
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->value = number;
    temp->lchild = NULL;
    temp->rchild = NULL;
    TreeNode *p = root;
    while (p != NULL){
        if (number < p->value){
            if (p->lchild == NULL){
                p->lchild = temp;
                break;
            }
            else{
                p = p->lchild;
            }
        }
        else if (number > p->value){
            if (p->rchild == NULL){
                p->rchild = temp;
                break;
            }
            else{
                p = p->rchild;
            }
        }
    }
    return root;
}

void LDR(TreeNode *root)
{
    if (root == NULL) return;
    LDR(root->lchild);
    printf("%d->",root->value);
    LDR(root->rchild);
}

TreeNode *BST_search_elem(TreeNode *root, int elem)
{
    TreeNode *temp = root;
    while (temp != NULL){
        if (temp->value == elem){
            return temp;
        }
        else if (elem < temp->value){
            temp = temp->lchild;
        }
        else if (elem > temp->value){
            temp = temp->rchild;
        }
    }
    return NULL;
}
