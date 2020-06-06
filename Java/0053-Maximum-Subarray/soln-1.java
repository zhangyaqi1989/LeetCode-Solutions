class Solution {
    public int maxSubArray(int[] nums) {
        int cur = 0;
        int mx = Integer.MIN_VALUE;
        for(int num : nums) {
            cur += num;
            cur = Math.max(cur, num);
            mx = Math.max(mx, cur);
        }
        return mx;
    }
}
