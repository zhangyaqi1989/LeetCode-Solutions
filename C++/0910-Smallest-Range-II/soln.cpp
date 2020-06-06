class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int res = A[A.size() - 1] - A[0];
        int mx, mn;
        for(int i = 0; i < A.size() - 1; ++i)
        {
            mx = max(A[A.size() - 1], A[i] + 2 * K);
            mn = min(A[i + 1], A[0] + 2 * K);
            res = min(mx - mn, res);
        }
        return res;
    }
};