/*
 *  C++ 算法竞赛笔记
 * ==================
 * 编译: g++ -std=c++17 -O2 -Wall 文件.cpp -o 文件
 */

// ==================== 目录 ====================
// 1. 基本语法与输入输出
// 2. 数组与字符串
// 3. STL 容器
// 4. STL 算法
// 5. 排序
// 6. 二分查找
// 7. 前缀和与差分
// 8. 双指针与滑动窗口
// 9. 贪心算法
// 10. 深度优先搜索 (DFS)
// 11. 广度优先搜索 (BFS)
// 12. 动态规划 (DP)
// 13. 图论
// 14. 并查集
// 15. 最小生成树
// 16. 最短路
// 17. 数论
// 18. 位运算
// 19. 常用技巧与宏
// ==================== 内容 ====================


// ==============================================
// 1. 基本语法与输入输出
// ==============================================

// ---- 基本类型 ----
// int          -> 32位, 约 ±2.1e9        ← 够用但注意: 10⁹ 以内的数相乘会爆!
// long long    -> 64位, 约 ±9e18         ← 竞赛见到 10⁹ 以上直接 long long
// double       -> 64位浮点, 有效15-16位   ← 高精度比较用 abs(a-b) < 1e-9
// char         -> 8位
// bool         -> true/false
//
// 建议: 除非内存极紧, 涉及整数的变量全用 long long, 省心防溢出
//       long long 被 GCC 编译后和 int 速度几乎一样

// ---- 常量 ----
const int INF = 0x3f3f3f3f;        // 约 1e9, 用于初始化最小值
// 为什么是 0x3f3f3f3f? 因为 memset 按字节赋值, 0x3f 每个字节,
// 所以 int 变成 0x3f3f3f3f, 且满足 INF + INF < INT_MAX 不会溢出
const long long LINF = 4e18;       // long long 的无穷大 (约等于 9e18 的一半)
const int MOD = 1000000007;        // 常用模数 (另一个常用: 998244353)
// 注意: MOD 取 1e9+7 是因为它在 int 范围内且是质数, 方便求逆元

// ---- 输入输出 ----
// 方法1: scanf/printf (快, C风格)
int a; long long b; char s[100];
scanf("%d%lld%s", &a, &b, s);
printf("%d %lld %s\n", a, b, s);

// 方法2: cin/cout (需加速, 之后就和 scanf 一样快)
ios::sync_with_stdio(false);
cin.tie(nullptr);
// 注意: 加速后不要混用 cin 和 scanf
int x; string str;
cin >> x >> str;
cout << x << ' ' << str << '\n';   // 用 '\n' 别用 endl

// 方法3: 快读 (竞赛手写, 读整数极快)
// 为什么需要快读? cin 加速后其实够用, 但少数题目输入量极大 (10⁶+),
// 用 getchar 快读能进一步提速, 尤其是读入量大的竞赛题
int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}
// 如果题目涉及 long long, 改返回值类型和 x 为 long long 即可

// ---- 浮点数输出 ----
double d = 3.14159;
printf("%.2f\n", d);               // 保留2位小数
cout << fixed << setprecision(2) << d << '\n';  // 需要 #include <iomanip>


// ==============================================
// 2. 数组与字符串
// ==============================================

// ---- 数组 (全局开默认 0 初始化) ----
// 关键: 全局/静态区 vs 栈区
// 全局区: 可以开很大 (1e7), 默认 0 初始化
// 栈区:   main() 里开太大 (如 1e6) 会栈溢出 crash
// 策略: 大数组一律开全局, 或用 vector
int arr[100005];                    // 全局数组, 较大 (栈上别开太大, 会爆)
const int N = 2e5 + 5;
int a[N];

// ---- memset (按字节赋值, 常用) ----
// 原理: 把每个字节设为指定值, 所以只适合 0, -1, 0x3f 等特殊值
// 不要用 memset 对非 char 数组赋别的值 (如 memset(arr, 1, sizeof(arr)) 不会把每个 int 变 1)
memset(arr, 0, sizeof(arr));        // 全部清 0
memset(arr, -1, sizeof(arr));       // 全部赋 -1 (补码: 全 1)
memset(arr, 0x3f, sizeof(arr));     // 赋 INF (0x3f3f3f3f)
// 注意: memset 按字节, sizeof(arr) 是字节数, 不要写成 sizeof(arr) / sizeof(int) 去掉除!

