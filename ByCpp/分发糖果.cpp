#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);

    // 从左到右扫描：若右边比左边大，则右边糖果 = 左边糖果 + 1
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // 从右到左扫描：若左边比右边大，则左边糖果 = max(左边糖果, 右边糖果 + 1)
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // 求和
    int total = 0;
    for (int c : candies) {
        total += c;
    }
    return total;
}
