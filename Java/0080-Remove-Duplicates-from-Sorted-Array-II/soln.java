class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0, n = nums.length, cur = 0;
        for(int j = 0; j < n; ++j) {
            if (nums[j] != nums[i]) {
                for(int k = 0; k < Math.min(2, j - i); ++k) nums[cur++] = nums[i];
                i = j;
            }
        }
        for(int k = 0; k < Math.min(2, n - i); ++k) nums[cur++] = nums[i];
        return cur;
    }
}
