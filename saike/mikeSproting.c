#include <stdio.h>
#include <stdlib.h>

int mikeSproting(int** tube, int N, int X) {
    int M = 0;
    int maxNode = N;
    while (1) {
        if (tube[M][0] == 0 && tube[M][1] == 0) break;
        if (tube[M][0] > maxNode) maxNode = tube[M][0];
        if (tube[M][1] > maxNode) maxNode = tube[M][1];
        M++;
    }
    if (M == 0) return -1;

    Edge* edges = (Edge*)malloc(M * sizeof(Edge));
    for (int i = 0; i < M; i++) {
        edges[i].u = tube[i][0];
        edges[i].v = tube[i][1];
        edges[i].delay = tube[i][2];
        edges[i].cap = tube[i][3];
    }

    qsort(edges, M, sizeof(Edge), cmp_by_cap);

    Node** adj = (Node**)calloc(maxNode + 1, sizeof(Node*));
    long long* dist = (long long*)malloc((maxNode + 1) * sizeof(long long));
    for (int i = 1; i <= maxNode; i++) dist[i] = INF;
    dist[1] = 0;

    HeapNode* heap = (HeapNode*)malloc((M + maxNode + 5) * sizeof(HeapNode));
    int heapSize = 0;
    heap_push(heap, &heapSize, 1, 0);

    long long answer = INF;

    for (int i = 0; i < M; ) {
        int curCap = edges[i].cap;

        while (i < M && edges[i].cap == curCap) {
            int u = edges[i].u, v = edges[i].v, w = edges[i].delay;

            Node* node = (Node*)malloc(sizeof(Node));
            node->v = v; node->w = w; node->next = adj[u]; adj[u] = node;
            node = (Node*)malloc(sizeof(Node));
            node->v = u; node->w = w; node->next = adj[v]; adj[v] = node;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                heap_push(heap, &heapSize, v, dist[v]);
            }
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                heap_push(heap, &heapSize, u, dist[u]);
            }
            i++;
        }

        while (heapSizinte > 0) {
            HeapNode hn = heap_pop(heap, &heapSize);
            int u = hn.node;
            if (hn.dist != dist[u]) continue;
            for (Node* p = adj[u]; p; p = p->next) {
                int v = p->v, w = p->w;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    heap_push(heap, &heapSize, v, dist[v]);
                }
            }
        }

        if (dist[N] < INF) {
            long long cand = dist[N] + (long long)X / curCap;
            if (cand < answer) answer = cand;
        }
    }

    free(edges);
    for (int i = 1; i <= maxNode; i++) {
        Node* p = adj[i];
        while (p) {
            Node* next = p->next;
            free(p);
            p = next;
        }
    }
    free(adj);
    free(dist);
    free(heap);

    return answer < INF ? (int)answer : -1;
}

int main() {
    int N, M, X;
    scanf("%d %d %d", &N, &M, &X);
    int** tube = (int*)malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++) {
        tube[i] = (int*)malloc(sizeof(int) * 4);
        scanf("%d %d %d %d", &tube[i][0], &tube[i][1], &tube[i][2], &tube[i][3]);
    }
    printf("%d", mikeSproting(tube, N, X));
    return 0;
}