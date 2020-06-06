class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        int rows [m];
        int cols [n];
        memset(rows, 0, sizeof rows);
        memset(cols, 0, sizeof cols);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) ++cnt;
            }
        }
        return cnt;
    }
};
