int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int n, int* returnSize, int** returnColumnSizes) {
    qsort(nums, n, sizeof(int), cmp);
    int** ans = malloc(n * n * sizeof(int*)); // 足以容纳答案
    *returnColumnSizes = malloc(n * n * sizeof(int));
    int m = 0;
    for (int i = 0; i < n - 2; i++) {
        int x = nums[i];
        if (i > 0 && x == nums[i - 1]) continue; // 跳过重复数字
        if (x + nums[i + 1] + nums[i + 2] > 0) break; // 优化一
        if (x + nums[n - 2] + nums[n - 1] < 0) continue; // 优化二
        int j = i + 1, k = n - 1;
        while (j < k) {
            int s = x + nums[j] + nums[k];
            if (s > 0) {
                k--;
            } else if (s < 0) {
                j++;
            } else { // 三数之和为 0
                // 添加三元组 (x, nums[j], nums[k]) 到 ans 中
                int* tuple = malloc(3 * sizeof(int));
                tuple[0] = x;
                tuple[1] = nums[j];
                tuple[2] = nums[k];
                ans[m] = tuple;
                (*returnColumnSizes)[m++] = 3;
                // 跳过重复数字
                for (j++; j < k && nums[j] == nums[j - 1]; j++);
                for (k--; k > j && nums[k] == nums[k + 1]; k--);
            }
        }
    }
    *returnSize = m;
    return ans;
}
