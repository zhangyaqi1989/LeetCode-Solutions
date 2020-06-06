class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        else if (n == 1) return nums[0];
        else if (n == 2) return Math.max(nums[0], nums[1]);
        else {
            return Math.max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
        }
    }
    
    public int helper(int[] nums, int lo, int hi) {
        int n = hi - lo + 1;
        if (n == 2) return Math.max(nums[lo], nums[lo + 1]);
        else {
            int first = nums[lo], second = Math.max(nums[lo], nums[lo + 1]);
            for(int i = lo + 2; i <= hi; ++i) {
                int temp = second;
                second = Math.max(first + nums[i], second);
                first = temp;
            }
            return second;
        }
    }
}
