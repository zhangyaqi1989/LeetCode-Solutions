class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int cur = 1, ans = 1, n = nums.size();
        for(int i = 1; i < n; ++i) {
            cur = nums[i] > nums[i - 1] ? cur + 1 : 1;
            ans = max(ans, cur);
        }
        return ans;
    }
};
