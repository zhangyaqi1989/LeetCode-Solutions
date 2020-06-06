class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int [][] dp = new int [n][2];
        for(int [] row : dp) Arrays.fill(row, 1);
        for(int i = 1; i < n; ++i)
            for(int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j][0] + 1 > dp[i][0]) {
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = dp[j][1];
                    } else if (dp[j][0] + 1 == dp[i][0]) {
                        dp[i][1] += dp[j][1];
                    }
                }
            }
        int longest = 0, ans = 0;
        for(int i = 0; i < n; ++i) {
            if (dp[i][0] > longest) {
                longest = dp[i][0];
                ans = dp[i][1];
            } else if (dp[i][0] == longest) {
                ans += dp[i][1];
            }
        }
        return ans;
    }
}
