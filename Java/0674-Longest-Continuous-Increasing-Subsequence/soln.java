class Solution {
    public int findLengthOfLCIS(int[] nums) {
        if (nums.length == 0) return 0;
        int cur = 1, mx = 1, n = nums.length;
        for(int i = 1; i < n; ++i) {
            cur = nums[i] > nums[i - 1] ? cur + 1 : 1;
            mx = Math.max(mx, cur);
        }
        return mx;
    }
}
