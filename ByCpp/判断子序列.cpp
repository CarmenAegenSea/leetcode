#include <string>

using namespace std;

bool isSubsequence(string s, string t) {
    int n = 0;
    if (s.empty()) return true;
    for (int i = 0; i < t.size(); i++) {
        if (s[n] == t[i]) {
            n++;
            if (n == s.size()) return true;
        }
    }
    return false;
}
