#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int length;
} Nums;

int up(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n, X, Y;
    scanf("%d %d %d", &n, &X, &Y);
    Nums nums[n];
    for(int i = 0; i < n; i++) {
        int xi, yi;
        scanf("%d %d", &xi, &yi);
        nums[i].id = i + 1;
        int leng = (xi - X) * (xi - X) + (yi - Y) * (yi - Y);
        nums[i].length = leng;
    }
    qsort(nums, n, sizeof(Nums), up);
    for(int i = 0; i < 3; i++) {
        printf("%d\n", nums[i].id);
    }
    return 0;
}