// ---- C++ string (优先用这个) ----
string s = "hello";
s += " world";                     // 拼接
s.size();                          // 长度 O(1)
s.empty();
s.substr(pos, len);                // 子串 O(len)
s.find("lo");                      // 查找, 找不到返回 string::npos
s.find('o', 3);                    // 从位置3开始找
s.insert(pos, str);                // 插入
s.erase(pos, len);                 // 删除
s.replace(pos, len, str);          // 替换
to_string(123);                    // 数字转字符串
stoi("456");                       // 字符串转 int
stoll("789");                      // 字符串转 long long
// 遍历:
for (char c : s) cout << c;
for (int i = 0; i < s.size(); i++) cout << s[i];

// ---- C 风格字符串 ----
char s[100];
scanf("%s", s);                    // 读取到空格/换行停止
fgets(s, 100, stdin);              // 读取一行 (含空格)
strlen(s); strcmp(s1, s2); strcpy(dest, src);


// ==============================================
// 3. STL 容器
// ==============================================

// 通用方法: .size() .empty() .clear() .begin() .end()

// ---- vector ----
vector<int> v;
v.push_back(1);                    // O(1) 尾部添加
v.pop_back();                      // O(1) 删除尾部
v.back(); v.front();
v.insert(v.begin() + 2, 10);       // O(n) 插入
v.erase(v.begin() + 2);            // O(n) 删除
v.resize(10);                      // 调整大小
// 二维
vector<vector<int>> mat(n, vector<int>(m, 0));

// ---- stack ----
stack<int> st;
st.push(1); st.pop(); st.top();

// ---- queue ----
queue<int> q;
q.push(1); q.pop(); q.front(); q.back();

// ---- deque (双端队列) ----
deque<int> dq;
dq.push_front(1); dq.push_back(2);
dq.pop_front(); dq.pop_back();
dq.front(); dq.back();

// ---- priority_queue (优先队列) ----
// 贪心算法和 Dijkstra 最短路的核心工具
priority_queue<int> pq;                        // 最大堆 (默认, top() 返回最大值)
priority_queue<int, vector<int>, greater<int>> pq_min;  // 最小堆
// 自定义结构体:
// 注意: priority_queue 默认是 less (最大堆), operator< 返回 true 表示 a 优先级低于 b
// 所以重载 operator< 为 > 会得到小顶堆, 这点容易搞混, 建议用 lambda 方式:
struct Node {
    int dist, id;
    bool operator<(const Node& other) const {
        return dist > other.dist;   // 小顶堆 (按 dist 升序)
    }
};
priority_queue<Node> pq_node;
// 替代方案 (不重载 operator<):
auto cmp = [](Node a, Node b) { return a.dist > b.dist; };
priority_queue<Node, vector<Node>, decltype(cmp)> pq_custom(cmp);

// ---- pair (键值对) ----
pair<int, int> p = {1, 2};
p.first; p.second;
// 排序: 先比 first, 再比 second

// ---- tuple (C++11) ----
tuple<int, int, int> t = {1, 2, 3};
get<0>(t); get<1>(t); get<2>(t);

// ---- map / unordered_map ----
// 什么时候用 map, 什么时候用 unordered_map?
// 需要有序遍历 / lower_bound -> map (红黑树 O(log n))
// 只要快速增删查 -> unordered_map (哈希 O(1))
// 但注意: unordered_map 有常数大, 且会被特殊构造的测试数据卡成 O(n)!
// 竞赛图省心, 数据量不大时直接用 map
map<string, int> mp;               // O(log n), 有序 (红黑树)
unordered_map<string, int> ump;    // O(1) 均摊, 无序 (哈希表)
// 用法相同:
mp["key"] = 1;                     // 注意: [] 如果 key 不存在会自动插入!
// 所以只查不插时用 .count() 或 .find()
mp.count("key");                   // 是否存在: 1/0
mp.find("key");                    // 迭代器, mp.end() 表示不存在
mp.erase("key");
for (auto& [k, v] : mp) cout << k << ' ' << v << '\n';  // C++17 结构化绑定

