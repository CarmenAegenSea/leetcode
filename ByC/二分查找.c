#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int i = left + (right - left) / 2;
        if (nums[i] == target)
            return i;
        else if (nums[i] < target)
            left = i + 1;
        else
            right = i - 1;
    }
    return -1;
}
