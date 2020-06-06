class Solution {
    public boolean checkPossibility(int[] nums) {
        boolean modified = false;
        int n = nums.length;
        for(int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                if (modified) {
                    return false;
                } else {
                    modified = true;
                    if (i - 1 == 0 || nums[i - 2] <= nums[i]) {
                        nums[i - 1] = nums[i];
                    } else {
                        nums[i] = nums[i - 1];
                    }
                }
            }
        }
        return true;
    }
}
