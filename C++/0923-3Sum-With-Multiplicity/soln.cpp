class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        // How to pick unique soln
        int n = A.size();
        long long ans = 0;
        sort(A.begin(), A.end());
        long long c[105] = {0};
        int mod = 1e9 + 7;
        for(int num : A) ++c[num];
        for(int i = 0; i < n - 2; ++i) {
            if(i > 0 && A[i] == A[i - 1]) continue;
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int s = A[i] + A[lo] + A[hi];
                if (s == target) {
                    if (A[i] == A[lo] && A[lo] == A[hi]) ans = (ans + c[A[i]] * (c[A[i]] - 1) * (c[A[i]] - 2) / 6 ) % mod;
                    else if (A[i] == A[lo] && A[lo] < A[hi]) ans = (ans + c[A[i]] * (c[A[i]] - 1) * c[A[hi]] / 2) % mod;
                    else if (A[i] < A[lo] && A[lo] < A[hi]) ans = (ans + c[A[i]] * c[A[lo]] * c[A[hi]]) % mod;
                    else ans = (ans + c[A[i]] * c[A[lo]] * (c[A[lo]] - 1) / 2) % mod;
                    
                    // cout <<ans << " "<< A[i] << " " << A[lo] << " " << A[hi] << endl;
                    // ans = (ans + counter[A[i]] * counter[A[lo]] * counter[A[hi]]) % mod;
                    while (lo + 1 < hi && A[lo + 1] == A[lo]) ++lo;
                    while (hi - 1 > lo && A[hi - 1] == A[hi]) --hi;
                    ++lo;
                    --hi;
                    
                } else if (s < target) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }
        return ans;
    }
    
    
};
