// 线段树 (Segment Tree)
// 用途: 区间查询 (和/最值) + 区间修改 (带懒标记)
// 以区间求和为例, 支持区间加操作
// 时间复杂度: O(log n) 每次操作

#define MAXN 100010

typedef struct {
    int l, r;       // 区间左右端点
    int sum;        // 区间和
    int add;        // 懒标记 (待加值)
} Node;

Node tr[MAXN * 4];
int arr[MAXN];      // 原数组, 下标从 1 开始

// 向上合并: 用子节点更新父节点
void pushup(int u) {
    tr[u].sum = tr[u * 2].sum + tr[u * 2 + 1].sum;
}

// 向下传递懒标记
void pushdown(int u) {
    if (tr[u].add) {
        tr[u * 2].add += tr[u].add;
        tr[u * 2 + 1].add += tr[u].add;
        tr[u * 2].sum += (tr[u * 2].r - tr[u * 2].l + 1) * tr[u].add;
        tr[u * 2 + 1].sum += (tr[u * 2 + 1].r - tr[u * 2 + 1].l + 1) * tr[u].add;
        tr[u].add = 0;
    }
}

// 建树
void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r, tr[u].add = 0;
    if (l == r) { tr[u].sum = arr[l]; return; }
    int mid = (l + r) / 2;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    pushup(u);
}

// 区间加: 在 [l, r] 上每个数加 x
void update(int u, int l, int r, int x) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * x;
        tr[u].add += x;
        return;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) / 2;
    if (l <= mid) update(u * 2, l, r, x);
    if (r > mid) update(u * 2 + 1, l, r, x);
    pushup(u);
}

// 区间查询: 返回 [l, r] 的和
int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) / 2, res = 0;
    if (l <= mid) res += query(u * 2, l, r);
    if (r > mid) res += query(u * 2 + 1, l, r);
    return res;
}
