class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int [] sorted_nums = nums.clone();
        Arrays.sort(sorted_nums);
        int n = nums.length;
        int lo = 0;
        while(lo < n && nums[lo] == sorted_nums[lo]) ++lo;
        int hi = n - 1;
        while(hi > lo && nums[hi] == sorted_nums[hi]) --hi;
        return hi - lo + 1;
    }
}
