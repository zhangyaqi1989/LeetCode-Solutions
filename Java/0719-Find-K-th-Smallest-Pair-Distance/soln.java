class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int lo = 0, hi = 1000000;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0, j = 0;
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
}
