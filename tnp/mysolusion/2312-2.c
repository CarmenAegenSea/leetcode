#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char** nums = (char**)malloc(sizeof(char*) * 8);
    for (int i = 0; i < n; i++) {
        nums[i] = (char*)malloc(sizeof(char) * 9);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%s", nums[j]);
        }`

        int change = 1;
        for (int j = 0; j < i; j++) {
            if (strcmp(nums[i], nums[j]) == 0) {
                change++;
            }
        }
        printf("%d\n", change);
    }
    return 0;
}