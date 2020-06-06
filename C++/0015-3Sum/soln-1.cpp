class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int s = nums[i] + nums[lo] + nums[hi];
                if (s == 0) {
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    while (lo + 1 < hi && nums[lo + 1] == nums[lo]) ++lo;
                    while (hi - 1 > lo && nums[hi - 1] == nums[hi]) --hi;
                    ++lo;
                    --hi;
                } else if (s < 0) ++lo;
                else --hi;
            }
        }
        return ans;
    }
};
