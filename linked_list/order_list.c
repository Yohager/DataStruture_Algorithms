/*
关于顺序表的一些知识点
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

//顺序表元素的抽象数据结构
typedef struct order_list{
    int *value;//数组存储数据元素
    int length;//线性表当前的长度
}Sqlist;

//ADT 线性表抽象数据类型
//初始化顺序表
void init_list(Sqlist *ptr);
//创建顺序表
void create_list(Sqlist *ptr, int numbers[],int count);
//判断线性表是否为空
int empty_list(Sqlist List);
//清空线性表
void clean_list(Sqlist *ptr);
//将线性表中第i个数据元素返回给elem
void get_elem_list(Sqlist List, int i, int *elem);
//按值查找线性表中的某个元素，查找成功返回位置，否则返回false
int locate_elem_list(Sqlist List, int elem);
//插入新的元素
void insert_elem_list(Sqlist *ptr, int i, int elem);
//删除list中的某个元素并返回其值给elem
void delete_elem_list(Sqlist *ptr, int i, int *elem);
//返回list的长度
int length_list(Sqlist List);
//遍历list检查代码运行的结果
void traversal_list(Sqlist List);
//顺序表就地逆置
void reverse_list(Sqlist *ptr);

int main()
{
    int number;
    int *temp;
    int elem=0;
    printf("请输入整数的数量：");
    scanf("%d",&number);
    temp = (int *)malloc(number*(sizeof(int)));
    printf("请输入这些整数：");
    for (int i=0;i<number;i++){
        scanf("%d",&elem);
        char c=getchar();
        temp[i] = elem;
        if (c=='\n') break;
    }
    printf("\n");
    /*
    for (int j=0;j<number;j++){
        printf("%d ",temp[j]);
    }
    */
    //上面的工作主要是从标准输入读取的一些数存入到temp数组中，为之后的list的创建做准备
    printf("\n");
    //初始化一个sqlist
    Sqlist list;
    //初始化一个sqlist*型的指针并分配内存空间
    Sqlist *ptr = (Sqlist *)malloc(sizeof(Sqlist));
    ptr = &list;
    init_list(ptr);
    create_list(ptr,temp,number);
    //printf("%d",list.length);
    //printf("%d\n",empty_list(list));
    int *elem_p;
    //get_elem_list(list,1,elem_p);
    //printf("%d\n",*elem_p);
    //printf("%d\n",locate_elem_list(list,3));
    //insert_elem_list(ptr,2,14);
    printf("就地逆置之前：");
    traversal_list(list);
    printf("\n");
    printf("就地逆置之后：");
    reverse_list(ptr);
    traversal_list(list);
    return 0;
}

//顺序表的初始化
void init_list(Sqlist *ptr)
{
    ptr->value = (int *)malloc(sizeof(int)*MAX_SIZE);
    ptr->length = 0;
}

//顺序表的创建
void create_list(Sqlist *ptr,int numbers[], int count)
{
    for (int i=0;i<count;i++){
        ptr->value[i] = numbers[i];
    }
    ptr->length = count;
}

//判断线性表是否为空
int empty_list(Sqlist List)
{
    if (List.length == 0) return TRUE;
    else return FALSE;
}

//清空线性表
void clean_list(Sqlist *ptr)
{
    //考虑线性表为空
    if (empty_list(*ptr) == 1) return;
    //线性表不为空时将其中所有的元素置0同时free掉分配的动态内存
    for (int i=0;i<ptr->length;i++){
        ptr->value[i] = 0;
    }
    ptr->length = 0;
    free(ptr->value);
}

//按位置查找元素
void get_elem_list(Sqlist List, int i, int *elem)
{
    if (i<=0) return;
    *elem = List.value[i-1];
}

//按值查找线性表中的某个元素，查找成功返回其位置，否则返回false
int locate_elem_list(Sqlist List, int elem)
{
    for (int i=0;i<List.length;i++){
        if (List.value[i] == elem) return i+1;
    }
    return FALSE;
}

//插入新元素
void insert_elem_list(Sqlist *ptr, int i, int elem)
{
    if (i<0 || i>ptr->length || ptr->length+1 > MAX_SIZE) return;
    for (int j=ptr->length-1;j >=i-1;j--){
        ptr->value[j+1] = ptr->value[j];
    }
    ptr->value[i-1] = elem;
    ptr->length += 1;
}

//删除线性表中某一个元素并返回其值给elem
void delete_elem_list(Sqlist *ptr, int i, int *elem)
{
    if (i<0 || ptr->length == 0 || i>=ptr->length) return ;
    *elem = ptr->value[i-1];
    for (int j=i-1; j<ptr->length-1;j++){
        ptr->value[j] = ptr->value[j+1];
    }
    ptr->value[ptr->length-1] = 0;
    ptr->length -= 1;
}

//返回list的长度
int length_list(Sqlist List)
{
    return List.length;
}

//遍历list中的元素用于检查代码运行结果
void traversal_list(Sqlist List)
{
    for (int i=0;i<List.length;i++){
        printf("%d ",List.value[i]);
    }
}

//顺序表的就地逆置
void reverse_list(Sqlist *ptr)
{
    int len = ptr->length;
    for (int i=0;i<(len/2);i++){
        ptr->value[i] = ptr->value[i]+ptr->value[len-i-1];
        ptr->value[len-i-1] = ptr->value[i] - ptr->value[len-i-1];
        ptr->value[i] = ptr->value[i] - ptr->value[len-i-1];
    }
}

