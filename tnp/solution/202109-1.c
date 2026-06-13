/**
 * CCF CSP 202109-1 数组推导
 *
 * 题意：已知前缀最大值数组 B（B[i]=max(A[1..i])），求 A 的元素和的最大值和最小值。
 *
 * 分析：
 *   - sum 最大时：A[i] = B[i]（每个位置都取可能的最大值）
 *   - sum 最小时：B[i] 没变时 A[i]=0，B[i] 变大时 A[i]=B[i]（取必须的最小值）
 *
 * 时间复杂度 O(n)
 */

#include <stdio.h>

int main() {
    int n;
    int B[105];
    long long maxSum = 0, minSum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    maxSum = B[0];
    minSum = B[0];

    for (int i = 1; i < n; i++) {
        maxSum += B[i];               /* A[i] = B[i] 时 sum 最大 */
        if (B[i] > B[i - 1]) {
            minSum += B[i];           /* B 变大了，A[i] 至少是 B[i] */
        }
        /* 否则 A[i] 可以为 0，不增加 minSum */
    }

    printf("%lld\n%lld\n", maxSum, minSum);
    return 0;
}
