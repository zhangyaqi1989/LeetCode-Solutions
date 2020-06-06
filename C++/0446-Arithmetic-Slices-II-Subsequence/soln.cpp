class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        const int kN = A.size();
        vector<unordered_map<long long, int>> dp(kN);
        int total = 0;
        for(int i = 0; i < kN; ++i) {
            for(int j = 0; j < i; ++j) {
                long long d = (long long) A[i] - A[j];
                dp[i][d] += 1;
                auto it = dp[j].find(d);
                if (it != dp[j].end()) {
                    dp[i][d] += it->second;
                    total += it->second;
                }
            }
        }
        return total;
    }
};
