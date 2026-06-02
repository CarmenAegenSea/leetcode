// KMP 字符串匹配
// 用途: O(n+m) 时间内查找模式串在文本串中的位置
// next[i] 表示 p[0..i] 的最长公共前后缀长度

#include <string.h>

#define MAXN 100010

int next[MAXN];

// 构建 next 数组
void build_next(char* p) {
    int m = strlen(p);
    next[0] = 0;
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) j = next[j - 1];
        if (p[i] == p[j]) j++;
        next[i] = j;
    }
}

// 返回模式串 p 在文本串 s 中首次出现的位置, 未找到返回 -1
int kmp(char* s, char* p) {
    int n = strlen(s), m = strlen(p);
    build_next(p);
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) j = next[j - 1];
        if (s[i] == p[j]) j++;
        if (j == m) return i - m + 1;
    }
    return -1;
}

// 返回模式串 p 在 s 中出现的次数 (可重叠)
int count_match(char* s, char* p) {
    int n = strlen(s), m = strlen(p), res = 0;
    build_next(p);
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) j = next[j - 1];
        if (s[i] == p[j]) j++;
        if (j == m) { res++; j = next[j - 1]; }
    }
    return res;
}
