class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        int ans = 0;
        for(int l = 0; l < n; ++l) {
            vector<int> arr(m, 0); 
            for(int r = l; r < n; ++r) {
                for(int i = 0; i < m; ++i) arr[i] += matrix[i][r];
                unordered_map<int, int> memo;
                memo[0] = 1;
                int acc = 0;
                int cnt = 0;
                for(int i = 0; i < m; ++i) {
                    acc += arr[i];
                    cnt += memo[acc - target];
                    ++memo[acc];
                }
                ans += cnt;
            }
        }
        return ans;
    }
};
