/**
 * CCF CSP 202104-1 灰度直方图
 *
 * 题意：统计 n×m 图像中每个灰度值出现的次数
 * 灰度范围 [0, L)，输出 h[0]..h[L-1]
 */

#include <stdio.h>

int main() {
    int n, m, L;
    int h[260] = {0};  /* L ≤ 256，用数组计数 */

    scanf("%d %d %d", &n, &m, &L);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int gray;
            scanf("%d", &gray);
            h[gray]++;  /* 统计该灰度值出现次数 */
        }
    }

    /* 输出直方图 */
    for (int k = 0; k < L; k++) {
        printf("%d%c", h[k], (k == L - 1) ? '\n' : ' ');
    }

    return 0;
}
