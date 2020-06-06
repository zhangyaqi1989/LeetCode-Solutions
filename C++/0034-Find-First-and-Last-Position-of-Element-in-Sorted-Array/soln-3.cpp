class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lo_iter = lower_bound(nums.begin(), nums.end(), target);
        auto lo = lo_iter - nums.begin();
        if (lo == nums.size() || nums[lo] != target) 
            return {-1, -1};
        auto hi = upper_bound(lo_iter, nums.end(), target) - nums.begin() - 1;
        return {lo, hi};
    }
};
