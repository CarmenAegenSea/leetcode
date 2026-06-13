/**
 * CCF CSP 202312-1 仓库规划
 *
 * 题意：n 个仓库，每个仓库有 m 维坐标。
 *       如果仓库 j 的所有维坐标都严格大于仓库 i 的对应坐标，则 j 是 i 的"上级"。
 *       选编号最小的上级。求每个仓库的上级编号（无上级则输出 0）。
 *
 * 算法：对每个仓库 i，枚举所有仓库 j，检查是否满足条件。
 *       复杂度 O(n² × m)，n ≤ 1000, m ≤ 10 → 约 10^7 次比较，可接受。
 */

#include <stdio.h>

int main() {
    int n, m;
    int coord[1005][12];

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &coord[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        int superior = 0;  /* 默认无上级 */

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            int allGreater = 1;
            for (int d = 0; d < m; d++) {
                if (coord[j][d] <= coord[i][d]) {
                    allGreater = 0;
                    break;
                }
            }

            if (allGreater) {
                superior = j;
                break;  /* 找编号最小的 */
            }
        }

        printf("%d\n", superior);
    }

    return 0;
}
