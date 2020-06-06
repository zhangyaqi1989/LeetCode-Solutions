class Solution {
    public int minFlipsMonoIncr(String S) {
        int zeros = 0, n = S.length();
        for (int i = 0; i < n; ++i) {
            if (S.charAt(i) == '0') ++zeros;
        }
        int ans = n, left_zeros = 0;
        for(int i = 0; i <= n; ++i) {
            int modifies = i - left_zeros + zeros - left_zeros;
            ans = Math.min(ans, modifies);
            if (i < n && S.charAt(i) == '0') ++left_zeros;
        }
        return ans;
    }
}
