class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(Helper(A, L, M), Helper(A, M, L));
    }
    
private:
    int Helper(const vector<int> & A, const int & L, const int & M) {
        const int kN = A.size();
        vector<int> best_L(kN, 0);
        vector<int> best_M(kN, 0);
        int window = 0;
        int mx = 0;
        // cout << L << " " << M << endl;
        for(int i = 0; i < kN; ++i) {
            window += A[i];
            if (i - L >= 0) window -= A[i - L];
            if (i >= L - 1) {
                mx = max(mx, window);
                best_L[i] = mx;
            }
        }
        window = 0;
        mx = 0;
        for(int i = kN - 1; i >= 0; --i) {
            window += A[i];
            if (i + M < kN) window -= A[i + M];
            if (i <= kN - M) {
                mx = max(mx, window);
                best_M[i] = mx;
            }
        }
        int ans = 0;
        for(int i = L - 1; i < kN - M; ++i) {
            ans = max(ans, best_L[i] + best_M[i + 1]);
        }

        return ans;
    }
};