// ---- set / unordered_set ----
set<int> st;                       // 有序, O(log n)
unordered_set<int> ust;            // 无序, O(1)
st.insert(5);
st.count(5);
st.erase(5);
// 常用: 用 set 去重/查是否存在

// ---- multiset (允许重复) ----
multiset<int> ms;
ms.insert(5);
ms.erase(ms.find(5));              // 只删一个
ms.erase(5);                       // 删所有等于5的元素
// 注意: multiset 的 erase(val) 会删除所有等于 val 的元素!

// ---- 迭代器 ----
// .begin() .end()
// 遍历:
for (auto it = v.begin(); it != v.end(); ++it) cout << *it;
// 对有序容器 lower_bound / upper_bound:
auto it = st.lower_bound(5);       // 第一个 >= 5
auto it2 = st.upper_bound(5);      // 第一个 > 5


// ==============================================
// 4. STL 算法 (<algorithm>)
// ==============================================

vector<int> a = {5, 2, 8, 1, 9};

sort(a.begin(), a.end());                          // 升序
sort(a.begin(), a.end(), greater<int>());          // 降序
sort(a.begin(), a.end(), [](int x, int y) {
    return x > y;                                  // lambda 自定义
});

reverse(a.begin(), a.end());                       // 反转
rotate(a.begin(), a.begin() + 2, a.end());         // 旋转

// 去重 (先排序!)
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());

// 二分查找 (有序数组)
binary_search(a.begin(), a.end(), 5);              // 返回 bool
lower_bound(a.begin(), a.end(), 5);                // 第一个 >= 5
upper_bound(a.begin(), a.end(), 5);                // 第一个 > 5
// 转下标:
int pos = lower_bound(a.begin(), a.end(), 5) - a.begin();

// 最值
*max_element(a.begin(), a.end());
*min_element(a.begin(), a.end());

// 和 (#include <numeric>)
long long sum = accumulate(a.begin(), a.end(), 0LL);

// 填充
fill(a.begin(), a.end(), 0);

// 全排列
next_permutation(a.begin(), a.end());              // 下一个排列
prev_permutation(a.begin(), a.end());              // 上一个排列

// 合并
vector<int> b = {3, 6, 7};
vector<int> c(a.size() + b.size());
merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());  // 合并有序


// ==============================================
// 5. 排序
// ==============================================

// O(n log n): sort (快速排序)
// O(n²): 冒泡/选择/插入 (n ≤ 5000 可用)
// O(n + k): 计数排序 (值域小)

// 自定义排序:
struct Student { string name; int score; };
vector<Student> stu;
// 按分数降序, 分数相同按名字升序
sort(stu.begin(), stu.end(), [](const Student& a, const Student& b) {
    if (a.score != b.score) return a.score > b.score;
    return a.name < b.name;
});


// ==============================================
// 6. 二分查找
// ==============================================

// 二分答案: 当答案单调时, 在值域上二分
// 核心思想: 对于 "最大值最小化" 或 "最小值最大化" 问题,
// 在答案值域上二分, 用 check(mid) 验证可行性
// 复杂度: O(log(值域) × check 的复杂度)

// 模板: 找第一个 >= target (开区间写法, 区间 [l, r))
int lower_bound(vector<int>& a, int target) {
    int l = 0, r = a.size();  // r = size (开区间, 不包含)
    while (l < r) {           // l == r 时跳出
        int mid = (l + r) / 2;
        if (a[mid] >= target) r = mid;   // 左移右边界
        else l = mid + 1;                // 右移左边界
    }
    return l;  // 返回第一个 >= target 的下标
}
// 等价闭区间写法:
// int l = 0, r = n - 1;
// while (l < r) { int mid = (l+r)/2; if (a[mid] >= target) r = mid; else l = mid+1; }
// return a[l] >= target ? l : n;

