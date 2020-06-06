class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), cur = 1;
        for(int i = 0; i < n; ++i) {
            ans.push_back(cur);
            cur *= nums[i];
        }
        cur = 1;
        for(int i = n - 1; i >= 0; --i) {
            ans[i] *= cur;
            cur *= nums[i];
        }
        return ans;
    }
};
