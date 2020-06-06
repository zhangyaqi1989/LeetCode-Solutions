class Solution {
    public void gameOfLife(int[][] board) {
        // 1: live, 0: dead
        // 1: fewer than two live dies; 2 or 3 lives, more than 3 dies
        // 0: ...3 becomes live
        // 1 --> 0: 3
        // 0 --> 1: 2
        if (board.length == 0 || board[0].length == 0) return;
        int m = board.length, n = board[0].length;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int cnt = neighbors8(board, i, j);
                if(board[i][j] == 1) {
                    if (cnt != 2 && cnt != 3) board[i][j] = 3;
                } else {
                    if (cnt == 3) board[i][j] = 2;
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (board[i][j] == 3) board[i][j] = 0;
                else if (board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
    
    public int neighbors8(int [][] board, int i, int j) {
        int m = board.length, n = board[0].length;
        int [] dirs = {-1, 0, 1};
        int cnt = 0;
        for(int di : dirs) {
            for(int dj : dirs) {
                if (di == 0 && dj == 0) continue;
                int newi = i + di, newj = j + dj;
                if (0 <= newi && newi < m && 0 <= newj && newj < n) {
                    cnt += board[newi][newj] % 2;
                }
            }
        }
        return cnt;
    }
    
    
}
