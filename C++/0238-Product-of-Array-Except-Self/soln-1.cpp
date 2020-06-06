class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int left = 1;
        for(int num : nums) {
            ans.push_back(left);
            left *= num;
        }
        int right = 1;
        const int n = nums.size();
        for(int i = n - 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};
