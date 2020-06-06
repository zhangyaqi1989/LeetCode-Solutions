class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1});
        int longest = 0, ans = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j].first + 1 > dp[i].first) {
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    } else if (dp[j].first + 1 == dp[i].first) {
                        dp[i].second += dp[j].second;
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            if (dp[i].first > longest) {
                longest = dp[i].first;
                ans = dp[i].second;
            } else if (dp[i].first == longest) {
                ans += dp[i].second;
            }
        }
        return ans;
    }
};
