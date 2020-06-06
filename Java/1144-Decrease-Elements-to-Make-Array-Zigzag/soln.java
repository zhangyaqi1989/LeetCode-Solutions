class Solution {
    public int movesToMakeZigzag(int[] nums) {
        return Math.min(countMoves(nums.clone(), true), countMoves(nums.clone(), false));
    }
    
    public int countMoves(int [] nums, boolean flag) {
        int cnt = 0, n = nums.length;
        for(int i = 1; i < n; ++i) {
            if (flag) { // nums[i - 1] > nums[i]
                if (nums[i - 1] <= nums[i]) {
                    cnt += nums[i] - nums[i - 1] + 1;
                    nums[i] = nums[i - 1] - 1;
                }
            } else { // nums[i - 1] < nums[i]
                if (nums[i - 1] >= nums[i]) {
                    cnt += nums[i - 1] - nums[i] + 1;
                    nums[i - 1] = nums[i] - 1;
                }
            }
            flag = !flag;
        }
        return cnt;
    }
}
