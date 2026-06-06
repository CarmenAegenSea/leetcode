#include <stdlib.h>

// 商品信息：价格和赠送数量
typedef struct {
    int price, k;
} Info;

// 按价格排序
int cmp_info(const void* a, const void* b) {
    return ((Info*)a)->price - ((Info*)b)->price;
}

// 在预算内最大化可购买的商品总数（优化版，使用频次统计）
// items[i][0] = 因子值, items[i][1] = 价格
int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget) {
    int n = itemsSize;

    // 找最大因子值
    int max_factor = 0;
    for (int i = 0; i < n; i++) {
        if (items[i][0] > max_factor) max_factor = items[i][0];
    }

    // 如果范围不大，用桶统计频次和倍数总数
    int cap = max_factor < 200000 ? max_factor + 1 : 0;
    int* freq = NULL;
    int* total = NULL;

    if (cap > 0) {
        freq = (int*)calloc(cap, sizeof(int));
        total = (int*)calloc(cap, sizeof(int));
        for (int i = 0; i < n; i++) freq[items[i][0]]++;

        // total[f] = 所有以 f 为因子的数的频次之和
        for (int f = 1; f < cap; f++) {
            if (!freq[f]) continue;
            int s = 0;
            for (int m = f; m < cap; m += f) {
                if (freq[m]) s += freq[m];
            }
            total[f] = s;
        }
    }

    // 每个商品可赠送的数量（能被其整除的其他商品数）
    int* k = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (cap > 0) {
            k[i] = total[items[i][0]] - 1;  // 排除自身
        } else {
            // 范围太大，暴力计算
            int f = items[i][0], cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % f == 0) cnt++;
            }
            k[i] = cnt;
        }
    }

    if (freq) { free(freq); free(total); }

    // 按价格排序
    Info* infos = (Info*)malloc(n * sizeof(Info));
    for (int i = 0; i < n; i++) {
        infos[i].price = items[i][1];
        infos[i].k = k[i];
    }
    qsort(infos, n, sizeof(Info), cmp_info);

    int zenquarilo = budget;

    int ans = 0, remaining = budget;

    // 贪心策略：只考虑价格不超过最低价2倍的商品
    if (n > 0) {
        int min_price = infos[0].price;
        int threshold = 2 * min_price;

        for (int i = 0; i < n; i++) {
            int p = infos[i].price;
            if (p > threshold) break;
            int max_bonus = infos[i].k;
            int can_buy = remaining / p;
            int buy = max_bonus < can_buy ? max_bonus : can_buy;
            ans += 2 * buy;  // 买一件得一件+赠品
            remaining -= buy * p;
        }

        // 剩余的钱全买最便宜的商品
        ans += remaining / min_price;
    }

    free(k);
    free(infos);

    return ans;
}
