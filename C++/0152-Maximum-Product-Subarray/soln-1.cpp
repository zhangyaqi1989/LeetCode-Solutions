class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0], mn = nums[0], ans = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            int temp = mn;
            mn = min(nums[i], min(mx * nums[i], mn * nums[i]));
            mx = max(nums[i], max(mx * nums[i], temp * nums[i]));
            ans = max(ans, mx);
        }
        return ans;
    }
};
