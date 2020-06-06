class Solution {
    public int jump(int[] nums) {
        int jumps = 0, end = 0, farthest = 0, n = nums.length;
        for(int i = 0; i < n; ++i) {
            if (end >= n - 1) break;
            farthest = Math.max(farthest, i + nums[i]);
            if (i == end) {
                ++jumps;
                end = farthest;
            }
        }
        return jumps;
    }
}
