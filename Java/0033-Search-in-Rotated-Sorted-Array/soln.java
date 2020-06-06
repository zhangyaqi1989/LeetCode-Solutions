class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else {
                if (nums[mid] < nums[hi]) { // right half is sorted
                    if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
                    else hi = mid - 1;
                } else { // left half is sorted
                    if (target >= nums[lo] && target < nums[mid]) hi = mid - 1;
                    else lo = mid + 1;
                }
            }
        }
        return -1;
    }
}
