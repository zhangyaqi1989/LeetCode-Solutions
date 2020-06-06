class Solution {
    double cache[120][120];
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        memset(cache, 0, sizeof(cache));
        return helper(A, A.size(), K);
    }
    
    double helper(vector<int> & A, int n, int K) {
        if (cache[n][K] > 0) return cache[n][K];
        double ans = 0.0;
        if (K == n || K == 1) {
            ans = accumulate(A.begin(), A.begin() + n, 0.0);
            if(K == 1) ans /= n;
            cache[n][K] = ans;
            return ans;
        }
        double cur = 0.0;
        int cnt = 0;
        for(int i = n - 1; i >= K - 1; --i) {
            ++cnt;
            cur += A[i];
            double temp = helper(A, i, K - 1) + cur / cnt;
            ans = max(ans, temp);
        }
        cache[n][K] = ans;
        return ans;
    }
};
