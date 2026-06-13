/**
 * CCF CSP 202206-1 归一化处理
 *
 * 题意：给定 n 个整数，求归一化值 f(a_i) = (a_i - mean) / sqrt(D)
 *       其中 mean = Σa_i / n, D = Σ(a_i - mean)² / n
 *
 * 使用 double 保证精度
 */

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int a[1005];
    double sum = 0.0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    double mean = sum / n;

    double variance = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = a[i] - mean;
        variance += diff * diff;
    }
    variance /= n;

    double std_dev = sqrt(variance);

    /* 输出归一化结果 */
    for (int i = 0; i < n; i++) {
        double f = (a[i] - mean) / std_dev;
        printf("%.10f\n", f);
    }

    return 0;
}
