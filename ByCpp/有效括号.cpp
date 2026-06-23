#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
    if (s.size() % 2 == 1) return false;
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char left = st.top(); st.pop();
            if ((c == ')' && left != '(') ||
                (c == ']' && left != '[') ||
                (c == '}' && left != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}
