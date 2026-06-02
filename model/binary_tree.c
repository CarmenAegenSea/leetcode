// 二叉树 (Binary Tree)
// 用途: 二叉树的构建与数组表示
// 包括: 链式存储 (指针) 和 顺序存储 (数组)

#include <stdlib.h>

// ========== 链式存储 ==========
typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// 创建新节点
TreeNode* new_node(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// 从层序遍历数组构建二叉树 (-1 表示空节点)
TreeNode* build_from_array(int arr[], int n) {
    if (n == 0) return NULL;
    TreeNode** nodes = (TreeNode**)malloc(n * sizeof(TreeNode*));
    for (int i = 0; i < n; i++)
        nodes[i] = arr[i] != -1 ? new_node(arr[i]) : NULL;
    for (int i = 0; i < n; i++) {
        if (!nodes[i]) continue;
        if (2 * i + 1 < n) nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n) nodes[i]->right = nodes[2 * i + 2];
    }
    TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

// ========== 顺序存储 (数组) ==========
// 根节点下标为 1, 左儿子 2*i, 右儿子 2*i+1
int tree_arr[MAXN];
int tree_pos;

void tree_arr_init() {
    memset(tree_arr, -1, sizeof(tree_arr));
    tree_pos = 0;
}

void tree_arr_insert(int val) {
    tree_arr[++tree_pos] = val;
}

int tree_arr_left(int i) { return 2 * i; }
int tree_arr_right(int i) { return 2 * i + 1; }
int tree_arr_parent(int i) { return i / 2; }
