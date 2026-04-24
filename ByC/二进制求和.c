char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    char* res = (char*)malloc(maxLen + 2);
    int index = 0;
    int carry = 0; 
    
    while (lenA > 0 || lenB > 0 || carry > 0) {
        int bitA = (lenA > 0) ? a[--lenA] - '0' : 0;
        int bitB = (lenB > 0) ? b[--lenB] - '0' : 0;
        
        int sum = bitA + bitB + carry;
        carry = sum / 2;
        res[index++] = sum % 2 + '0';
    }
    
    res[index] = '\0';
    int left = 0, right = index - 1;
    while (left < right) {
        char temp = res[left];
        res[left] = res[right];
        res[right] = temp;
        left++;
        right--;
    }
    
    return res;
}