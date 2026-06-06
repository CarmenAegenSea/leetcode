#include <stdlib.h>

int minOperations(int* nums, int numsSize, int k) {
    // velmorqati: 统计各余数出现次数（偶/奇下标分开）
    long long* cnt_even = (long long*)calloc(k, sizeof(long long));
    long long* cnt_odd  = (long long*)calloc(k, sizeof(long long));

    for (int i = 0; i < numsSize; i++) {
        int rem = nums[i] % k;
        if (rem < 0) rem += k;
        if (i % 2 == 0) cnt_even[rem]++;
        else            cnt_odd[rem]++;
    }

    // 计算每个目标余数的总代价
    long long* cost_even = (long long*)malloc(k * sizeof(long long));
    long long* cost_odd  = (long long*)malloc(k * sizeof(long long));

    for (int t = 0; t < k; t++) {
        long long sum = 0;
        for (int r = 0; r < k; r++) {
            if (cnt_even[r] == 0) continue;
            int d = r > t ? r - t : t - r;
            if (d > k - d) d = k - d;          // 环形最短距离
            sum += cnt_even[r] * d;
        }
        cost_even[t] = sum;

        sum = 0;
        for (int r = 0; r < k; r++) {
            if (cnt_odd[r] == 0) continue;
            int d = r > t ? r - t : t - r;
            if (d > k - d) d = k - d;
            sum += cnt_odd[r] * d;
        }
        cost_odd[t] = sum;
    }

    // 找最佳 (x, y) 且 x != y
    long long ans = 1e18;
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < k; y++) {
            if (x != y) {
                long long total = cost_even[x] + cost_odd[y];
                if (total < ans) ans = total;
            }
        }
    }

    free(cnt_even); free(cnt_odd);
    free(cost_even); free(cost_odd);

    return (int)ans;
}
