int romanToInt(char* s) {
    int num = 0;
    for(int i = 0; i < strlen(s); i++){
        int change = 0;
        switch(s[i]){
            case 'I': change = 1; break;
            case 'V': change = 5; break;
            case 'X': change = 10; break;
            case 'L': change = 50; break;
            case 'C': change = 100; break;
            case 'D': change = 500; break;
            case 'M': change = 1000; break;
        }

		if(i != strlen(s) - 1){
            if (s[i] == 'I' && s[i + 1] == 'V') { change = 4; i++; }
            if (s[i] == 'I' && s[i + 1] == 'X') { change = 9; i++; }
            if (s[i] == 'X' && s[i + 1] == 'L') { change = 40; i++; }
            if (s[i] == 'X' && s[i + 1] == 'C') { change = 90; i++; }
            if (s[i] == 'C' && s[i + 1] == 'D') { change = 400; i++; }
            if (s[i] == 'C' && s[i + 1] == 'M') { change = 900; i++; }
        }


        num += change;
    }

    return num;
}