# C语言竞赛速查笔记

## 一、输入输出

### scanf / printf

```c
int n; scanf("%d", &n);
long long x; scanf("%lld", &x);
char s[100]; scanf("%s", s);        // 读到空白为止，无&
char c; scanf(" %c", &c);           // 空格跳过空白
int a, b; scanf("%d%d", &a, &b);    // 连续读

printf("%d\n", n);
printf("%lld\n", x);
printf("%.2f\n", 3.1415);           // 保留2位小数
```

### getchar / putchar

```c
int c = getchar();    // 读一个字符（包括空格换行）
putchar(c);           // 输出一个字符
```

### gets 已废弃，用 fgets

```c
char s[100];
fgets(s, 100, stdin);               // 读一行（含换行符），最多读 99 个字符 + '\0'
int len = strlen(s);                // strlen: 计算字符串长度（不含 '\0'）
if (s[len - 1] == '\n') s[--len] = 0;  // 去掉末尾换行
```

### 快速读入（竞赛常用）

```c
int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}
```

### 注意事项
- **地址符 &**：非数组变量要加 `&`，数组名本身就是地址
- **缓冲区**：`scanf` 和 `getchar` 混用时注意换行符残留
- **回车处理**：读完整数后用 `getchar()` 吃掉换行，再读字符/字符串

---

## 二、数组

### 一维数组

```c
int a[100] = {0};          // 全部初始化为0
int a[100] = {1,2,3};      // 前三个赋值，其余0
int n; scanf("%d", &n);
int a[n];                  // C99 VLA，竞赛可用，但不要太大
```

### 二维数组

```c
int g[100][100] = {0};     // 全部初始0
int g[100][100] = {{1,2},{3,4}};

// 传参给函数
void func(int n, int m, int a[][100]) { ... }
// 或者
void func(int n, int m, int (*a)[100]) { ... }
```

### memset（需 string.h）

```c
#include <string.h>
int a[100];
memset(a, 0, sizeof(a));               // 清零
memset(a, -1, sizeof(a));              // 全部-1
memset(a, 0x3f, sizeof(a));            // 每个字节0x3f ≈ 1e9
```

### memcpy

```c
int b[100];
memcpy(b, a, sizeof(a));               // 复制整个数组
```

### 注意事项
- **数组越界**不报错，是 UB（未定义行为），竞赛中容易产生诡异bug
- VLA 放在栈上，太大（> 10^6）会导致栈溢出，改用全局变量
- 全局数组自动初始化为0，局部数组不会

```c
int g[1000000];                    // 全局，自动清零
void f() { int a[1000000]; }      // 危险！栈可能爆
```

---

## 三、字符串

### 定义与输入

```c
char s[100];                       // 字符数组，最后一个存 '\0'
scanf("%s", s);                    // 读入，自动加 '\0'
printf("%s\n", s);
```

### 常用函数（需 string.h）

```c
strlen(s);                         // 返回字符串长度（不含结尾的 '\0'）
strcmp(a, b);                      // 比较两个字符串：相等返回0，a<b返回负数，a>b返回正数
strncmp(a, b, n);                  // 只比较前 n 个字符
strcpy(dst, src);                  // 把 src 复制到 dst（含 '\0'），不检查 dst 容量
strncpy(dst, src, n);              // 最多复制 n 个字符，不足补 '\0'
strcat(dst, src);                  // 把 src 拼接到 dst 末尾（覆盖 dst 的 '\0'）
strncat(dst, src, n);              // 最多拼接 n 个字符
strchr(s, 'c');                    // 在 s 中找字符 c 首次出现的位置，返回指针；没找到返回 NULL
strrchr(s, 'c');                   // 从右往左找
strstr(s, sub);                    // 在 s 中找子串 sub，返回首次出现的指针；没找到返回 NULL
strtok(s, delim);                  // 按分隔符 delim 切分字符串，会修改原串（用 NULL 续调）
strspn(s, accept);                 // 返回 s 开头连续属于 accept 的字符数
strcspn(s, reject);                // 返回 s 开头连续不在 reject 中的字符数（常用: 去掉换行符）
```

