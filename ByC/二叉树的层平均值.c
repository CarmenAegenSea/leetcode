#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    int n = 0;
    int ceng = strlen(root);
    for (; n < 1000; n++) {
        if (pow(2, n) == ceng) ;
    }

    double* returnNums = (double*)malloc(sizeof(double) * ceng);
    for (int i = 1; i < ceng; i++) {
        int last = pow(2, n - 1);
        int next = pow(2, n);
        int sums = 0;
        for (int j = last; j < next; j++) {
            sums += root[j];
        }
        returnNums[i] = sums / pow(2, n);
    }
    return returnNums;
}