class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros = 0;
        int lo = 0, ans = 0;
        const int kN = nums.size();
        for(int i = 0; i < kN; ++i) {
            zeros += nums[i] == 0;
            while(zeros > 1) {
                zeros -= nums[lo] == 0;
                ++lo;
            }
            ans = max(ans, i - lo);
        }
        return ans;
    }
};
