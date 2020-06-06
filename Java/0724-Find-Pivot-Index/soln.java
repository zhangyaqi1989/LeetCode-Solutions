class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        int left = 0, n = nums.length;
        for(int i = 0; i < n; ++i) {
            if (left + nums[i] + left == sum) return i;
            left += nums[i];
        }
        return -1;
    }
}
