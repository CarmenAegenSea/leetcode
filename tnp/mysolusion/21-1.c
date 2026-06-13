#include <stdio.h>

#define MAX 260

int main() {
    int n, m, L;
    scanf("%d %d %d", &n, &m ,&L);
    int returnNums[MAX] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            scanf("%d", &a);
            returnNums[a]++;
        }
    }
    for (int i = 0; i < L; i++) {
        printf("%d ", returnNums[i]);
    }
    return 0;
}