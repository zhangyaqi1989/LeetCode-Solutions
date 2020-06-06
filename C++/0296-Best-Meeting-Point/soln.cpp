class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                } 
            }
        }
        sort(cols.begin(), cols.end());
        return helper(rows) + helper(cols);
    }
    
private:
    int helper(const vector<int> & arr) {
        int n = arr.size();
        int ans = 0;
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            ans += arr[hi--] - arr[lo++];
        }
        return ans;
    }
};
