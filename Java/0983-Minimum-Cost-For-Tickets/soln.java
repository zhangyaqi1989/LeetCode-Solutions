class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;
        int mx = days[n - 1];
        int c1 = costs[0], c7 = costs[1], c30 = costs[2];
        int[] dp = new int[mx + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        int i = 0;
        for(int day = 1; day <= mx; ++day) {
            if (day != days[i]) {
                dp[day] = dp[day - 1];
            } else {
                ++i;
                dp[day] = Math.min(c1 + dp[day - 1], Math.min(c7 + dp[Math.max(0, day - 7)], c30 + dp[Math.max(0, day - 30)]));
            }
        }
        return dp[mx];
    }
}
