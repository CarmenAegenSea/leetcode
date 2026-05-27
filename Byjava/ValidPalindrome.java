class Solution {
    public boolean isPalindrome(String s) {
        int i = 0, l = s.length() - 1;
        while (i < l) {
            while (i < l && !Character.isLetterOrDigit(s.charAt(i))) i++;
            while (i < l && !Character.isLetterOrDigit(s.charAt(l))) l--;
            if (i >= l) break;
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(l))) {
                return false;
            }
            i++; l--;
        }
        return true;
    }
}