### 注意事项
- 确保目标数组够大，strcpy/strcat 不检查长度，溢出是 UB
- 字符数字转整数：`c - '0'`
- 大写转小写：`c + 32` 或 `c - 'A' + 'a'`
- strtok 会修改原始字符串，不可传字符串字面量

---

## 四、指针

### 基础

```c
int a = 5;
int *p = &a;             // p 指向 a
*p = 10;                  // 通过p修改a
```

### 指针与数组

```c
int a[5] = {1,2,3,4,5};
int *p = a;               // 等价于 p = &a[0]
p[0] == a[0];             // true
*(a+1) == a[1];           // true
```

### malloc / free / calloc / realloc（需 stdlib.h）

```c
// malloc: 分配 n*sizeof(int) 字节，返回 void*，需强转
int *p = (int*)malloc(n * sizeof(int));
if (p == NULL) { ... }    // 检查分配失败
free(p);                   // free: 释放 malloc/calloc/realloc 分配的内存

// calloc: 分配并自动清零（n 个元素，每个 size 字节）
int *q = (int*)calloc(n, sizeof(int));

// realloc: 调整已分配内存大小（可能移动内存）
p = (int*)realloc(p, new_n * sizeof(int));

// 二维动态数组
int **g = (int**)malloc(n * sizeof(int*));     // 先分配行指针数组
for (int i = 0; i < n; i++)
    g[i] = (int*)malloc(m * sizeof(int));      // 再逐行分配
```

### 函数指针

```c
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
qsort(arr, n, sizeof(int), cmp);
```

### 注意事项
- malloc 后必须检查 NULL
- 分配的内存一定要 free，否则内存泄漏
- **野指针**：未初始化的指针乱写会崩

---

## 五、常用库函数

### stdlib.h

```c
abs(x);                    // int 绝对值（如 abs(-5) → 5）
labs(x);                   // long 绝对值
llabs(x);                  // long long 绝对值（C99）
srand(time(NULL)); rand(); // 初始化随机种子，生成 [0, RAND_MAX] 的随机数
rand() % n;                // 生成 [0, n-1] 的随机数（分布不均匀，竞赛够用）
qsort(arr, n, sizeof(T), cmp);   // 快速排序，需自定义 cmp 比较函数
bsearch(&key, arr, n, sizeof(T), cmp);  // 二分查找，数组必须已排序，返回指针或 NULL
atoi(s); atol(s); atoll(s);      // 字符串 → int/long/long long（如 atoi("123") → 123）
strtol(s, &end, base);           // 字符串 → long，base 指定进制（2~36），end 指向未转部分
```

### math.h（需链接 -lm）

```c
sqrt(x);                   // 平方根（double）
cbrt(x);                   // 立方根（C99）
pow(x, y);                 // x 的 y 次方（double，注意浮点误差）
fabs(x);                   // double 绝对值
floor(x);                  // 向下取整（如 floor(3.9) → 3.0）
ceil(x);                   // 向上取整（如 ceil(3.1) → 4.0）
round(x);                  // 四舍五入（C99）
fmod(x, y);                // 浮点数取模（x % y）
exp(x); log(x); log10(x);  // e^x, ln x, log₁₀ x
sin(x); cos(x); tan(x);    // 三角函数，x 是弧度
asin(x); acos(x); atan(x); // 反三角函数
```

### string.h

```c
memset(p, val, n);         // 把 p 指向的前 n 个字节全设为 val（按字节操作！）
memcpy(dst, src, n);       // 从 src 复制 n 个字节到 dst（不要重叠）
memmove(dst, src, n);      // 同 memcpy，但支持源和目标重叠
memcmp(a, b, n);           // 比较 a 和 b 的前 n 个字节，返回 <0 / =0 / >0
memchr(p, c, n);           // 在 p 的前 n 个字节中找字符 c，返回指针或 NULL
```

