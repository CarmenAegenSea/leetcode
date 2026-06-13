/**
 * CCF CSP 202009-2 风险人群筛查
 *
 * 题意：给定 n 个人的连续 t 个位置坐标，判断每个人是否"经过"或"逗留"过
 *       高危区域（矩形）。高危区域由左下角(xl,yd)和右上角(xr,yu)定义。
 *
 *       经过 = 至少有一个时刻在矩形内
 *       逗留 = 连续 k 个或更多时刻在矩形内
 */

#include <stdio.h>

/* 判断点是否在矩形内（含边界） */
int inRect(int x, int y, int xl, int yd, int xr, int yu) {
    return (x >= xl && x <= xr && y >= yd && y <= yu);
}

int main() {
    int n, k, t, xl, yd, xr, yu;
    int pass = 0, stay = 0;  /* 经过人数, 逗留人数 */

    scanf("%d %d %d %d %d %d %d", &n, &k, &t, &xl, &yd, &xr, &yu);

    for (int i = 0; i < n; i++) {
        int cnt = 0;       /* 当前连续在区域内的时刻数 */
        int maxCnt = 0;    /* 最大连续在区域内的时刻数 */
        int everIn = 0;    /* 是否曾经在区域内 */

        for (int j = 0; j < t; j++) {
            int x, y;
            scanf("%d %d", &x, &y);

            if (inRect(x, y, xl, yd, xr, yu)) {
                everIn = 1;
                cnt++;
                if (cnt > maxCnt) maxCnt = cnt;
            } else {
                cnt = 0;  /* 离开区域，重置连续计数 */
            }
        }

        if (everIn) pass++;
        if (maxCnt >= k) stay++;
    }

    printf("%d\n%d\n", pass, stay);

    return 0;
}
