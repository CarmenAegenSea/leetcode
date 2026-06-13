/**
 * CCF CSP 202112-1 序列查询
 *
 * 题意：给定递增序列 A[0..n]（A[0]=0），定义 f(x) = max{i | A[i] ≤ x}。
 *       求 sum f(x) for x in [0, N)。
 *
 * 思路：对于每一段 (A[i], A[i+1])，其中的 x 对应的 f(x) = i。
 *       该段长度为 A[i+1] - A[i]，贡献为 i * (A[i+1] - A[i])。
 *       最后一段是 (A[n], N)，贡献为 n * (N - A[n])。
 *
 * 时间复杂度 O(n)
 */

#include <stdio.h>

int main() {
    int n, N;
    int A[205];

    scanf("%d %d", &n, &N);
    A[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        /* 区间 (A[i], A[i+1]) 内的 x，f(x) = i */
        ans += (long long)i * (A[i + 1] - A[i]);
    }
    /* 最后一段 (A[n], N)，f(x) = n */
    ans += (long long)n * (N - A[n]);

    printf("%lld\n", ans);
    return 0;
}
