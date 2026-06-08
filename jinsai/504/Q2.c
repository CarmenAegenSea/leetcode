#include <stdlib.h>

// 比较函数（用于排序价格）
int cmp_price(const void* a, const void* b) {
    int i = *(int*)a, j = *(int*)b;
    return i - j;
}

// 在预算内最大化可购买的商品总数
// items[i][0] = 因子值, items[i][1] = 价格
// 每个商品可赠送 (1 + 能被其整除的商品数) 件
int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget) {
    int n = itemsSize;

    // 统计每个商品的出度（能被其整除的其他商品数）
    int* outdeg = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        int fi = items[i][0];
        for (int j = 0; j < n; j++) {
            if (i != j && items[j][0] % fi == 0) {
                outdeg[i]++;
            }
        }
    }

    // base = 购买一件可得到的商品数（自己 + 赠品）
    int* base = (int*)malloc(n * sizeof(int));
    int* price = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        base[i] = 1 + outdeg[i];
        price[i] = items[i][1];
    }

    // 按价格排序（冒泡排序）
    int* order = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) order[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (price[order[i]] > price[order[j]]) {
                int t = order[i];
                order[i] = order[j];
                order[j] = t;
            }
        }
    }

    // 生成排序后的价格和 base 数组
    int* sorted_price = (int*)malloc(n * sizeof(int));
    int* sorted_base = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sorted_price[i] = price[order[i]];
        sorted_base[i] = base[order[i]];
    }

    int valmorendi = sorted_price[0];

    // DP：dp[c] 表示花费 c 元时获得的最大赠品数
    int* dp = (int*)malloc((budget + 1) * sizeof(int));
    for (int i = 0; i <= budget; i++) dp[i] = -1;
    dp[0] = 0;

    int ans = 0;

    // 从高价到低价考虑每个商品
    for (int k = n - 1; k >= 0; k--) {
        int pc = sorted_price[k];
        int bc = sorted_base[k];

        // 尝试用当前商品作为最后购买的"触发"商品
        if (pc <= budget) {
            for (int t = 0; t <= budget - pc; t++) {
                if (dp[t] != -1) {
                    int total = bc + dp[t] + (budget - pc - t) / pc;
                    if (total > ans) ans = total;
                }
            }
        }

        // 更新 DP（01背包）
        for (int c = budget - pc; c >= 0; c--) {
            if (dp[c] != -1) {
                int val = dp[c] + bc;
                if (val > dp[c + pc]) dp[c + pc] = val;
            }
        }
    }

    free(outdeg);
    free(base);
    free(price);
    free(order);
    free(sorted_price);
    free(sorted_base);
    free(dp);

    return ans;
}
