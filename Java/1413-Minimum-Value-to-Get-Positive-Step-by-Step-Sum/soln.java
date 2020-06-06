class Solution {
    public int minStartValue(int[] nums) {
        int mn = Integer.MAX_VALUE;
        int cur = 0;
        for(int num : nums) {
            cur += num;
            mn = Math.min(mn, cur);
        }
        return Math.max(1, 1 - mn);
    }
}
