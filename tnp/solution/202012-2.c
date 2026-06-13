/**
 * CCF CSP 202012-2 期末预测之最佳阈值
 *
 * 题意：有 m 个 (y_i, result_i)，选阈值 θ。
 *       预测规则：y >= θ → 预测挂科(1)，y < θ → 预测不挂科(0)
 *       求使预测正确次数最多的最大 θ。
 *
 * 算法思路（O(m log m)）：
 *   1. 将数据按 y 升序排序
 *   2. 预处理前缀和：pre0[i] = 前 i 个中 result=0 的数量
 *                    pre1[i] = 前 i 个中 result=1 的数量
 *   3. 对于每个可能的分界点 idx（即选 θ = y_{idx}），计算：
 *      - y < θ 的人（前 idx 个）中，result=0 的数量 → 预测正确
 *      - y >= θ 的人（后 m-idx 个）中，result=1 的数量 → 预测正确
 *   4. 取最大值，如有相同选更大的 θ
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct {
    int y;
    int result;
} Record;

/* 按 y 升序排序 */
int cmp(const void *a, const void *b) {
    Record *ra = (Record *)a;
    Record *rb = (Record *)b;
    return ra->y - rb->y;
}

int main() {
    int m;
    Record rec[MAXN];
    int pre0[MAXN] = {0}, pre1[MAXN] = {0};

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &rec[i].y, &rec[i].result);
    }

    /* 排序 */
    qsort(rec + 1, m, sizeof(Record), cmp);

    /* 前缀和：pre0[i] = 前 i 个中 result=0 的数量 */
    for (int i = 1; i <= m; i++) {
        pre0[i] = pre0[i - 1] + (rec[i].result == 0);
        pre1[i] = pre1[i - 1] + (rec[i].result == 1);
    }

    int bestTheta = 0, bestCorrect = 0;

    for (int i = 1; i <= m; i++) {
        /* 跳过重复的 y 值，只在每个 y 值第一次出现的位置计算 */
        if (i > 1 && rec[i].y == rec[i - 1].y) continue;

        int theta = rec[i].y;
        int idx = i - 1;  /* 严格小于 theta 的元素个数 */

        /* y < θ 的人中 result=0 的数量（预测正确为不挂科） */
        int correct0 = pre0[idx];
        /* y >= θ 的人中 result=1 的数量（预测正确为挂科） */
        int correct1 = pre1[m] - pre1[idx];

        int correct = correct0 + correct1;

        if (correct > bestCorrect ||
            (correct == bestCorrect && theta > bestTheta)) {
            bestCorrect = correct;
            bestTheta = theta;
        }
    }

    printf("%d\n", bestTheta);

    return 0;
}
