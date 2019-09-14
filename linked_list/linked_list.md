### 数据结构之线性表复习

----

#### 顺序表

关于顺序表的知识点主要有关于顺序表的抽象数据结构以及创建，插入，删除元素，查找值以及就地逆置等。

顺序表的一些抽象数据类型：

```c
//ADT 线性表抽象数据类型
//初始化顺序表
void init_list(Sqlist *ptr);
//创建顺序表
void create_list(Sqlist *ptr, int numbers[],int count);
//判断线性表是否为空
int empty_list(Sqlist List);
//清空线性表
void clean_list(Sqlist *ptr);
//将线性表中第i个数据元素返回给elem
void get_elem_list(Sqlist List, int i, int *elem);
//按值查找线性表中的某个元素，查找成功返回位置，否则返回false
int locate_elem_list(Sqlist List, int elem);
//插入新的元素
void insert_elem_list(Sqlist *ptr, int i, int elem);
//删除list中的某个元素并返回其值给elem
void delete_elem_list(Sqlist *ptr, int i, int *elem);
//返回list的长度
int length_list(Sqlist List);
```

对于每个function的详细内容见代码：`order_list.c`

