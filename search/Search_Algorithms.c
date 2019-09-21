/*
顺序查找
二分查找
插值查找
斐波那契查找
树表查找
分块查找
哈希查找
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

void quick_sort(int numbers[], int start, int end);
int *order_search(int *numbers, int count, int target);
int *binary_search(int *numbers, int count, int target);
int *interpolation_search(int *numbers, int target, int low, int high);
void Fibonacci(int *F,int size);
int *Fibonacci_search(int *numbers, int count, int target);

int main()
{
    int count;
    int *numbers;
    printf("input the count of numbers:");
    scanf("%d",&count);
    numbers = malloc(sizeof(int)*count);
    int *temp = numbers;
    printf("input the numbers:");
    for (int i=0; i<count; i++){
        scanf("%d",numbers);
        numbers++;
    }
    quick_sort(temp,0,count-1);
    for (int j=0;j<count;j++){
        printf("%d ",temp[j]);
    }
    int target;
    printf("\n");
    printf("input target number:");
    scanf("%d",&target);
    int *result;
    result = interpolation_search(temp,target,0,count-1);
    if (result != NULL) printf("find it！");
    else printf("cannont find it!");
    return 0;
}

int *order_search(int *numbers, int count, int target)
{
    for (int i=0;i<count;i++){
        if (*numbers == target){
            return numbers;
        }
        numbers++;
    }
    return NULL;
}

void quick_sort(int numbers[], int start, int end)
{
    //如果数组中只有一个元素则表示已经有序直接返回
    if (start >= end) return ;
    int low = start;
    int high = end;
    int temp = numbers[low];
    while (low < high){
        //从后往前扫描
        while (low<high && numbers[high]>=temp){
            high--;
        }
        numbers[low] = numbers[high];
        //从前往后扫描
        while (low<high && numbers[low]<=temp){
            low++;
        }
        numbers[high] = numbers[low];
    }
    numbers[low] = temp;
    quick_sort(numbers,start,low-1);
    quick_sort(numbers,low+1,end);
}

int *binary_search(int *numbers, int count, int target)
{
    int low = 0;
    int high = count-1;
    int mid = (low+high)/2;
    while (low<high){
        mid = (low+high)/2;
        if (numbers[mid] == target){
            int *result = &(numbers[mid]);
            return result;
        }
        else if (numbers[mid] < target){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return NULL;
}

int *interpolation_search(int *numbers, int target, int low, int high)
{
     if (low<=high){
        int mid = low + ((target - numbers[low])/(numbers[high] - numbers[low]))*(high - low);
        if (numbers[mid] == target){
            return &(numbers[mid]);
        }
        if (numbers[mid] > target){
            return interpolation_search(numbers,target,low,mid-1);
        }
        if (numbers[mid] < target){
            return interpolation_search(numbers,target,mid+1,high);
        }
    }
    else{
        return NULL;
    }
}

void Fibonacci(int *F, int size)
{
    F[0] = 1;
    F[1] = 1;
    for (int i=2;i<size;i++){
        F[i] = F[i-1] + F[i-2];
    }
}
int *Fibonacci_search(int *numbers, int count, int target)
{
    int low,high,mid;
    int size = 20;
    low = 0;
    high = count-1;
    int Fib[size];
    Fibonacci(Fib,size);
    int k = 0;
    //先找到一个k的值使得F(k)的值最接近于count
    while (Fib[k]-1 < high){
        k++;
    }
    int *new_numbers;
    new_numbers = (int *)malloc((Fib[k])*sizeof(int));
    memcpy(new_numbers,numbers,count);
    //将numbers中已有的所有元素复制到new_numbers中，并将后面的值补为最后一个元素的值
    for (int j=count;j<Fib[k];j++){
        new_numbers[j] = new_numbers[high];
    }
    //将数据补齐后开始进行查找
    while (low <= high){
        mid = low + Fib[k-1] - 1;
        if (new_numbers[mid] == target){
            if (mid < (count-1)) return &(new_numbers[mid]);
            else{
                return &(new_numbers[count-1]);
            }
        }
        if (new_numbers[mid] < target){
            low = mid + 1;
            k = k-2;
        }
        if (new_numbers[mid] > target){
            high = mid - 1;
            k = k-1;
        }
    }
    return NULL;
}

