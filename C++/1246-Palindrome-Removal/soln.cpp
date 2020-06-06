class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        const int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for(int i = 0; i < n; ++i) dp[i][i] = 1;
        for(int i = 0; i + 1 < n; ++i) {
            if(arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
            else dp[i][i + 1] = 2;
        }
        for(int len = 3; len <= n; ++len) {
            for(int i = 0; i + len - 1 < n; ++i) {
                int left = i;
                int right = i + len - 1;
                if(arr[left] == arr[right]) dp[left][right] = dp[left + 1][right - 1];
                for(int mid = left; mid < right; ++mid) {
                    dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
