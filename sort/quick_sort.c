/*
��������
*/
#include<stdio.h>
#include<stdlib.h>

void quick_sort(int numbers[], int start, int end);

int main()
{
    int count = 10;
    int start = 0;
    int end = count-1;
    int numbers[10] = {12,3,45,6,19,22,312,89,50,20};
    printf("before quick sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
    quick_sort(numbers,start, end);
    printf("\n");
    printf("after quick sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
    return 0;
}

void quick_sort(int numbers[], int start, int end)
{
    //���������ֻ��һ��Ԫ�����ʾ�Ѿ�����ֱ�ӷ���
    if (start >= end) return ;
    int low = start;
    int high = end;
    int temp = numbers[low];
    while (low < high){
        //�Ӻ���ǰɨ��
        while (low<high && numbers[high]>=temp){
            high--;
        }
        if (low<high){
            numbers[low++] = numbers[high];
        }
        //��ǰ����ɨ��
        while (low<high && numbers[low]<=temp){
            low++;
        }
        if (low < high){
            numbers[high--] = numbers[low];
        }
    }
    numbers[low] = temp;
    quick_sort(numbers,start,low-1);
    quick_sort(numbers,low+1,end);
}
