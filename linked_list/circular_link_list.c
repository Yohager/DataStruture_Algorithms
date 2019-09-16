/*
��ѭ������
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}ListNode;

void josephus_circle(int numbers, int k);

void travesal_circle(ListNode *list);

int main()
{
    int numbers;
    int k;
    printf("�����������ͱ�����");
    scanf("%d,%d",&numbers,&k);
    josephus_circle(numbers,k);
    return 0;
}

void josephus_circle(int numbers, int k)
{
    //�ȹ���һ����ѭ������
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    ListNode *s = head;
    ListNode *p;
    for (int i=0;i<numbers;i++){
        p = (ListNode *)malloc(sizeof(ListNode));
        p->data = i+1;
        p->next = s->next;
        s->next = p;
        //printf("%d ",p->data);
        s=p;
    }
    //p->next = NULL;
    //travesal_circle(head);
    p->next = head->next;
    free(head);
    //����ͷ����ѭ����������ϣ���ʱ������һ����β�ڵ�ĵ�ѭ������
    //��ʼ����Լɪ���㷨������
    /*
    ����㷨��Ҫ��Ҫ���е��ǽڵ��ɾ������
    ÿ��k���˾�ɾ��һ���ڵ�
    */
    int length = numbers;
    ListNode *temp_1=p->next;
    ListNode *temp_2;
    ListNode *q;
    while (length>=k){
        int count=k-1;
        for (;count>0;count--){
            temp_2 = temp_1;
            temp_1 = temp_1->next;
        }
        printf("��һ�ֱ�ɾ���Ľڵ�Ϊ%d\n",temp_1->data);
        //q = (ListNode *)malloc(ListNode);
        q = temp_1;
        temp_2->next = temp_1->next;
        temp_1 = temp_1->next;
        free(q);
        length--;
    }
    //free(head);
}

void travesal_circle(ListNode *list)
{
    ListNode *temp = list->next;
    while (temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
