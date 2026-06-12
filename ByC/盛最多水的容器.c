#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int last = 0;
    int next = heightSize - 1;
    int maxV = 0;
    while (last < next) {
        int tall = height[last] < height[next] ? height[last] : height[next];
        int kual = next - last;
        int V = tall * kual;
        if (V > maxV) maxV = V;
        if (height[last] < height[next]) {
            last++;
        } else {
            next--;
        }
    }
    return maxV;
}