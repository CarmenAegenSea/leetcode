import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> ans = new ArrayList<>();
        int n = words.length, i = 0;
        while (i < n) {
            int j = i, len = 0;
            while (j < n && len + words[j].length() + (j - i) <= maxWidth) {
                len += words[j].length();
                j++;
            }
            StringBuilder sb = new StringBuilder();
            int slots = j - i - 1;
            if (j == n || slots == 0) {
                for (int k = i; k < j; k++) {
                    if (k > i) sb.append(' ');
                    sb.append(words[k]);
                }
                while (sb.length() < maxWidth) sb.append(' ');
            } else {
                int spaces = maxWidth - len;
                int each = spaces / slots;
                int extra = spaces % slots;
                for (int k = i; k < j; k++) {
                    if (k > i) {
                        for (int t = 0; t < each; t++) sb.append(' ');
                        if (k - i <= extra) sb.append(' ');
                    }
                    sb.append(words[k]);
                }
            }
            ans.add(sb.toString());
            i = j;
        }
        return ans;
    }
}
