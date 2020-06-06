class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> window;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            auto lo = window.lower_bound(nums[i]);
            if (lo != window.begin() && (long) nums[i] - *prev(lo) <= t) return true;
            if (lo != window.end() && (long)*lo - nums[i] <= t) return true;
            window.insert(nums[i]);
            if (i >= k) window.erase(window.find(nums[i - k]));
        }
        return false;
    }
};
