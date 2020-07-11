class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int kN = nums.size();
        if(kN <= 4) return 0;
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums[0];
        for(int i = 0; i <= 3; ++i) {
            ans = min(ans, nums[kN - 1 - (3 - i)] - nums[i]);
        }
        return ans;
    }
};
