class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for(int num : nums) ans += num;
        return (n + 1) * n / 2 - ans;
    }
}
