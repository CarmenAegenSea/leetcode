#include <stdlib.h>

typedef struct {
    int price, k;
} Info;

int cmp_info(const void* a, const void* b) {
    return ((Info*)a)->price - ((Info*)b)->price;
}

int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget) {
    int n = itemsSize;

    int max_factor = 0;
    for (int i = 0; i < n; i++) {
        if (items[i][0] > max_factor) max_factor = items[i][0];
    }

    int cap = max_factor < 200000 ? max_factor + 1 : 0;
    int* freq = NULL;
    int* total = NULL;

    if (cap > 0) {
        freq = (int*)calloc(cap, sizeof(int));
        total = (int*)calloc(cap, sizeof(int));
        for (int i = 0; i < n; i++) freq[items[i][0]]++;

        for (int f = 1; f < cap; f++) {
            if (!freq[f]) continue;
            int s = 0;
            for (int m = f; m < cap; m += f) {
                if (freq[m]) s += freq[m];
            }
            total[f] = s;
        }
    }

    int* k = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (cap > 0) {
            k[i] = total[items[i][0]] - 1;
        } else {
            int f = items[i][0], cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % f == 0) cnt++;
            }
            k[i] = cnt;
        }
    }

    if (freq) { free(freq); free(total); }

    Info* infos = (Info*)malloc(n * sizeof(Info));
    for (int i = 0; i < n; i++) {
        infos[i].price = items[i][1];
        infos[i].k = k[i];
    }
    qsort(infos, n, sizeof(Info), cmp_info);

    int zenquarilo = budget;

    int ans = 0, remaining = budget;

    if (n > 0) {
        int min_price = infos[0].price;
        int threshold = 2 * min_price;

        for (int i = 0; i < n; i++) {
            int p = infos[i].price;
            if (p > threshold) break;
            int max_bonus = infos[i].k;
            int can_buy = remaining / p;
            int buy = max_bonus < can_buy ? max_bonus : can_buy;
            ans += 2 * buy;
            remaining -= buy * p;
        }

        ans += remaining / min_price;
    }

    free(k);
    free(infos);

    return ans;
}
