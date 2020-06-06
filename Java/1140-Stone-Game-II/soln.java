class Solution {
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        int [] prefix = new int [n + 1];
        for(int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + piles[i];
        }
        int [][] memo = new int [105][105];
        return dfs(piles, memo, prefix, 0, 1);
    }
    
    private int dfs(int [] piles, int [][] memo, int [] prefix, int lo, int M) {
        if (memo[lo][M] != 0) return memo[lo][M];
        if (lo == piles.length) return 0;
        int n = piles.length;
        int total = prefix[n] - prefix[lo];
        int ans = 0;
        for(int i = lo + 1; i <= Math.min(lo + 2 * M, n); ++i) {
            ans = Math.max(ans, total - dfs(piles, memo, prefix, i, Math.max(M, i - lo)));
        }
        memo[lo][M] = ans;
        return ans;
    }
}