// 模板: 找最后一个 <= target
int upper_bound(vector<int>& a, int target) {
    int l = 0, r = a.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] > target) r = mid;   // 注意: 这里是 >
        else l = mid + 1;
    }
    return l - 1;  // 最后一个 <= target
}
// 记忆: lower = 左闭右开, upper = 第一个 > target
// (l+r+1)/2 的右中位数写法也常用, 回头查一下记熟的模板即可
// 比赛里直接用 std::lower_bound / std::upper_bound 最省事

// 模板: 浮点数二分 (求平方根)
double sqrt_bin(double x) {
    double l = 0, r = x;
    for (int i = 0; i < 100; i++) {  // 迭代足够多次
        double mid = (l + r) / 2;
        if (mid * mid >= x) r = mid;
        else l = mid;
    }
    return l;
}


// ==============================================
// 7. 前缀和与差分
// ==============================================

// ---- 一维前缀和 ----
// 原数组 a[1..n], 前缀和 s[i] = a[1] + ... + a[i]
vector<int> s(n + 1, 0);           // s[0] = 0
for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
// 区间 [l, r] 和 = s[r] - s[l - 1]

// ---- 二维前缀和 ----
// s[i][j] = sum of a[1..i][1..j]
vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
// 子矩阵 (x1,y1) 到 (x2,y2) 和:
// sum = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]

// ---- 差分 ----
// 对 a[l..r] += c: diff[l] += c, diff[r+1] -= c
vector<int> diff(n + 2, 0);
diff[l] += c; diff[r + 1] -= c;
// 处理完所有操作后, 前缀和还原:
for (int i = 1; i <= n; i++) diff[i] += diff[i - 1];


// ==============================================
// 8. 双指针与滑动窗口
// ==============================================

// ---- 双指针适用范围 ----
// 要求数据有单调性 (通常先排序)
// 核心: 两个指针同向或相向移动, 每次至少移一个, O(n)
// 比二分的 O(n log n) 有时更优

// 双指针: 有序数组两数之和
int i = 0, j = n - 1;
while (i < j) {
    int sum = a[i] + a[j];
    if (sum == target) break;
    else if (sum < target) i++;
    else j--;
}

// 滑动窗口: 找最短子数组和 >= target
// 适用于: 子数组/子串问题, 要求连续
// 核心: 右指针扩张, 左指针收缩, 维护窗口内的某种性质
int l = 0, sum = 0, ans = INF;
for (int r = 0; r < n; r++) {
    sum += a[r];              // 右指针加入
    while (sum >= target) {   // 窗口满足条件, 尝试收缩左指针
        ans = min(ans, r - l + 1);
        sum -= a[l++];        // 左指针移除
    }
}
// 另一种常见: 固定窗口大小 (如最长无重复子串)
// 用 unordered_map 维护窗口内元素的出现次数
    }
}


// ==============================================
// 9. 贪心算法
// ==============================================

// 关键是证明: 局部最优 -> 全局最优
// 常见题型: 区间调度, 哈夫曼编码, 最小生成树, 最短路
// 例: 区间选点/区间覆盖, 按结束时间排序


// ==============================================
// 10. 深度优先搜索 (DFS)
// ==============================================

// ---- 全排列 ----
int vis[10], perm[10];
void dfs(int k, int n) {
    if (k == n) {
        for (int i = 0; i < n; i++) cout << perm[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            perm[k] = i;
            dfs(k + 1, n);
            vis[i] = 0;   // 回溯
        }
    }
}

// ---- 子集枚举 (选或不选) ----
vector<int> chosen;
void subset(int k, int n) {
    if (k == n) {
        for (int x : chosen) cout << x << ' ';
        cout << '\n';
        return;
    }
    // 不选
    subset(k + 1, n);
    // 选
    chosen.push_back(k);
    subset(k + 1, n);
    chosen.pop_back();
}

// ---- DFS vs BFS 怎么选? ----
// DFS: 适合 "有没有解" "所有解" "连通块数量"
//      递归实现简单, 但深度大时 (≥10⁵) 可能爆栈
// BFS: 适合 "最短路径" "最少步数"
//      队列实现, 第一次到达目标就是最短, 不会爆栈
// 技巧: 如果 BFS 状态空间很大但深度浅, BFS 好用
//       如果深度可能很深但分支不宽, DFS 好用

