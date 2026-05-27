class Solution {
    private void reverse(char[] s, int f, int l) {
        for (; f < l; f++, l--) {
            char t = s[f]; s[f] = s[l]; s[l] = t;
        }
    }

    public String reverseWords(String s) {
        char[] arr = s.toCharArray();
        int length = arr.length;
        reverse(arr, 0, length - 1);

        int f = 0, l = length - 1;
        while (f < length && arr[f] == ' ') f++;
        while (l >= 0 && arr[l] == ' ') l--;

        for (int lf = f; lf <= l; lf++) {
            if (arr[lf] == ' ' || lf == l) {
                reverse(arr, f, lf - (lf == l ? 0 : 1));
                f = lf + 1;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != ' ') {
                sb.append(arr[i]);
            } else if (sb.length() > 0 && sb.charAt(sb.length() - 1) != ' ') {
                sb.append(' ');
            }
        }
        if (sb.length() > 0 && sb.charAt(sb.length() - 1) == ' ') {
            sb.deleteCharAt(sb.length() - 1);
        }
        return sb.toString();
    }
}
