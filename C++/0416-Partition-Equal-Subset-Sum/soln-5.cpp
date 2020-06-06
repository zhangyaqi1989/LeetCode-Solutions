class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 == 1) return false;
        target /= 2;
        const int kN = nums.size();
        vector<int> dp(target + 1);
        dp[0] = true;
        for(int i = 1; i <= kN; ++i) {
            for(int j = target; j >= 0; --j) {
                if (j >= nums[i - 1] && dp[j - nums[i - 1]]) dp[j] = true;
            }
            if (dp.back()) return true;
        }
        return dp.back();
    }
};
