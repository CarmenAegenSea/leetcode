// 堆 (最小堆 / Priority Queue)
// 用途: 快速取最值, 常用于 Dijkstra / Huffman / 贪心
// 以下为最小堆 (堆顶最小), 改为 > 即变为最大堆

#define MAXN 100010

int heap[MAXN], sz;

void init() { sz = 0; }

// 插入元素
void push(int x) {
    int i = ++sz;
    while (i > 1 && heap[i / 2] > x) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

// 弹出堆顶并返回
int pop() {
    int res = heap[1], x = heap[sz--];
    int i = 1, child = 2;
    while (child <= sz) {
        if (child < sz && heap[child + 1] < heap[child]) child++;
        if (x <= heap[child]) break;
        heap[i] = heap[child];
        i = child;
        child *= 2;
    }
    heap[i] = x;
    return res;
}

int top() { return heap[1]; }
int empty() { return sz == 0; }
int size() { return sz; }
