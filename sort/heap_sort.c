/*
�������㷨
�㷨��Ϊ�����֣�
1.����ͨ�����鹹��Ϊ�ѣ����ڶѵĶ�����md�ļ�������ϸ˵������
2.�����Ѷ�Ԫ�غ�β��Ԫ�غ�ȥ��β��Ԫ�ز�ά������ѣ�
3.����ִ�еڶ�����
*/
#include<stdio.h>
#include<stdlib.h>

void built_heap(int numbers[], int count);
void remove_top_item(int numbers[], int count);
void heap_sort(int numbers[], int count);

int main()
{
    int count = 10;
    int numbers[10] = {12,3,45,6,19,22,312,89,50,20};
    printf("before heap sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
    //built_heap(numbers,count);
    heap_sort(numbers,count);
    printf("\n");
    printf("after heap sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
    return 0;
}

void built_heap(int numbers[], int count)
{
    for (int i=0;i<count;i++){
        int index=i;
        while (index != 0){
            int parent = (index-1)/2;
            if (numbers[index] <= numbers[parent]){
                break;
            }
            int temp = numbers[index];
            numbers[index] = numbers[parent];
            numbers[parent] = temp;
            index = parent;
        }
    }
}

void remove_top_item(int numbers[], int count)
{
    int i    int count = 10;
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
    return 0;ndex=0;
    while (1){
        int left = 2*index+1;
        int right = 2*index+2;
        if (left >= count) left = index;
        if (right >= count) right = index;
        if (numbers[index] >= numbers[left] && numbers[index] >= numbers[right]){
            break;
        }
        int swap_number;
        if (numbers[left] > numbers[right]){
            swap_number = left;
        }
        else{
            swap_number = right;
        }
        int temp = numbers[index];
        numbers[index] = numbers[swap_number];
        numbers[swap_number] = temp;
        index = swap_number;
    }
    //return result;
}

void heap_sort(int numbers[], int count)
{
    built_heap(numbers,count);
    for (int i=count-1;i>=0;i--){
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        remove_top_item(numbers,i);
    }
}


