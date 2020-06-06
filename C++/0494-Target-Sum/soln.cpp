class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size(), ans = 0;
        int bound = 1 << n;
        for (int cur = 0; cur < bound; ++cur) {
            int temp = 0;
            for(int i = 0; i < n; ++i) {
                if ((1 << i) & cur) temp += nums[i];
                else temp -= nums[i];
            }
            if (temp == S) ++ans;
        }
        return ans;
    }
};
