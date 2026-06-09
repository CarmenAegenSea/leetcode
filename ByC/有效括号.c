#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 用栈判断有效括号：遇到左括号入栈，遇到右括号检查栈顶是否匹配
bool isValid(char* s) {
    int length = strlen(s);
    // 空字符串视为有效
    if (length == 0) return true;
    // 奇数长度直接排除
    if (length % 2 == 1) return false;

    // 用 d 数组模拟栈，最坏情况全部为左括号，需 length 字节
    char* d = (char*)malloc(length);
    int j = -1;  // 栈顶指针，-1 表示空栈

    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            // 左括号入栈
            d[++j] = s[i];
        } else {
            // 右括号但栈空 → 不匹配
            if (j == -1) { free(d); return false; }

            char left = d[j--];  // 弹出栈顶左括号
            // 检查是否与当前右括号匹配
            if ((s[i] == ')' && left != '(') ||
                (s[i] == ']' && left != '[') ||
                (s[i] == '}' && left != '{')) {
                free(d);
                return false;
            }
        }
    }

    bool ok = (j == -1);  // 栈恰好清空则全部匹配
    free(d);
    return ok;
}
