int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; ++i) {
        for (int n = i + 1; n < numsSize; ++n) {
            if (nums[i] + nums[n] == target) {
                int* num = malloc(sizeof(int) * 2);
                num[0] = i; num[1] = n;
                *returnSize = 2;
                return num;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}