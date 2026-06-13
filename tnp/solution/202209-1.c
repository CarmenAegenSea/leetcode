/**
 * CCF CSP 202209-1 如此编码
 *
 * 题意：已知 c[1..m] 和 n，求 a[1..m] 满足：
 *       n = Σ_{i=1}^{m} c_{i-1} × a_i，其中 c_0 = 1
 *       且 a_i 是 c_i 进制下的系数。
 *
 * 其实就是将 n 表示为一个混合进制数：
 *   c_0=1, c_1, c_2, ..., c_m 是各位的权重
 *   a_i = (n mod (c_0×c_1×...×c_i)) / (c_0×c_1×...×c_{i-1})
 *   更简单的方法：从低位到高位逐步求余数和商
 *
 * 时间复杂度 O(m)
 */

#include <stdio.h>

int main() {
    int n, m;
    int c[25];

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &c[i]);
    }

    int a[25];
    int prefix = 1;  /* c_0 × c_1 × ... × c_{i-1} */

    for (int i = 1; i <= m; i++) {
        /* a_i = (n mod (prefix × c_i)) / prefix */
        a[i] = (n % (prefix * c[i])) / prefix;
        prefix *= c[i];
    }

    for (int i = 1; i <= m; i++) {
        printf("%d%c", a[i], (i == m) ? '\n' : ' ');
    }

    return 0;
}
