#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 三指针从后往前归并，O(m+n) 时间，O(1) 额外空间
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // nums1 有效部分的末尾
        int j = n - 1;      // nums2 的末尾
        int k = m + n - 1;  // nums1 的总末尾
        // 从后往前比较，较大的放到 nums1[k]
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        // nums2 还剩元素时直接复制（nums1 剩下的已经在正确位置）
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution sol;
    sol.merge(nums1, 3, nums2, 3);
    for (int x : nums1) cout << x << ' ';
    cout << flush;
    cin.get();
    return 0;
}
