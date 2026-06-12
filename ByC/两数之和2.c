#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int last = 0; 
    int next = numbersSize - 1;
    int* returnNums = (int*)malloc(sizeof(int) * 2);
    while (last < next) {
        int sums = numbers[last] + numbers[next];
        if (sums == target) {
            returnNums[0] = last + 1; returnNums[1] = next + 1; break;
        } else if (sums < target) {
            last++;
        } else if (sums > target) {
            next--;
        }
    }
    
    *returnSize = 2;
    return returnNums;
}