# C 语言数据结构学习笔记

---

## 目录
1. [数组 (Array)](#1-数组-array)
2. [链表 (Linked List)](#2-链表-linked-list)
3. [栈 (Stack)](#3-栈-stack)
4. [队列 (Queue)](#4-队列-queue)
5. [哈希表 (Hash Table)](#5-哈希表-hash-table)
6. [二叉树 (Binary Tree)](#6-二叉树-binary-tree)
7. [堆 (Heap)](#7-堆-heap)
8. [图 (Graph)](#8-图-graph)
9. [常用技巧总结](#9-常用技巧总结)

---

## 1. 数组 (Array)

### 1.1 基本概念
数组是**连续内存**中存储的**相同类型**元素的集合。数组名是指向首元素的指针。

```c
int arr[5] = {1, 2, 3, 4, 5};  // 静态分配（栈上）
int *arr2 = (int*)malloc(5 * sizeof(int));  // 动态分配（堆上）
```

### 1.2 关键操作及复杂度

| 操作 | 时间复杂度 | 说明 |
|------|-----------|------|
| 随机访问 `arr[i]` | O(1) | 通过基地址 + 偏移量直接计算 |
| 尾部插入 | O(1) | 有空间则直接写入 |
| 中间插入/删除 | O(n) | 需要移动后续元素 |
| 查找（无序） | O(n) | 需遍历 |
| 查找（有序，二分） | O(log n) | 折半查找 |

### 1.3 常用技巧：双指针
双指针是数组问题最核心的技巧：

```c
// 快慢指针 —— 移除数组中值为 val 的元素，返回新长度
int removeElement(int* nums, int numsSize, int val) {
    int slow = 0;
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}
```

```c
// 对撞指针 —— 两数之和 II（有序数组）
int* twoSum(int* numbers, int size, int target, int* returnSize) {
    int left = 0, right = size - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) break;
        else if (sum < target) left++;
        else right--;
    }
    // 返回 left, right ...
}
```

### 1.4 常用技巧：前缀和
```c
// 构建前缀和：pref[i] = sum(arr[0]..arr[i-1])
int pref[n + 1];
pref[0] = 0;
for (int i = 0; i < n; i++)
    pref[i + 1] = pref[i] + arr[i];

// 区间 [L, R] 的和 = pref[R+1] - pref[L]   （O(1) 查询）
```

### 1.5 C 语言注意事项
- 数组作为函数参数时会**退化为指针**，`sizeof(arr)` 返回的是指针大小而非数组大小，必须显式传递长度。
- 动态分配的内存务必 `free()`，防止内存泄漏。
- 使用 `memset` 清零数组（来自 `<string.h>`）。

---

## 2. 链表 (Linked List)

### 2.1 基本定义
```c
struct ListNode {
    int val;
    struct ListNode *next;
};
```

### 2.2 链表 vs 数组

| 特性 | 数组 | 链表 |
|------|------|------|
| 内存 | 连续 | 分散 |
| 随机访问 | O(1) | O(n) |
| 头部插入/删除 | O(n) | O(1) |
| 尾部插入/删除 | O(1)* | O(n) / O(1)（有尾指针）|
| 额外空间 | 无 | 每个节点一个指针 |

### 2.3 核心操作

#### 反转链表（面试必考）
```c
// 迭代法（推荐）
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head;
    while (curr) {
        struct ListNode *next = curr->next;  // 保存下一个
        curr->next = prev;                   // 反转
        prev = curr;                         // 前移
        curr = next;                         // 前移
    }
    return prev;
}
```

#### 快慢指针找中点 / 判环
```c
// 判断是否有环（Floyd 判圈算法）
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;  // 快慢相遇 = 有环
    }
    return false;
}
```

#### 合并两个有序链表
```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *tail = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) { tail->next = l1; l1 = l1->next; }
        else                   { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;  // 接上剩余部分
    return dummy.next;
}
```

### 2.4 哑结点 (Dummy Node) 技巧
在需要操作头节点的场景（删除、合并），使用哑结点可避免特判空链表：

```c
struct ListNode dummy = {0, head};
struct ListNode *prev = &dummy;
// ... 操作后 return dummy.next;
```

---

## 3. 栈 (Stack)

### 3.1 基本概念
**LIFO**（后进先出）。在 C 中通常用**数组 + 栈顶指针**实现。

```c
typedef struct {
    int *data;
    int top;     // 栈顶索引（-1 表示空栈）
    int capacity;
} Stack;

void push(Stack *s, int val) { s->data[++(s->top)] = val; }
int  pop(Stack *s)          { return s->data[(s->top)--]; }
int  peek(Stack *s)         { return s->data[s->top]; }
bool isEmpty(Stack *s)      { return s->top == -1; }
```

### 3.2 经典场景
- **括号匹配**：遇到 `(` 入栈，遇到 `)` 时检查栈顶。
- **表达式求值**：操作数栈 + 运算符栈。
- **单调栈**：维护栈内元素单调递增/递减，求"下一个更大元素"。

```c
// 单调递减栈模板 —— 找每个元素右边第一个比它大的
for (int i = 0; i < n; i++) {
    while (!isEmpty(&s) && nums[peek(&s)] < nums[i]) {
        int idx = pop(&s);
        ans[idx] = nums[i];  // nums[i] 是 nums[idx] 右边第一个更大的
    }
    push(&s, i);
}
```

---

## 4. 队列 (Queue)

### 4.1 基本概念
**FIFO**（先进先出）。C 中常用**循环队列**节省空间。

```c
typedef struct {
    int *data;
    int front;   // 队首索引
    int rear;    // 队尾索引（下一个插入位置）
    int capacity;
} Queue;

void enqueue(Queue *q, int val) {
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % q->capacity;
}
int dequeue(Queue *q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return val;
}
```

### 4.2 循环队列的判空与判满
- **浪费一个位置法**（最常用）：
  - 空：`front == rear`
  - 满：`(rear + 1) % capacity == front`
  - 实际容量 = capacity - 1

### 4.3 经典场景
- **BFS 层级遍历**。
- **滑动窗口**（配合双端队列 deque）。
- **生产者-消费者模型**。

---

## 5. 哈希表 (Hash Table)

### 5.1 基本概念
通过**哈希函数**将键映射到数组索引，实现 O(1) 平均查找。

### 5.2 简单实现：拉链法
```c
#define SIZE 10007  // 取质数减少冲突

typedef struct HashNode {
    int key;
    int val;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **buckets;
} HashMap;

int hash(int key) {
    return (key % SIZE + SIZE) % SIZE;  // 处理负数
}

void put(HashMap *map, int key, int val) {
    int h = hash(key);
    HashNode *node = map->buckets[h];
    while (node) {
        if (node->key == key) { node->val = val; return; }
        node = node->next;
    }
    // 头插法插入新节点 ...
}
```

### 5.3 常用技巧：数组当哈希表
当键的范围有限时（如字母、ASCII），直接用数组替代：

```c
int count[26] = {0};           // 统计小写字母频率
int map[256] = {0};            // 字符映射（同构字符串）
int idx[100001] = {0};         // 值 → 下标的映射
```

### 5.4 经典场景
- **两数之和**：遍历时查 `target - num` 是否在哈希表中。
- **字符频率统计**。
- **快速去重**。

---

## 6. 二叉树 (Binary Tree)

### 6.1 基本定义
```c
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
```

### 6.2 遍历方式（必须熟练）

| 遍历方式 | 顺序 | 递归代码 |
|----------|------|----------|
| 先序 (preorder) | 根 → 左 → 右 | `visit(root); pre(l); pre(r);` |
| 中序 (inorder) | 左 → 根 → 右 | `in(l); visit(root); in(r);` |
| 后序 (postorder) | 左 → 右 → 根 | `post(l); post(r); visit(root);` |
| 层序 (levelorder) | 逐层 | 使用队列 BFS |

```c
// 先序遍历（递归）
void preorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
```

### 6.3 二叉搜索树 (BST)
**性质**：左子树所有节点 < 根 < 右子树所有节点。

- 查找：O(log n) 平均，O(n) 最坏（退化成链）。
- **中序遍历 BST = 升序序列**（重要结论！）。

```c
// 验证 BST：递归传递上下界
bool isValidBST(struct TreeNode* root, long min, long max) {
    if (!root) return true;
    if (root->val <= min || root->val >= max) return false;
    return isValidBST(root->left, min, root->val)
        && isValidBST(root->right, root->val, max);
}
```

### 6.4 常用技巧
- **递归三板斧**：终止条件 → 处理当前节点 → 递归子树。
- **对称性判断**：双指针同步遍历左右子树。
- **深度计算**：`1 + max(maxDepth(left), maxDepth(right))`。
- **路径问题**：DFS + 回溯。

---

## 7. 堆 (Heap)

### 7.1 基本概念
堆是一棵**完全二叉树**，满足堆序性质：
- **最小堆**：父节点 ≤ 子节点（根最小）。
- **最大堆**：父节点 ≥ 子节点（根最大）。

用**数组**存储：节点 i 的左子 = `2*i+1`，右子 = `2*i+2`，父 = `(i-1)/2`。

### 7.2 核心操作

| 操作 | 复杂度 | 说明 |
|------|--------|------|
| 插入 | O(log n) | 上浮 (sift-up / bubble-up) |
| 取堆顶 | O(1) | 返回 arr[0] |
| 删除堆顶 | O(log n) | 交换末尾后下沉 (sift-down) |
| 建堆 | O(n) | 从最后非叶节点向前逐个下沉 |

```c
// 最小堆 — 下沉操作（核心）
void siftDown(int *heap, int size, int i) {
    while (1) {
        int smallest = i;
        int left  = 2 * i + 1;
        int right = 2 * i + 2;

        if (left  < size && heap[left]  < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest == i) break;  // 已满足堆序
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}
```

### 7.3 经典场景
- **Top K 问题**：最小堆维护前 K 大的元素。
- **优先队列**：Dijkstra、任务调度。
- **堆排序**：建堆 → 依次取堆顶，O(n log n)。
- **数据流中位数**：双堆（最大堆存较小半 + 最小堆存较大半）。

---

## 8. 图 (Graph)

### 8.1 存储方式

#### 邻接矩阵
```c
int graph[MAX_N][MAX_N];  // graph[i][j] = 1 表示 i→j 有边
// 优点：O(1) 判边，缺点：O(V²) 空间
```

#### 邻接表（推荐）
```c
// 链式前向星（竞赛常用，性能最优）
int head[MAX_N], to[MAX_M], nxt[MAX_M], idx = 0;

void addEdge(int u, int v) {
    to[idx] = v;
    nxt[idx] = head[u];
    head[u] = idx++;
}
// 遍历 u 的所有邻居：
for (int e = head[u]; e != -1; e = nxt[e]) {
    int v = to[e];
    // ...
}
```

### 8.2 遍历

#### DFS（栈 / 递归）
```c
bool visited[MAX_N];
void dfs(int u) {
    visited[u] = true;
    for (int e = head[u]; e != -1; e = nxt[e]) {
        int v = to[e];
        if (!visited[v]) dfs(v);
    }
}
```

#### BFS（队列）
```c
// 求无权图最短路径
int bfs(int start, int target) {
    int dist[MAX_N];
    memset(dist, -1, sizeof(dist));

    int q[MAX_N], front = 0, rear = 0;
    q[rear++] = start;
    dist[start] = 0;

    while (front < rear) {
        int u = q[front++];
        if (u == target) return dist[u];
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q[rear++] = v;
            }
        }
    }
    return -1;  // 不可达
}
```

### 8.3 经典算法

| 算法 | 用途 | 复杂度 |
|------|------|--------|
| DFS | 连通分量、拓扑排序、找桥 | O(V+E) |
| BFS | 无权最短路径 | O(V+E) |
| Dijkstra | 非负权单源最短路径 | O((V+E) log V) |
| Floyd-Warshall | 全源最短路径 | O(V³) |
| Kruskal | 最小生成树（边排序+并查集）| O(E log E) |
| Prim | 最小生成树（点扩展）| O((V+E) log V) |

---

## 9. 常用技巧总结

### 9.1 双指针汇总
| 变体 | 用途 | 模式 |
|------|------|------|
| 快慢指针 | 链表判环、找中点、删除倒数第 N 个 | slow 走一步，fast 走两步 |
| 对撞指针 | 有序数组两数之和、回文验证 | left=0, right=n-1 |
| 读写指针 | 原地去重、移除元素 | slow 指向写入位，fast 扫描 |
| 滑动窗口 | 子串/子数组问题 | 窗口右扩左缩 |

### 9.2 递归设计思路
1. **明确函数定义**：输入什么，返回什么。
2. **基准条件 (base case)**：何时停止递归。
3. **拆分问题**：如何缩小问题规模。
4. **合并结果**：如何用子问题的解答构建当前解答。

### 9.3 常见错误排查
- 指针是否判空 (`NULL`)。
- 循环条件是否可能死循环。
- 数组越界（尤其 `-1` 索引）。
- 递归是否有 base case。
- `malloc` 后是否 `free`。
- 整数溢出（用 `long` 做中间结果）。

### 9.4 数值处理
```c
#include <limits.h>  // INT_MAX, INT_MIN
#include <math.h>    // fmax, fmin, sqrt

// 安全的加法（防溢出）
int safeAdd(int a, int b) {
    if (b > 0 && a > INT_MAX - b) return INT_MAX;
    if (b < 0 && a < INT_MIN - b) return INT_MIN;
    return a + b;
}
```

---

> **参考**：本笔记为 LeetCode 刷题过程中积累的 C 语言数据结构知识点，配合仓库中 `/ByC/` 目录下的题目代码一起学习效果更佳。
