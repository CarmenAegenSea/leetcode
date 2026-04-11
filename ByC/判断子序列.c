bool isSubsequence(char* s, char* t) {
    int n = 0;
    if(strlen(s) == 0) return true;
    for(int i = 0; t[i] != '\0'; i++){
        if(s[n] == t[i]){
            n++;
            if(n == strlen(s)) return true;
        }
    }

    return false;
}