### ctype.h（字符处理）

```c
isalpha(c);                // 是否是字母（a-z / A-Z）
isdigit(c);                // 是否是数字（0-9）
isalnum(c);                // 是否是字母或数字
islower(c);                // 是否小写字母
isupper(c);                // 是否大写字母
isspace(c);                // 是否空白符（空格、\t、\n、\v、\f、\r）
tolower(c);                // 转小写，非字母原样返回
toupper(c);                // 转大写，非字母原样返回
```

### limits.h / float.h（类型范围）

```c
INT_MAX / INT_MIN          // int 最大值 2³¹⁻¹ / 最小值 -2³¹
LONG_MAX / LONG_MIN        // long 最大值 / 最小值
LLONG_MAX / LLONG_MIN      // long long 最大值 / 最小值
SIZE_MAX                   // size_t 最大值
DBL_MAX / DBL_MIN          // double 最大值 / 最小值
```

### 常用宏

```c
NULL                       // 空指针常量，通常为 ((void*)0)
EOF                        // 文件结束标志，通常为 -1
EXIT_SUCCESS / EXIT_FAILURE// exit() 退出码
```

---

## 六、常见算法模板

### 快速排序

```c
// qsort 的比较函数：参数是 const void*，需强转后解引用
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;       // 升序
    // return *(int*)b - *(int*)a;    // 降序
}
qsort(a, n, sizeof(int), cmp);       // qsort: 快速排序，O(n log n)
```

### 二分查找（手动）

```c
int l = 0, r = n - 1;
while (l <= r) {
    int m = l + (r - l) / 2;         // 防溢出
    if (a[m] == target) { ...; break; }
    else if (a[m] < target) l = m + 1;
    else r = m - 1;
}
```

### 数组模拟栈

```c
int stk[100000], top = -1;
stk[++top] = x;       // push
x = stk[top--];       // pop
top == -1 ? empty;    // 判空
stk[top];             // 取栈顶
```

### 数组模拟队列

```c
int q[100000], head = 0, tail = 0;
q[tail++] = x;         // enqueue
x = q[head++];         // dequeue
head == tail ? empty;  // 判空
```

### 邻接表（链式前向星）

```c
int head[100010], to[200010], nxt[200010], w[200010], idx = 0;

void add_edge(int u, int v, int wt) {
    to[idx] = v; w[idx] = wt;
    nxt[idx] = head[u]; head[u] = idx++;
}
// 遍历 u 的邻接点
for (int i = head[u]; i != -1; i = nxt[i]) {
    int v = to[i], wt = w[i];
}
```

---

## 七、竞赛常见坑

| 问题 | 说明 |
|------|------|
| **int 溢出** | 10^9 * 10^9 会炸，用 `long long` |
| **数组开小** | 多开 5~10 个防止越界 |
| **未初始化** | 局部变量不是0，要手动清零 |
| **scanf 漏 &** | 非数组变量务必加 & |
| **字符串改字面量** | `char *s = "abc"; s[0]='x';` 是 UB |
| **除零** | n % 0 会崩 |
| **忘记 return** | 非 void 函数不 return 是 UB |
| **全局变量和局部同名** | 局部优先，容易踩坑 |
| **中文路径/文件名** | 部分 OJ 不支持，用英文 |

---

## 八、编译命令

```bash
gcc source.c -o program -Wall -Wextra -std=c99
gcc source.c -o program -O2 -std=c99       # 竞赛常用优化
```

---

## 九、高频算法模板（取自你 LeetCode 题解）

### 1. 贪心

