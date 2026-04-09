bool isPalindrome(char* s) {
    bool change = true;
    int i = 0;
    int l = strlen(s) - 1;
    while (i < l) {
        while (i < l && !isalnum(s[i])) i++;
        while (i < l && !isalnum(s[l])) l--;
        if (i >= l) break;
        if (tolower(s[i]) != tolower(s[l])) {
            change = false;
        }
        i++,l--;
    }
    return change;
}