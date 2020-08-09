class Solution {
    private int [] [] dp;
    public int minCost(int n, int[] cuts) {
        dp = new int [105][105];
        int [] new_cuts = new int [cuts.length + 2];
        for(int i = 0; i < cuts.length; ++i) {
            new_cuts[i] = cuts[i];
        }
        new_cuts[cuts.length] = 0;
        new_cuts[cuts.length + 1] = n;
        Arrays.sort(new_cuts);
        return dfs(new_cuts, 0, new_cuts.length - 1);
    }
    
    private int dfs(int [] cuts, int lo, int hi) {
        if(hi - lo <= 1) return 0;
        if(dp[lo][hi] != 0) return dp[lo][hi];
        int ans = Integer.MAX_VALUE;
        for(int k = lo + 1; k < hi; ++k) {
            ans = Math.min(ans, dfs(cuts, lo, k) + dfs(cuts, k, hi));
        }
        ans += cuts[hi] - cuts[lo];
        dp[lo][hi] = ans;
        return ans;
    }
}
