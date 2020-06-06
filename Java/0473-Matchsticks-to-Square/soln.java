class Solution {
    public boolean makesquare(int[] nums) {
        if(nums.length < 4) return false;
        int total = 0;
        for(int num : nums) total += num;
        if (total % 4 != 0) return false;
        int [] sides = new int [4];
        return dfs(0, nums, sides, total / 4);
    }
    
    private boolean dfs(int idx, int [] nums, int [] sides, int target) {
        if (idx == nums.length) return true;
        for(int i = 0; i < 4; ++i) {
            if (sides[i] + nums[idx] <= target) {
                sides[i] += nums[idx];
                if (dfs(idx + 1, nums, sides, target)) return true;
                sides[i] -= nums[idx];
            }
        }
        return false;
    } 
}
