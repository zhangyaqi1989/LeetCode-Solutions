class Solution {
    public void sortColors(int[] nums) {
        // in-place
        int n = nums.length;
        int zero_idx = 0;
        int two_idx = n - 1;
        for(int i = 0; i <= two_idx; ++i) {
            if(nums[i] == 0) {
                nums[zero_idx++] = 0;
            } else if (nums[i] == 2) {
                nums[i] = nums[two_idx];
                nums[two_idx--] = 2;
                --i;
            }
        }
        for(int i = zero_idx; i <= two_idx; ++i) nums[i] = 1;
    }
}
