

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        unordered_set<string> visited;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    dfs(i, j, board, visited);
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
    
private:
    void dfs(int i, int j, vector<vector<char>>& board, unordered_set<string> & visited) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        string code = to_string(i) + " " + to_string(j);
        if (visited.find(code) == visited.end() && board[i][j] == 'O') {
            visited.insert(code);
            board[i][j] = 'S';
            dfs(i - 1, j, board, visited);
            dfs(i + 1, j, board, visited);
            dfs(i, j - 1, board, visited);
            dfs(i, j + 1, board, visited);
        }
    }
};
