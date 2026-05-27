class Solution {
    public int romanToInt(String s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            int change = 0;
            switch (s.charAt(i)) {
                case 'I': change = 1; break;
                case 'V': change = 5; break;
                case 'X': change = 10; break;
                case 'L': change = 50; break;
                case 'C': change = 100; break;
                case 'D': change = 500; break;
                case 'M': change = 1000; break;
            }
            if (i != s.length() - 1) {
                if (s.charAt(i) == 'I' && s.charAt(i + 1) == 'V') { change = 4; i++; }
                else if (s.charAt(i) == 'I' && s.charAt(i + 1) == 'X') { change = 9; i++; }
                else if (s.charAt(i) == 'X' && s.charAt(i + 1) == 'L') { change = 40; i++; }
                else if (s.charAt(i) == 'X' && s.charAt(i + 1) == 'C') { change = 90; i++; }
                else if (s.charAt(i) == 'C' && s.charAt(i + 1) == 'D') { change = 400; i++; }
                else if (s.charAt(i) == 'C' && s.charAt(i + 1) == 'M') { change = 900; i++; }
            }
            num += change;
        }
        return num;
    }
}
