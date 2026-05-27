class Solution {
    public String addBinary(String a, String b) {
        int lenA = a.length(), lenB = b.length();
        int maxLen = Math.max(lenA, lenB);
        StringBuilder sb = new StringBuilder();
        int carry = 0;

        while (lenA > 0 || lenB > 0 || carry > 0) {
            int bitA = (lenA > 0) ? a.charAt(--lenA) - '0' : 0;
            int bitB = (lenB > 0) ? b.charAt(--lenB) - '0' : 0;
            int sum = bitA + bitB + carry;
            carry = sum / 2;
            sb.append(sum % 2);
        }

        return sb.reverse().toString();
    }
}
