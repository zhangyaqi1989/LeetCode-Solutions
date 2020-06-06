ass Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        const int INF = 1e9 + 100;
        vector<int> dp(n, -INF);
        multiset<int> window;
        int ans = nums[0];
        dp[0] = nums[0];
        window.insert(dp[0]);
        for(int i = 1; i < n; ++i) {
            if(i - k - 1 >= 0) {
                window.erase(window.find(dp[i - k - 1]));
            }
            if (*window.rbegin() > 0) {
                dp[i] = *window.rbegin() + nums[i];
            }  else {
                dp[i] = nums[i];
            }
            ans = max(ans, dp[i]);
            window.insert(dp[i]);
            
        }
        return ans;
    }
};
