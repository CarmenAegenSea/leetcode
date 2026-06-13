/**
 * CCF CSP 202312-2 因子化简
 *
 * 题意：给定 q 个查询，每个查询给出 n 和 k。
 *       将 n 分解为质因数 p_i^{e_i}，保留所有 e_i ≥ k 的质因数，
 *       计算新数字 n' = ∏_{e_i ≥ k} p_i^{e_i}。
 *
 * 算法：
 *   - n ≤ 10^10，只需要试除到 sqrt(n) ≈ 10^5
 *   - 对每个除数 d 从 2 到 sqrt(n)，统计 n 中 d 的次数
 *   - 最后如果 n > 1，说明剩余的是一个大质因子（指数为 1）
 *   - 快速幂计算 p^e
 *
 * 时间复杂度 O(q × sqrt(n))，q ≤ 10, sqrt(n) ≤ 10^5 → 约 10^6 次运算
 */

#include <stdio.h>
#include <math.h>

/* 快速幂：计算 base^exp */
long long quickPow(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        long long n;
        int k;
        scanf("%lld %d", &n, &k);

        long long result = 1;
        long long limit = (long long)sqrt((double)n);

        for (long long d = 2; d <= limit && n > 1; d++) {
            if (n % d == 0) {
                int cnt = 0;
                while (n % d == 0) {
                    n /= d;
                    cnt++;
                }
                if (cnt >= k) {
                    result *= quickPow(d, cnt);
                }
                limit = (long long)sqrt((double)n);
            }
        }

        /* 剩余的大质因子，指数为 1 */
        if (n > 1 && 1 >= k) {
            result *= n;
        }

        printf("%lld\n", result);
    }

    return 0;
}
