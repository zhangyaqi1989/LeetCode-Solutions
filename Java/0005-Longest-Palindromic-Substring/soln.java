class Solution {
    public String longestPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        for(char ch : s.toCharArray()) {
            sb.append('#');
            sb.append(ch);
        }
        sb.append('#');
        int n = sb.length();
        int c = 0, r = 0;
        int [] P = new int [n];
        int mx = 0;
        int left = 0, right = 0;
        for(int i = 0; i < n; ++i) {
            int mirror = 2 * c - i;
            if (i < r) {
                P[i] = Math.min(P[mirror], r - i);
            }
            int lo = i - (P[i] + 1);
            int hi = i + (P[i] + 1);
            while (lo >= 0 && hi < n && sb.charAt(lo) == sb.charAt(hi)) {
                --lo;
                ++hi;
                ++P[i];
            }
            if (i + P[i] > r) {
                c = i;
                r = i + P[i];
                if (P[i] > mx) {
                    mx = P[i];
                    left = i - P[i];
                    right = i + P[i];
                }
            }
        }
        StringBuilder ans = new StringBuilder();
        for(int i = left; i <= right; ++i) {
            if (sb.charAt(i) != '#') ans.append(sb.charAt(i));
        }
        return ans.toString();
    }
}
