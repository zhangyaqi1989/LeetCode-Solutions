class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty() ) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        for(int l = 0; l < n; ++l) {
            vector<int> accs(m, 0);
            for(int r = l; r < n; ++r) {
                for(int i = 0; i < m; ++i) {
                    accs[i] += matrix[i][r];
                }
                
                set<int> acc_set;
                acc_set.insert(0);
                int cur = 0, mx_area = INT_MIN;
                for(int s : accs) {
                    cur += s;
                    auto it = acc_set.lower_bound(cur - k);
                    if (it != acc_set.end()) mx_area = max(mx_area, cur - *it);
                    acc_set.insert(cur);
                }
                res = max(res, mx_area);
            }
        }
        return res;
    }
};
