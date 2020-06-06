class Solution {
    public int findSubstringInWraproundString(String p) {
        int[] dp = new int[26];
        for(char ch : p.toCharArray()) {
            dp[ch - 'a'] = 1;
        }
        int len = 1;
        int n = p.length();
        for(int i = 0; i < n - 1; ++i) {
            char a = p.charAt(i), b = p.charAt(i + 1);
            if (b - a == 1 || (a == 'z' && b == 'a')) {
                ++len;
            } else {
                len = 1;
            }
            dp[b - 'a'] = Math.max(dp[b - 'a'], len);
        }
        int ans = 0;
        for(int i = 0; i < 26; ++i) {
            ans += dp[i];
        }
        return ans;
    }
}
