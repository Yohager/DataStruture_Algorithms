/*
single_linked_list.c
������Ĵ�����Ԫ�صĲ��ң����룬ɾ������������ٵȲ���
*/
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Node{
    int data;
    struct node *next;
}ListNode;

//��ʼ��������
void init_linklist(ListNode **ptr);
//��յ�����
void clear_linkist(ListNode **ptr);
//�жϵ������Ƿ�Ϊ��
int empty_linklist(ListNode *list);
//���ص�����ĳ���
int length_linklist(ListNode *list);
//���ַ����
void get_elem_linklist(ListNode *list, int i, int *elem);
//��ֵ���Ҳ����ظ�ֵ�õ�ַ
ListNode *locate_elem_linklist(ListNode *list, int elem);
//�ڵ������еĵ�i������Ԫ�ص�λ�ò�����Ԫ��e
void insert_elem_linklist(ListNode **ptr, int i, int elem);
//ɾ���������еĵ�i��Ԫ�ز�����ֵ������elem��
void delete_elem_linklist(ListNode **ptr, int i, int *elem);
//�����������е�����Ԫ�ز���ӡ����
void traverse_linklist(ListNode *list);

ListNode *k_position_node(ListNode *list);

int main()
{
    int *elem_p;
    elem_p = (int *)malloc(sizeof(int));
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
    insert_elem_linklist(ptr,5,21);
    traverse_linklist(list);
    int count = length_linklist(list);
    printf("������ĳ���Ϊ%d\n",count);
    //get_elem_linklist(list,2,elem_p);
    //printf("%d\n",*elem_p);
    //ListNode *location;
    //location = locate_elem_linklist(list,21);
    //printf("%d\n",location->data);
    //delete_elem_linklist(ptr,2,elem_p);
    //printf("%d\n",*elem_p);
    /*
    int numbers[] = {6,10,3,21};
    int counts = 4;
    head_insert_linklist(ptr,numbers,counts);
    */
    //printf("�͵�����ǰ��");
    //traverse_linklist(list);
    //reverse_linklist(ptr);
    //printf("�͵����ú�");
    //traverse_linklist_reverse(list);
    ListNode *k_postion = (ListNode *)malloc(sizeof(ListNode));
    k_postion = k_position_node(list);
    printf("%d\n",k_postion->data);
    return 0;
}

void init_linklist(ListNode **ptr)
{
    *ptr = (ListNode *)malloc(sizeof(ListNode));
    //Ϊͷ�������ڴ�
    if (*ptr == NULL) return;
    //ͷ����������û��ֵ��ָ����ֵΪ�ռ���
    (*ptr)->next = NULL;
}

void clear_linkist(ListNode **ptr)
{
    //������Ϊ��ֱ�ӷ���
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
    //ͷ�������û�����ȥ
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
    *elem = temp->data;
}

ListNode *locate_elem_linklist(ListNode *list, int elem)
{
    ListNode *temp = list;
    while (temp!=NULL){
        if (temp->data == elem){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insert_elem_linklist(ListNode **ptr,int i, int elem)
{
    int j=0;
    ListNode *p = *ptr;
    ListNode *new_elem;
    //ʹ��һ��pָ�룬��pָ����Ѱ��λ��i
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

void delete_elem_linklist(ListNode **ptr,int i, int *elem)
{
    int j=1;
    ListNode *temp = (*ptr)->next;
    while (temp!=NULL && j<i-1){
        j++;
        temp = temp->next;
    }
    ListNode *s = temp->next;
    *elem = s->data;
    temp->next = s->next;
    free(s);
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


//ͷ����ڵ�
void head_insert_linklist(ListNode **ptr, int numbers[], int length)
{
    ListNode *temp = *ptr;
    ListNode *s;
    for (int i=0; i<length; i++){
        s = (ListNode *)malloc(sizeof(ListNode));
        if (s==NULL) return;
        s->data = numbers[i];
        s->next = temp->next;
        temp->next = s;
    }
}

//β���뷨
void tail_insert_linklist(ListNode **ptr, int numbers[], int length)
{
    ListNode *temp = *ptr;
    ListNode *s;
    for (int i=0;i<length;i++){
        s = (ListNode *)malloc(sizeof(ListNode));
        s->data = numbers[i];
        s->next = NULL;
        temp->next = s;
        temp = temp->next;
    }
}

//������ľ͵�����
void reverse_linklist(ListNode **ptr)
{
    ListNode *temp;
    temp = (*ptr)->next;
    //printf("%d\n",temp->data);
    ListNode *r;
    ListNode *s;
    s = NULL;
    while (temp != NULL){
        r = temp->next;
        //printf("%d ",r->data);
        temp->next = s;
        s = temp;
        temp = r;
    }
    //printf("%d\n",temp->data);
    (*ptr) = s;
}

void traverse_linklist_reverse(ListNode *list)
{
    ListNode *temp = list;
    while (temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

//����һ���ȡ1/k���Ľڵ��λ��
ListNode *k_position_node(ListNode *list)
{
    //��fast��slowָ�붼��ָ���һ������ֵ�Ľڵ�
    ListNode *fast = list;
    ListNode *slow = list;
    while (fast){
        if (fast->next != NULL){
            ListNode *temp = fast->next;
            fast = temp->next;
        }
        else{
            break;
        }
        slow = slow->next;
    }
    return slow;
}

