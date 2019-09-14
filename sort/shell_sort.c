/*
Ï£¶ûÅÅĞò
*/
#include<stdio.h>
#include<stdlib.h>

void shell_sort(int numbers[], int count);

int main()
{
    int count = 10;
    int numbers[10] = {12,3,45,6,19,22,312,89,50,20};
    printf("before shell sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
    shell_sort(numbers,count);
    printf("\n");
    printf("after shell sort: ");
    for (int i=0; i<10; i++){
        printf("%d ",numbers[i]);
    }
}

void shell_sort(int numbers[], int count)
{
    int increment = count;
    while (increment > 1){
        increment = increment/3 + 1;
        int i,j;
        for (i=0;i<count;i+=increment){
            int temp = numbers[i];
            j=0;
            for (j=i-increment;j>=0;j-=increment){
                if (numbers[j] > temp){
                    numbers[j+increment] = numbers[j];
                    numbers[j] = temp;
                }
                else{
                    break;
                }
            }
        }
    }
}
