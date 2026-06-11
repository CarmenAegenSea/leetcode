#include <string>
#include <algorithm>

using namespace std;

// 反转字符串s中 [left, right] 区间内的字符
void reverseRange(string& s, int left, int right) {
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

string reverseWords(string s) {
    // 1. 去除首尾空格并压缩中间多余空格
    int n = s.length();
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            // 单词之间加一个空格
            if (idx > 0) s[idx++] = ' ';
            // 复制整个单词
            while (i < n && s[i] != ' ') {
                s[idx++] = s[i++];
            }
        }
    }
    s.resize(idx);

    // 2. 反转整个字符串
    reverse(s.begin(), s.end());

    // 3. 反转每个单词
    int start = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (i == s.length() || s[i] == ' ') {
            reverseRange(s, start, i - 1);
            start = i + 1;
        }
    }

    return s;
}
