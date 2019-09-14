/*
插入排序的改进版本一：折半插入排序
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
        //temp指向当前需要进行排序的那个数
        int temp = numbers[i];
        //此时将low和high分别指向有序数组的头和尾
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
        //时刻记住low就是新的元素需要插入的位置
        for (int j=i-1;j>=low;j--){
            numbers[j+1] = numbers[j];
        }
        numbers[low] = temp;
   }
}
