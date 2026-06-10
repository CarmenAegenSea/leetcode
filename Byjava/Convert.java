class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) return s;
        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) rows[i] = new StringBuilder();
        int cur = 0, step = 1;
        for (char c : s.toCharArray()) {
            rows[cur].append(c);
            if (cur == 0) step = 1;
            else if (cur == numRows - 1) step = -1;
            cur += step;
        }
        StringBuilder ans = new StringBuilder();
        for (StringBuilder row : rows) ans.append(row);
        return ans.toString();
    }
}
