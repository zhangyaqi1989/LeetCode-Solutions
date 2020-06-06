class Solution {
    public int maxCoins(int[] nums) {
        List<Integer> lst = new ArrayList<>();
        lst.add(1);
        for(int num : nums) lst.add(num);
        lst.add(1);
        int n = lst.size();
        int [][] dp = new int [n][n];
        return helper(0, n - 1, lst, dp);
    }
    
    private int helper(int lo, int hi, List<Integer> lst, int[][] dp) {
        if (dp[lo][hi] > 0 || hi == lo + 1) return dp[lo][hi];
        int ans = 0;
        for(int m = lo + 1; m < hi; ++m) {
            ans = Math.max(ans, lst.get(lo) * lst.get(m) * lst.get(hi) + helper(lo, m, lst, dp) + helper(m, hi, lst, dp));
        }
        dp[lo][hi] = ans;
        return ans;
    }
}
