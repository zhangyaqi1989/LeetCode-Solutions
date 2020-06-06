class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return Solve(1, n, &memo);
    }
    
private:
    int Solve(int lo, int hi, vector<vector<int>> * memo) {
        if (lo >= hi) return 0;
        if ((*memo)[lo][hi] != -1) {
            return (*memo)[lo][hi];
        }
        int ans = INT_MAX;
        for(int guess = lo; guess < hi; ++guess) {
            ans = min(ans, guess + max(Solve(lo, guess - 1, memo), Solve(guess + 1, hi, memo)));
        }
        (*memo)[lo][hi] = ans;
        return ans;
    }
};
