void change(char *s, int f, int l){
    for(; f < l; f++, l--){
        int t = s[f]; s[f] = s[l]; s[l] = t;
    }
}

char* reverseWords(char* s) {
    int length = strlen(s);
    change(s, 0, strlen(s) - 1);

    int f = 0, l = length - 1;
    while(s[f] == ' ') f++;
    while(s[l] == ' ') l--;
    int fi = f, li = l;

    for(int lf = f; lf < l + 1; lf++){
        if(s[lf] == ' ' || lf == l){
            change(s, f, lf - (lf == l ? 0 : 1));
            f = lf + 1;
        }
    }

    char *ts = malloc(length + 1);
    int idx = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] != ' '){
            ts[idx++] = s[i];
        } else if(idx > 0 && ts[idx-1] != ' '){
            ts[idx++] = ' ';
        }
    }
    
    if(idx > 0 && ts[idx-1] == ' ') idx--;
    ts[idx] = '\0';
        
    return ts;
}