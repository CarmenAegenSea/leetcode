/**
 * CCF CSP 202206-2 寻宝！大冒险！
 *
 * 题意：绿化图上有 n 棵树（坐标 ≤ 10^9），藏宝图是 S×S 的 0/1 矩阵。
 *       问藏宝图能与绿化图在多少个位置匹配（藏宝图左下角放在 (x,y)，
 *       检查 [x,x+S]×[y,y+S] 区域内树的位置是否与藏宝图的 1 完全一致）。
 *
 * 算法：
 *   - n ≤ 1000, S ≤ 50，数据量不大
 *   - 枚举每棵树作为藏宝图的某个位置（只在树位置检查即可）
 *   - 对于藏宝图中的每个 1，检查对应位置是否有树；对于每个 0，检查对应位置是否无树
 *   - 用哈希表存储树坐标以便 O(1) 查询
 *
 * 复杂度 O(n × S²)（实际很小）
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005
#define MAXS 55

typedef struct {
    int x, y;
} Tree;

/* 简单的坐标哈希，用于快速判断某位置是否有树 */
#define HASH_SIZE 1000003

typedef struct Node {
    long long key;  /* key = x * 2000000000LL + y (坐标压缩) */
    struct Node *next;
} Node;

Node *hashTable[HASH_SIZE];

void hash_insert(long long key) {
    int idx = (int)(key % HASH_SIZE);
    if (idx < 0) idx += HASH_SIZE;
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->next = hashTable[idx];
    hashTable[idx] = node;
}

int hash_find(long long key) {
    int idx = (int)(key % HASH_SIZE);
    if (idx < 0) idx += HASH_SIZE;
    for (Node *p = hashTable[idx]; p; p = p->next) {
        if (p->key == key) return 1;
    }
    return 0;
}

void hash_clear() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *p = hashTable[i];
        while (p) {
            Node *next = p->next;
            free(p);
            p = next;
        }
        hashTable[i] = NULL;
    }
}

long long encode(int x, int y) {
    return x * 2000000000LL + y;
}

int main() {
    int n, L, S;
    Tree trees[MAXN];
    int B[MAXS][MAXS];  /* 藏宝图，B[0][0]是左下角 */

    scanf("%d %d %d", &n, &L, &S);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &trees[i].x, &trees[i].y);
        hash_insert(encode(trees[i].x, trees[i].y));
    }

    /* 读藏宝图（注意：输入从左上到右下，即 (S,0) 到 (0,S)） */
    for (int i = S; i >= 0; i--) {
        for (int j = 0; j <= S; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int ans = 0;

    /* 以每棵树作为藏宝图左下角的参考，检查以该树为原点的一一对应 */
    for (int t = 0; t < n; t++) {
        int ox = trees[t].x;
        int oy = trees[t].y;

        /* 检查是否越界 */
        if (ox + S > L || oy + S > L) continue;

        int match = 1;
        /* 检查藏宝图中每棵树在绿化图中是否存在 */
        for (int i = 0; i <= S && match; i++) {
            for (int j = 0; j <= S && match; j++) {
                int tx = ox + i, ty = oy + j;
                int expect = B[i][j];
                int actual = hash_find(encode(tx, ty));

                if (expect != actual) {
                    match = 0;
                }
            }
        }

        if (match) ans++;
    }

    hash_clear();
    printf("%d\n", ans);
    return 0;
}
