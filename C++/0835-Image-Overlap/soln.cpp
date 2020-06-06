class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size();
        set<pair<int, int>> A_ones, B_ones;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(A[i][j] == 1) A_ones.insert({i, j});
                if(B[i][j] == 1) B_ones.insert({i, j});
            }
        int ans = 0;
        for(int di = -m; di < m; ++di) {
            for(int dj = -n; dj < n; ++dj) {
                int cnt = 0;
                for(auto & p : B_ones) {
                    int i = p.first + di, j = p.second + dj;
                    if(A_ones.find({i, j}) != A_ones.end()) ++cnt;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
