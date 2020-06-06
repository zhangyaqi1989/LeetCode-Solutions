class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        const int kN = prob.size();
        vector<double> dp(kN + 1, 0.0);
        dp[0] = 1;
        for(int i = 0; i < kN; ++i) {
            vector<double> temp(kN + 1, 0.0);
            double head = prob[i];
            double tail = 1 - head;
            temp[0] = dp[0] * tail;
            for(int j = 1; j <= min(target, i + 1); ++j) {
                temp[j] = dp[j] * tail + dp[j - 1] * head;
            }
            swap(dp, temp);
        }
        return dp[target];
    }
};
