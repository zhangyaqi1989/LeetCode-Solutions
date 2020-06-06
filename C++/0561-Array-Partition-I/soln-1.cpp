class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ans = 0;
        const int kN = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < kN; i += 2) {
            ans += nums[i];
        }
        return ans;
    }
};
