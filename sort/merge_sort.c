/*
归并排序
*/
#include<stdio.h>
#include<stdlib.h>

void merge_sort(int numbers[], int temp[], int start, int end);

int main()
{
    int start = 0;
    int count = 10;
    int numbers[10] = {12,3,45,6,19,22,312,89,50,20};
    int temp[10];
    printf("before merge sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
    merge_sort(numbers,temp,start,count-1);
    printf("\n");
    printf("after merge sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
}

void merge_sort(int numbers[], int temp[], int start, int end)
{
    //给出递归的返回条件
    if (start == end) return ;
    int mid;
    mid = (start + end) / 2;
    merge_sort(numbers, temp, start, mid);
    merge_sort(numbers, temp, mid+1, end);
    int left_index = start;
    int right_index = mid+1;
    int temp_index = left_index;
    while (left_index <= mid && right_index <= end){
        if (numbers[left_index] <= numbers[right_index]){
            temp[temp_index] = numbers[left_index];
            left_index += 1;
        }
        else{
            temp[temp_index] = numbers[right_index];
            right_index += 1;
        }
        temp_index++;
    }
    while (left_index<=mid){
        temp[temp_index++] = numbers[left_index++];
    }
    while (right_index <= end){
        temp[temp_index++] = numbers[right_index++];
    }
    for (int k=start;k<=end;k++){
        numbers[k] = temp[k];
    }
}
