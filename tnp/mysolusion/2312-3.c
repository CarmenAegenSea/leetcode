#include <stdio.h>
#include <math.h>

#define PI 3.14159265358

int main() {
    int argement, numsSize;
    scanf("%d %d", &argement, &numsSize);
    double changeX = 0, changeY = 0;
    for (int i = 0; i < argement; i++) {
        int change;
        scanf("%d", &change);
        if (change == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            changeX += x; changeY += y;
        } else {
            double cita;
            scanf("%lf", &cita);
            
        }
    }
    return 0;
}