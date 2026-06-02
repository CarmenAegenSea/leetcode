// 并查集 (Union-Find / Disjoint Set Union)
// 用途: 判断两个元素是否在同一集合, 合并两个集合
// 时间复杂度: 接近 O(1) (路径压缩 + 按秩合并)

#define MAXN 100010
int parent[MAXN], rank[MAXN];

// 初始化: 每个元素自成一个集合
void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// 查找: 返回 x 所在集合的根节点, 带路径压缩
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// 合并: 将 x 和 y 所在的集合合并, 按秩优化
void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y])
        parent[x] = y;
    else if (rank[x] > rank[y])
        parent[y] = x;
    else {
        parent[y] = x;
        rank[x]++;
    }
}

// 判断 x 和 y 是否在同一集合
int same(int x, int y) {
    return find(x) == find(y);
}
