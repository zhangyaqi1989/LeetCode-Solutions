class Solution {
    public boolean canJump(int[] nums) {
        int farthest = 0;
        int n = nums.length;
        for(int i = 0; i < n; ++i) {
            if (farthest < i) return false;
            farthest = Math.max(farthest, i + nums[i]);
            if (farthest >= n - 1) return true;
        }
        return farthest >= n - 1;
    }
}
