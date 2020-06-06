class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = accumulate(nums.begin(), nums.begin() + k, 0.0);
        double cur = ans;
        for(int i = 0; i < nums.size() - k; ++i) {
            cur = cur + nums[i + k] - nums[i];
            ans = max(cur, ans);
        }
        return ans / k;
    }
};