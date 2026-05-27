class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        if (strs.length == 1) return strs[0];

        for (int y = 0; y < strs[0].length(); y++) {
            for (int x = 1; x < strs.length; x++) {
                if (y >= strs[x].length() || strs[x].charAt(y) != strs[0].charAt(y)) {
                    return strs[0].substring(0, y);
                }
            }
        }
        return strs[0];
    }
}
