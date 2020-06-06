class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, n = nums.length;
        for(int i = 0; i < n; i += 2) {
            ans += nums[i];
        }
        return ans;
    }
}
