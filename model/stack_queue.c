// 栈 / 队列 / 双端队列 - 数组模拟
// 用途: O(1) 各操作, 替代 STL (C语言无 STL)
// 注意: 队列和双端队列的数组可循环利用 (竞赛中直接开大也够用)

#define MAXN 100010

// ========== 栈 (Stack) ==========
int stack[MAXN], stk_top;

void stk_init() { stk_top = 0; }
void stk_push(int x) { stack[stk_top++] = x; }
int stk_pop() { return stack[--stk_top]; }
int stk_top_val() { return stack[stk_top - 1]; }
int stk_empty() { return stk_top == 0; }
int stk_size() { return stk_top; }

// ========== 队列 (Queue) ==========
int queue[MAXN], q_head, q_tail;

void q_init() { q_head = q_tail = 0; }
void q_push(int x) { queue[q_tail++] = x; }
int q_pop() { return queue[q_head++]; }
int q_front() { return queue[q_head]; }
int q_back() { return queue[q_tail - 1]; }
int q_empty() { return q_head == q_tail; }
int q_size() { return q_tail - q_head; }

// ========== 双端队列 (Deque) ==========
int deque[MAXN], dq_head, dq_tail;

void dq_init() { dq_head = 0; dq_tail = 0; }
void dq_push_back(int x) { deque[dq_tail++] = x; }
void dq_push_front(int x) { deque[--dq_head] = x; }
int dq_pop_back() { return deque[--dq_tail]; }
int dq_pop_front() { return deque[dq_head++]; }
int dq_front() { return deque[dq_head]; }
int dq_back() { return deque[dq_tail - 1]; }
int dq_empty() { return dq_head == dq_tail; }
int dq_size() { return dq_tail - dq_head; }
