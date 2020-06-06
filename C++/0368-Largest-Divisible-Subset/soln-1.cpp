class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, -1});
        int mx = 1, best = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i].first < dp[j].first + 1) {
                        dp[i] = {dp[j].first + 1, j};
                        if (dp[j].first + 1 > mx) {
                            mx = dp[j].first + 1;
                            best = i;
                        }
                    }
                }
            }
        }
        int i = best;
        vector<int> ans = {nums[i]};
        while (dp[i].second != -1) {
            i = dp[i].second;
            ans.push_back(nums[i]);
        }
        return ans;
        
    }
};
