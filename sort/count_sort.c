/*
��������
�Ƚ�������һЩ�Ƚ����ݹ�ģ�ϴ����ݱ仯��Χ��С����������
*/
#include<stdio.h>
#include<stdlib.h>

void count_sort(int numbers[], int count, int max_value);

int main()
{
    int count = 10;
    int numbers[10] = {12,3,45,6,19,22,12,89,50,20};
    int max_value = 89;
    printf("before count sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
    count_sort(numbers,count,max_value);
    printf("\n");
    printf("after count sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
}

void count_sort(int numbers[], int count, int max_value)
{
    int count_numbers[max_value+1];
    for (int p=0;p<=max_value;p++){
        count_numbers[p] = 0;
    }
    //���м���
    for (int i=0; i<count; i++){
        count_numbers[numbers[i]]+=1;
    }
    //����Щֵ������ԭ������
    int index=0;
    for (int j=0; j<=max_value; j++){
        //��j����count_numbers[k]�ε�ԭ������
        for (int k=1;k<=count_numbers[j];k++){
            numbers[index] = j;
            index++;
        }
    }
}