// ---- 网格 DFS (岛屿数量) ----
int grid[100][100], vis_grid[100][100];
int dx[4] = {0, 0, 1, -1};    // 方向数组: 右, 左, 下, 上
int dy[4] = {1, -1, 0, 0};

void dfs_grid(int x, int y, int n, int m) {
    vis_grid[x][y] = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m
            && grid[nx][ny] && !vis_grid[nx][ny])
            dfs_grid(nx, ny, n, m);
    }
}

// ---- 剪枝技巧 (DFS 优化的核心) ----
// 1. 可行性剪枝: 当前状态已不可能满足条件, 提前返回
//    例: 走迷宫还剩 3 步但离终点至少 5 步 -> 直接 return
// 2. 最优性剪枝: 当前代价已 >= 当前最优解, 提前返回
//    例: 找最短路径, 当前长度已 >= 已找到的最短 -> 不用继续了
// 3. 记忆化搜索: 用数组存结果, 避免重复计算
//    例: 斐波那契 f(n) 算过的值存下来, 下次直接用
//    ⇢ 本质 = 递归版 DP


// ==============================================
// 11. 广度优先搜索 (BFS)
// ==============================================

// ---- 网格 BFS (最短步数) ----
// BFS 为什么能找到最短路径?
// 因为队列按层次遍历, 第一次到达目标就是步数最少的那一层
// 核心技巧: dist 数组存起点的距离, 同时充当 visited 标记 (-1=未访问)
int bfs_grid(int sx, int sy, int tx, int ty, int n, int m) {
    int dist[100][100];
    memset(dist, -1, sizeof(dist));   // -1 = 未访问
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == tx && y == ty) return dist[x][y];  // 第一次到达 => 最短

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                && grid[nx][ny] && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;       // 更新距离
                q.push({nx, ny});
            }
        }
    }
    return -1;  // 不可达
}


// ==============================================
// 12. 动态规划 (DP)
// ==============================================

// ---- 斐波那契 (入门) ----
int fib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b; b = c;
    }
    return b;
}

// ---- 01背包 ----
// 01背包: 每件物品 选 或 不选, 只能选一次
// dp[j] = 容量 j 时的最大价值
// 为什么容量要逆序遍历? 因为一维 dp 复用数组,
// j-- 确保 dp[j-w[i]] 是上一轮的值 (即没选当前物品的情况)
// 如果 j++ 就会重复选同一个物品 (变成完全背包了!)
int dp[1005];   // 一维压缩 (相比二维省内存, 但失去了具体选了哪些物品)
for (int i = 0; i < n; i++)          // 遍历物品
    for (int j = cap; j >= w[i]; j--)  // 容量逆序! (关键)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

// ---- 完全背包 ----
// 完全背包: 每件物品可以选无限次
// 为什么容量正序? j++ 意味着 dp[j-w[i]] 可能已经在当前轮被更新过
// (也就是已经选过当前物品), 这样就能重复选同一物品了
// 对比 01 背包: 一个 j-- (禁止重复), 一个 j++ (允许重复)
for (int i = 0; i < n; i++)
    for (int j = w[i]; j <= cap; j++)  // 容量正序! (与 01 背包唯一的区别)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

// ---- 最长递增子序列 (LIS) O(n log n) ----
// 贪心 + 二分: 维护 tails 数组
// tails[i] = 长度为 i+1 的递增子序列的最小可能末尾值
// 末尾越小, 越有利于后续拼接更长的子序列
// 例: a = [10,9,2,5,3,7,101,18]
// tails: [10] -> [9] -> [2] -> [2,5] -> [2,3] -> [2,3,7] -> [2,3,7,101] -> [2,3,7,18]
// 答案: 4
vector<int> tails;
for (int x : a) {
    auto it = lower_bound(tails.begin(), tails.end(), x);
    if (it == tails.end()) tails.push_back(x);  // x 比所有末尾都大 => 增加长度
    else *it = x;                                 // 否则替换第一个 >= x 的末尾
}
// ans = tails.size()
// 注意: tails 存的是长度对应的最小末尾, 不是真正的最长递增子序列!

