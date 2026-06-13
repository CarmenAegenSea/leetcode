#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 字典序比较函数，用于 qsort */
static int cmp(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

/* 返回最美序列
 * 美丽序列定义（即合法括号序列，A='(' , B=')'）：
 *   1. 空串是美的
 *   2. 若 s 是美的，则 AsB 也是美的
 *   3. 若 s 和 t 是美的，则 st 也是美的
 *
 * 算法：将输入按平衡度归零拆分出多个美丽子串，再字典序排序后拼接 */
char* isButifou(char* nums, int numsSize) {
    /* 存储拆分出的美丽子串 */
    char** parts = (char**)malloc(numsSize * sizeof(char*));
    int cnt = 0;       /* 子串个数 */
    int bal = 0;       /* 平衡度，A+1，B-1 */
    int start = 0;     /* 当前子串起始位置 */

    /* 扫描：遇到 A 平衡度 +1，遇到 B 平衡度 -1 */
    for (int i = 0; i < numsSize; i++) {
        bal += (nums[i] == 'A') ? 1 : -1;
        if (bal == 0) {                     /* 平衡归零 ⇒ 找到一个美丽子串 */
            int len = i - start + 1;
            parts[cnt] = (char*)malloc(len + 1);
            strncpy(parts[cnt], nums + start, len);
            parts[cnt][len] = '\0';
            cnt++;
            start = i + 1;                  /* 继续扫描下一个子串 */
        }
    }

    /* 将所有子串按字典序排序 */
    qsort(parts, cnt, sizeof(char*), cmp);

    /* 拼接结果 */
    char* res = (char*)malloc(numsSize + 1);
    int pos = 0;
    for (int i = 0; i < cnt; i++) {
        int len = strlen(parts[i]);
        memcpy(res + pos, parts[i], len);
        pos += len;
        free(parts[i]);
    }
    res[pos] = '\0';
    free(parts);
    return res;
}

int main() {
    char s[1001];
    scanf("%1000s", s);
    char* res = isButifou(s, (int)strlen(s));
    printf("%s", res);
    free(res);
    return 0;
}
