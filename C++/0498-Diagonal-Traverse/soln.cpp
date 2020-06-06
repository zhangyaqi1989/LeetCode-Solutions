class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        bool reverse = true;
        for(int j = 0; j < n; ++j) {
            vector<int> temp;
            int r = 0, c = j;
            while(r < m && c >= 0) {
                temp.push_back(matrix[r][c]);
                ++r;
                --c;
            }
            if (reverse) ans.insert(ans.end(), temp.rbegin(), temp.rend());
            else ans.insert(ans.end(), temp.begin(), temp.end());
            reverse = !reverse;
        }
        for(int i = 1; i < m; ++i) {
            vector<int> temp;
            int r = i, c = n - 1;
            while(r < m && c >= 0) {
                temp.push_back(matrix[r][c]);
                ++r;
                --c;
            }
            if (reverse) ans.insert(ans.end(), temp.rbegin(), temp.rend());
            else ans.insert(ans.end(), temp.begin(), temp.end());   
            reverse = !reverse;
        }
        return ans;
    }
};
