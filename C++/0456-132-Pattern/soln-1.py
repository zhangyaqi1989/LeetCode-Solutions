class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> stk;
        int n = nums.size();
        int two = INT_MIN;
        for(int i = n - 1; i >= 0; --i) {
            if (two > nums[i]) return true;
            while (!stk.empty() && nums[i] > stk.back()) {
                two = max(two, stk.back());
                stk.pop_back();
            }
            stk.push_back(nums[i]);
        }
        return false;
    }
};
