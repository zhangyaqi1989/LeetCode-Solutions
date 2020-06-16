class Solution {
    public int[] runningSum(int[] nums) {
        int n = nums.length;
        int [] ans = new int [n];
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            cur += nums[i];
            ans[i] = cur;
        }
        return ans;
    }
}
