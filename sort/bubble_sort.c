/*
冒泡排序(最简单的版本)
*/
#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int numbers[],int count);

int main()
{
    int count = 10;
    int numbers[10] = {12,3,45,6,19,22,312,89,50,20};
    printf("before bubble sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
    bubble_sort(numbers,count);
    printf("\n");
    printf("after bubble sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
}

void bubble_sort(int numbers[],int count)
{
    for (int i=0;i<count;i++){
        for (int j=i+1;j<count;j++){
            if (numbers[i]>=numbers[j]){
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}
