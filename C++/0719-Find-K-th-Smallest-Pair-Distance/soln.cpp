class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = 1000000;
        int n = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int j = 0;
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                int num = nums[i];
                while (j < n && nums[j] - num <= mid) ++j;
                cnt += j - i - 1;
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
