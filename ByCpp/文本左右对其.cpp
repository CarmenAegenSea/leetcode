#include <vector>
#include <string>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    int i = 0;
    while (i < n) {
        int j = i, lineLen = 0;
        while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
            lineLen += words[j].size();
            j++;
        }
        int spaces = maxWidth - lineLen;
        int wordCount = j - i;
        string line;
        if (j == n || wordCount == 1) {
            for (int k = i; k < j; k++) {
                line += words[k];
                if (k < j - 1) line += ' ';
            }
            line += string(maxWidth - line.size(), ' ');
        } else {
            int spaceEach = spaces / (wordCount - 1);
            int extra = spaces % (wordCount - 1);
            for (int k = i; k < j; k++) {
                line += words[k];
                if (k < j - 1) {
                    line += string(spaceEach + (k - i < extra ? 1 : 0), ' ');
                }
            }
        }
        result.push_back(line);
        i = j;
    }
    return result;
}
