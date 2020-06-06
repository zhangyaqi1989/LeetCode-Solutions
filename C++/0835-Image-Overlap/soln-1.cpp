class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size();
        vector<pair<int, int>> A_ones, B_ones;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(A[i][j] == 1) A_ones.push_back({i, j});
                if(B[i][j] == 1) B_ones.push_back({i, j});
            }
        map<pair<int, int>, int> counter;
        for(auto & a : A_ones) {
            for(auto & b : B_ones) {
                int di = a.first - b.first, dj = a.second - b.second;
                counter[make_pair(di, dj)]++;
            }
        }
        int ans = 0;
        for(auto & it : counter) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};
