class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        const int kR = matrix.size(), kC = matrix[0].size();
        vector<pair<int, int>> starts;
        for(int i = 0; i < kR; ++i) starts.emplace_back(i, 0);
        for(int j = 1; j < kC; ++j) starts.emplace_back(kR - 1, j);
        vector<int> ans;
        bool reversed = false;
        for(const auto & start : starts) {
            vector<int> level;
            int r = start.first, c = start.second;
            while(r >= 0 && c < kC) {
                level.push_back(matrix[r--][c++]);
            }
            if(reversed) ans.insert(ans.end(), level.rbegin(), level.rend());
            else ans.insert(ans.end(), level.begin(), level.end());
            reversed = !reversed;
        }
        return ans;
    }
};
