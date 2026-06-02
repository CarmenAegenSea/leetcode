// Dijkstra 最短路算法 (邻接矩阵版)
// 用途: 求单源最短路径 (仅适用于非负权图)
// 时间复杂度: O(n^2), 适合稠密图
// 稀疏图建议用邻接表 + 堆优化版

#include <string.h>

#define MAXN 1010
#define INF 0x3f3f3f3f

int graph[MAXN][MAXN];  // 邻接矩阵
int dist[MAXN], vis[MAXN];  // 最短距离, 是否已确定

// 初始化图: 对角线为 0, 其余为 INF
void init_graph(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = i == j ? 0 : INF;
}

// 从 start 出发求到所有点的最短距离
void dijkstra(int n, int start) {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[start] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        if (u == -1 || dist[u] == INF) break;
        vis[u] = 1;
        for (int v = 0; v < n; v++) {
            int d = dist[u] + graph[u][v];
            if (!vis[v] && d < dist[v])
                dist[v] = d;
        }
    }
}
