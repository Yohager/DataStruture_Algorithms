/*
single_linked_list.c
单链表的创建，元素的查找，插入，删除，链表的销毁等操作
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;


