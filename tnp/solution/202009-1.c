/**
 * CCF CSP 202009-1 称检测点查询
 *
 * 题意：给定市民位置 (X,Y) 和 n 个检测点，找出距离最近的3个检测点
 * 距离使用欧几里得距离的平方：D = (X-x_i)^2 + (Y-y_i)^2
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;     // 检测点编号
    int dist;   // 距离平方
} Point;

/* qsort 比较函数：按距离升序，距离相同按编号升序 */
int cmp(const void *a, const void *b) {
    Point *pa = (Point *)a;
    Point *pb = (Point *)b;
    if (pa->dist != pb->dist)
        return pa->dist - pb->dist;
    return pa->id - pb->id;
}

int main() {
    int n, X, Y;
    Point points[200];  /* n ≤ 200 */

    scanf("%d %d %d", &n, &X, &Y);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        points[i].id = i + 1;
        points[i].dist = (X - x) * (X - x) + (Y - y) * (Y - y);
    }

    /* 排序后取前3个 */
    qsort(points, n, sizeof(Point), cmp);

    for (int i = 0; i < 3; i++) {
        printf("%d\n", points[i].id);
    }

    return 0;
}
