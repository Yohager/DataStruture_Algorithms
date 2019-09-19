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
//根据传入的值创建一个新的节点，插入的规则是：小于root插入左子树，大于root插入右子树
void create_tree(BTNode **rootptr, int numbers[], int count);
//前序遍历
void DLR(BTNode *root);
//中序遍历
void LDR(BTNode *root);
//后序遍历
void LRD(BTNode *root);
//判断这棵树是否为空，为空返回1，否则返回0
int is_empty_tree(BTNode *root);
//在二叉树中查找某一个值并返回结点的位置
BTNode *get_node_position(BTNode *root, int elem);
//返回这棵树的深度
int depth_of_tree(BTNode *root);
//计算二叉树的叶子节点个数
int numbers_of_leaves(BTNode *root);


int main()
{
    int count = 4;
    int numbers[] = {2,1,3,5};
    //BTNode *root = (BTNode *)malloc(sizeof(BTNode));
    BTNode *root;
    BTNode **root_ptr;
    root_ptr = &root;
    init_tree(root_ptr);
    printf("%d\n",root->value);
    create_tree(root_ptr,numbers,count);
    //DLR(root);
    //printf("\n");
    //destroy_tree(root_ptr);
    LDR(root);
    printf("\n");
    //int result;
    //result = is_empty_tree(root);
    //printf("%d\n",result);
    BTNode *temp;
    temp = get_node_position(root,3);
    printf("%d\n",temp->value);
    int depth;
    depth = depth_of_tree(root);
    printf("%d\n",depth);
    int leaves_number;
    leaves_number = numbers_of_leaves(root);
    printf("%d\n",leaves_number);
    return 0;

}

void init_tree(BTNode **root_ptr)
{
    (*root_ptr) = (BTNode *)malloc(sizeof(BTNode));
    (*root_ptr)->value = 0;
    (*root_ptr)->lchild = NULL;
    (*root_ptr)->rchild = NULL;
}

void create_tree(BTNode **rootptr, int numbers[], int count)
{
    BTNode *root = (*rootptr);
    root->value = numbers[0];
    for (int i=1; i<count; i++){
        BTNode *temp = root;
        BTNode *new_node;
        new_node = (BTNode *)malloc(sizeof(BTNode));
        new_node->value = numbers[i];
        new_node->lchild = NULL;
        new_node->rchild = NULL;
        while (temp != NULL){
            if (numbers[i] <= temp->value){
                if (temp->lchild == NULL){
                    temp->lchild = new_node;
                    break;
                }
                else{
                    temp = temp->lchild;
                }
            }
            else{
                if (temp->rchild == NULL){
                    temp->rchild = new_node;
                    break;
                }
                else{
                    temp = temp->rchild;
                }
            }
        }
    }
}

//前序遍历
void DLR(BTNode *root)
{
    if (root == NULL) return ;
    printf("%d->",root->value);
    DLR(root->lchild);
    DLR(root->rchild);
}

//中序遍历
void LDR(BTNode *root)
{
    if (root == NULL) return ;
    LDR(root->lchild);
    printf("%d->",root->value);
    LDR(root->rchild);
}

//后序遍历
void LRD(BTNode *root)
{
    if (root == NULL) return ;
    LRD(root->lchild);
    LRD(root->rchild);
    printf("%d->",root->value);
}

//销毁一棵二叉树
void destroy_tree(BTNode **root_ptr)
{
    if ((*root_ptr) && (root_ptr)){
        destroy_tree(&(*root_ptr)->lchild);
        destroy_tree(&(*root_ptr)->rchild);
        free((*root_ptr));
        (*root_ptr) = NULL;
    }
    //return;
}

//判断此二叉树是否为空
int is_empty_tree(BTNode *root)
{
    return (root==NULL)?1:0;
}

//在二叉树中查找某个值的位置
BTNode *get_node_position(BTNode *root, int elem)
{
    BTNode *p;
    if (root == NULL) return NULL;
    else if (root->value == elem) return root;
    else{
        p = get_node_position(root->lchild,elem);
        if (p != NULL){
            return p;
        }
        else{
            return get_node_position(root->rchild,elem);
        }
    }
}

//求解二叉树的深度
int depth_of_tree(BTNode *root)
{
    if (root == NULL) return 0;
    return (1 + (depth_of_tree(root->lchild) > depth_of_tree(root->rchild)?depth_of_tree(root->lchild):depth_of_tree(root->rchild)));
}

//求解二叉树的叶子节点数
int numbers_of_leaves(BTNode *root)
{
    int number_1,number_2;
    if (root == NULL) return 0;
    else if (root->lchild == NULL && root->rchild == NULL) return 1;
    else {
        number_1 = numbers_of_leaves(root->lchild);
        number_2 = numbers_of_leaves(root->rchild);
        return (number_1+number_2);
    }
}
