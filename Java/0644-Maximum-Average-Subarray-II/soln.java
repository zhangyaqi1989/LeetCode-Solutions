class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double lo = -10000, hi = 10000;
        while (hi - lo >= 0.00001) {
            double mid = (lo + hi) * 0.5;
            if (check(nums, k, mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    
    public boolean check(int[] nums, int k, double avg) {
        double cur = 0, pre = 0, min_seen = 0;
        int n = nums.length;
        for(int i = 0; i < k; ++i) cur += nums[i] - avg;
        if(cur >= 0) return true;
        for(int i = k; i < n; ++i) {
            cur += nums[i] - avg;
            pre += nums[i - k] - avg;
            min_seen = Math.min(min_seen, pre);
            if (cur >= min_seen) {
                return true;
            }
        }
        return false;
    }
}
