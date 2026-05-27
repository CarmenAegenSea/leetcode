class Solution {
    public boolean isSubsequence(String s, String t) {
        int n = 0;
        if (s.length() == 0) return true;
        for (int i = 0; i < t.length(); i++) {
            if (s.charAt(n) == t.charAt(i)) {
                n++;
                if (n == s.length()) return true;
            }
        }
        return false;
    }
}
