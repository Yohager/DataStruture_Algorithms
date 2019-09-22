/*
分块查找（在顺序查找中引入索引的思想）
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct block{
    int index;
    int *numbers;
}Block;

void build_blocks(int nums[],int block_nums);

int main()
{
    int nums[] = {14,15,4,9,10,17,11,1,2,6,7,8,12,3,5,13,16};

}
