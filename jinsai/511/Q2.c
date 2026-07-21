#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfs(struct TreeNode* root, int* count) {
    if (!root) return INT_MIN;
    int leftMax = dfs(root->left, count);
    int rightMax = dfs(root->right, count);
    int subMax = root->val;
    if (leftMax > subMax) subMax = leftMax;
    if (rightMax > subMax) subMax = rightMax;
    if (root->val == subMax) (*count)++;
    return subMax;
}

int countDominantNodes(struct TreeNode* root) {
    struct TreeNode* norlavetic = root;
    int count = 0;
    dfs(norlavetic, &count);
    return count;
}