#include <stdio.h>
#include <bits/stdc++.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    if (costSize == 0) { return -1;}

    int Woil = 0;       // 实时油料
    int i = 0;          // 始发站
    int change = i;
    for (; i < gasSize; i++) {
        if (gas[i] > cost[i]) {
            Woil = gas[i]; break; // 获取初始状况，假设从i处出发
        }

        for (int j = i; j < gasSize + i;) {
            Woil -= cost[j++ % costSize];  // 先耗油
            Woil += gas[j  % gasSize];     // 再加油
            printf(" %d", Woil);
            if (Woil < 0) { change = -1; break;}
        }
    }

    return change;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {3, 4, 5, 1, 2};
    canCompleteCircuit( A, 5, B, 5);
    std::cin.get();
    return 0;
}