class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int n = nums.length;
        int[] sorted_nums = new int[n];
        for(int i = 0; i < n; ++i) sorted_nums[i] = nums[i];
        Arrays.sort(sorted_nums);
        int lo = 0, hi = -1;
        for(int i = 0; i < n; ++i) {
            if (nums[i] != sorted_nums[i]) {
                lo = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; --i) {
            if (nums[i] != sorted_nums[i]) {
                hi = i;
                break;
            }
        }
        return hi - lo + 1;
    }
}
