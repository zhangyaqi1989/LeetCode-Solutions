class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        else if (n == 1) return nums[0];
        else {
            int a = nums[0];
            int b = Math.max(a, nums[1]);
            for(int i = 2; i < n; ++i) {
                int temp = b;
                b = Math.max(a + nums[i], b);
                a = temp;
            }
            return b;
        }
    }
}
