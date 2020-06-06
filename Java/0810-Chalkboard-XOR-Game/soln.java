class Solution {
    public boolean xorGame(int[] nums) {
        int ans = 0;
        for(int num : nums) ans ^= num;
        return ans == 0 || nums.length %2 == 0;
    }
}
