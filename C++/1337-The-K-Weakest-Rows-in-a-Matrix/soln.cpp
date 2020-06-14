class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int h = mat.size(), w = mat[0].size();
        vector<int> soldiers(h, 0);
        vector<int> idxes(h);
        for(int i = 0; i < h; ++i) {
            idxes[i] = i;
            int cnt = 0;
            for(int j = 0; j < w; ++j) cnt += mat[i][j];
            soldiers[i] = cnt;
        }
        sort(idxes.begin(), idxes.end(), [&](int a, int b) {
            return soldiers[a] == soldiers[b] ? a < b : soldiers[a] < soldiers[b];
        });
        idxes.resize(k);
        return idxes;
    }
};
