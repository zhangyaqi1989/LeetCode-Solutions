class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0, n = nums.length;
        for(int num : nums) {
            if (num != 0) nums[i++] = num;
        }
        while (i < n) nums[i++] = 0;
    }
}
