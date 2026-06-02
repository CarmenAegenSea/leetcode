// 二叉树遍历 - 非递归版 (Binary Tree Traversal)
// 用途: 前序 / 中序 / 后序 / 层序遍历
// 非递归避免递归栈溢出, 适合竞赛大数据

#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

// 前序遍历 (根 -> 左 -> 右)
void preorder(TreeNode* root) {
    if (!root) return;
    int stk[10010], top = 0;
    TreeNode* node = root;
    while (top > 0 || node) {
        while (node) {
            stk[top++] = (int)(intptr_t)node;
            node = node->left;
        }
        node = (TreeNode*)(intptr_t)stk[--top];
        node = node->right;
    }
}

// 中序遍历 (左 -> 根 -> 右)
void inorder(TreeNode* root) {
    if (!root) return;
    int stk[10010], top = 0;
    TreeNode* node = root;
    while (top > 0 || node) {
        while (node) {
            stk[top++] = (int)(intptr_t)node;
            node = node->left;
        }
        node = (TreeNode*)(intptr_t)stk[--top];
        node = node->right;
    }
}

// 后序遍历 (左 -> 右 -> 根), 双栈法
void postorder(TreeNode* root) {
    if (!root) return;
    int stk1[10010], stk2[10010], top1 = 0, top2 = 0;
    stk1[top1++] = (int)(intptr_t)root;
    while (top1 > 0) {
        TreeNode* node = (TreeNode*)(intptr_t)stk1[--top1];
        stk2[top2++] = (int)(intptr_t)node;
        if (node->left) stk1[top1++] = (int)(intptr_t)(node->left);
        if (node->right) stk1[top1++] = (int)(intptr_t)(node->right);
    }
}

// 层序遍历 (广度优先), 队列实现
void level_order(TreeNode* root) {
    if (!root) return;
    TreeNode* q[10010];
    int head = 0, tail = 0;
    q[tail++] = root;
    while (head < tail) {
        TreeNode* node = q[head++];
        if (node->left) q[tail++] = node->left;
        if (node->right) q[tail++] = node->right;
    }
}
