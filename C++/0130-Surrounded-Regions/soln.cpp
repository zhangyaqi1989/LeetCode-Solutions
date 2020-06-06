class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        stack<pair<int, int>> s;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    board[i][j] = 'F';
                    s.push({i, j});
                }
            }
        }
        int dis[4] = {0, 0, 1, -1};
        int djs[4] = {1, -1, 0, 0};
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            int i = node.first, j = node.second;
            // board[i][j] = 'F';
            for (int k = 0; k < 4; ++k) {
                int newi = i + dis[k];
                int newj = j + djs[k];
                if (newi >= 0 && newi < m && newj >= 0 && newj < n && board[newi][newj] == 'O') {
                    board[newi][newj] = 'F';
                    s.push({newi, newj});
                    
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'F') board[i][j] = 'O';
            }
        }
        // return board;
    }
};
