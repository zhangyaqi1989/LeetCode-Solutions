class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int memo[21][21];
        memset(memo, -1, sizeof(memo));
        int total = accumulate(nums.begin(), nums.end(), 0);
        return compute_score(total, nums, 0, nums.size() - 1, memo) >= total / 2.0;
    }
    
    int compute_score(int total, vector<int> & nums, int s, int e, int memo[][21]) {
        if (s > e) return 0;
        if (memo[s][e] != -1) return memo[s][e];
        int ans;
        int left = total - compute_score(total - nums[s], nums, s + 1, e, memo);
        int right = total - compute_score(total - nums[e], nums, s, e - 1, memo);
        ans = max(left, right);
        memo[s][e] = ans;
        return ans;
    }
};
