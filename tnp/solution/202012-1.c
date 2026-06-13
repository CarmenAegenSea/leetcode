/**
 * CCF CSP 202012-1 期末预测之安全指数
 *
 * 题意：计算加权和 y = Σ(w_i * score_i)，然后取 ReLU(y) = max(0, y)
 * 直接循环累加即可
 */

#include <stdio.h>

int main() {
    int n;
    long long sum = 0;  /* 使用 long long 防止溢出 */

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int w, score;
        scanf("%d %d", &w, &score);
        sum += (long long)w * score;
    }

    /* ReLU: max(0, sum) */
    if (sum < 0) sum = 0;

    printf("%lld\n", sum);

    return 0;
}
