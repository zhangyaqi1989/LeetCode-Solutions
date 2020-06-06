class Solution {
    public int findDuplicate(int[] nums) {
        int lo = 1, hi = nums.length - 1;
        // find the first one that cnt > mid
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for(int num : nums) {
                if (num <= mid) ++cnt;
            }
            if (cnt > mid) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
}
