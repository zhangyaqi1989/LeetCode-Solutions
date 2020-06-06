
class Solution {
    public String smallestSubsequence(String text) {
        int [] last = new int[26];
        boolean [] used = new boolean[26];
        int n = text.length();
        for(int i = 0; i < n; ++i) last[text.charAt(i) - 'a'] = i;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; ++i) {
            char ch = text.charAt(i);
            if (!used[ch - 'a']) {
                while (sb.length() != 0 && ch < sb.charAt(sb.length() - 1) && i < last[sb.charAt(sb.length() - 1) - 'a']) {
                    used[sb.charAt(sb.length() - 1) - 'a'] = false;
                    sb.deleteCharAt(sb.length() - 1);
                }
                used[ch - 'a'] = true;
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}
