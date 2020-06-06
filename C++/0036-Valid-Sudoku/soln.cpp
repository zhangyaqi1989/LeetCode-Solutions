class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_used[9][9] = {0}, col_used[9][9] = {0}, sub_used[9][9] = {0};
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1', sub_idx = i / 3 * 3 + j / 3;
                    if (row_used[i][num] || col_used[j][num] || sub_used[sub_idx][num])
                        return false;
                    row_used[i][num] = col_used[j][num] = sub_used[sub_idx][num] = 1;
                }
            }
        return true;
    }
};
