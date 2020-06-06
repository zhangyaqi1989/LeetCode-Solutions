class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int mn = A.back() - A.front();
        int n = A.size();
        for(int i = 0; i < n - 1; ++i) {
            int cur_mn = min(A[i + 1], A[0] + 2 * K);
            int cur_mx = max(A.back(), A[i] + 2 * K);
            mn = min(mn, cur_mx - cur_mn);
        }
        return mn;
    }
};
