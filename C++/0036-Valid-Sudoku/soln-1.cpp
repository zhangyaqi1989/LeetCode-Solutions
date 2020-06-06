class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r = 0; r < 9; ++r) {
            for(int c = 0; c < 9; ++c) {
                if (board[r][c] != '.' && !valid(board, r, c)) return false;
            }
        }
        return true;
    }
    
private:
    bool valid(vector<vector<char>>& board, int r, int c) {
        char ch = board[r][c];
        board[r][c] = '.';
        int r0 = 3 * (r / 3), c0 = 3 * (c / 3);
        for(int i = 0; i < 9; ++i) {
            if (board[i][c] != '.' && board[i][c] == ch) return false;
            if (board[r][i] != '.' && board[r][i] == ch) return false;
            if (board[r0 + i / 3][c0 + i % 3] != '.' && board[r0 + i / 3][c0 + i % 3] == ch) return false;
        }
        board[r][c] = ch;
        return true;
    }
};
