class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return helper(0, n - 1, nums, dp);
    }
    
    int helper(int lo, int hi, vector<int> & nums, vector<vector<int>> & dp) {
        if (dp[lo][hi] > 0 || hi == lo + 1) return dp[lo][hi];
        int ans = 0;
        for(int m = lo + 1; m < hi; ++m) {
            ans = max(ans, helper(lo, m, nums, dp) + nums[lo] * nums[m] * nums[hi] + helper(m, hi, nums, dp));
        }
        dp[lo][hi] = ans;
        return ans;
    }
};
