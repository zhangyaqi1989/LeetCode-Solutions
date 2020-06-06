class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> board(N, vector<double>(N, 0.0));
        board[r][c] = 1.0;
        int dis[] = {1, 1, 2, 2, -1, -1, -2, -2};
        int djs[] = {2, -2, 1, -1, 2, -2, 1, -1};
        for(int k = 0; k < K; ++k) {
            vector<vector<double>> temp(N, vector<double>(N, 0.0));
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j) {
                    double cnt = 0.0;
                    for(int p = 0; p < 8; ++p) {
                        int di = dis[p], dj = djs[p];
                        int newi = i + di, newj = j + dj;
                        if (0 <= newi && newi < N && 0 <= newj && newj < N) {
                            cnt += board[newi][newj];
                        }
                    }   
                    // cout << cnt << endl;
                    temp[i][j] = cnt / 8;
                }
            swap(temp, board);
        }
        double ans = 0.0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j) {
                // cout << board[i][j] << endl;
                ans += board[i][j];
            }
        return ans;
    }
};
