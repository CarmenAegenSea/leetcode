/**
 * CCF CSP 202305-1 重复局面
 *
 * 题意：输入 n 个国际象棋局面（每个 8×8 字符矩阵），
 *       对于每个局面，输出它是第几次出现（1-indexed）。
 *
 * 算法：O(n) 字符串比较。
 *   n ≤ 100，每个局面 64 字符，可以逐局面比较。
 *   将每个局面拼接成一个长字符串，遍历之前的局面计数。
 */

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char board[105][65] = {0};  /* 存储每个局面（拼接成一维字符串） */

    scanf("%d", &n);
    getchar();  /* 消耗换行符 */

    for (int k = 0; k < n; k++) {
        /* 读 8 行拼接为一个字符串 */
        for (int i = 0; i < 8; i++) {
            char line[10];
            fgets(line, sizeof(line), stdin);
            /* fgets 会包含换行符，取前 8 个字符 */
            strncat(board[k], line, 8);
        }

        /* 统计之前出现过几次相同局面 */
        int cnt = 1;
        for (int j = 0; j < k; j++) {
            if (strcmp(board[k], board[j]) == 0) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
