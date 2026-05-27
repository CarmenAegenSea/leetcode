class Solution {
    public int strStr(String haystack, String needle) {
        int lengthH = haystack.length();
        int lengthN = needle.length();

        for (int i = 0; i + lengthN <= lengthH; i++) {
            if (haystack.charAt(i) == needle.charAt(0)) {
                boolean found = true;
                for (int n = 0; n < lengthN; n++) {
                    if (haystack.charAt(i + n) != needle.charAt(n)) {
                        found = false;
                        break;
                    }
                }
                if (found) return i;
            }
        }
        return -1;
    }
}
