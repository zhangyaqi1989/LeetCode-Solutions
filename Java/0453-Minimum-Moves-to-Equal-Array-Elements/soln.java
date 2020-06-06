class Solution {
    public int minMoves(int[] nums) {
        int mn = Integer.MAX_VALUE;
        for(int num : nums) {
            if (num < mn) mn = num;
        }
        int ans = 0;
        for(int num : nums) {
            ans += num - mn;
        }
        return ans;
    }
}
