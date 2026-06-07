#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {
    int *candyNums = (int*)malloc(ratingsSize * sizeof(int));
    for (int i = 0; i < ratingsSize; i++) {
        candyNums[i] = 1;
    }

    for (int i = 0; i < ratingsSize - 1; i++) {
        if ((ratings[i] < ratings[i + 1]) && !(candyNums[i] < candyNums[i + 1])) { candyNums[i + 1]++;}
        else if ((ratings[i] > ratings[i + 1]) && !(candyNums[i] > candyNums[i + 1])) { candyNums[i]++;}
    }

    int change = 0;
    for (int i = 0; i < ratingsSize; i++) {
        change += ratings[i];
    }

    return change;
}
