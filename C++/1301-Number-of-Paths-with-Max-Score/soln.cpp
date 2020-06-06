class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const long kMod = 1e9 + 7;
        const int kN = board.size();
        vector<vector<pair<int, int>>> dp(kN + 1, vector<pair<int, int>>(kN + 1, {-1, 0}));
        const int dis[3] = {0, 1, 1};
        const int djs[3] = {1, 0, 1};
        dp[kN - 1][kN - 1] = {0, 1};
        for(int i = kN - 1; i >= 0; --i) {
            for(int j = kN - 1; j >= 0; --j) {
                if(board[i][j] == 'X' || board[i][j] == 'S') continue;
                for(int k = 0; k < 3; ++k) {
                    int ni = i + dis[k], nj = j + djs[k];
                    if (dp[ni][nj].first > dp[i][j].first) {
                        dp[i][j] = dp[ni][nj];
                    } else if (dp[ni][nj].first == dp[i][j].first) {
                        dp[i][j].second = ((long) dp[i][j].second + dp[ni][nj].second) % kMod;
                    }
                }
                
                if (dp[i][j].first != -1) {
                    dp[i][j].first += isdigit(board[i][j]) ? (board[i][j] - '0') : 0;
                }
            }
        }
        return {max(dp[0][0].first, 0), dp[0][0].second};
    }
};