// ---- 最长公共子序列 (LCS) O(n²) ----
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
// ans = dp[n][m]

// ---- 区间 DP (合并石子) ----
// dp[i][j] = 合并 i..j 的最小代价
vector<vector<int>> dp(n, vector<int>(n, INF));
vector<int> sum(n + 1, 0);
for (int i = 0; i < n; i++) { dp[i][i] = 0; sum[i + 1] = sum[i] + a[i]; }
for (int len = 2; len <= n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        for (int k = i; k < j; k++)
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j + 1] - sum[i]);
    }
}

// ---- 状态压缩 DP (TSP) ----
// dp[mask][i] = 访问过 mask 中的城市, 最后在 i 的最短路径
// mask 是位掩码, 表示哪些城市已访问
int dp[1 << n][n];
memset(dp, INF, sizeof(dp));
dp[1][0] = 0;   // 从 0 出发
for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) continue;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) continue;
            int nmask = mask | (1 << j);
            dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + dist[i][j]);
        }
    }
}


// ==============================================
// 13. 图论
// ==============================================

// ---- 图的存储 ----

// 1. 邻接矩阵 (n ≤ 1000)
int g[1005][1005];

// 2. 邻接表 (常用)
vector<pair<int, int>> adj[100005];  // adj[u] = {v, w}
// 加边:
adj[u].push_back({v, w});
adj[v].push_back({u, w});  // 无向图

// 3. 链式前向星 (略快, 但邻接表够用)
// 邻接表 vs 邻接矩阵选择:
// 稀疏图 (m << n²) -> 邻接表, 省内存
// 稠密图 (m ≈ n²) -> 邻接矩阵, 方便查边
// 竞赛中 90% 用邻接表 (vector 版) 就够了

// ---- 拓扑排序 (Kahn) ----
// 拓扑排序 = 有向无环图 (DAG) 的线性排序
// 应用: 任务调度, 依赖关系, 编译顺序
// 核心: 不断删除入度为 0 的节点
// 如结果长度 != n => 图中有环
vector<int> in_deg(n, 0);
for (int u = 0; u < n; u++)
    for (auto [v, w] : adj[u]) in_deg[v]++;

queue<int> q;
for (int i = 0; i < n; i++) if (in_deg[i] == 0) q.push(i);

vector<int> topo;
while (!q.empty()) {
    int u = q.front(); q.pop();
    topo.push_back(u);
    for (auto [v, w] : adj[u])
        if (--in_deg[v] == 0) q.push(v);
}
if (topo.size() != n) cout << "有环";  // 有环则无法拓扑


// ==============================================
// 14. 并查集 (DSU)
// ==============================================

struct DSU {
    vector<int> parent, sz;  // sz: 集合大小

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);  // 路径压缩
        return parent[x];
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        if (sz[ra] < sz[rb]) swap(ra, rb);  // 按大小合并
        parent[rb] = ra;
        sz[ra] += sz[rb];
    }

    bool same(int a, int b) { return find(a) == find(b); }
};


// ==============================================
// 15. 最小生成树 (MST)
// ==============================================

// ---- Kruskal (贪心 + 并查集) ----
struct Edge { int u, v, w; };
vector<Edge> edges;

sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) { return a.w < b.w; });

DSU dsu(n);
long long mst_weight = 0;
int cnt = 0;  // 已选边数
for (auto& [u, v, w] : edges) {
    if (!dsu.same(u, v)) {
        dsu.unite(u, v);
        mst_weight += w;
        if (++cnt == n - 1) break;
    }
}

// ---- Prim (类似 Dijkstra, 稠密图用) ----


// ==============================================
// 16. 最短路
// ==============================================

// ---- Dijkstra (单源, 非负权) O((n+m) log n) ----
// 适用于: 边权非负的单源最短路
// 为什么权不能为负? 因为 Dijkstra 的贪心假设: 已确定最短路的节点不会再更新
// 如果后续有负权边, 这个假设就错了
// 对比: 权为负用 Bellman-Ford 或 SPFA
vector<long long> dijkstra(int s, int n) {
    const long long INF = 4e18;
    vector<long long> dist(n, INF);
    // 小顶堆 (距离, 节点)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;  // 关键优化: 过时数据直接跳过

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});  // 不用删旧的, 上面会跳过
            }
        }
    }
    return dist;
}

