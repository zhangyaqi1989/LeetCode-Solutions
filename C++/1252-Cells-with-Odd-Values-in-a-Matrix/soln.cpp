class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n, 0), cols(m, 0);
        for(const auto & indice : indices) {
            int r = indice[0], c = indice[1];
            ++rows[r];
            ++cols[c];
        }
        int ans = 0;
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < m; ++c) {
                ans += (rows[r] + cols[c]) % 2;
            }
        }
        return ans;
    }
};
