// 树状数组 / 二叉索引树 (Fenwick Tree / BIT)
// 用途: 单点加 + 前缀和查询, 可转化为区间和
// 时间复杂度: O(log n) 每次操作
// 注意: 下标从 1 开始

#define MAXN 100010

int bit[MAXN], n;

// 初始化
void init(int size) {
    n = size;
    memset(bit, 0, sizeof(bit));
}

int lowbit(int x) {
    return x & -x;
}

// 在下标 i 处加 x
void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += lowbit(i);
    }
}

// 求前 i 个元素的和 (前缀和)
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= lowbit(i);
    }
    return s;
}

// 区间和 [l, r]
int range_sum(int l, int r) {
    return sum(r) - sum(l - 1);
}
