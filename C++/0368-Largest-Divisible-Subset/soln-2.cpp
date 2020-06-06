class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {}; 
        // 1, 2, 4, 8
        const int kN = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(kN);
        for(int i = 0; i < kN; ++i) dp[i].push_back(nums[i]);
        for(int i = 1; i < kN; ++i) {
            int mx_len = dp[i].size();
            int best_j = 0;
            for(int j = 0; j < i; ++j) {

                if (nums[i] % nums[j] == 0) {
                    if (dp[j].size() + 1 > mx_len) {
                        mx_len = dp[j].size() + 1;
                        best_j = j;
                    }
                }
            }
            if (mx_len > dp[i].size()) {
                dp[i] = dp[best_j];
                dp[i].push_back(nums[i]);
            }
        }
        int mx_len = 0;
        int idx = 0;
        for(int i = 0; i < kN; ++i) {
            if(dp[i].size() > mx_len) {
                mx_len = dp[i].size();
                idx = i;
            }
        }
        return dp[idx];
    }
};
