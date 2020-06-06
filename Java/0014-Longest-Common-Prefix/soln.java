class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        StringBuilder sb = new StringBuilder();
        int min_len = strs[0].length();
        for(String str : strs) min_len = Math.min(min_len, str.length());
        int n = strs.length;
        for(int i = 0; i < min_len; ++i) {
            boolean valid = true;
            for(int j = 0; j < n; ++j) {
                if (strs[j].charAt(i) != strs[0].charAt(i)) {
                    valid = false;
                    break;
                }
            }
            if (valid) sb.append(strs[0].charAt(i));
            else break;
        }
        return sb.toString();
    }
}
