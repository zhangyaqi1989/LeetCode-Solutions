class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int mx = INT_MIN;
        for(int i = 0; i < m; ++i) {
            vector<int> array(m, 0);
            for(int j = i; j < n; ++j) {
                for(int r = 0; r < m; ++r) {
                    array[r] += matrix[r][j];
                }
                // cout << maxSumSubarray(array, k) << endl;
                mx = max(mx, maxSumSubarray(array, k));
            }
        }
        return mx == INT_MIN ? -1 : mx;
    }
    
private:
    int maxSumSubarray(vector<int> & array, int k) {
        set<int> tree;
        tree.insert(0);
        int acc = 0;
        int mx = INT_MIN;
        for(int num : array) {
            acc += num;
            auto it = tree.lower_bound(acc - k); // *it >= acc - k
            if (it != tree.end()) {
                mx = max(mx, acc - *it);
            }
            tree.insert(acc);
        }
        return mx;
    }
};
