class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        // how to compute F(i) quickly
        long long F = 0, s = 0;
        int n = A.size();
        for(int i = 0; i < n; ++i) {
            F += i * A[i];
            s += A[i];
        }
        long long ans = F;
        for(int i = 0; i < n - 1; ++i) {
            F = F + s - (long) n * A[n - 1 - i];
            ans = max(ans, F);
        }
        return ans;
        
    }
};
