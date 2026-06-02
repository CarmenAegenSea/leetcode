// 活动选择 (Activity Selection / 区间调度)
// 用途: 选择最多不相交区间, 经典贪心
// 思路: 按结束时间升序排序, 每次选最早结束且不冲突的
// 时间复杂度: O(n log n)

#include <stdlib.h>

#define MAXN 100010

typedef struct {
    int start, end;
} Activity;

int cmp_end(const void* a, const void* b) {
    return ((Activity*)a)->end - ((Activity*)b)->end;
}

// 返回最多可选活动数, 选中的活动下标写入 chosen[] (需预先分配)
int activity_selection(Activity acts[], int n, int chosen[]) {
    qsort(acts, n, sizeof(Activity), cmp_end);

    int cnt = 0, last_end = -1;
    for (int i = 0; i < n; i++) {
        if (acts[i].start >= last_end) {
            chosen[cnt++] = i;
            last_end = acts[i].end;
        }
    }
    return cnt;
}
