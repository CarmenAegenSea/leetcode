void reverse(char *s, int l, int r) {
    while (l < r) {
        char t = s[l];
        s[l] = s[r];
        s[r] = t;
        l++, r--;
    }
}

char* reverseWords(char* s) {
    int n = strlen(s), l = 0;
    reverse(s, 0, n - 1); // 整体翻转
    for (int i = 0; i < n; ++i) { // 逐个单词翻转
        while (i < n  && s[i] != ' ') i++;
        reverse(s, l, i - 1);
        l = i + 1;
    }
    
    char *ans = malloc(sizeof(char) * (n + 1));
    int i = 0, j = n - 1, size = 0;
    while (i < n && s[i] == ' ') i++; // 消除首部的空格 
    while (j >= 0 && s[j] == ' ') j--; // 消除尾部的空格
    while (i <= j) { 
        if (i > 0 && s[i] == ' ' && s[i - 1] == ' ') { // 单词间只留一个空格
            i++;
            continue;
        }
        ans[size++] = s[i++];
    }

    ans[size] = '\0';
    return ans;
}