// ---- Floyd-Warshall (全源, O(n³), n ≤ 500) ----
// 求任意两点间最短路, 代码极短
// 注意: k 在最外层! 如果 i,j 在外部会错
// 原理: 动态规划, dp[k][i][j] 表示只经过前 k 个点的最短路径
// 压缩掉第一维后, k 必须在最外层
int dist_fw[505][505];
// 初始化: dist[i][i] = 0, 其他 = INF
for (int k = 0; k < n; k++)             // 中间点必须在最外层!
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist_fw[i][k] + dist_fw[k][j] < dist_fw[i][j])
                dist_fw[i][j] = dist_fw[i][k] + dist_fw[k][j];

// ---- Bellman-Ford (可判负环) ----
vector<long long> dist_bf(n, INF);
dist_bf[s] = 0;
bool neg_cycle = false;

for (int i = 0; i < n; i++) {
    bool updated = false;
    for (auto& [u, v, w] : edges) {
        if (dist_bf[u] != INF && dist_bf[u] + w < dist_bf[v]) {
            dist_bf[v] = dist_bf[u] + w;
            updated = true;
            if (i == n - 1) neg_cycle = true;  // 第 n 次还能更新 => 负环
        }
    }
    if (!updated) break;
}


// ==============================================
// 17. 数论
// ==============================================

// ---- 最大公约数 (C++17 内置 gcd) ----
int g = __gcd(a, b);     // C++14 及以下
int g = gcd(a, b);       // C++17 <numeric>
int l = lcm(a, b);       // C++17

// ---- 欧几里得 ----
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// ---- 扩展欧几里得 (求解 ax + by = gcd(a,b)) ----
int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

// ---- 素数判断 O(√n) ----
// 优化思路: 2 单独处理, 之后只检查奇数
// 注意: i*i 可能溢出 int, 用 (long long)i * i 或 i <= n / i
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= n / i; i += 2)   // i <= n/i 等价于 i*i <= n 且防溢出
        if (n % i == 0) return false;
    return true;
}
// 如果需要判大量数 (10⁶+ 次) -> 用筛法预处理
// 如果 n 很大 (10¹² 左右) -> 用 Miller-Rabin 算法

// ---- 素数筛 (埃氏筛 O(n log log n)) ----
// 从 i=2 开始, 将所有 i 的倍数标记为合数
// 优化: 从 i*i 开始筛 (因为更小的倍数已被更小的质数筛过)
const int MAXN = 1000000;
bool is_prime_sieve[MAXN + 1];
vector<int> primes;

void sieve() {
    fill(is_prime_sieve, is_prime_sieve + MAXN + 1, true);
    is_prime_sieve[0] = is_prime_sieve[1] = false;
    for (int i = 2; i * i <= MAXN; i++) {
        if (is_prime_sieve[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                is_prime_sieve[j] = false;
        }
    }
}

// ---- 线性筛 (欧拉筛 O(n), 更快) ----
// 核心改进: 每个合数只被它的最小质因子标记一次
// 相比埃氏筛 (一个合数被多个质数标记多次), 线性筛更快
vector<int> linear_sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
        for (int p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) break;  // 关键: 避免重复标记
        }
    }
    return primes;
}

