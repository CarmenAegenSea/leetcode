#include <string>

using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < t.size(); j++) {
            int flag1 = (s[i] == s[j]);
            int flag2 = (t[i] != t[j]);
            if ((flag1 && flag2) || (!flag1 && !flag2)) {
                return false;
            }
        }
    }
    return true;
}
