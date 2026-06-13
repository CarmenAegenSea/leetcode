/**
 * CCF CSP 202112-2 序列查询新解
 *
 * 题意：在上一题基础上，定义 g(x) = floor(x / r)，其中 r = floor(N/(n+1))。
 *       求 Σ|f(x) - g(x)| for x in [0, N)。
 *
 * 算法（O(n) 分段计算）：
 *   N 可能很大（≤10^9），不能逐点计算。
 *   f(x) 是分段常数函数（在 A[i]..A[i+1] 内不变）。
 *   g(x) 也是分段常数函数（每 r 个值不变）。
 *
 *   我们可以按 f(x) 的分段来遍历，在每个 f 段内再细分 g 段。
 *   因为 n ≤ 10^5，而每段内 g 最多变化 A[i+1]-A[i]/r 次，
 *   总复杂度是 O(n + N/r) = O(n)（因为 N/r ≈ n+1）。
 */

#include <stdio.h>
#include <stdlib.h>

long long min(long long a, long long b) {
    return a < b ? a : b;
}

long long absll(long long x) {
    return x >= 0 ? x : -x;
}

int main() {
    int n;
    long long N;
    long long A[100005];

    scanf("%d %lld", &n, &N);
    A[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }

    long long r = N / (n + 1);
    if (r == 0) {
        /* r=0 时 g(x)=0，直接算 */
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (long long)i * (A[i + 1] - A[i]);
        }
        ans += (long long)n * (N - A[n]);
        printf("%lld\n", ans);
        return 0;
    }

    long long ans = 0;

    /* 遍历每个 f 段 */
    for (int i = 0; i <= n; i++) {
        long long L = A[i];
        long long R = (i == n) ? N : A[i + 1];

        if (L >= R) continue;

        long long fi = i;

        /* 在 [L, R) 内，按 g 分段（每 r 个 g 相同） */
        for (long long x = L; x < R; ) {
            /* 当前 g 值 */
            long long gi = x / r;
            /* 当前 g 段的右边界 */
            long long gR = (gi + 1) * r;
            if (gR > R) gR = R;

            long long len = gR - x;
            ans += len * absll(fi - gi);

            x = gR;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
