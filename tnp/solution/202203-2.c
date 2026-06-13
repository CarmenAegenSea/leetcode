/**
 * CCF CSP 202203-2 出行计划
 *
 * 题意：在 t 时刻做核酸，在 [t+k, t+k+23] 时间内有效。
 *       第 i 个出行计划需要在时刻 t_i 进入场所，要求核酸在 c_i 小时内有效。
 *       即：出行计划 i 能被满足，当且仅当 t ∈ [t_i - c_i - k + 1, t_i - k]。
 *       有 m 个查询 q，求每个 q 能满足多少出行计划。
 *
 * 算法：差分数组 + 前缀和 O(N + m)
 *       对每个出行计划，计算其"允许的做核酸时间区间"，
 *       用差分数组将该区间内每个时刻的计数 +1，
 *       最后前缀和得到每个时刻能满足的计划数。
 */

#include <stdio.h>

#define MAXT 200005  /* t_i, c_i, q ≤ 2×10^5 */

int diff[MAXT * 2] = {0};  /* 差分数组 */
int cnt[MAXT * 2] = {0};   /* 前缀和后的结果 */

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        int t, c;
        scanf("%d %d", &t, &c);

        /* 出行计划 i 能被满足的做核酸时间区间 */
        int left = t - c - k + 1;
        int right = t - k;

        /* 限制在合理范围内 */
        if (right < 0) continue;  /* 不存在合法时间 */
        if (left < 0) left = 0;

        diff[left]++;
        diff[right + 1]--;
    }

    /* 前缀和恢复 */
    cnt[0] = diff[0];
    for (int i = 1; i < MAXT * 2; i++) {
        cnt[i] = cnt[i - 1] + diff[i];
    }

    /* 回答查询 */
    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);
        printf("%d\n", cnt[q]);
    }

    return 0;
}
