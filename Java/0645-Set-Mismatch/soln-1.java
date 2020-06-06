class Solution {
    public int[] findErrorNums(int[] nums) {
        // map num to index (abs(num) - 1)
        int repeat = 0;
        int n = nums.length;
        for(int i = 0; i < n; ++i) {
            int j = Math.abs(nums[i]) - 1;
            if (nums[j] < 0) repeat = j + 1;
            else nums[j] = -nums[j];
        }
        int miss = 0;
        for(int i = 0; i < n; ++i) {
            if (nums[i] > 0) miss = i + 1;
        }
        return new int [] {repeat, miss};
    }
}
