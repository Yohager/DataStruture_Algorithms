/*
single_linked_list.c
单链表的创建，元素的查找，插入，删除，链表的销毁等操作
*/
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Node{
    int data;
    struct node *next;
}ListNode;

//初始化单链表
void init_linklist(ListNode **ptr);
//清空单链表
void clear_linkist(ListNode **ptr);
//判断单链表是否为空
int empty_linklist(ListNode *list);
//返回单链表的长度
int length_linklist(ListNode *list);
//查地址查找
void get_elem_linklist(ListNode *list, int i, int *elem);
//查值查找并返回该值得地址
ListNode *locate_elem_linklist(ListNode *list, int elem);
//在单链表中的第i个数据元素的位置插入新元素e
void insert_elem_linklist(ListNode **ptr, int i, int elem);
//删除单链表中的第i个元素并将其值保存在elem中
void delete_elem_linklist(ListNode **ptr, int i, int elem);
//遍历单链表中的所有元素并打印出来
void traverse_linklist(ListNode *list);

int main()
{
    int *elem_p;
    ListNode *list;
    ListNode **ptr = &list;
    init_linklist(ptr);
    traverse_linklist(list);
    insert_elem_linklist(ptr,1,6);
    traverse_linklist(list);
    insert_elem_linklist(ptr,2,10);
    traverse_linklist(list);
    insert_elem_linklist(ptr,3,3);
    traverse_linklist(list);
    insert_elem_linklist(ptr,4,21);
    traverse_linklist(list);
    int count = length_linklist(list);
    printf("单链表的长度为%d\n",count);
    get_elem_linklist(list,2,elem_p);
    return 0;
}

void init_linklist(ListNode **ptr)
{
    *ptr = (ListNode *)malloc(sizeof(ListNode));
    //为头结点分配内存
    if (*ptr == NULL) return;
    //头结点的数据域没有值，指针域赋值为空即可
    (*ptr)->next = NULL;
}

void clear_linkist(ListNode **ptr)
{
    //单链表为空直接返回
    if (*ptr == NULL) return;
    //ListNode *s = *ptr;
    ListNode *temp;
    while ((*ptr)->next != NULL){
        temp = (*ptr)->next;
        (*ptr)->next = temp->next;
        free(temp);
    }
}

int empty_linklist(ListNode *list)
{
    if (list->next == NULL) return TRUE;
    else return FALSE;
}

int length_linklist(ListNode *list)
{
    int count=0;
    ListNode *temp = list;
    while (temp != NULL){
        count += 1;
        temp =temp->next;
    }
    //头结点这里没有算进去
    return count-1;
}

void get_elem_linklist(ListNode *list, int i, int *elem)
{
    int j=1;
    ListNode *temp = list->next;
    while ((temp!=NULL) && (j<i)){
        j++;
        temp = temp->next;
    }
}

void insert_elem_linklist(ListNode **ptr,int i, int elem)
{
    int j=0;
    ListNode *p = *ptr;
    ListNode *new_elem;
    //使用一个p指针，用p指针来寻找位置i
    while (p && j<i-1){
        p = p->next;
        j++;
    }
    if (!p || j > i-1) return ;
    else{
        new_elem = (ListNode *)malloc(sizeof(ListNode));
        new_elem->data = elem;
        new_elem->next = p->next;
        p->next = new_elem;
    }
}

void traverse_linklist(ListNode *list)
{
    ListNode *temp = list->next;
    while (temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}



