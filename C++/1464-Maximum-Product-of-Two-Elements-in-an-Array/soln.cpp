class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int kN = nums.size();
        int ans = 0;
        for(int i = 0; i < kN; ++i) {
            for(int j = i + 1; j < kN; ++j) {
                ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        return ans;
    }
};
