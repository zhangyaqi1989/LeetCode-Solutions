class Solution {
    public int removeDuplicates(int[] nums) {
        int idx = 0;
        int n = nums.length;
        for(int i = 0; i < n; ++i) {
            if(i == 0 || nums[i] != nums[i - 1]) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
}
