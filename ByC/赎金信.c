bool canConstruct(char* ransomNote, char* magazine) {
    bool change = true;
    int let[26] = {0};

    if(strlen(ransomNote) > strlen(magazine)) return false;

    for(int i = 0; i < strlen(ransomNote); i++){
        let[ransomNote[i] - 'a']++;
    }
    for(int i = 0; i < strlen(magazine); i++){
        let[magazine[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(let[i] > 0) change = false;
    }

    return change;
}