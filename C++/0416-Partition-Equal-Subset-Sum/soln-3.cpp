class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 == 1) return false;
        target /= 2;
        const int kN = nums.size();
        vector<vector<bool>> dp(kN + 1, vector<bool>(target + 1, 0));
        dp[0][0] = true;
        for(int i = 1; i <= kN; ++i) {
            dp[i][0] = true;
            for(int j = 1; j <= target; ++j) {
                if (j >= nums[i - 1]) dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[kN][target];
    }
};
