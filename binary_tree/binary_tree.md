### 二叉树的一些总结

-----

#### 二叉树的一些抽象数据类型

```c
//初始化一棵二叉树
void init_tree(BTNode **root_ptr);
//销毁一棵二叉树
void destroy_tree(BTNode **root_ptr);
//根据传入的数组的顺序依次插入节点构造二叉树
void create_tree(BTNode **rootptr, int numbers[]);
//前序遍历
void DLR(BTNode *root);
//中序遍历
void LDR(BTNode *root);
//后序遍历
void LRD(BTNode *root);
//判断这棵树是否为空，为空返回1，否则返回0
void is_empty_tree(BTNode *root);
//在二叉树中查找某一个值并返回结点的位置
BTNode *get_node_position(BTNode *root, int elem);
//返回这棵树的深度
int depth_of_tree(BTNode *root);
//修改某个节点的值
void assign_node_value(BTNode **rootptr, BTNode *cur_node, int elem);
//计算二叉树的叶子节点个数
int numbers_of_leaves(BTNode *root);
```

