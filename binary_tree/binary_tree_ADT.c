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
//���ݴ����ֵ����һ���µĽڵ㣬����Ĺ����ǣ�С��root����������������root����������
void create_tree(BTNode **rootptr, int numbers[], int count);
//ǰ�����
void DLR(BTNode *root);
//�������
void LDR(BTNode *root);
//�������
void LRD(BTNode *root);
//�ж�������Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
int is_empty_tree(BTNode *root);
//�ڶ������в���ĳһ��ֵ�����ؽ���λ��
BTNode *get_node_position(BTNode *root, int elem);
//��������������
int depth_of_tree(BTNode *root);
//�����������Ҷ�ӽڵ����
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

//ǰ�����
void DLR(BTNode *root)
{
    if (root == NULL) return ;
    printf("%d->",root->value);
    DLR(root->lchild);
    DLR(root->rchild);
}

//�������
void LDR(BTNode *root)
{
    if (root == NULL) return ;
    LDR(root->lchild);
    printf("%d->",root->value);
    LDR(root->rchild);
}

//�������
void LRD(BTNode *root)
{
    if (root == NULL) return ;
    LRD(root->lchild);
    LRD(root->rchild);
    printf("%d->",root->value);
}

//����һ�ö�����
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

//�жϴ˶������Ƿ�Ϊ��
int is_empty_tree(BTNode *root)
{
    return (root==NULL)?1:0;
}

//�ڶ������в���ĳ��ֵ��λ��
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

//�������������
int depth_of_tree(BTNode *root)
{
    if (root == NULL) return 0;
    return (1 + (depth_of_tree(root->lchild) > depth_of_tree(root->rchild)?depth_of_tree(root->lchild):depth_of_tree(root->rchild)));
}

//����������Ҷ�ӽڵ���
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
