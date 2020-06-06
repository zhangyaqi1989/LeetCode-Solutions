class Solution {
public:
    int rob(vector<int> & nums) {
        // dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        int n = nums.size();
        if (n == 0) return 0;
        else if (n == 1) return nums[0];
        else if (n == 2) return max(nums[0], nums[1]);
        else {
            return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
        }
    }

    int helper(vector<int> & nums, int lo, int hi) {
        int n = hi - lo + 1;
        int first = nums[lo], second = max(nums[lo], nums[lo + 1]);
        for(int i = lo + 2; i <= hi; ++i) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};
