class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        int i = 0, n = S.length();
        for(int j = 0; j < n; ++j) {
            if (S[j] != S[i]) {
                if (j - i >= 3) ans.push_back({i, j - 1});
                i = j;
            }
        }
        if (n - i >= 3) ans.push_back({i, n - 1});
        return ans;
    }
};
