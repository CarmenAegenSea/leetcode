// 大数运算 (Big Integer)
// 用途: 处理超出 long long 范围的整数 (加/减/乘/比较)
// 存储方式: 低位在前 (d[0] 存个位)

#include <string.h>
#include <stdio.h>

#define MAX_LEN 1010

typedef struct {
    int len;          // 当前位数
    int d[MAX_LEN];   // 数字, d[0] 为个位
} BigInt;

// 清零
void zero(BigInt* a) {
    memset(a->d, 0, sizeof(a->d));
    a->len = 0;
}

// 从字符串构造 (如 "12345")
void from_str(BigInt* a, char* s) {
    zero(a);
    a->len = strlen(s);
    for (int i = 0; i < a->len; i++)
        a->d[i] = s[a->len - 1 - i] - '0';
}

// 打印大数
void print(BigInt* a) {
    if (a->len == 0) { putchar('0'); return; }
    for (int i = a->len - 1; i >= 0; i--)
        putchar('0' + a->d[i]);
}

// 比较: a > b 返回正数, a == b 返回 0, a < b 返回负数
int cmp(BigInt* a, BigInt* b) {
    if (a->len != b->len) return a->len - b->len;
    for (int i = a->len - 1; i >= 0; i--)
        if (a->d[i] != b->d[i]) return a->d[i] - b->d[i];
    return 0;
}

// c = a + b
void add(BigInt* a, BigInt* b, BigInt* c) {
    zero(c);
    int carry = 0, t = a->len > b->len ? a->len : b->len;
    for (int i = 0; i < t; i++) {
        int s = a->d[i] + b->d[i] + carry;
        c->d[i] = s % 10;
        carry = s / 10;
    }
    if (carry) c->d[t++] = 1;
    c->len = t;
}

// c = a - b (需保证 a >= b)
void sub(BigInt* a, BigInt* b, BigInt* c) {
    zero(c);
    int borrow = 0, t = a->len;
    for (int i = 0; i < t; i++) {
        int s = a->d[i] - b->d[i] - borrow;
        if (s < 0) { s += 10; borrow = 1; }
        else borrow = 0;
        c->d[i] = s;
    }
    while (c->len > 0 && c->d[c->len - 1] == 0) c->len--;
    if (c->len == 0) c->len = 1;
    if (c->d[c->len - 1] == 0) c->len = 0;
}

// c = a * b
void mul(BigInt* a, BigInt* b, BigInt* c) {
    zero(c);
    for (int i = 0; i < a->len; i++)
        for (int j = 0; j < b->len; j++)
            c->d[i + j] += a->d[i] * b->d[j];
    int carry = 0, t = a->len + b->len;
    for (int i = 0; i < t; i++) {
        int s = c->d[i] + carry;
        c->d[i] = s % 10;
        carry = s / 10;
    }
    while (carry) c->d[t++] = carry % 10, carry /= 10;
    c->len = t;
    while (c->len > 0 && c->d[c->len - 1] == 0) c->len--;
}
