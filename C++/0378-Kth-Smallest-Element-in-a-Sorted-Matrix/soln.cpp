class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        k -= 1;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            int cnt = count(matrix, mid);
            if (cnt > k) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        return lo;
    }
    
private:
    int count(vector<vector<int>> & matrix, int num) {
        int ans = 0;
        for(auto & row : matrix) {
            int idx = lower_bound(row.begin(), row.end(), num) - row.begin();
            ans += idx;
        }
        return ans;
    }
};
