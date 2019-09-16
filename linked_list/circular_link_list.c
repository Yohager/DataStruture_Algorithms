/*
单循环链表
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
    printf("输入总人数和报数：");
    scanf("%d,%d",&numbers,&k);
    josephus_circle(numbers,k);
    return 0;
}

void josephus_circle(int numbers, int k)
{
    //先构建一个单循环链表
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
    //不带头结点的循环链表建立完毕（此时我们有一个带尾节点的单循环链表）
    //开始进行约瑟夫环算法的流程
    /*
    这个算法主要需要进行的是节点的删除操作
    每隔k个人就删除一个节点
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
        printf("这一轮被删除的节点为%d\n",temp_1->data);
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
