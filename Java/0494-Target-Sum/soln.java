class Solution {
    private int ans;
    public int findTargetSumWays(int[] nums, int S) {
        // How many ways to sum to target
        // 2 ** 20
        // 1000,000
        ans = 0;
        dfs(nums, S, 0, 0);
        return ans;
    }
    
    private void dfs(int[] nums, int S, int idx, int sum) {
        if (idx == nums.length) {
            if (sum == S) ++ans;
        } else {
            dfs(nums, S, idx + 1, sum + nums[idx]);
            dfs(nums, S, idx + 1, sum - nums[idx]);
        }
    }
}
