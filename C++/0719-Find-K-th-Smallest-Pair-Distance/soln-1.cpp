class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // is there a way to compute number of pairs <= distance
        // sort and compute ...
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0, hi = 1000000;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            int l = 0, r = 1;
            for(; l < n; ++l) {
                r = max(r, l + 1);
                while (r < n && nums[r] - nums[l] <= mid) ++r;
                cnt += r - l - 1;
            }
            if (cnt < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
