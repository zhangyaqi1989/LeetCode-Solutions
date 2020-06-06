class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        for(int i = 0; i < n; ++i) {
            int idx = Math.abs(nums[i]) - 1;
            if (nums[idx] < 0) ans.add(idx + 1);
            else nums[idx] = -nums[idx];
        }
        return ans;
    }
}
