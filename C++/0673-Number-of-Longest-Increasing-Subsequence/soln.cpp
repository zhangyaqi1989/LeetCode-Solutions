class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        vector<int> counts(dp);
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j])
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        counts[i] = counts[j];
                    } else if (dp[j] + 1 == dp[i])
                    {
                        counts[i] += counts[j];
                    }
            }
        }
        int max_length = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for(int i = 0; i < dp.size(); ++i)
        {
            if(dp[i] == max_length)
                ans += counts[i];
        }
        return ans;
    }
};