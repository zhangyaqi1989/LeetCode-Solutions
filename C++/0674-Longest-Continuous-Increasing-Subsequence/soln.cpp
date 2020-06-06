class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};