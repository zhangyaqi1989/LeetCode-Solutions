class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        const int kN = nums.size();
        vector<int> ans(kN);
        int cur = 0;
        for(int i = 0; i < kN; ++i) {
            cur += nums[i];
            ans[i] = cur;
        }
        return ans;
    }
};
