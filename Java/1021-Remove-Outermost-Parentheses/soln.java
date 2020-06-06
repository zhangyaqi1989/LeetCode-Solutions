class Solution {
    public String removeOuterParentheses(String S) {
        StringBuilder sb = new StringBuilder();
        int cnt = 0;
        int lo = 0, n = S.length();
        for(int i = 0; i < n; ++i) {
            char ch = S.charAt(i);
            if (ch == '(') {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    sb.append(S.substring(lo + 1, i));
                    lo = i + 1;
                }
            }
        }
        return sb.toString();
    }
}
