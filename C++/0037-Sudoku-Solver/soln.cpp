class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> unfills;
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j)
                if (board[i][j] == '.')
                    unfills.emplace_back(i, j);
        }
        solve(board, unfills);
    }
    
private:
    bool valid(vector<vector<char>>& board, int r, int c, char val) {
        int r0 = 3 * (r / 3), c0 = 3 * (c / 3);
        for(int i = 0; i < 9; ++i) {
            if(board[r][i] != '.' && board[r][i] == val) return false;
            if(board[i][c] != '.' && board[i][c] == val) return false;
            if(board[r0 + i / 3][c0 + i % 3] != '.' && board[r0 + i / 3][c0 + i % 3] == val) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, vector<pair<int, int>> & unfills) {
        if (unfills.empty()) {
            return true;
        }
        auto p = unfills.back();
        unfills.pop_back();
        int r = p.first, c = p.second;
        for(char val = '1'; val <= '9'; ++val) {
            if (valid(board, r, c, val)) {
                board[r][c] = val;
                if (solve(board, unfills)) return true;
                else {
                    board[r][c] = '.';
                }
            }
        }
        unfills.emplace_back(r, c);
        return false;
    }

};
