#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size()) return false;
    int letters[26] = {0};
    for (char c : ransomNote) letters[c - 'a']++;
    for (char c : magazine) letters[c - 'a']--;
    for (int i = 0; i < 26; i++) {
        if (letters[i] > 0) return false;
    }
    return true;
}
