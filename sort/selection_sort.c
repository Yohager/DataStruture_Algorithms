/*
选择排序
*/
#include<stdio.h>
#include<stdlib.h>

void selection_sort(int numbers[], int count);

int main()
{
    int count = 10;
    int numbers[10] = {12,3,45,6,19,22,312,89,50,20};
    printf("before selection sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
    selection_sort(numbers,count);
    printf("\n");
    printf("after selection sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
}


void selection_sort(int numbers[], int count)
{
    for (int i=0;i<count;i++){
        //int temp = numbers[i];
        int index = i;
        for (int j=i+1;j<count;j++){
            //找出最小的值
            if (numbers[index] > numbers[j]){
                //temp = numbers[j];
                index = j;
            }
        }
        int swap = numbers[index];
        numbers[index] = numbers[i];
        numbers[i] = swap;
    }
}
