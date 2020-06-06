class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // find the first and last
        const int n = nums.size();
        auto p = equal_range(nums.begin(), nums.end(), target);
        if (p.first == p.second) return {-1, -1};
        return {p.first - nums.begin(), p.second - nums.begin() - 1};
    }
};
