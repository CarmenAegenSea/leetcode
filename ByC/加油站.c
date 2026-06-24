#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total_tank = 0;
    int curr_tank = 0;
    int start = 0;

    for (int i = 0; i < gasSize; i++) {
        int diff = gas[i] - cost[i];
        total_tank += diff;
        curr_tank += diff;
        if (curr_tank < 0) {
            start = i + 1;
            curr_tank = 0;
        }
    }

    return total_tank >= 0 ? start : -1;
}