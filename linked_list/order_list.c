/*
����˳����һЩ֪ʶ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

//˳���Ԫ�صĳ������ݽṹ
typedef struct order_list{
    int *value;//����洢����Ԫ��
    int length;//���Ա�ǰ�ĳ���
}Sqlist;

//ADT ���Ա������������
//��ʼ��˳���
void init_list(Sqlist *ptr);
//����˳���
void create_list(Sqlist *ptr, int numbers[],int count);
//�ж����Ա��Ƿ�Ϊ��
int empty_list(Sqlist List);
//������Ա�
void clean_list(Sqlist *ptr);
//�����Ա��е�i������Ԫ�ط��ظ�elem
void get_elem_list(Sqlist List, int i, int *elem);
//��ֵ�������Ա��е�ĳ��Ԫ�أ����ҳɹ�����λ�ã����򷵻�false
int locate_elem_list(Sqlist List, int elem);
//�����µ�Ԫ��
void insert_elem_list(Sqlist *ptr, int i, int elem);
//ɾ��list�е�ĳ��Ԫ�ز�������ֵ��elem
void delete_elem_list(Sqlist *ptr, int i, int *elem);
//����list�ĳ���
int length_list(Sqlist List);
//����list���������еĽ��
void traversal_list(Sqlist List);
//˳���͵�����
void reverse_list(Sqlist *ptr);

int main()
{
    int number;
    int *temp;
    int elem=0;
    printf("������������������");
    scanf("%d",&number);
    temp = (int *)malloc(number*(sizeof(int)));
    printf("��������Щ������");
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
    //����Ĺ�����Ҫ�Ǵӱ�׼�����ȡ��һЩ�����뵽temp�����У�Ϊ֮���list�Ĵ�����׼��
    printf("\n");
    //��ʼ��һ��sqlist
    Sqlist list;
    //��ʼ��һ��sqlist*�͵�ָ�벢�����ڴ�ռ�
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
    printf("�͵�����֮ǰ��");
    traversal_list(list);
    printf("\n");
    printf("�͵�����֮��");
    reverse_list(ptr);
    traversal_list(list);
    return 0;
}

//˳���ĳ�ʼ��
void init_list(Sqlist *ptr)
{
    ptr->value = (int *)malloc(sizeof(int)*MAX_SIZE);
    ptr->length = 0;
}

//˳���Ĵ���
void create_list(Sqlist *ptr,int numbers[], int count)
{
    for (int i=0;i<count;i++){
        ptr->value[i] = numbers[i];
    }
    ptr->length = count;
}

//�ж����Ա��Ƿ�Ϊ��
int empty_list(Sqlist List)
{
    if (List.length == 0) return TRUE;
    else return FALSE;
}

//������Ա�
void clean_list(Sqlist *ptr)
{
    //�������Ա�Ϊ��
    if (empty_list(*ptr) == 1) return;
    //���Ա�Ϊ��ʱ���������е�Ԫ����0ͬʱfree������Ķ�̬�ڴ�
    for (int i=0;i<ptr->length;i++){
        ptr->value[i] = 0;
    }
    ptr->length = 0;
    free(ptr->value);
}

//��λ�ò���Ԫ��
void get_elem_list(Sqlist List, int i, int *elem)
{
    if (i<=0) return;
    *elem = List.value[i-1];
}

//��ֵ�������Ա��е�ĳ��Ԫ�أ����ҳɹ�������λ�ã����򷵻�false
int locate_elem_list(Sqlist List, int elem)
{
    for (int i=0;i<List.length;i++){
        if (List.value[i] == elem) return i+1;
    }
    return FALSE;
}

//������Ԫ��
void insert_elem_list(Sqlist *ptr, int i, int elem)
{
    if (i<0 || i>ptr->length || ptr->length+1 > MAX_SIZE) return;
    for (int j=ptr->length-1;j >=i-1;j--){
        ptr->value[j+1] = ptr->value[j];
    }
    ptr->value[i-1] = elem;
    ptr->length += 1;
}

//ɾ�����Ա���ĳһ��Ԫ�ز�������ֵ��elem
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

//����list�ĳ���
int length_list(Sqlist List)
{
    return List.length;
}

//����list�е�Ԫ�����ڼ��������н��
void traversal_list(Sqlist List)
{
    for (int i=0;i<List.length;i++){
        printf("%d ",List.value[i]);
    }
}

//˳���ľ͵�����
void reverse_list(Sqlist *ptr)
{
    int len = ptr->length;
    for (int i=0;i<(len/2);i++){
        ptr->value[i] = ptr->value[i]+ptr->value[len-i-1];
        ptr->value[len-i-1] = ptr->value[i] - ptr->value[len-i-1];
        ptr->value[i] = ptr->value[i] - ptr->value[len-i-1];
    }
}

