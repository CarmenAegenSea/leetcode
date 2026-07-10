#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> char2word;
    unordered_map<string, char> word2char;
    istringstream iss(s);
    string word;
    int i = 0;
    while (iss >> word) {
        if (i >= pattern.size()) return false;
        char c = pattern[i];
        if (char2word.count(c) && char2word[c] != word) return false;
        if (word2char.count(word) && word2char[word] != c) return false;
        char2word[c] = word;
        word2char[word] = c;
        i++;
    }
    return i == pattern.size();
}
