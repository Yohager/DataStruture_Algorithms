/*
给出一般二叉树的一些抽象数据类型
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct BTreeNode{
    int value;
    struct BTreeNode *lchild;
    struct BTreeNode *rchild;
}BTNode;

//初始化一棵二叉树
void init_tree(BTNode **root_ptr);
//销毁一棵二叉树
void destroy_tree(BTNode **root_ptr);
//根据传入的数组的顺序(假设是以前序遍历得到的数组)依次插入节点构造二叉树
void create_tree(BTNode **rootptr, int numbers[]);
//前序遍历
void DLR(BTNode *root);
//中序遍历
void LDR(BTNode *root);
//后序遍历
void LRD(BTNode *root);
//判断这棵树是否为空，为空返回1，否则返回0
void is_empty_tree(BTNode *root);
//在二叉树中查找某一个值并返回结点的位置
BTNode *get_node_position(BTNode *root, int elem);
//返回这棵树的深度
int depth_of_tree(BTNode *root);
//修改某个节点的值
void assign_node_value(BTNode **rootptr, BTNode *cur_node, int elem);
//计算二叉树的叶子节点个数
int numbers_of_leaves(BTNode *root);


int main()
{
    int numbers[] = {1,3,2,5,7};
    //BTNode *root = (BTNode *)malloc(sizeof(BTNode));
    BTNode *root;
    BTNode **root_ptr;
    root_ptr = &root;
    init_tree(root_ptr);
    printf("%d\n",root->value);
    return 0;

}

void init_tree(BTNode **root_ptr)
{
    (*root_ptr) = (BTNode *)malloc(sizeof(BTNode));
    (*root_ptr)->value = 10;
    (*root_ptr)->lchild = NULL;
    (*root_ptr)->rchild = NULL;
}
