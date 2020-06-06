class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < (int) board.size(); ++i) {
            for(int j = 0; j < (int) board[0].size(); ++j) {
                if (dfs(board, 0, i, j, word)) return true;
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, int idx, int r, int c, const string & word) {
        if (idx == word.length()) return true;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[idx]) return false;
        board[r][c] = '#';
        if (dfs(board, idx + 1, r - 1, c, word) ||
            dfs(board, idx + 1, r + 1, c, word) ||
            dfs(board, idx + 1, r, c - 1, word) ||
            dfs(board, idx + 1, r, c + 1, word)) return true;
        board[r][c] = word[idx];
        return false;
    }
};
