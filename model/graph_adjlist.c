// 邻接表存图 (Adjacency List)
// 用途: 存储稀疏图, 遍历某顶点的所有邻居
// 边数 MAXM 通常设为 MAXN * 2 (无向图双向边)

#define MAXN 100010
#define MAXM 200010

typedef struct {
    int to;     // 目标顶点
    int next;   // 下一条边的下标 (头插法)
    int w;      // 边权 (不需要时可为 1)
} Edge;

Edge edge[MAXM];
int head[MAXN], tot;  // head[u] = u 的第一条边下标

// 初始化: head 全部置为 -1
void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

// 添加一条有向边 u -> v, 权值为 w
void add_edge(int u, int v, int w) {
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

// 添加无向边 (双向)
void add_undirected(int u, int v, int w) {
    add_edge(u, v, w);
    add_edge(v, u, w);
}

// 遍历顶点 u 的所有邻居
void traverse(int u) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        // 处理 v
    }
}
