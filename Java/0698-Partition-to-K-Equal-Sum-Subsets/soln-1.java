class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int total = 0;
        for(int num : nums) total += num;
        if (nums.length < k || total % k != 0) return false;
        Arrays.sort(nums);
        int target = total / k;
        if (nums[nums.length - 1] > target) return false;
        int [] subs = new int[k];
        return dfs(nums, subs, nums.length - 1, target);
    }
    
    public boolean dfs(int [] nums, int [] subs, int idx, int target) {
        if (idx == -1) return true;
        for(int j = 0; j < subs.length; ++j) {
            if (subs[j] + nums[idx] <= target) {
                subs[j] += nums[idx];
                if (dfs(nums, subs, idx - 1, target)) return true;
                subs[j] -= nums[idx];
            }
            if (subs[j] == 0) break;
        }
        return false;
    }
}
