/*
 * C++ STL 竞赛笔记
 * ==================
 * 编译: g++ -std=c++17 -O2 文件.cpp -o 文件
 * 注意: 竞赛中务必使用 C++17 (或 C++11/14)
 */

/* ========== 1. 头文件 ========== */
#include <bits/stdc++.h>  // 万能头 (竞赛常用, 但实际工程不推荐)
// 如果不能用万能头, 手动包含常用库:
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;  // 竞赛中 using namespace std 省事

/* ========== 2. 快速 I/O ========== */
// 放在 main() 开头, 加速 cin/cout (比 scanf/printf 快)
ios::sync_with_stdio(false);
cin.tie(nullptr);

// 之后就可以正常用:
int n;
cin >> n;
cout << n << '\n';       // 用 '\n' 而不是 endl (endl 会刷新缓冲区, 慢)

/* ========== 3. vector - 动态数组 ========== */
vector<int> v;                        // 空数组
vector<int> v(10);                    // 10 个元素, 默认 0
vector<int> v(10, 5);                 // 10 个元素, 全为 5
vector<int> v = {1, 2, 3, 4, 5};      // 初始化列表 (C++11)

v.push_back(6);          // 尾部追加 O(1)
v.pop_back();            // 尾部删除 O(1)
v.size();                // 元素个数
v.empty();               // 是否为空
v.clear();               // 清空
v.resize(20);            // 重新调整大小
v.resize(20, -1);        // 重新调整大小, 新元素填 -1
v.front();               // 首元素
v.back();                // 尾元素
v[0];                    // 下标访问 (不检查越界)

// 遍历
for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
for (int x : v) cout << x << ' ';

// 二维数组 (常用于 DP)
vector<vector<int>> dp(n, vector<int>(m, 0));

/* ========== 4. stack - 栈 (LIFO) ========== */
stack<int> st;
st.push(10);       // 入栈
st.pop();          // 出栈 (无返回值)
st.top();          // 取栈顶
st.size();
st.empty();

/* ========== 5. queue - 队列 (FIFO) ========== */
queue<int> q;
q.push(10);        // 入队
q.pop();           // 出队 (无返回值)
q.front();         // 队首
q.back();          // 队尾
q.size();
q.empty();

// priority_queue - 优先队列 (默认最大堆)
priority_queue<int> pq;                 // 最大堆 (大顶)
priority_queue<int, vector<int>, greater<int>> pq;  // 最小堆 (小顶)
pq.push(5);
pq.pop();          // 删除堆顶
pq.top();          // 取堆顶

/* ========== 6. unordered_map - 哈希表 (O(1) 增删查) ========== */
unordered_map<string, int> mp;
mp["apple"] = 3;          // 插入/修改
mp["apple"]++;            // 计数常用
mp.count("apple");        // 是否存在 (1/0)
mp.find("apple");         // 返回迭代器, mp.end() 表示没找到
mp.erase("apple");        // 删除

for (auto& [key, val] : mp) {  // C++17 结构化绑定
    cout << key << ' ' << val << '\n';
}

/* ========== 7. map - 有序字典 (红黑树, O(log n)) ========== */
map<int, int> mp2;  // 按 key 自动升序排序
// 用法同 unordered_map

/* ========== 8. unordered_set / set ========== */
unordered_set<int> s;  // 哈希集合, O(1)
set<int> s2;           // 有序集合, O(log n)

s.insert(5);
s.count(5);     // 0 或 1
s.erase(5);
s.find(5);

/* ========== 9. string - 字符串 ========== */
string s = "hello";
s += " world";         // 拼接
s.size();              // 长度
s.substr(0, 5);        // 子串 (起始, 长度)
s.find("lo");          // 返回首次出现位置, 找不到返回 string::npos
s.push_back('!');      // 追加字符
s.pop_back();          // 删除末尾字符
to_string(123);        // 数字 -> 字符串
stoi("456");           // 字符串 -> int
stoll("789");          // 字符串 -> long long

/* ========== 10. <algorithm> 常用函数 ========== */
vector<int> a = {5, 2, 8, 1, 9};

sort(a.begin(), a.end());                          // 升序
sort(a.begin(), a.end(), greater<int>());          // 降序
sort(a.begin(), a.end(), [](int x, int y) { return x > y; }); // 自定义

reverse(a.begin(), a.end());                       // 反转

unique(a.begin(), a.end());                        // 去重 (需先排序), 返回新末尾迭代器
// 常用去重写法:
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());

lower_bound(a.begin(), a.end(), x);   // 第一个 >= x 的元素迭代器
upper_bound(a.begin(), a.end(), x);   // 第一个 > x  的元素迭代器
// 使用前数组必须有序, 返回迭代器, 用 * 取值
int pos = lower_bound(a.begin(), a.end(), x) - a.begin();  // 下标

max(a, b);     min(a, b);
max_element(a.begin(), a.end());  // 返回最大元素迭代器
min_element(a.begin(), a.end());  // 返回最小元素迭代器
accumulate(a.begin(), a.end(), 0LL);  // 求和 (需 <numeric>)

fill(a.begin(), a.end(), 0);     // 全部赋值为 0

/* ========== 11. 常用技巧 ========== */

// 无穷大
const int INF = 0x3f3f3f3f;        // 约 10^9, 可防溢出
const long long LINF = 4e18;

// 取模
const int MOD = 1e9 + 7;
// 负数的模处理:
int modAdd(int x, int y) { return ((x % MOD) + (y % MOD)) % MOD; }
int modSub(int x, int y) { return ((x % MOD) - (y % MOD) + MOD) % MOD; }
int modMul(int x, int y) { return (1LL * x * y) % MOD; }

// 快速幂
long long qpow(long long a, long long b, long long m) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// 最大公约数 (C++17 内置 gcd)
int g = gcd(12, 8);   // 4
int l = lcm(12, 8);   // 24 (C++17)

// 素数判断
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

/* ========== 12. 竞赛模板框架 ========== */
void solve() {
    // 每道题的逻辑写在这里
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;          // 多组测试数据
    while (t--) {
        solve();
    }
    return 0;
}

/*
 * Tips:
 * - 数组开全局 (默认 0 初始化, 且栈空间更大)
 * - 开 long long 防溢出, 尤其涉及 1e9 相乘
 * - 看见 n <= 20 考虑状压 DP/爆搜, n <= 2000 O(n²),
 *   n <= 1e5 O(n log n), n <= 1e7 O(n)
 * - 善用 STL, 别手写数据结构浪费时间
 * - 不会的题先写暴力拿部分分
 */
