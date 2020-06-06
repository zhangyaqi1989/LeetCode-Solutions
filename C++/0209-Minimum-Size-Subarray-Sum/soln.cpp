class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        int i = 0, sum = 0;
        for(int j = 0; j < n; ++j) {
            sum += nums[j];
            if (sum >= s) {
                while (i < j && sum - nums[i] >= s) {
                    sum -= nums[i++];
                }
                ans = min(ans, j - i + 1);
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};
