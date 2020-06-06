class Solution {
    public int combinationSum4(int[] nums, int target) {
        int [] dp = new int[target + 1];
        dp[0] = 1;
        for(int x = 1; x <= target; ++x) {
            for(int num : nums) {
                if (x >= num) dp[x] += dp[x - num];
            }
        }
        return dp[target];
    }
}
