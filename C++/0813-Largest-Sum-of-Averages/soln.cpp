class Solution {
    map<pair<int, int>, double> cache;
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        cache.clear();
        return helper(A, A.size(), K);
    }
    
    double helper(vector<int> & A, int n, int K) {
        pair<int, int> p = {n, K};
        auto it = cache.find(p);
        if (it != cache.end()) return it->second;
        double ans = 0.0;
        if (K == n || K == 1) {
            ans = accumulate(A.begin(), A.begin() + n, 0.0);
            if(K == 1) ans /= n;
            cache[p] = ans;
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
        cache[p] = ans;
        return ans;
    }
};
