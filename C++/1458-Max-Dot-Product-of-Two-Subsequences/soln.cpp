class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MIN));
        for(int i = n1 - 1; i >= 0; --i) {
            for(int j = n2 - 1; j >= 0; --j) {
                dp[i][j] = max(max(dp[i + 1][j], dp[i][j + 1]), nums1[i] * nums2[j] + max(0, dp[i + 1][j + 1]));
            }
        }
        return dp[0][0];
    }
};
