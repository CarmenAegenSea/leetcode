#include <stdlib.h>

int cmp_price(const void* a, const void* b) {
    int i = *(int*)a, j = *(int*)b;
    return i - j;
}

int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget) {
    int n = itemsSize;

    int* outdeg = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        int fi = items[i][0];
        for (int j = 0; j < n; j++) {
            if (i != j && items[j][0] % fi == 0) {
                outdeg[i]++;
            }
        }
    }

    int* base = (int*)malloc(n * sizeof(int));
    int* price = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        base[i] = 1 + outdeg[i];
        price[i] = items[i][1];
    }

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

    int* sorted_price = (int*)malloc(n * sizeof(int));
    int* sorted_base = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sorted_price[i] = price[order[i]];
        sorted_base[i] = base[order[i]];
    }

    int valmorendi = sorted_price[0];

    int* dp = (int*)malloc((budget + 1) * sizeof(int));
    for (int i = 0; i <= budget; i++) dp[i] = -1;
    dp[0] = 0;

    int ans = 0;

    for (int k = n - 1; k >= 0; k--) {
        int pc = sorted_price[k];
        int bc = sorted_base[k];

        if (pc <= budget) {
            for (int t = 0; t <= budget - pc; t++) {
                if (dp[t] != -1) {
                    int total = bc + dp[t] + (budget - pc - t) / pc;
                    if (total > ans) ans = total;
                }
            }
        }

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