**跳跃游戏** — 维护最远可达位置
```c
bool canJump(int* nums, int numsSize) {
    int maxX = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > maxX) return false;
        if (i + nums[i] > maxX) maxX = i + nums[i];
        if (maxX >= numsSize - 1) return true;
    }
    return true;
}
```

**买卖股票 II** — 累加所有正差价
```c
int maxProfit(int* prices, int pricesSize) {
    int W = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1])
            W += prices[i] - prices[i - 1];
    }
    return W;
}
```

**整数转罗马数字** — 查表贪心
```c
char* intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    char* result = (char*)malloc(20 * sizeof(char));  // malloc: 堆上分配 20 字节
    result[0] = '\0';                                  // 初始化为空串（strcat 的前提）
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);                // strcat: 将 symbols[i] 拼到 result 末尾
            num -= values[i];
        }
    }
    return result;
}
```

---

### 2. 双指针

**移除元素** — 快慢指针原地删除
```c
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
```

**删除有序数组重复项** — 快慢指针保留唯一
```c
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int n = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[n - 1] != nums[i]) {
            nums[n++] = nums[i];
        }
    }
    return n;
}
```

**删除有序数组重复项 II** — 每个数最多2次
```c
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 3) return numsSize;
    int n = 2;
    for (int i = 2; i < numsSize; i++) {
        if (nums[n - 2] != nums[i]) {
            nums[n++] = nums[i];
        }
    }
    return n;
}
```

**合并两个有序数组** — 三指针从后往前
```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
    while (j >= 0) nums1[k--] = nums2[j--];
}
```

**验证回文串** — 跳过非字母数字
```c
bool isPalindrome(char* s) {
    int i = 0, l = strlen(s) - 1;     // strlen: O(n) 计算长度，循环前算好避免反复调用
    while (i < l) {
        while (i < l && !isalnum(s[i])) i++;   // isalnum: 判断是否字母或数字
        while (i < l && !isalnum(s[l])) l--;
        if (i >= l) break;
        if (tolower(s[i]) != tolower(s[l])) return false;  // tolower: 大写转小写
        i++; l--;
    }
    return true;
}
```

**反转字符串中的单词** — 三步法
```c
void change(char *s, int f, int l) {
    for (; f < l; f++, l--) {
        int t = s[f]; s[f] = s[l]; s[l] = t;
    }
}
// 整体反转 → 逐词反转 → 清理空格
```

**判断子序列** — 双指针扫描
```c
bool isSubsequence(char* s, char* t) {
    int n = 0;
    if (strlen(s) == 0) return true;   // strlen: 空串直接返回 true
    for (int i = 0; t[i] != '\0'; i++) {
        if (s[n] == t[i]) {
            n++;
            if (n == strlen(s)) return true;  // 注意：这里 strlen 每次重算，可优化为只算一次
        }
    }
    return false;
}
```

---

### 3. 链表操作

