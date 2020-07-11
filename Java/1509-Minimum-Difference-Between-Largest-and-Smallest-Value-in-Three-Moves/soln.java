class Solution {
    public int minDifference(int[] nums) {
        int n = nums.length;
        if(n <= 4) return 0;
        Arrays.sort(nums);
        int ans = nums[n - 1] - nums[0];
        for(int i = 0; i <= 3; ++i) {
            ans = Math.min(ans, nums[n - 1 - (3 - i)] - nums[i]);
        }
        return ans;
    }
}
