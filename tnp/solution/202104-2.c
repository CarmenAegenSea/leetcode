/**
 * CCF CSP 202104-2 邻域均值
 *
 * 题意：对于图像中每个位置 (i,j)，计算以其为中心、半径 r 的方形邻域内
 *       所有像素的平均灰度，统计均值 ≤ 阈值 t 的位置个数。
 *
 * 算法：二维前缀和 O(n*m)
 *   sum[i][j] = 从 (0,0) 到 (i-1,j-1) 的矩形区域和
 *   查询矩形 (x1,y1)-(x2,y2) 的和 = sum[x2+1][y2+1] - sum[x1][y2+1]
 *                                     - sum[x2+1][y1] + sum[x1][y1]
 */

#include <stdio.h>

#define MAXN 605

int a[MAXN][MAXN];
long long sum[MAXN][MAXN];  /* 前缀和数组（可能较大） */

int main() {
    int n, m, L, r, t;
    scanf("%d %d %d %d %d", &n, &m, &L, &r, &t);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    /* 构建二维前缀和 */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j]
                              - sum[i][j] + a[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            /* 邻域边界（不能越界） */
            int x1 = (i - r > 0) ? i - r : 0;
            int y1 = (j - r > 0) ? j - r : 0;
            int x2 = (i + r < n - 1) ? i + r : n - 1;
            int y2 = (j + r < m - 1) ? j + r : m - 1;

            /* 邻域内像素个数 */
            int count = (x2 - x1 + 1) * (y2 - y1 + 1);
            /* 邻域和 */
            long long area_sum = sum[x2 + 1][y2 + 1] - sum[x1][y2 + 1]
                               - sum[x2 + 1][y1] + sum[x1][y1];

            if (area_sum / count <= t) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
