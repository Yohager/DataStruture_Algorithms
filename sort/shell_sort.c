/*
ϣ������
*/
#include<stdio.h>
#include<stdlib.h>

void insert_sort(int numbers[], int count);

int main()
{
    int count = 10;
    int numbers[10] = {12,3,45,6,19,22,312,89,50,20};
    printf("before insert sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
    insert_sort(numbers,count);
    printf("\n");
    printf("after insert sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
}

void insert_sort(int numbers[], int count)
{
    for (int i=1;i<count;i++){
        //temp�洢����δ����������ȡ�����Ǹ�ֵ
        int temp = numbers[i];
        int j=0;
        for (j=i-1;j>=0;j--){
            if (numbers[j] > temp){
                //ֻҪǰ���ֵ�д���temp�ľͽ�numbers[j]�����ƶ�һ��λ��
                numbers[j+1] = numbers[j];
            }
            else{
                break;
            }
        }
        numbers[j+1] = temp;
    }
}
