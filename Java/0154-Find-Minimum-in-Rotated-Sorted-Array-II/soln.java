class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } else if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                // nums[mid] == nums[hi];
                hi -= 1;
            }
        }
        return nums[lo];
    }
}
