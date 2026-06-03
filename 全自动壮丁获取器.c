#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ids[52];
    int i, r, temp;

    for (i = 0; i < 52; i++) {
        ids[i] = i + 1;
    }

    srand((unsigned)time(NULL));

    for (i = 51; i >= 32; i--) {
        r = rand() % (i + 1);
        temp = ids[i];
        ids[i] = ids[r];
        ids[r] = temp;
    }

    for (i = 51; i >= 32; i--) {
        printf(" %d", ids[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}
