class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return true;
            else {
                if (nums[mid] == nums[hi]) --hi;
                else if (nums[mid] < nums[hi]) {
                    if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
                    else hi = mid - 1;
                } else {
                    if (target < nums[mid] && nums[lo] <= target) hi = mid - 1;
                    else lo = mid + 1;
                }
            }
        }
        return false;
    }
}
