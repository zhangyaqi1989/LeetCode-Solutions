class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }

    bool helper(int left, vector<int> & dp) {
        if(left <= 0) return false;
        if(dp[left] != -1) return dp[left] == 1;
        int ans = 0;
        for(int r = 1; r * r <= left; ++r) {
            if(!helper(left - r * r, dp)) {
                ans = 1;
                break;
            }
        }
        dp[left] = ans;
        return ans == 1;
    }
};
