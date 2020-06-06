class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int acc = 0;
        vector<int> accs = {acc};
        for(int num : A) {
            acc += num;
            accs.push_back(acc);
        }
        int n = accs.size();
        int ans = accs[L] + accs.back() - accs[n - M - 1];
        for(int i = L; i < n; ++i) {
            int lacc = accs[i] - accs[i - L];
            int macc = INT_MIN;
            for(int j = M; j <= i - L; ++j) {
                macc = max(macc, accs[j] - accs[j - M]);
            }
            for(int j = i; j + M < n; ++j) {
                macc = max(macc, accs[j + M] - accs[j]);
            }
            ans = max(ans, lacc + macc);
        }
        return ans;
    }
};
