class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        int i = 0, j = n - 1;
        for(int idx = n - 1; idx >= 0; --idx) {
            if (abs(A[i]) > abs(A[j])) {
                ans[idx] = A[i] * A[i];
                i += 1;
            } else {
                ans[idx] = A[j] * A[j];
                j -= 1;
            }
        }
        return ans;
    }
};
