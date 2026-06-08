int minimumSwaps(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1, swaps = 0;
    while (left < right) {
        while (left < right && nums[left] != 0) left++;   // 从左找第一个 0
        while (left < right && nums[right] == 0) right--; // 从右找第一个非 0
        if (left < right) {
            int t = nums[left]; nums[left] = nums[right]; nums[right] = t;
            swaps++;
            left++;
            right--;
        }
    }
    return swaps;
}
