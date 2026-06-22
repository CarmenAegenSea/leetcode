#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxV = 0;
    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        maxV = max(maxV, h * w);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxV;
}
