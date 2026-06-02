// 哈希表 - 开放寻址法 (Hash Table with Open Addressing)
// 用途: O(1) 平均复杂度的插入/查找/删除
// 特点: 线性探测解决冲突, 用特殊标记区分空位和已删除

#define MAXN 1000003          // 取质数减少冲突
#define EMPTY -2000000000     // 空位标记
#define DELETED -2000000001   // 已删除标记

int hash_table[MAXN];

// 初始化所有位置为 EMPTY
void init_hash() {
    for (int i = 0; i < MAXN; i++)
        hash_table[i] = EMPTY;
}

// 哈希函数 (处理负数)
int hash_func(int key) {
    return ((key % MAXN) + MAXN) % MAXN;
}

// 插入 key, 成功返回 1, 已存在返回 0
int insert(int key) {
    int idx = hash_func(key);
    while (hash_table[idx] != EMPTY && hash_table[idx] != DELETED && hash_table[idx] != key) {
        idx = (idx + 1) % MAXN;
    }
    if (hash_table[idx] == key) return 0;
    hash_table[idx] = key;
    return 1;
}

// 查找 key, 存在返回 1, 否则返回 0
int search(int key) {
    int idx = hash_func(key);
    while (hash_table[idx] != EMPTY) {
        if (hash_table[idx] == key) return 1;
        idx = (idx + 1) % MAXN;
    }
    return 0;
}

// 删除 key, 成功返回 1, 不存在返回 0
int erase(int key) {
    int idx = hash_func(key);
    while (hash_table[idx] != EMPTY) {
        if (hash_table[idx] == key) {
            hash_table[idx] = DELETED;
            return 1;
        }
        idx = (idx + 1) % MAXN;
    }
    return 0;
}
