/*
��������ĸĽ��汾һ���۰��������
*/
#include<stdio.h>
#include<stdlib.h>

void binary_insert_sort(int numbers[], int count);

int main()
{
    int count = 6;
    int numbers[6] = {12,3,45,6,19,22};
    printf("before binary insert sort: ");
    for (int i=0; i<6; i++){
        printf("%d ",numbers[i]);
    }
    binary_insert_sort(numbers,count);
    printf("\n");
    printf("after binary insert sort: ");
    for (int i=0; i<6; i++){
        printf("%d ",numbers[i]);
    }
}

void binary_insert_sort(int numbers[], int count)
{
   int low,mid,high;
   int i;
   for (i=1;i<count;i++){
        //tempָ��ǰ��Ҫ����������Ǹ���
        int temp = numbers[i];
        //��ʱ��low��high�ֱ�ָ�����������ͷ��β
        low = 0;
        high = i-1;
        while (low <= high){
            mid = (low+high)/2;
            if (numbers[mid] > temp){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        //ʱ�̼�סlow�����µ�Ԫ����Ҫ�����λ��
        for (int j=i-1;j>=low;j--){
            numbers[j+1] = numbers[j];
        }
        numbers[low] = temp;
   }
}
