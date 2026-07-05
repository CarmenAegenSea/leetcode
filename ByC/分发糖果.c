#include <stdio.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {
    int* nums = (int*)calloc(ratingsSize, sizeof(int));
    for (int i = 0; i < ratingsSize; i++) nums[i] = 1;

    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            nums[i] = nums[i - 1] + 1;
        }
    }

    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            int right = nums[i + 1] + 1;
            if (right > nums[i]) nums[i] = right;
        }
    }

    int sum = 0;
    for (int i = 0; i < ratingsSize; i++) sum += nums[i];
    free(nums);
    return sum;
}