// ---- 快速幂 (O(log n)) ----
// 原理: a^b = a^(二进制分解的各位幂的乘积)
// 例: 3⁵ = 3^(101)₂ = 3⁴ × 3¹
// 应用: 快速幂取模, 矩阵快速幂
// 注意: 底数 a 可能先取模 (尤其 a 很大时)
long long qpow(long long a, long long b, long long m) {
    long long res = 1 % m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// ---- 组合数 (预处理阶乘, n ≤ 1e5) ----
// 公式: C(n,k) = n! / (k! × (n-k)!)
// 模意义下除法用乘逆元: inv_fact[k]
// 逆元用费马小定理: a^(MOD-2) ≡ a⁻¹ (mod MOD)  (MOD 是质数时成立)
long long fact[MAXN], inv_fact[MAXN];

long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

// 预处理:
fact[0] = 1;
for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
inv_fact[MAXN - 1] = qpow(fact[MAXN - 1], MOD - 2, MOD);  // 费马小定理求逆元
for (int i = MAXN - 2; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;


// ==============================================
// 18. 位运算
// ==============================================

// 常用操作:
x & 1                   // 判断奇偶 (1=奇数, 0=偶数)
x & (-x)                // lowbit: 取最低位的 1 及其后面的 0 (如 12(1100) => 4(100))
x = x & (x - 1)         // 去掉最低位的 1 (如 12(1100) => 8(1000))
(x >> i) & 1            // 取第 i 位 (从 0 开始)
x | (1 << i)            // 将第 i 位置 1
x & ~(1 << i)           // 将第 i 位置 0
x ^ (1 << i)            // 翻转第 i 位 (1 变 0, 0 变 1)
(x & (x - 1)) == 0      // 判断是否是 2 的幂
__builtin_popcount(x)   // x 的二进制中 1 的个数 (GCC)
__builtin_ctz(x)        // 末尾 0 的个数 (count trailing zeros)
__builtin_clz(x)        // 前导 0 的个数
// 64 位版本:
__builtin_popcountll(x)
__builtin_ctzll(x)
__builtin_clzll(x)

// 枚举子集:
// 典型应用: 状态压缩 DP 中遍历 mask 的所有子集
// 原理: (sub-1) & mask 会得到 mask 的下一个真子集
for (int sub = mask; sub; sub = (sub - 1) & mask) {
    // sub 是 mask 的非空子集
    // 对 sub 做处理
}
// 如果要包括空集, 加 do-while 或单独处理 sub=0


// ==============================================
// 19. 常用技巧与宏
// ==============================================

// ---- 宏 (省代码, 但别滥用) ----
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); i--)

// ---- 自动类型 ----
auto x = 5;             // int
auto v = vector<int>(); // vector<int>

// ---- lambda (匿名函数) ----
auto add = [](int a, int b) { return a + b; };
// 递归 lambda (C++14 需要 std::function):
function<int(int)> fib = [&](int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
};

// ---- 随机数 ----
// mt19937 比 rand() + srand() 质量好得多
// 竞赛中如果需要随机化 (如随机打乱数组), 用这个
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd = uniform_int_distribution<int>(0, n - 1)(rng);

// ---- 计时 ----
auto start = chrono::high_resolution_clock::now();
// ... 跑代码 ...
auto end = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
// cout << "Time: " << duration << " ms\n";


// ==============================================
// 竞赛通用模板
// ==============================================

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;
const long long LINF = 4e18;
const int MOD = 1e9 + 7;

void solve() {
    // 每题的逻辑写这里
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 如果需要文件读写 (比赛看题要求):
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t;          // 多组测试
    while (t--) solve();

    return 0;
}

/*
 * ==================== 数据范围与算法选择 ====================
 * n ≤ 20       -> O(2ⁿ), O(n!)              -> 状压 DP, DFS
 * n ≤ 100      -> O(n³)                     -> Floyd, 区间DP
 * n ≤ 1000     -> O(n²)                     -> DP, 暴力
 * n ≤ 10⁵     -> O(n log n)                -> 排序, 二分, Dijkstra
 * n ≤ 10⁶     -> O(n)                      -> 线性, 前缀和
 * n ≤ 10⁷     -> O(n) 且常数小             -> 筛法, 线性
 * n ≤ 10⁹     -> O(log n) / O(√n)          -> 数学, 数论
 * ===========================================================
 * 注意事项:
 * 1. 数组开全局, 自动 0 初始化
 * 2. 涉及乘法先转 long long (1LL * a * b)
 * 3. 多组数据记得重置全局变量
 * 4. 读题看清数据范围, 决定算法
 * 5. 写暴力拿部分分, 别空着
 * 6. 注意 int 溢出, 能用 long long 就用
 * 7. 数组开 N + 5 留余量
 * 8. 文件读写: 比赛看要求, 有时需要 freopen 有时不需要
 * 9. 提交前去掉调试输出 (cerr / cout), 否则 WA
 */
