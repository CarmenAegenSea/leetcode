#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int x = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == x) {
            count++;
        } else {
            count--;
            if (count == 0) {
                x = nums[i];
                count = 1;
            }
        }
    }
    return x;
}
