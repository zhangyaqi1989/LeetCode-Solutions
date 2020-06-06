class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int best = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; ++i) {
            int lo = i + 1, hi = n - 1;
            while(lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (Math.abs(sum - target) == 0) {
                    return target;
                } else if (Math.abs(sum - target) < Math.abs(best - target)) {
                    best = sum;
                }
                if (sum > target) {
                    --hi;
                } else {
                    ++lo;
                }
            }
        }
        return best;
    }
}
