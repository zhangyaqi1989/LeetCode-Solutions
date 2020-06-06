class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int cnt = count(board, i, j);
                if (board[i][j] == 1 && (cnt != 2 && cnt != 3)) board[i][j] = 3;
                if (board[i][j] == 0 && cnt == 3) board[i][j] = 2;
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (board[i][j] > 1) board[i][j] = (1 - board[i][j] % 2);
            }
        }
    }
    
private:
    int count(vector<vector<int>>& board, int r, int c) {
        int cnt = 0;
        for(int dr = -1; dr <= 1; ++dr) {
            for(int dc = -1; dc <= 1; ++dc) {
                if(dr == 0 && dc == 0) continue;
                int nr = r + dr, nc = c + dc;
                if (0 <= nr && nr < board.size() && 0 <= nc && nc < board[0].size()) {
                    cnt += board[nr][nc] % 2;
                }
            }
        }
        return cnt;
    }
};
