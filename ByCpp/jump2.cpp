#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        int reach = i + nums[i];
        if (reach > curFarthest) curFarthest = reach;
        if (i == curEnd) {
            jumps++;
            curEnd = curFarthest;
        }
    }
    return jumps;
}
