class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i0 = 0, j0 = 0;
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j) 
                if (board[i][j] == 'R') {
                    i0 = i;
                    j0 = j;
                    break;
                }
        int dis[4] = {0, 0, 1, -1};
        int djs[4] = {1, -1, 0, 0};
        int cnt = 0;
        for(int k = 0; k < 4; ++k) {
            int di = dis[k], dj = djs[k];
            int i = i0 + di, j = j0 + dj;
            while (i >= 0 && i < 8 && j >= 0 && j < 8) {
                if (board[i][j] == 'p') {
                    ++cnt;
                    break;
                }
                if (board[i][j] == 'B') break;
                i += di;
                j += dj;
            }
        }
        return cnt;
    }
};
