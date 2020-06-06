class Solution {
    public int countBinarySubstrings(String s) {
        int pre_cnt = 0;
        int ans = 0;
        int lo = 0, n = s.length();
        for(int i = 0; i < n; ++i) {
            if(s.charAt(i) != s.charAt(lo)) {
                int cnt = i - lo;
                ans += Math.min(cnt, pre_cnt);
                lo = i;
                pre_cnt = cnt;
            }
        }
        ans += Math.min(pre_cnt, n - lo);
        return ans;
    }
}
