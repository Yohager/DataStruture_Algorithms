/*
计数排序
比较适用于一些比较数据规模较大，数据变化范围较小的数据排序
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
    //进行计数
    for (int i=0; i<count; i++){
        count_numbers[numbers[i]]+=1;
    }
    //将这些值拷贝回原数组中
    int index=0;
    for (int j=0; j<=max_value; j++){
        //将j拷贝count_numbers[k]次到原数组中
        for (int k=1;k<=count_numbers[j];k++){
            numbers[index] = j;
            index++;
        }
    }
}

