/**
 * CCF CSP 202303-1 田地丈量
 *
 * 题意：n 块田地（矩形），岛屿是 [0,a]×[0,b] 的矩形。
 *       求每块田地与岛屿的交集面积之和（重叠部分不合并，各算各的）。
 *
 * 两个矩形 [x1,x2]×[y1,y2] 和 [X1,X2]×[Y1,Y2] 的交集：
 *   交集左 = max(x1, X1), 交集右 = min(x2, X2)
 *   交集下 = max(y1, Y1), 交集上 = min(y2, Y2)
 *   若 交集左 < 交集右 且 交集下 < 交集上，才有交集
 */

#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n, a, b;
    long long totalArea = 0;

    scanf("%d %d %d", &n, &a, &b);

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        /* 求田地与岛屿的交集 */
        int left   = max(x1, 0);
        int right  = min(x2, a);
        int bottom = max(y1, 0);
        int top    = min(y2, b);

        if (left < right && bottom < top) {
            totalArea += (long long)(right - left) * (top - bottom);
        }
    }

    printf("%lld\n", totalArea);
    return 0;
}
