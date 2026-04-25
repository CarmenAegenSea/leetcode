int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    
    ans[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        ans[i] = ans[i-1] * nums[i-1];
    }
    
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        ans[i] *= right;
        right *= nums[i];
    }
    
    *returnSize = numsSize;
    return ans;
}