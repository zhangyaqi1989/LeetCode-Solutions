class Solution {
    private int [] memo = new int [100005];
    private final int MOD = 1000000007;
    public int numberOfArrays(String s, int k) {
        Arrays.fill(memo, -1);
        return solve(0, k, s);
    }
    
    private int solve(int idx, int k, String s) {
        if(idx == s.length()) return 1;
        if(memo[idx] != -1) return memo[idx];
        long num = 0;
        int ans = 0;
        for(int nxt = idx; nxt < s.length(); ++nxt) {
            num = num * 10 + s.charAt(nxt) - '0';
            if(num <= 0 || num > k || (nxt > idx && s.charAt(idx) == '0')) break;
            ans = (int) ((long) ans + solve(nxt + 1, k, s)) % MOD;
        }
        memo[idx] = ans;
        return ans;
    }
}
