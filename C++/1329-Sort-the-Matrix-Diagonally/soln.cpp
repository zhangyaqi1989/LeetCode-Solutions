class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> diags;
        const int kM = mat.size(), kN = mat[0].size();
        for(int i = 0; i < kM; ++i) {
            for(int j = 0; j < kN; ++j) {
                diags[i - j].push_back(mat[i][j]);
            }
        }
        for(auto & p : diags) sort(p.second.rbegin(), p.second.rend());
        for(int i = 0; i < kM; ++i) {
            for(int j = 0; j < kN; ++j) {
                mat[i][j] = diags[i - j].back();
                diags[i - j].pop_back();
            }
        }
        return mat;
    }
};
