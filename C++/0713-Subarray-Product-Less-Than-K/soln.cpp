class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0, n = nums.size();
        int cur = 1;
        for(int j = 0; j < n; ++j) {
            cur *= nums[j];
            while(i < j && cur >= k) cur /= nums[i++];
            if (cur < k) ans += j - i + 1;
        }
        return ans;
    }
};
