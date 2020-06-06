class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int cur = nums[0], n = nums.size();
        for(int i = 1; i < n; ++i) {
            cur = max(cur + nums[i], nums[i]);
            ans = max(cur, ans);
        }
        return ans;
    }
};
