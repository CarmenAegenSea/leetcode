/**
 * CCF CSP 202212-1 现值计算
 *
 * 题意：未来 n 年的收入 a_k，年利率 i%。
 *       现值 PV_k = a_k / (1 + i%)^k
 *       求所有年份现值的和，保留 3 位小数。
 */

#include <stdio.h>
#include <math.h>

int main() {
    int n, i_rate;
    scanf("%d %d", &n, &i_rate);

    double rate = 1.0 + i_rate / 100.0;
    double result = 0.0;

    for (int k = 0; k <= n; k++) {
        int a;
        scanf("%d", &a);
        result += a / pow(rate, k);
    }

    printf("%.3f\n", result);
    return 0;
}
