#include <string>

using namespace std;

int romanToInt(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        int change = 0;
        switch (s[i]) {
            case 'I': change = 1; break;
            case 'V': change = 5; break;
            case 'X': change = 10; break;
            case 'L': change = 50; break;
            case 'C': change = 100; break;
            case 'D': change = 500; break;
            case 'M': change = 1000; break;
        }
        if (i != s.size() - 1) {
            if (s[i] == 'I' && s[i + 1] == 'V') { change = 4; i++; }
            else if (s[i] == 'I' && s[i + 1] == 'X') { change = 9; i++; }
            else if (s[i] == 'X' && s[i + 1] == 'L') { change = 40; i++; }
            else if (s[i] == 'X' && s[i + 1] == 'C') { change = 90; i++; }
            else if (s[i] == 'C' && s[i + 1] == 'D') { change = 400; i++; }
            else if (s[i] == 'C' && s[i + 1] == 'M') { change = 900; i++; }
        }
        num += change;
    }
    return num;
}
