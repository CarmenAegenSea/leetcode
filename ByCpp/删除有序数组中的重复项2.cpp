#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 3) return nums.size();
    int n = 2;
    for (int i = 2; i < nums.size(); i++) {
        if (nums[n - 2] != nums[i]) {
            nums[n++] = nums[i];
        }
    }
    return n;
}