**环形链表** — 快慢指针判环
```c
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

**合并两个有序链表** — 哑节点
```c
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* cur = &dummy;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            cur->next = list1; list1 = list1->next;
        } else {
            cur->next = list2; list2 = list2->next;
        }
        cur = cur->next;
    }
    cur->next = list1 ? list1 : list2;
    return dummy.next;
}
```

---

### 4. 动态规划 / 线性扫描

**买卖股票 I** — 跟踪最低价和最大利润
```c
int maxProfit(int* prices, int pricesSize) {
    int minW = prices[0], maxW = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minW) minW = prices[i];
        else if (prices[i] - minW > maxW) maxW = prices[i] - minW;
    }
    return maxW;
}
```

---

### 5. 数组操作

**除自身以外数组的乘积** — 前缀积 × 后缀积
```c
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(numsSize * sizeof(int));
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++)
        answer[i] = answer[i-1] * nums[i-1];
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= right;
        right *= nums[i];
    }
    *returnSize = numsSize;
    return answer;
}
```

**多数元素** — Boyer-Moore 投票算法
```c
int majorityElement(int* nums, int numsSize) {
    int x = nums[0], count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == x) count++;
        else {
            count--;
            if (count == 0) { x = nums[i]; count = 1; }
        }
    }
    return x;
}
```

---

### 6. 字符串处理

**最长公共前缀** — 纵向扫描
```c
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];
    for (int y = 0; strs[0][y] != '\0'; y++) {
        for (int x = 1; x < strsSize; x++) {
            if (strs[x][y] != strs[0][y]) {
                char* res = (char*)malloc((y + 1) * sizeof(char));  // malloc: 分配 (y+1) 字节
                strncpy(res, strs[0], y);  // strncpy: 复制前 y 个字符，不自动加 '\0'
                res[y] = '\0';             // 手动加字符串终止符
                return res;
            }
        }
    }
    char* res = (char*)malloc((strlen(strs[0]) + 1) * sizeof(char));  // strlen: 算长度
    strcpy(res, strs[0]);                  // strcpy: 完整复制字符串（含 '\0'）
    return res;
}
```

**二进制求和** — 模拟进位，结果反转
```c
char* addBinary(char* a, char* b) {
    int lenA = strlen(a), lenB = strlen(b);  // strlen: 分别获取两个字符串长度
    int maxLen = lenA > lenB ? lenA : lenB;
    char* res = (char*)malloc(maxLen + 2);    // malloc: +2 给进位和 '\0' 留空间
    int idx = 0, carry = 0;
```

**赎金信** — 字符计数数组（'a'~'z' 的哈希表）
```c
bool canConstruct(char* ransomNote, char* magazine) {
    int let[26] = {0};
    if (strlen(ransomNote) > strlen(magazine)) return false;  // strlen: 比较长度，快速剪枝
    for (int i = 0; i < strlen(ransomNote); i++) let[ransomNote[i] - 'a']++;
    for (int i = 0; i < strlen(magazine); i++) let[magazine[i] - 'a']--;
    for (int i = 0; i < 26; i++) if (let[i] > 0) return false;
    return true;
}
// ⚠ 注意：循环条件中多次调用 strlen，可提前用变量保存长度优化性能
```

**最后一个单词长度** — 从右往左
```c
int lengthOfLastWord(char *s) {
    int len = 0, i = strlen(s) - 1;  // strlen: 获取总长度，从末尾开始遍历
```

**罗马数字转整数** — 左到右扫描，处理减法规则
```c
int romanToInt(char* s) {
    int num = 0;
    for (int i = 0; i < strlen(s); i++) {  // strlen: 每次循环都重算，可提前存到变量
```

---

### 7. 子串搜索（暴力）

```c
int strStr(char* haystack, char* needle) {
    int hLen = strlen(haystack), nLen = strlen(needle);  // strlen: 先算好两个长度
```

---

### 8. 排序后处理

**H指数** — 排序后扫描
```c
// qsort 的比较函数：降序排列（b - a）
int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }

int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), cmp);  // qsort: 先排序，再扫描
```

---

## 十、竞赛输入输出专项

### 读不确定数量的整数（到 EOF）

```c
int n;
while (scanf("%d", &n) != EOF) {
    // 处理
}
```

### 读 T 组数据

```c
int T;
scanf("%d", &T);
while (T--) {
    // 每组处理
}
```

### 读一行带空格的字符串

```c
char s[1000];
// 方法1：scanf 正则
scanf("%[^\n]", s); getchar();
// 方法2：fgets
fgets(s, 1000, stdin);
s[strcspn(s, "\n")] = 0;  // strcspn: 返回第一个 '\n' 出现位置，将其替换为 '\0' 去掉换行
```

### 输出样例格式

```c
// 除了最后一组，每组输出后加空行
for (int i = 0; i < T; i++) {
    printf("Case %d: %d\n", i + 1, ans);
    if (i != T - 1) printf("\n");
}
```
