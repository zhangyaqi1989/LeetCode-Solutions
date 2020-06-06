class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while (true) {
            if (!process(board)) break;
        }
        return board;
    }
private:
    bool process(vector<vector<int>> & M) {
        vector<pair<int, int>> crushes;
        int m = M.size(), n = M[0].size();
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j + 2 < n && M[i][j] != 0 && M[i][j] == M[i][j + 1] && M[i][j] == M[i][j + 2]) {
                    crushes.push_back({i, j});
                    crushes.push_back({i, j + 1});
                    crushes.push_back({i, j + 2});
                }
                if (i + 2 < m && M[i][j] != 0 && M[i][j] == M[i + 1][j] && M[i][j] == M[i + 2][j]) {
                    crushes.push_back({i, j});
                    crushes.push_back({i + 1, j});
                    crushes.push_back({i + 2, j});
                }
            }
        }
        for(auto & p : crushes) {
            M[p.first][p.second] = 0;
        }
        for(int j = 0; j < n; ++j) {
            int wi = m - 1;
            for(int i = m - 1; i >= 0; --i) {
                if (M[i][j] != 0) {
                    M[wi--][j] = M[i][j];
                }
            }
            for(int i = wi; i >= 0; --i) {
                M[i][j] = 0;
            }
        }
        return !crushes.empty();
    } 
};
