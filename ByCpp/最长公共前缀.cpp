#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];

    for (int y = 0; y < strs[0].size(); y++) {
        for (int x = 1; x < strs.size(); x++) {
            if (y >= strs[x].size() || strs[x][y] != strs[0][y]) {
                return strs[0].substr(0, y);
            }
        }
    }
    return strs[0];
}
