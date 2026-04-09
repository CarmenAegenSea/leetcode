int strStr(char* haystack, char* needle) {
    int lengthH = strlen(haystack);
    int lengthN = strlen(needle);

    for(int i = 0; i + lengthN <= lengthH; i++){
        int change = 0;
        if(haystack[i] == needle[0]){
            for(int n = 0; n < lengthN; n++){
                if(haystack[i + n] != needle[n]) break;
                else change++;
                if(change == lengthN) return i;
            }
        }
    }

    return -1;
}