#include <stdio.h>

bool canReach(int* start, int startSize, int* target, int targetSize) {
    int dx = target[0] - start[0];
    int dy = target[1] - start[1];
    int d = (dx + dy) % 2;
    if (d) {
        return false;
    } else {
        return true;
    }