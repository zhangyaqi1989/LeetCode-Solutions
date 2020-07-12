class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        const int kN = nums.size();
        int ans = 0;
        for(int i = 0; i < kN; ++i) {
            for(int j = i + 1; j < kN; ++j) {
                ans += nums[i] == nums[j];
            }
        }
        return ans;
    }
};
