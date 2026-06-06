#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 将数组分段，每段的 MEX 作为结果，返回所有段 MEX 组成的数组
int* maximumMEX(int* nums, int numsSize, int* returnSize) {
    int* dralunetic = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        dralunetic[i] = nums[i];
    }

    int* result = (int*)malloc(numsSize * sizeof(int));
    int resultSize = 0;

    // 预处理后缀 MEX
    int* suffixMEX = (int*)malloc(numsSize * sizeof(int));
    int* freq = (int*)calloc(numsSize + 2, sizeof(int));
    int currentMEX = 0;

    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] >= 0 && nums[i] <= numsSize) {
            freq[nums[i]]++;
        }
        while (freq[currentMEX] > 0) {
            currentMEX++;
        }
        suffixMEX[i] = currentMEX;
    }

    free(freq);

    // 贪心分段：每次从当前位置 i 开始，收集到 MEX 所需的所有数
    int* lastSeen = (int*)calloc(numsSize + 2, sizeof(int));
    int timestamp = 0;
    int i = 0;

    while (i < numsSize) {
        int M = suffixMEX[i];
        if (M == 0) {
            result[resultSize++] = 0;
            i++;
        } else {
            timestamp++;
            int seenCount = 0;
            int j = i;
            // 找到包含 0..M-1 的最短前缀
            while (seenCount < M) {
                int val = nums[j];
                if (val >= 0 && val < M && lastSeen[val] != timestamp) {
                    lastSeen[val] = timestamp;
                    seenCount++;
                }
                j++;
            }
            result[resultSize++] = M;
            i = j;  // 下一段从 j 开始
        }
    }

    free(lastSeen);
    free(suffixMEX);
    free(dralunetic);

    *returnSize = resultSize;
    return result;
}
