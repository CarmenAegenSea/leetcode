#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;
        if (i + nums[i] > maxReach) maxReach = i + nums[i];
        if (maxReach >= nums.size() - 1) return true;
    }
    return true;
}
