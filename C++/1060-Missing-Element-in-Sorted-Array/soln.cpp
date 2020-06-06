class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int lo = 1, hi = 1e9;
        const int kN = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int left = mid - nums[0];
            auto it = lower_bound(nums.begin(), nums.end(), mid);
            int less = it - nums.begin();
            int miss = left - less;
            if (it == nums.end() || *it != mid) ++miss;
            if (miss < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            } 
        }
        return lo;
    }
};
