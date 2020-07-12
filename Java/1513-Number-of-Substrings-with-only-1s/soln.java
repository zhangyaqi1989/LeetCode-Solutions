class Solution {
    public int numSub(String s) {
        int n = s.length();
        final int MOD = 1000000007;
        int ans = 0;
        for(int i = 0, j; i < n; i = j) {
            j = i;
            while(j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
            }
            if(s.charAt(i) == '1') {
                int len = j - i;
                ans += (int) (((long) len + 1) * len / 2 % MOD);
            }
        }
        return ans;
    }
}
