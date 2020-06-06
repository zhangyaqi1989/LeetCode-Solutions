class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        vector<vector<char>> board(8, vector<char>(8, 'E'));
        for(const auto & q : queens) {
            board[q[0]][q[1]] = 'Q';
        }
        board[king[0]][king[1]] = 'K';
        int r = king[0], c = king[1];
        for(int k = 0; k < 8; ++k) {
            int dr = dirs[k][0], dc = dirs[k][1];
            int new_r = r + dr, new_c = c + dc;
            while (0 <= new_r && new_r < 8 && 0 <= new_c && new_c < 8) {
                if (board[new_r][new_c] == 'Q') {
                    ans.push_back({new_r, new_c});
                    break;
                }
                new_r += dr;
                new_c += dc;
            }
        }
        return ans;
    }
};
