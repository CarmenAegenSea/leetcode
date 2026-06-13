/**
 * CCF CSP 202203-1 未初始化警告
 *
 * 题意：程序有 k 条赋值语句 x_i = y_i。如果右值 y_i 在之前没有被赋值过
 *       （即未初始化），且 y_i ≠ 0（0 是常量），则产生一个警告。
 *       统计警告总数。
 *
 * 算法：用数组标记哪些变量已被初始化，O(k)
 */

#include <stdio.h>

int main() {
    int n, k;
    int initialized[100005] = {0};  /* initialized[v]=1 表示变量 v 已初始化 */

    scanf("%d %d", &n, &k);

    int warnings = 0;

    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        /* y=0 是常量，不会引起警告 */
        if (y != 0 && !initialized[y]) {
            warnings++;
        }

        /* 左值 x 被赋值，标记为已初始化 */
        initialized[x] = 1;
    }

    printf("%d\n", warnings);
    return 0;
}
