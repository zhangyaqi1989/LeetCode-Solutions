class Solution {
    public int maxSubArray(int[] nums) {
        int cur = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            int num = nums[i];
            cur = Math.max(cur + num, num);
            res = Math.max(res, cur);
        }
        return res;
    }
}