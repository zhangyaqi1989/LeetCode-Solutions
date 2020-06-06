class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int miss = 0, dup = 0;
        for(int i = 0; i < n; ++i) {
            int idx = Math.abs(nums[i]) - 1;
            if (nums[idx] < 0) dup = idx + 1;
            else nums[idx] = -nums[idx];
        }
        for(int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                miss = i + 1;
                break;
            }
        }
        return new int[] {dup, miss};
    }
}
