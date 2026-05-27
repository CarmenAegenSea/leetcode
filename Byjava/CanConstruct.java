class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if (ransomNote.length() > magazine.length()) return false;
        int[] let = new int[26];
        for (int i = 0; i < ransomNote.length(); i++) {
            let[ransomNote.charAt(i) - 'a']++;
        }
        for (int i = 0; i < magazine.length(); i++) {
            let[magazine.charAt(i) - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (let[i] > 0) return false;
        }
        return true;
    }
}
