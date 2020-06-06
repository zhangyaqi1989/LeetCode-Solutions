class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        const int kR = mat.size(), kC = mat[0].size();
        int min_cand = mat[0][0], max_cand = mat[0][kC - 1];
        for(int i = 1; i < kR; ++i) {
            min_cand = max(min_cand, mat[i][0]);
            max_cand = min(max_cand, mat[i][kC - 1]);
        }
        for(int cand = min_cand; cand <= max_cand; ++cand) {
            bool valid = true;
            for(int r = 0; r < kR; ++r) {
                auto it = lower_bound(mat[r].begin(), mat[r].end(), cand);
                if (it == mat[r].end() || (*it) != cand) {
                    valid = false;
                    break;
                }
            }
            if (valid) return cand;
        }
        return -1;
    }
};
