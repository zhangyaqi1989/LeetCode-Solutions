class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        process(board, click[0], click[1]);
        return board;
    }
    
private:
    
    void process(vector<vector<char>>& board, int r, int c) {
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
        } else {
            int cnt = countMines(board, r, c);
            if (cnt == 0) {
                board[r][c] = 'B';
                for(int dr = -1; dr <= 1; ++dr) {
                    for(int dc = -1; dc <= 1; ++dc) {
                        if (dr == 0 && dc == 0) continue;
                        int nr = r + dr, nc = c + dc;
                        if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && (board[nr][nc] == 'M' || board[nr][nc] == 'E'))
                            process(board, nr, nc);
                    }
                } 
            } else {
                board[r][c] = '0' + cnt;
            }
        }        
    }
    

    int countMines(const vector<vector<char>>& board, int r, int c) {
        const int R = board.size();
        const int C = board[0].size();
        int cnt = 0;
        for(int dr = -1; dr <= 1; ++dr) {
            for(int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0) continue;
                int nr = r + dr, nc = c + dc;
                cnt += 0 <= nr && nr < R && 0 <= nc && nc < C && (board[nr][nc] == 'X' || board[nr][nc] == 'M');
            }
        }
        return cnt;
    }
};
