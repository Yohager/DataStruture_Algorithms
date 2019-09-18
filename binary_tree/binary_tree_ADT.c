/*
����һ���������һЩ������������
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct BTreeNode{
    int value;
    struct BTreeNode *lchild;
    struct BTreeNode *rchild;
}BTNode;

//��ʼ��һ�ö�����
void init_tree(BTNode **root_ptr);
//����һ�ö�����
void destroy_tree(BTNode **root_ptr);
//���ݴ���������˳��(��������ǰ������õ�������)���β���ڵ㹹�������
void create_tree(BTNode **rootptr, int numbers[]);
//ǰ�����
void DLR(BTNode *root);
//�������
void LDR(BTNode *root);
//�������
void LRD(BTNode *root);
//�ж�������Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
void is_empty_tree(BTNode *root);
//�ڶ������в���ĳһ��ֵ�����ؽ���λ��
BTNode *get_node_position(BTNode *root, int elem);
//��������������
int depth_of_tree(BTNode *root);
//�޸�ĳ���ڵ��ֵ
void assign_node_value(BTNode **rootptr, BTNode *cur_node, int elem);
//�����������Ҷ�ӽڵ����
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
