char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];

    for (int y = 0; strs[0][y] != '\0'; y++) {
        for (int x = 1; x < strsSize; x++) {
            if (strs[x][y] == '\0' || strs[x][y] != strs[0][y]) {
                char* result = (char*)malloc((y + 1) * sizeof(char));
                strncpy(result, strs[0], y);
                result[y] = '\0'; 
                return result;
            }
        }
    }
    char* result = (char*)malloc((strlen(strs[0]) + 1) * sizeof(char));
    strcpy(result, strs[0]);
    return result;
}