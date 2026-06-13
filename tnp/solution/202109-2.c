/**
 * CCF CSP 202109-2 非零段划分
 *
 * 题意：给定数组 A[1..n]。选一个自然数 p，
 *       定义 B[i] = 1 if A[i] > p else 0。
 *       求所有 p 中 B 数组的非零段（连续 1 的段）的最大数量。
 *
 * 算法（O(n + maxA)）：
 *   考虑 p 从小变大时非零段的变化：
 *   - 当 p = A[i]-1 时（即 p 即将小于 A[i]），A[i] 从 0 变成 1
 *   - 如果左右都是 1，则两个非零段合并，段数 -1
 *   - 如果左右都是 0，则新增一个非零段，段数 +1
 *   - 否则段数不变
 *
 *   我们可以用"水淹法"：p 从大到小变化，
 *   维护每个值出现的位置，当 p 降到某个值时更新段数。
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 500005
#define MAXV 10005

int main() {
    int n;
    int A[MAXN];
    /* cnt[v] 记录值为 v 的位置有哪些会影响段数变化 */
    int *pos[MAXV];
    int posCnt[MAXV] = {0};
    int posCap[MAXV];

    scanf("%d", &n);

    /* 去重相邻相同值并读取 */
    int m = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (m == 0 || x != A[m - 1]) {
            A[m++] = x;
        }
    }

    /* 统计每个值出现的位置 */
    int maxVal = 0;
    for (int i = 0; i < m; i++) {
        if (A[i] > maxVal) maxVal = A[i];
        posCnt[A[i]]++;
    }

    for (int v = 0; v <= maxVal; v++) {
        if (posCnt[v] > 0) {
            pos[v] = (int *)malloc(posCnt[v] * sizeof(int));
            posCap[v] = posCnt[v];
            posCnt[v] = 0;  /* 重置为计数器 */
        } else {
            pos[v] = NULL;
            posCap[v] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int v = A[i];
        pos[v][posCnt[v]++] = i;
    }

    /* p = maxVal 时，所有位置都是 0（假设 maxVal 不会让所有位置为 0）
     * 实际上初始时 p > maxVal，B 全为 0，段数为 0 */
    int seg = 0;
    int ans = 0;

    /* p 从大到小变化 */
    for (int v = maxVal; v >= 1; v--) {
        if (pos[v] == NULL) continue;
        for (int k = 0; k < posCap[v]; k++) {
            int idx = pos[v][k];
            int left = (idx > 0) ? (A[idx - 1] > v ? 1 : 0) : 0;
            int right = (idx < m - 1) ? (A[idx + 1] > v ? 1 : 0) : 0;

            if (left && right) {
                seg--;  /* 两个 1 段被合并 */
            } else if (!left && !right) {
                seg++;  /* 新增一个独立的 1 */
            }
            /* 否则段数不变 */
        }
        if (seg > ans) ans = seg;
        free(pos[v]);
    }

    printf("%d\n", ans);
    return 0;
}
