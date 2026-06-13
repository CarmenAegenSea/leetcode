#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long planS(int** nums, int numsSize, int a, int b) {
    int MAXa = a, MAXb = b;
    int MINa = 0, MINb = 0;
    long long sums = 0;
    for (int i = 0; i < numsSize; i++) {
        int a0 = nums[i][0];
        int b0 = nums[i][1];
        int a1 = nums[i][2];
        int b1 = nums[i][3];
        if (a0 < MINa) a0 = MINa;
        if (b0 < MINb) b0 = MINb;
        if (a1 < MINa) a1 = MINa;
        if (b1 < MINb) b1 = MINb;
        if (a0 > MAXa) a0 = MAXa;
        if (b0 > MAXb) b0 = MAXb;
        if (a1 > MAXa) a1 = MAXa;
        if (b1 > MAXb) b1 = MAXb;
        sums += (a1 - a0) * (b1 - b0);
    }
    return sums;
}

int main() {
    int numsSize, a, b;
    scanf("%d %d %d", &numsSize, &a, &b);
    int** nums = (int**)malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++) {
        nums[i] = (int*)malloc(4 * sizeof(int));
    }
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &nums[i][j]);
        }
    }
    int result = planS(nums, numsSize, a, b);
    printf("%d\n", result);
    for (int i = 0; i < numsSize; i++) {
        free(nums[i]);
    }
    free(nums);
    return 0;
}